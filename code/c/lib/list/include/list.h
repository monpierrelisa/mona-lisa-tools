/*
** Mona Lisa Tools
** Author : Lisa Monpierre
** File : list.h
*/

#ifndef __MLT_LIST__
#define __MLT_LIST__

#include <stddef.h>

// Structure of list node
typedef struct s_mlt_list_node
{
  void *                    data;
  struct s_mlt_list_node *  next;
  struct s_mlt_list_node *  prev;
} t_mlt_list_node;

// structure of the doubly linked list
typedef struct s_mlt_list
{
  t_mlt_list_node * begin;
  t_mlt_list_node * end;
  size_t            size;
} t_mlt_list;

// Callback function type to apply to the node provided by parameter
typedef void (*t_mlt_list_callback)(t_mlt_list_node * node);

// -- List Operations --

// Instantiate a new empty list and return a pointer to it
t_mlt_list * mlt_list_new();

// Delete all nodes and the 'list' itself
void mlt_list_delete(t_mlt_list ** list);

// -- Insertion operations --

// Instantiate and insert a new node with 'data' into the list before 
// the node place in the list
// If 'node' is equals to NULL the new node will be inserted at the end 
// of 'list'
t_mlt_list_node * mlt_list_insert(t_mlt_list *      list, 
                                  t_mlt_list_node * node, 
                                  void *            data);

// Instantiate and insert a new node with 'data' at the end of 'list' 
t_mlt_list_node * mlt_list_push_back(t_mlt_list * list, 
                                     void *       data);

// Instantiate and insert a new node with 'data' at the begining of 'list'                                  
t_mlt_list_node * mlt_list_push_front(t_mlt_list * list, 
                                      void *       data);

// -- Deletion operations --

// Remove 'node_to_remove' of 'list' and liberate it then return 
// 'node_to_remove' data
void * mlt_list_remove(t_mlt_list *       list, 
                       t_mlt_list_node *  node_to_remove);

// Remove and liberate the node at the end of 'list' and  return
// its data
void * mlt_list_pop_back(t_mlt_list * list);

// Remove and liberate the node at the begning of 'list' and return 
// its data
void * mlt_list_pop_front(t_mlt_list * list);

// Remove and liberate all nodes contained into 'list'
void mlt_list_clear(t_mlt_list * list);

// -- Accessing operations --

// Provide the data of the node at the begining of 'list'
#define mlt_list_front(list) ((list)->begin->data)

// Provide the data of the node at the ending of 'list'
#define mlt_list_back(list) ((list)->end->data)

// Return the node at the 'index' position of 'list'
t_mlt_list_node * mlt_list_at(t_mlt_list *  list, 
                              int const     index);

// Return the node which correponding to 'data' into 'list'
t_mlt_list_node * mlt_list_find_node(t_mlt_list * list, 
                                     void *       data);

// -- Other operations --

// Provide the size of 'list'
#define mlt_list_size(list) ((list)->size)

// Indicate if 'list' is empty
#define  mlt_list_is_empty(list) ((list)->size == 0)

// Call for each node in 'list' the 'mlt_list_callback' function
void mlt_list_apply_callback(t_mlt_list *         list, 
                             t_mlt_list_callback  mlt_list_callback);

#endif // !__MLT_LIST__