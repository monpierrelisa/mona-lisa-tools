/*
** Mona Lisa Tools
** Author : Lisa Monpierre
** File : insert.c
*/

#include <stdlib.h>

#include "list.h"

t_mlt_list_node * mlt_list_insert(t_mlt_list *      list, 
                                  t_mlt_list_node * node, 
                                  void *            data)
{
    t_mlt_list_node * new_node = malloc(sizeof(*new_node));

    if (new_node == NULL)
        return NULL;
    new_node->data = data;
    new_node->next = node;
    if (list->size == 0 || list->begin == node)
        list->begin = new_node;
    if (node == NULL)
    {
        new_node->prev = list->end;
        list->end = new_node;
    }
    else
    {
        new_node->prev = node->prev;
        node->prev = new_node;
    }
    ++(list->size);
    return new_node;
}
