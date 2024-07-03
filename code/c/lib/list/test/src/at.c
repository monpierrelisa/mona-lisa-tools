/*
** Mona Lisa Tools
** Author : Lisa Monpierre
** File : at.c
*/

#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>

#include "list.h"
#include "test_list.h"

void test_mlt_list_at()
{
    setup();

    int data[3] = {0, 1, 2};
    size_t i = 0;

    {
        CU_ASSERT_PTR_NULL(g_test_list.begin);
        CU_ASSERT_PTR_NULL(g_test_list.end);
        CU_ASSERT_EQUAL(g_test_list.size, 0);
    }

    t_mlt_list_node * node0 = mlt_list_push_back(&g_test_list, &(data[i++]));
    t_mlt_list_node * node1 = mlt_list_push_back(&g_test_list, &(data[i++]));
    t_mlt_list_node * node2 = mlt_list_push_back(&g_test_list, &(data[i]));
    
    CU_ASSERT_EQUAL(g_test_list.size, 3);
    CU_ASSERT_EQUAL(mlt_list_at(&g_test_list, 0), node0);
    CU_ASSERT_EQUAL(mlt_list_at(&g_test_list, 1), node1);
    CU_ASSERT_EQUAL(mlt_list_at(&g_test_list, 2), node2);

    tear_down();
}
