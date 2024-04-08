#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <stdio.h>
#include <stddef.h>
#include <inttypes.h>
#include <string.h>

#include "linkedlist.hpp"
#include "textfuncs.hpp"
#include "utils.hpp"

typedef uint64_t (*hashFunction_t)(const void* memory, size_t size); 

struct HashTable
{
    List* lists;

    hashFunction_t hashFunction;

    size_t size;
};

ErrorCode CreateHashTable (HashTable* ht, size_t bucketsQuantity, hashFunction_t hashFunction);

ErrorCode DestroyHashTable (HashTable* ht);

ErrorCode findElement(HashTable* ht, size_t listIndex, Elem_t elem);


#endif