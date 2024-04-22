#include <immintrin.h>

#include "hashfuncs.hpp"

uint64_t zeroHash (const void* seed, size_t seedLength)
{   
    return 0;
}

uint64_t firstLetterHash (const void* seed, size_t seedLength)
{
    uint64_t hash = *(const char*) seed;

    return hash;
}

uint64_t wordLengthHash (const void* seed, size_t seedLength)
{
    return (uint64_t) seedLength;
}

uint64_t letterSumHash (const void* seed, size_t seedLength)
{
    uint64_t hash = 0;

    const char* key = (const char*) seed;

    for (int i = 0; i < seedLength; i++)
    {   
        hash += key[i];
    }
    
    return hash;
}

uint64_t letterSumDivLenHash (const void* seed, size_t seedLength)
{
    uint64_t hash = 0;

    const char* key = (const char*) seed;

    for (int i = 0; i < seedLength; i++)
    {
        hash += key[i];
    }

    return (uint64_t)( (double) hash / (double) seedLength);
}

inline static uint64_t rotateRight (uint64_t hash) 
{
    return ( (hash >> 1) | (hash << 63) );
}

uint64_t rotateRightHash (const void* seed, size_t seedLength)
{
    const char* key = (const char*) seed;

    uint64_t hash = (uint64_t)key[0];

    for (uint64_t i = 0; i < seedLength; i++)
    {
        hash = rotateRight(hash) ^ key[i]; 
    }

    return hash;    
}

inline static uint64_t rotateLeft (uint64_t hash) 
{
    return ( (hash << 1) | (hash >> 63) );
}

uint64_t rotateLeftHash (const void* seed, size_t seedLength)
{
    const char* key = (const char*) seed;

    uint64_t hash = (uint64_t)key[0];

    for (size_t i = 0; i < seedLength; i++)
    {
        hash = rotateLeft(hash) ^ key[i]; 
    }

    return hash; 
}

uint64_t FNVHash (const void* seed, size_t seedLength)
{
    uint64_t FNVprime = 0x811C9DC5;

    const char* key = (const char*) seed;

    uint64_t hash = key[0];

    for (size_t i = 0; i < seedLength; i++)
    {
       hash *= FNVprime;
       hash ^= key[i];
    }

    return hash;
}

uint64_t CRC32Hash (const void* seed, size_t seedLength)
{
    uint64_t hash = 0xFFFFFFFFu;

    const char* key = (const char*) seed;

    for (size_t i = 0; i < seedLength; i++) 
    {
        hash = _mm_crc32_u8(hash, key[i]);
	}

	return hash;
}