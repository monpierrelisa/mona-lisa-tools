/*
** Mona Lisa Tools
** Author : Lisa Monpierre
** File : is_empty.c
*/

#include <stdlib.h>

#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>

#include "list.h"

void test_mlt_list_is_empty()
{
  // list empty
  {
    t_mlt_list list;

    list.size = 0;
    CU_ASSERT_TRUE(mlt_list_is_empty(&list));
  }

  // list not empty
  {
    t_mlt_list list;

    list.size = 1;
    CU_ASSERT_FALSE(mlt_list_is_empty(&list));
  }
}
