#include "linkedlist.h"

int main(void)
{
    List list = {};
    
    CreateList(&list);
    
    PushFront(&list, 30);
    DumpListGraph(&list);
    PushFront(&list, 20);
    DumpListGraph(&list);
    PushFront(&list, 15);
    DumpListGraph(&list);
    PushBack(&list, 12);
    DumpListGraph(&list);
    PrintList(&list);
    DumpListGraph(&list);
    
    DestroyList(&list);

}