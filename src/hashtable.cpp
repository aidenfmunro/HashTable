#include <stdio.h>
#include <stddef.h>
#include <inttypes.h>

#include "linkedlist.h"
#include "utils.h"

struct HashTable
{
    List* lists;

    hashFunction_t hashFunction;

    size_t size;
};

// Aiden: maybe use uint64_t for size? (or use size_t everywhere?)

typedef uint64_t (*hashFunction_t)(const void* memory, size_t size); 

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

uint64_t zeroHash (const void* memory, size_t htSize)
{   
    return 0;
}

uint64_t firstLetterHash (const void* memory, size_t htSize)
{
    uint64_t hash = *(char*) memory;

    return hash % htSize;
}

// Give the pointer of the number location

uint64_t wordLengthHash (const void* memory, size_t htSize)
{
    uint64_t hash = atol((char*) memory); 

    return hash % htSize;
}
