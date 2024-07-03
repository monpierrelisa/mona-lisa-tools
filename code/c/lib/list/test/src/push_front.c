/*
** Mona Lisa Tools
** Author : Lisa Monpierre
** File : push_front.c
*/

#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>

#include "list.h"
#include "test_list.h"

void test_mlt_list_push_front()
{
    setup();

    int data[3] = {0, 1, 2};
    size_t i = 0;

    // begin > NULL < end
    {
        CU_ASSERT_PTR_NULL(g_test_list.begin);
        CU_ASSERT_PTR_NULL(g_test_list.end);
        CU_ASSERT_EQUAL(g_test_list.size, 0);
    }

    // begin > node0 < end
    t_mlt_list_node * node0 = mlt_list_push_front(&g_test_list, &(data[i]));
    {
        CU_ASSERT_PTR_NOT_NULL(node0);
        CU_ASSERT_PTR_NULL(node0->prev);
        CU_ASSERT_PTR_NULL(node0->next);
        CU_ASSERT_EQUAL(*(int *)(node0->data), data[i]);

        CU_ASSERT_EQUAL(g_test_list.begin, node0);
        CU_ASSERT_EQUAL(g_test_list.end, node0);
        CU_ASSERT_EQUAL(g_test_list.size, 1);
        i++;
    }

    // begin > node1 <> node0 < end
    t_mlt_list_node * node1 = mlt_list_push_front(&g_test_list, &(data[i]));
    {
        CU_ASSERT_PTR_NOT_NULL(node1);
        CU_ASSERT_PTR_NULL(node1->prev);
        CU_ASSERT_EQUAL(node1->next, node0);
        CU_ASSERT_EQUAL(*(int *)(node1->data), data[i]);

        CU_ASSERT_EQUAL(g_test_list.begin, node1);
        CU_ASSERT_EQUAL(g_test_list.end, node0);
        CU_ASSERT_EQUAL(g_test_list.size, 2);
        i++;
    }

    // begin > node2 <> node1 <> node0 < end
    t_mlt_list_node * node2 = mlt_list_push_front(&g_test_list, &(data[i]));
    {
        CU_ASSERT_PTR_NOT_NULL(node2);
        CU_ASSERT_PTR_NULL(node2->prev);
        CU_ASSERT_EQUAL(node2->next, node1);
        CU_ASSERT_EQUAL(*(int *)(node2->data), data[i]);

        CU_ASSERT_EQUAL(g_test_list.begin, node2);
        CU_ASSERT_EQUAL(g_test_list.end, node0);
        CU_ASSERT_EQUAL(g_test_list.size, 3);
    }

    tear_down();
}
