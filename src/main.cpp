#include "linkedlist.h"
#include "listdump.h"

int main(void)
{
    List list = {};
    
    CreateList(&list);

    char* str1 = "hello";
    char* str2 = "world";
    char* str3 = "great";
    char* str4 = "place";
    
    PushBack(&list, str1);
    DumpListGraph(&list);
    PushBack(&list, str2);
    DumpListGraph(&list);
    PushBack(&list, str3);
    DumpListGraph(&list);
    PushBack(&list, str4);
    DumpListGraph(&list);
    PrintList(&list);
    DumpListGraph(&list);
    
    DestroyList(&list);

}