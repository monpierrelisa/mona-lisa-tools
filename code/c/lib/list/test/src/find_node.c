/*
** Mona Lisa Tools
** Author : Lisa Monpierre
** File : find_node.c
*/

#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>

#include "list.h"
#include "test_list.h"

void test_mlt_list_find_node()
{
    setup();

    int data[3] = {0, 1, 2};
    size_t i = 0;

    {
        CU_ASSERT_PTR_NULL(g_test_list.begin);
        CU_ASSERT_PTR_NULL(g_test_list.end);
        CU_ASSERT_EQUAL(g_test_list.size, 0);
    }

    mlt_list_push_back(&g_test_list, &(data[i++]));
    t_mlt_list_node * node1 = mlt_list_push_back(&g_test_list, &(data[i++]));
    t_mlt_list_node * node2 = mlt_list_push_back(&g_test_list, &(data[i]));
    
    CU_ASSERT_EQUAL(g_test_list.size, 3);
    t_mlt_list_node * node_found = mlt_list_find_node(&g_test_list, &(data[1]));
    CU_ASSERT_EQUAL(node_found, node1);

    tear_down();
}
