#include "linkedlist.hpp"
#include "hashtable.hpp"
#include "hashfuncs.hpp"
#include "textfuncs.hpp"
#include "listdump.hpp"

int main(void)
{
    HashTable ht = {};
    size_t bucketsQuantity = 809; // load factor 5 1009

    CreateHashTable(&ht, bucketsQuantity, letterSumHash);

    Text text = {};
    CreateText(&text, "result.txt");

    fillWithLetterSumHash(&ht, &text);

    fillHashData(&ht, "hashres.txt", "ASCII sum hash (AWESOME)");

    DestroyText(&text);
    DestroyHashTable(&ht);

    return OK;
}