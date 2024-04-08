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

uint64_t wordLengthHash (const void* seed, size_t htSize)
{
    uint64_t hash = *(size_t*) seed;

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

