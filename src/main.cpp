#include "linkedlist.h"
#include "listdump.h"

int main(void)
{
    List list = {};
    
    CreateList(&list);
    
    PushBack(&list, 30);
    DumpListGraph(&list);
    PushBack(&list, 20);
    DumpListGraph(&list);
    PushBack(&list, 15);
    DumpListGraph(&list);
    PushBack(&list, 12);
    DumpListGraph(&list);
    PrintList(&list);
    DumpListGraph(&list);
    
    DestroyList(&list);

}