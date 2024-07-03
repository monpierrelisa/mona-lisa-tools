/*
** Mona Lisa Tools
** Author : Lisa Monpierre
** File : push_back.c
*/

#include <stdlib.h>

#include "list.h"

t_mlt_list_node * mlt_list_push_back(t_mlt_list *   list, 
                                    void *          data)
{
    t_mlt_list_node * new_node = malloc(sizeof(*new_node));

    if (new_node == NULL)
        return NULL;
    new_node->data = data;
    new_node->prev = list->end;
    new_node->next = NULL;
    if (list->size == 0)
        list->begin = new_node;
    else
        list->end->next = new_node;
    list->end = new_node;
    list->size++;
    return new_node;
}