/*
** Mona Lisa Tools
** Author : Lisa Monpierre
** File : apply_callback.c
*/

#include "list.h"

void mlt_list_apply_callback(t_mlt_list * list, t_mlt_list_callback mlt_list_callback)
{
    t_mlt_list_node * node = list->begin;
    
    while (node != NULL && node != list->end)
    {
        mlt_list_callback(node);
        node = node->next;
    }
}