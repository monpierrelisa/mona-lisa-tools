/*
** Mona Lisa Tools
** Author : Lisa Monpierre
** File : remove.c
*/

#include <stdlib.h>
#include <stdio.h>

#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>

#include "test_list.h"

int main()
{
    if (CUE_SUCCESS != CU_initialize_registry())
        return CU_get_error();

    CU_pSuite suite = CU_add_suite("mlt_list_Test_Suite", 0, 0);

    if (NULL == suite) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    CU_add_test(suite, "test_mlt_list_new", test_mlt_list_new);
    CU_add_test(suite, "test_mlt_list_delete", test_mlt_list_delete);
    
    CU_add_test(suite, "test_mlt_list_insert", test_mlt_list_insert);
    CU_add_test(suite, "test_mlt_list_push_front", test_mlt_list_push_front);
    CU_add_test(suite, "test_mlt_list_push_back", test_mlt_list_push_back);

    CU_add_test(suite, "test_mlt_list_remove", test_mlt_list_remove);
    CU_add_test(suite, "test_mlt_list_pop_front", test_mlt_list_pop_front);
    CU_add_test(suite, "test_mlt_list_pop_back", test_mlt_list_pop_back);
    CU_add_test(suite, "test_mlt_list_clear", test_mlt_list_clear);

    CU_add_test(suite, "test_mlt_list_front", test_mlt_list_front);
    CU_add_test(suite, "test_mlt_list_back", test_mlt_list_back);
    CU_add_test(suite, "test_mlt_list_find_node", test_mlt_list_find_node);
    
    CU_add_test(suite, "test_mlt_list_size", test_mlt_list_size);
    CU_add_test(suite, "test_mlt_list_is_empty", test_mlt_list_is_empty);
    CU_add_test(suite, "test_mlt_list_apply_callback", test_mlt_list_apply_callback);
    
    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();

  return CU_get_error();
}
