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

    for (size_t testCount = 1; testCount <= 5; testCount++)
    {
        printf("test_%llu: %llu\n", testCount, testHashTable(8192, FNVHash, &text, 100));
    }

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



