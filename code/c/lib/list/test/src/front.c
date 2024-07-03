/*
** Mona Lisa Tools
** Author : Lisa Monpierre
** File : front.c
*/

#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>

#include "list.h"
#include "test_list.h"

void test_mlt_list_front()
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
    
    void * data_front = mlt_list_front(&g_test_list);
    CU_ASSERT_EQUAL(g_test_list.size, 3);
    CU_ASSERT_EQUAL(data_front, &(data[0]));

    tear_down();
}