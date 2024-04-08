#include "hashtable.hpp"

// Aiden: maybe use uint64_t for size? (or use size_t everywhere?)

ErrorCode CreateHashTable (HashTable* ht, size_t bucketsQuantity, hashFunction_t hashFunction)
{
    AssertSoft(ht, NULL_PTR);

    SafeCalloc(temp, List, bucketsQuantity, NO_MEMORY_AVAILABLE);

    ht->size = bucketsQuantity;

    ht->lists = temp;

    for (int i = 0; i < bucketsQuantity; i++)
    {
        CreateList(&ht->lists[i]);
    }

    ht->hashFunction = hashFunction;

    return OK;
}

ErrorCode DestroyHashTable (HashTable* ht)
{
    AssertSoft(ht, NONE_EXISTING);

    for (int i = 0; i < ht->size; i++)
    {
        DestroyList(&ht->lists[i]);
    }

    free(ht->lists);

    ht->size = 0;

    ht->hashFunction = NULL;

    return OK;
}

ErrorCode findElement (HashTable* ht, size_t listIndex, Elem_t elem)
{
    AssertSoft(ht, NULL_PTR);
    AssertSoft(elem, NULL_PTR);
    AssertSoft(listIndex < ht->size, INDEX_OUT_OF_RANGE);

    for (int elemIndex = 0; elemIndex < ht->lists[listIndex].size; elemIndex++)
    {
        if (! strcmp(elem, ht->lists[listIndex].ptr[elemIndex].value))
        {
            ht->lists[listIndex].ptr[elemIndex].count += 1;

            return OK;
        }
    }

    PushBack(&ht->lists[listIndex], elem);

    return OK;
}

ErrorCode fillHashTable (HashTable* ht, const char* inputFile)
{
    AssertSoft(ht, NULL_PTR);
    AssertSoft(inputFile, NULL_PTR);

    Text text = {};
    CreateText(&text, inputFile);
}
