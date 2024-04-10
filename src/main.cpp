#include "linkedlist.hpp"
#include "hashtable.hpp"
#include "hashfuncs.hpp"
#include "textfuncs.hpp"
#include "listdump.hpp"

int main(void)
{
    HashTable ht = {};
    size_t bucketsQuantity = 809; // load factor 5 1009

    CreateHashTable(&ht, bucketsQuantity, FNVHash);

    Text text = {};
    CreateText(&text, "result.txt");

    fillHashTable(&ht, &text);

    fillHashData(&ht, "hashres.txt", "FNV hash");

    DestroyText(&text);
    DestroyHashTable(&ht);

    return OK;
}