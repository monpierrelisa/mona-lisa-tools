/*
** Mona Lisa Tools
** Author : Lisa Monpierre
** File : remove.c
*/

#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>

#include "list.h"
#include "test_list.h"

void check_node(t_mlt_list_node * node)
{
    static int i = 0;
 
    CU_ASSERT_EQUAL(*(int*)node->data, i++);
}

void test_mlt_list_apply_callback()
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
    mlt_list_push_back(&g_test_list, &(data[i++]));
    mlt_list_push_back(&g_test_list, &(data[i]));
    
    CU_ASSERT_EQUAL(g_test_list.size, 3);
    mlt_list_apply_callback(&g_test_list, check_node);

    tear_down();
}
