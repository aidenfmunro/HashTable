#include "linkedlist.hpp"
#include "hashtable.hpp"
#include "hashfuncs.hpp"
#include "textfuncs.hpp"
#include "listdump.hpp"

int main(void)
{
    HashTable ht = {};
    size_t bucketsQuantity = 879490 / 5;

    CreateHashTable(&ht, bucketsQuantity, letterSumDivLenHash);

    Text text = {};
    CreateText(&text, "result.txt");

    fillWithLetterSumDivLenHash(&ht, &text);

    fillHashData(&ht, "hashres.txt", "ASCII sum hash (Load factor = 5)");

    printf("list size: %llu\n", ht.lists[0].size);

    PrintList(&ht.lists[0]);

    DestroyText(&text);
    DestroyHashTable(&ht);

    return OK;
}