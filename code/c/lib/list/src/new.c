/*
** Mona Lisa Tools
** Author : Lisa Monpierre
** File : new.c
*/

#include <stdlib.h>

#include "list.h"

t_mlt_list * mlt_list_new()
{
  t_mlt_list * list;

  if ((list = malloc(sizeof(*list))) == NULL)
    return NULL;

  list->begin = NULL;
  list->end = NULL;
  list->size = 0;
  return list;
}
