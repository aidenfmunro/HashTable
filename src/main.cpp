#include "linkedlist.hpp"
#include "hashtable.hpp"
#include "hashfuncs.hpp"
#include "textfuncs.hpp"
#include "listdump.hpp"

int main(void)
{
    HashTable ht = {};
    size_t bucketsQuantity = 1009;

    CreateHashTable(&ht, bucketsQuantity, firstLetterHash);

    Text text = {};
    CreateText(&text, "result.txt");

    // fillWithWordLengthHash(&ht, &text);

    // fillWithLetterSumHash(&ht, &text);

    fillWithFirstLetterHash(&ht, &text);

    fillHashData(&ht, "hashres.txt");

    printf("list size: %llu\n", ht.lists[0].size);

    PrintList(&ht.lists[0]);

    DestroyText(&text);
    DestroyHashTable(&ht);

    return OK;
}