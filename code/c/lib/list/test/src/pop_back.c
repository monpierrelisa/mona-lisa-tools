/*
** Mona Lisa Tools
** Author : Lisa Monpierre
** File : pop_back.c
*/

#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>

#include "list.h"
#include "test_list.h"

void test_mlt_list_pop_back()
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
    mlt_list_push_back(&g_test_list, &(data[i]));
    
    CU_ASSERT_EQUAL(g_test_list.size, 3);
    void * data_popped = mlt_list_pop_back(&g_test_list);
    CU_ASSERT_EQUAL(g_test_list.size, 2);
    CU_ASSERT_EQUAL(g_test_list.begin, node0);
    CU_ASSERT_EQUAL(g_test_list.end, node1);
    CU_ASSERT_EQUAL(data_popped, &(data[2]));

    tear_down();
}
