#include "dsl.h"
#include "graphparams.h"
#include "listdump.h"

ErrorCode DumpListHTML(List* list)
{

}

const int MAX_FILENAME_LENGTH = 256;
const int MAX_COMMAND_LENGTH  = 256;

#define dumpGraph(filename, ...) fprintf(filename, __VA_ARGS__)

ErrorCode DumpListGraph(List* list)
{
    static int DOT_DUMP_NUM = 0;

    char filename[MAX_FILENAME_LENGTH] = {};

    sprintf(filename, "log/dot/result_%d.dot", DOT_DUMP_NUM);

    myOpen(filename, "w", graphFile);

    dumpGraph(graphFile, 
                        "  digraph\n"
                        "  {\n"
                        "  rankdir = LR;\n"
                        "  node [shape = record, color = " NODE_FRAME_COLOR ", fontname = " FONT_NAME ", fontsize = " FONT_SIZE "];\n"
                        "  bgcolor = " BACKGROUND_COLOR ";\n"
                        "  ROOT[style = \"filled\", fillcolor = " ROOT_COLOR ", "
                        "  label = \"ROOT|{<head>head = %zu|<tail>tail = %zu}\"];\n"
                        "  FREE_HEAD[style = \"filled\", fillcolor = " FREE_HEAD_COLOR ", "
                        "  label = \"FREE_HEAD|<free>free = %zu\"];\n",
                           NEXT(0), PREV(0), list->freeHead
    );

    for (size_t i = 1; i < list->capacity; i++)
    {
        dumpGraph(graphFile,
                            "  NODE_%zu[style = \"filled\", fillcolor = " NODE_COLOR ", "
                            "  label = \"index = %lu|value\\n%s|{prev = %lu|next = %lu}\"];\n",
                            i, i, VALUE(i), PREV(i), NEXT(i)
        );
    }

    dumpGraph(graphFile, "ROOT"); // TODO: show -1 in png file for better view

    for (size_t i = 1; i < list->capacity; i++)
    {
        dumpGraph(graphFile, "->NODE_%zu", i);
    }

    dumpGraph(graphFile, " [weight = 100000, color = " BACKGROUND_COLOR "];\n");

    dumpGraph(graphFile, "ROOT:head");

    size_t nodePointer = NEXT(0);

    for (size_t i = 1; i < list->size; i++)
    {
        dumpGraph(graphFile, "->NODE_%zu", nodePointer);

        nodePointer = NEXT(nodePointer);
    }

    dumpGraph(graphFile, "->ROOT:tail;\n");

    dumpGraph(graphFile, "FREE_HEAD:free->NODE_%zu;\n", 
                            list->freeHead
    );
    
    dumpGraph(graphFile, "  }\n");

    myClose(graphFile);

    char command[MAX_COMMAND_LENGTH] = {};

    sprintf(command, "dot -Tpng log/dot/result_%d.dot -o log/img/result_%d.png", DOT_DUMP_NUM, DOT_DUMP_NUM);

    system(command);

    DOT_DUMP_NUM++;

    return OK;
}

#undef dumpGraph

ErrorCode PrintList(List* list)
{
    printf("physical address: \n");

    for (size_t i = 0; i < list->capacity; i++)
    {
        printf("[%lu] -> value: %d, next: %lu, prev %lu\n", i, VALUE(i), NEXT(i), PREV(i));
    }

    printf("\nin order:\n");

    size_t curIndex = list->head;

    for (size_t i = 0; i < list->size; i++)
    {
        printf("[%lu] -> value: %d, next: %lu, prev %lu\n", curIndex, VALUE(curIndex), NEXT(curIndex), PREV(curIndex));

        curIndex = NEXT(curIndex);
    }

    return OK;
}