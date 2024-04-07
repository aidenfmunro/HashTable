#include "hashtable.hpp"

// Aiden: maybe use uint64_t for size? (or use size_t everywhere?)

ErrorCode CreateHashTable (HashTable* ht, size_t bucketsQuantity, hashFunction_t hashFunction)
{
    AssertSoft(ht, NULL_PTR);

    SafeCalloc(temp, List, bucketsQuantity, NO_MEMORY_AVAILABLE);

    ht->lists = temp;

    ht->size = bucketsQuantity;

    ht->hashFunction = hashFunction;

    return OK;
}

ErrorCode DestroyHashTable (HashTable* ht)
{
    AssertSoft(ht, NONE_EXISTING);

    free(ht->lists);

    ht->size = 0;

    ht->hashFunction = NULL;

    return OK;
}
