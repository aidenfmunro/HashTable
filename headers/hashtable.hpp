#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <stdio.h>
#include <stddef.h>
#include <inttypes.h>
#include <string.h>

#include "linkedlist.hpp"
#include "textfuncs.hpp"
#include "utils.hpp"

typedef uint64_t (*hashFunction_t)(const void* seed, size_t seedLength); 

struct HashTable
{
    List* lists;

    hashFunction_t hashFunction;

    size_t size;
};

ErrorCode CreateHashTable             (HashTable* ht, size_t bucketsQuantity, hashFunction_t hashFunction);
           
ErrorCode DestroyHashTable            (HashTable* ht);
           
ErrorCode findElement                 (HashTable* ht, size_t listIndex, Elem_t elem);           
    
ErrorCode fillHashTable               (HashTable* ht, Text* text);

ErrorCode fillHashData                (HashTable* ht, const char* outputFileName, const char* hashName);

size_t    countSumSizeOfLists         (HashTable* ht);

double    calculateLoadFactor         (size_t bucketsQuantity, hashFunction_t hashFunction, const char* inputFile);


#endif