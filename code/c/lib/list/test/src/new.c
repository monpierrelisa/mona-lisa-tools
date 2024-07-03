/*
** Mona Lisa Tools
** Author : Lisa Monpierre
** File : new.c
*/

#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>

#include "list.h"

void test_mlt_list_new()
{
    t_mlt_list * list = mlt_list_new();

    CU_ASSERT_PTR_NOT_NULL(list);
    CU_ASSERT_PTR_NULL(list->begin);
    CU_ASSERT_PTR_NULL(list->end);
    CU_ASSERT_EQUAL(list->size, 0);
}
