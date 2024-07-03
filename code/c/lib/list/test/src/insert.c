/*
** Mona Lisa Tools
** Author : Lisa Monpierre
** File : insert.c
*/

#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>

#include "list.h"
#include "test_list.h"

void test_mlt_list_insert()
{
    setup();

    int data[5] = {0, 1, 2, 3, 4};
    size_t i = 0;

    // begin > NULL < end
    {
        CU_ASSERT_PTR_NULL(g_test_list.begin);
        CU_ASSERT_PTR_NULL(g_test_list.end);
        CU_ASSERT_EQUAL(g_test_list.size, 0);
    }

    // begin > node0 < end
    t_mlt_list_node * node0 = mlt_list_insert(&g_test_list, NULL, &(data[i]));
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
    t_mlt_list_node * node1 = mlt_list_insert(&g_test_list, node0, &(data[i]));
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
    t_mlt_list_node * node2 = mlt_list_insert(&g_test_list, node1, &(data[i]));
    {
        CU_ASSERT_PTR_NOT_NULL(node2);
        CU_ASSERT_PTR_NULL(node2->prev);
        CU_ASSERT_EQUAL(node2->next, node1);
        CU_ASSERT_EQUAL(*(int *)(node2->data), data[i]);

        CU_ASSERT_EQUAL(g_test_list.begin, node2);
        CU_ASSERT_EQUAL(g_test_list.end, node0);
        CU_ASSERT_EQUAL(g_test_list.size, 3);
        i++;
    }

    // begin > node2 <> node1 <> node3 <> node0 < end
    t_mlt_list_node * node3 = mlt_list_insert(&g_test_list, node0, &(data[i]));
    {
        CU_ASSERT_PTR_NOT_NULL(node3);
        CU_ASSERT_EQUAL(node3->prev, node1);
        CU_ASSERT_EQUAL(node3->next, node0);
        CU_ASSERT_EQUAL(*(int *)(node3->data), data[i]);

        CU_ASSERT_EQUAL(g_test_list.begin, node2);
        CU_ASSERT_EQUAL(g_test_list.end, node0);
        CU_ASSERT_EQUAL(g_test_list.size, 4);
    }

    // begin > node2 <> node1 <> node3 <> node0 < end
    t_mlt_list_node * node4 = mlt_list_insert(&g_test_list, NULL, &(data[i]));
    {
        CU_ASSERT_PTR_NOT_NULL(node4);
        CU_ASSERT_EQUAL(node4->prev, node0);
        CU_ASSERT_PTR_NULL(node4->next);
        CU_ASSERT_EQUAL(*(int *)(node4->data), data[i]);

        CU_ASSERT_EQUAL(g_test_list.begin, node2);
        CU_ASSERT_EQUAL(g_test_list.end, node4);
        CU_ASSERT_EQUAL(g_test_list.size, 5);
    }

    tear_down();
}
