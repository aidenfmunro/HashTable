#include "dsl.h"

#include "graphparams.h"

#include "linkedlist.h"

// TD: linearization

ErrorCode CreateList(List* list)
{
    AssertSoft(list, NULL_PTR);

    SafeCalloc(tempPtr, ListElem_t, DEFAULT_LIST_CAPACITY, NO_MEMORY_AVAILABLE);

    list->ptr = tempPtr;

    list->size = 1;

    list->capacity = DEFAULT_LIST_CAPACITY;

    // TD: fill_range()
    // DSL: add_to_free

    for (size_t i = 0; i < DEFAULT_LIST_CAPACITY; i++)
    {
        VALUE(i) = POISON;
    }

    for (size_t i = 1; i < DEFAULT_LIST_CAPACITY - 1; i++)
    {
        NEXT(i) = i + 1;
    }

    for (size_t i = 1; i < DEFAULT_LIST_CAPACITY; i++)
    {
        PREV(i) = FREE_ELEM;
    }

    list->freeHead = 1;

    list->head = NEXT(0);
    list->tail = PREV(0); // TD: sensiel

    return OK;
}

ErrorCode DestroyList(List* list) // TODO: fill with poison value 
{
    AssertSoft(list, NULL_PTR);

    free(list->ptr);

    return OK;
}

#define CHECK_VERIFICATION(error)       \
    if (error)                          \
    {                                   \
        return error;                   \
    }

ErrorCode InsertAfter(List* list, size_t index, Elem_t value)
{
    CHECK_VERIFICATION(listVerify(list));

    list->size++;

    if (list->size > list->capacity)
    {
       reallocList(list); 
    }
    // TODO: DSL - CONNECT_NODES(node1, node2)
    size_t insertIndex = list->freeHead; 

    list->freeHead     = NEXT(insertIndex);

    VALUE(insertIndex) = value;

    PREV(insertIndex)  = index;
    NEXT(insertIndex)  = NEXT(index);

    PREV(NEXT(index))  = insertIndex;
    NEXT(index)        = insertIndex;

    CHECK_VERIFICATION(listVerify(list));

    return OK;
}

#undef CHECK_VERIFICATION

ErrorCode InsertBefore(List* list, size_t index, Elem_t value)
{
    return InsertAfter(list, PREV(index), value);
}

ErrorCode PushFront(List* list, Elem_t value)
{
    return InsertAfter(list, list->head, value);
}

ErrorCode PushBack(List* list, Elem_t value) // TODO: return physical address
{
    return InsertBefore(list, list->tail, value); 
}
    
Elem_t Remove(List* list, size_t index)
{
    AssertSoft(index < list->size, "INDEX OUT OF RANGE");

    Elem_t value   = VALUE(index);
    size_t delPrev = PREV(index);
    size_t delNext = NEXT(index);

    size_t curFree = list->freeHead;

    NEXT(curFree) = index;

    list->freeHead = index;

    VALUE(index) = POISON;

    NEXT(index) = curFree;

    PREV(index) = FREE_ELEM;

    NEXT(delPrev) = delNext;

    PREV(delNext) = delPrev;

    list->size--;

    return value;
}

ErrorCode reallocList(List* list)
{
    SafeRealloc(tempPtr, ListElem_t, list->ptr, list->capacity * MULTIPLIER * sizeof(ListElem_t));

    size_t capacityExtended = list->capacity * MULTIPLIER;

    list->ptr = tempPtr;

    for (size_t i = list->capacity; i < capacityExtended - 1; i++)
    {
        NEXT(i) = i + 1;
    }

    for (size_t i = list->capacity; i < capacityExtended; i++)
    {
        VALUE(i) = POISON;
        PREV(i) = FREE_ELEM;
    }
    
    NEXT(capacityExtended - 1) = 0; 

    list->freeHead = list->capacity;

    list->capacity = capacityExtended;

    return OK;
}

ErrorCode linearizeList(List* list)
{
    SafeCalloc(tempPtr, ListElem_t, list->capacity, NULL_PTR)

    size_t curIndex = list->head;

    size_t counter = 1;

    while (curIndex)
    {
        tempPtr[counter].value = VALUE(curIndex);
        curIndex = NEXT(curIndex);
    }

    for (size_t i = list->size; i < list->capacity; i++)
    {
        VALUE(i) = POISON;
    }

    for (size_t i = 1; i < list->capacity - 1; i++)
    {
        NEXT(i) = i + 1;
    }

    for (size_t i = 1; i < list->capacity; i++)
    {
        PREV(i) = FREE_ELEM;
    }

    list->head = PREV(0);
    list->tail = NEXT(0);

    list->freeHead = list->size;

    return OK;
}

#define CHECK_ERROR(EXPRESSION, ERROR)                  \
    if (EXPRESSION)                                     \
    {                                                   \
        return ERROR;                                   \
    }                


ErrorCode listVerify(List* list)
{
    CHECK_ERROR(!list, NULL_PTR);
    CHECK_ERROR(!list->ptr, NULL_PTR);
    CHECK_ERROR(list->size > list->capacity, LIST_OVERFLOW);
    CHECK_ERROR(list->capacity > MAX_LIST_CAPACITY, LIST_OVERFLOW);
    CHECK_ERROR(list->freeHead > list->capacity - 1, FREEHEAD_FUCKED_UP);

    // TD: loop?

    return OK;
}

#undef CHECK_ERROR
