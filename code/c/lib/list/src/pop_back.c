/*
** Mona Lisa Tools
** Author : Lisa Monpierre
** File : pop_back.c
*/

#include <stdlib.h>

#include "list.h"

void * mlt_list_pop_back(t_mlt_list * list)
{
    t_mlt_list_node * new_back_node = list->end->prev;
    void * data_popped = list->end->data;

    free(list->end);
    list->end = new_back_node;
    new_back_node->next = NULL;
    --(list->size);
    return data_popped;
}