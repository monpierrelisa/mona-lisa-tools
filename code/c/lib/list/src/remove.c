/*
** Mona Lisa Tools
** Author : Lisa Monpierre
** File : remove.c
*/

#include <stdlib.h>

#include "list.h"

void * mlt_list_remove(t_mlt_list *      list, 
                       t_mlt_list_node * node_to_remove)
{
    void * data_popped = node_to_remove->data;

    node_to_remove->prev = node_to_remove->next;
    free(node_to_remove);
    --(list->size);
    return data_popped;
}