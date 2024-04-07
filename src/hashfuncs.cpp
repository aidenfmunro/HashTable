#include "hashfuncs.hpp"

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
    uint64_t hash = *(size_t*) memory;

    return hash % htSize;
}

uint64_t letterSumHash (const void* memory, size_t htSize)
{
    uint64_t hash = 0;

    int iterator = 0;

    char curSym = *(char*) memory + iterator;

    while ( curSym != '\0' )
    {
        hash += curSym;

        iterator++; 
    }

    return hash;
}

