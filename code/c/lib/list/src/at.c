/*
** Mona Lisa Tools
** Author : Lisa Monpierre
** File : at.c
*/

#include "list.h"

t_mlt_list_node * mlt_list_at(t_mlt_list * list, int const index)
{
    t_mlt_list_node * node = list->begin;

    for (int i = 0; 
        i < index && node != NULL && node != list->end; 
        ++i)
        node = node->next;
    return node;
}