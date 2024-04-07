#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdio.h>
#include <stdlib.h>
#include "utils.hpp"

typedef char* Elem_t;
 
const size_t FREE_ELEM = -1;

const int MULTIPLIER = 2;

const Elem_t POISON = "POISON";

const int DEFAULT_LIST_CAPACITY = 8;

const int MAX_LIST_CAPACITY = 1024;

const size_t FREE_HEAD = -1;

struct ListElem_t
{
    Elem_t value;

    size_t next;
    size_t prev;
};

struct List
{
    ListElem_t* ptr;

    size_t size;
    size_t capacity;
    size_t freeHead;

    size_t head;
    size_t tail;
};

ErrorCode CreateList(List* list);

ErrorCode DestroyList(List* list);

ErrorCode PushFront(List* list, Elem_t value);

ErrorCode PushBack(List* list, Elem_t value);

ErrorCode InsertAfter(List* list, size_t index, Elem_t value);

ErrorCode InsertBefore(List* list, size_t index, Elem_t value);

ErrorCode reallocList(List* list);

Elem_t    Remove(List* list, size_t index);

ErrorCode listVerify(List* list);

#endif