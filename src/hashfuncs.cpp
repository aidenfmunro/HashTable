#include "hashfuncs.hpp"

uint64_t zeroHash (const void* seed, size_t htSize)
{   
    return 0;
}

uint64_t firstLetterHash (const void* seed, size_t htSize)
{
    uint64_t hash = *(char*) seed;

    return hash % htSize;
}

// Give the pointer of the number location

const int CHAR_POINTER_SIZE = 8;

// struct Line {char* ..., size_t length}

uint64_t wordLengthHash (const void* seed, size_t htSize)
{
    uint64_t hash = *(size_t*) ((char*)seed + CHAR_POINTER_SIZE);

    return hash % htSize;
}

uint64_t letterSumHash (const void* seed, size_t htSize)
{
    uint64_t hash = 0;

    char* key = (char*) seed;

    while (*key != '\0')
    {   
        hash += *key;

        key++;
    }
    
    return hash % htSize;
}

uint64_t letterSumDivLenHash (const void* seed, size_t htSize)
{
    uint64_t hash = 0;

    char* key = (char*) seed;
    uint64_t length = 0;

    while (*key != '\0')
    {
        hash += *key;

        key++;
        length++;
    }

    return (uint64_t)( (double) hash / (double) length) % htSize;
}

const uint64_t BITS_IN_BYTE = 8;

uint64_t rotateRightHash (const void* seed, size_t htSize)
{
    const char* key = (char*) seed;

    uint64_t hash = (uint64_t)key[0];
    uint64_t keyLength = strlen(key);

    for (uint64_t i = 0; i < keyLength; i++)
    {
        hash = ( (hash >> 1) | (hash << 63) ) ^ key[i]; 
    }

    return hash % htSize;    
}

