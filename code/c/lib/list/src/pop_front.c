/*
** Mona Lisa Tools
** Author : Lisa Monpierre
** File : pop_front.c
*/

#include <stdlib.h>

#include "list.h"

void * mlt_list_pop_front(t_mlt_list * list)
{
    t_mlt_list_node * new_front_node = list->begin->next;
    void * data_popped = list->begin->data;

    free(list->begin);
    list->begin = new_front_node;
    new_front_node->prev = NULL;
    list->size--;
    return data_popped;
}