/*
** Mona Lisa Tools
** Author : Lisa Monpierre
** File : delete.c
*/

#include <stdlib.h>

#include "list.h"

void mlt_list_delete(t_mlt_list ** list)
{
  mlt_list_clear(*list);
  free(*list);
  *list = NULL;
}
