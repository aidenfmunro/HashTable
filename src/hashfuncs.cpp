#include "hashfuncs.hpp"

uint64_t zeroHash (const void* seed, size_t seedLength)
{   
    return 0;
}

uint64_t firstLetterHash (const void* seed, size_t seedLength)
{
    uint64_t hash = *(char*) seed;

    return hash;
}

// Give the pointer of the number location

const int CHAR_POINTER_SIZE = 8;

// struct Line {char* ..., size_t length}

uint64_t wordLengthHash (const void* seed, size_t seedLength)
{
    return (uint64_t) seedLength;
}

uint64_t letterSumHash (const void* seed, size_t seedLength)
{
    uint64_t hash = 0;

    char* key = (char*) seed;

    for (int i = 0; i < seedLength; i++)
    {   
        hash += key[i];
    }
    
    return hash;
}

uint64_t letterSumDivLenHash (const void* seed, size_t seedLength)
{
    uint64_t hash = 0;

    char* key = (char*) seed;

    for (int i = 0; i < seedLength; i++)
    {
        hash += key[i];
    }

    return (uint64_t)( (double) hash / (double) seedLength);
}

uint64_t rotateRightHash (const void* seed, size_t seedLength)
{
    const char* key = (char*) seed;

    uint64_t hash = (uint64_t)key[0];

    for (uint64_t i = 0; i < seedLength; i++)
    {
        hash = ( (hash >> 1) | (hash << 63) ) ^ key[i]; 
    }

    return hash;    
}

uint64_t rotateLeftHash (const void* seed, size_t seedLength)
{
    const char* key = (char*) seed;

    uint64_t hash = (uint64_t)key[0];

    for (uint64_t i = 0; i < seedLength; i++)
    {
        hash = ( (hash << 1) | (hash >> 63) ) ^ key[i]; 
    }

    return hash; 
}

uint64_t FNVHash (const void* seed, size_t seedLength)
{
    uint64_t FNVprime = 0x811C9DC5;

    const char* key = (char*) seed;

    uint64_t hash = key[0];

    for (uint64_t i = 0; i < seedLength; i++)
    {
        hash *= FNVprime;
        hash ^= key[i];
    }

    return hash;
}