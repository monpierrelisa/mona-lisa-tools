/*
** Mona Lisa Tools
** Author : Lisa Monpierre
** File : clear.c
*/

#include <stdlib.h>

#include "list.h"

void mlt_list_clear(t_mlt_list * list)
{
  t_mlt_list_node * node = list->begin;
    
  while (node != NULL && node != list->end)
    {
      t_mlt_list_node * node_to_delete = node;

      node = node->next;
      free(node_to_delete);
    }
  list->begin = NULL;
  list->end = NULL;
  list->size = 0;
}
