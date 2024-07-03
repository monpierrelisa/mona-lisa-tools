/*
** Mona Lisa Tools
** Author : Lisa Monpierre
** File : find_node.c
*/

#include "list.h"

t_mlt_list_node * mlt_list_find_node(t_mlt_list *   list, 
                                     void *         data)
{
    for (t_mlt_list_node * node = list->begin;
        node != NULL && node != list->end;
        node = node->next)
        if (data == node->data)
            return node;
    return NULL;
}