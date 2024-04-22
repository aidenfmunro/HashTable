#include "linkedlist.hpp"
#include "hashtable.hpp"
#include "hashfuncs.hpp"
#include "textfuncs.hpp"
#include "listdump.hpp"

ErrorCode benchmarkHashFunctions (HashTable* ht);

int main(void)
{
    HashTable ht = {};

    // benchmarkHashFunctions(&ht);
    Text text = {};
    CreateText(&text, "txt/result.txt");

    size_t bucketsQuantity = 5009;

    CreateHashTable(&ht, bucketsQuantity, CRC32Hash);
    fillHashTable(&ht, &text);
    fillHashData(&ht, "hashres.txt", "CRC32 Hash");
    
    DestroyHashTable(&ht);

    DestroyText(&text);

    calculateLoadFactor(5009, CRC32Hash, "txt/result.txt");

    return OK;
}

ErrorCode benchmarkHashFunctions (HashTable* ht)
{
    AssertSoft(ht, NULL_PTR);

    size_t bucketsQuantity = 5009; // 35265


    Text text = {};
    CreateText(&text, "txt/result.txt");

    CreateHashTable(ht, bucketsQuantity, zeroHash);
    fillHashTable(ht, &text);
    fillHashData(ht, "hashres.txt", "Zero hash");
    DestroyHashTable(ht);

    CreateHashTable(ht, bucketsQuantity, firstLetterHash);
    fillHashTable(ht, &text);
    fillHashData(ht, "hashres.txt", "First char hash");
    DestroyHashTable(ht);

    CreateHashTable(ht, bucketsQuantity, wordLengthHash);
    fillHashTable(ht, &text);
    fillHashData(ht, "hashres.txt", "String length hash");
    DestroyHashTable(ht);

    CreateHashTable(ht, bucketsQuantity, letterSumDivLenHash);
    fillHashTable(ht, &text);
    fillHashData(ht, "hashres.txt", "ASCII sum divided by length hash");
    DestroyHashTable(ht);

    CreateHashTable(ht, bucketsQuantity, letterSumHash);
    fillHashTable(ht, &text);
    fillHashData(ht, "hashres.txt", "ASCII sum hash");
    DestroyHashTable(ht);

    CreateHashTable(ht, bucketsQuantity, rotateLeftHash);
    fillHashTable(ht, &text);
    fillHashData(ht, "hashres.txt", "ROL hash");
    DestroyHashTable(ht);

    CreateHashTable(ht, bucketsQuantity, rotateRightHash);
    fillHashTable(ht, &text);
    fillHashData(ht, "hashres.txt", "ROR hash");
    DestroyHashTable(ht);

    CreateHashTable(ht, bucketsQuantity, FNVHash);
    fillHashTable(ht, &text);
    fillHashData(ht, "hashres.txt", "FNV hash");
    DestroyHashTable(ht);

    DestroyText(&text);

    return OK;
}





