#include "linkedlist.hpp"
#include "hashtable.hpp"
#include "hashfuncs.hpp"
#include "textfuncs.hpp"
#include "listdump.hpp"

int main(void)
{
    HashTable ht = {};
    size_t bucketsQuantity = 101; // load factor 5

    CreateHashTable(&ht, bucketsQuantity, letterSumHash);

    Text text = {};
    CreateText(&text, "result.txt");

    fillWithLetterSumHash(&ht, &text);

    int sumSizeOfLists = 0;
    for (int i = 0; i < ht.size; i++)
    {
        sumSizeOfLists += ht.lists[i].size;
    }

    printf("summed up size of list %d, load factor %d\n", sumSizeOfLists, sumSizeOfLists / ht.size);

    fillHashData(&ht, "hashres.txt", "ASCII sum hash (101 buckets)");

    DestroyText(&text);
    DestroyHashTable(&ht);

    return OK;
}