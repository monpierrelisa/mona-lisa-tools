/*
** Mona Lisa Tools
** Author : Lisa Monpierre
** File : test_list.h
*/

#ifndef __MLT_TEST_LIST__
#define __MLT_TEST_LIST__

#define init()      g_test_list.size = 0; \
                    g_test_list.begin = NULL; \
                    g_test_list.end = NULL
#define setup()     t_mlt_list g_test_list; \
                    init()
#define tear_down() init()

void test_mlt_list_new();
void test_mlt_list_delete();

void test_mlt_list_insert();
void test_mlt_list_push_front();
void test_mlt_list_push_back();

void test_mlt_list_remove();
void test_mlt_list_pop_front();
void test_mlt_list_pop_back();
void test_mlt_list_clear();

void test_mlt_list_at();
void test_mlt_list_front();
void test_mlt_list_back();
void test_mlt_list_find_node();

void test_mlt_list_size();
void test_mlt_list_is_empty();
void test_mlt_list_apply_callback();

#endif // !__MLT_TEST_LIST__
