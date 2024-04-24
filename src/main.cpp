#include <immintrin.h>

#include "linkedlist.hpp"
#include "hashtable.hpp"
#include "hashfuncs.hpp"
#include "textfuncs.hpp"
#include "listdump.hpp"

size_t benchmarkHashTable (HashTable* ht, Text* text);

size_t testHashTable (size_t bucketsQuantity, hashFunction_t hashFunction, Text* text, size_t sampleSize);

int main(void)
{
    Text text = {};
    CreateText(&text, "txt/result.txt");

    size_t avg = 0;
    size_t time = 0;

    for (size_t testCount = 1; testCount <= 5; testCount++)
    {
        time = testHashTable(16384, CRC32Hash_64, &text, 50);

        printf("test_%llu: %llu\n", testCount, time);

        avg += time;
    }

    printf("avg: %llu\n", avg / 5);   
   
    DestroyText(&text);

    return OK;
}

size_t testHashTable (size_t bucketsQuantity, hashFunction_t hashFunction, Text* text, size_t sampleSize)
{
    HashTable ht = {};

    size_t time = 0;

    for (int i = 0; i < sampleSize; i++)
    {
        CreateHashTable(&ht, bucketsQuantity, hashFunction);

        time += benchmarkHashTable(&ht, text);

        DestroyHashTable(&ht);
    }

    return time;
}

size_t benchmarkHashTable (HashTable* ht, Text* text)
{
    size_t start = __rdtsc();

    fillHashTable(ht, text);

    size_t end   = __rdtsc();

    return end - start;
}



