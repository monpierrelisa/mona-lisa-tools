/*
** Mona Lisa Tools
** Author : Lisa Monpierre
** File : push_front.c
*/

#include <stdlib.h>

#include "list.h"

t_mlt_list_node * mlt_list_push_front(t_mlt_list *  list, 
                                      void *        data)
{
    t_mlt_list_node * new_node = malloc(sizeof(*new_node));

    if (new_node == NULL)
        return NULL;
    new_node->data = data;
    new_node->prev = NULL;
    new_node->next = list->begin;
    if (list->size == 0)
        list->end = new_node;
    else
        list->begin->next = new_node;
    list->begin = new_node;
    list->size++;
    return new_node;
}