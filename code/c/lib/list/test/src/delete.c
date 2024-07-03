/*
** Mona Lisa Tools
** Author : Lisa Monpierre
** File : delete.c
*/

#include <stdlib.h>

#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>

#include "list.h"

void test_mlt_list_delete()
{
  t_mlt_list * list = malloc(sizeof(*list));

  CU_ASSERT_PTR_NOT_NULL(list);
  mlt_list_delete(&list);
  CU_ASSERT_PTR_NULL(list);
}
