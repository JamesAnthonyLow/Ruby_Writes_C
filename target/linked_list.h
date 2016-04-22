#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "node.h"

typedef struct LinkedList {
  Node * head;
  void (*free)(struct LinkedList*);
  void (*print)(struct LinkedList*);
  void (*add)(struct LinkedList*, Node*);
} LinkedList;

extern LinkedList * new_linked_list(void);
void free_linked_list(LinkedList * _linked_list);
void print_linked_list(LinkedList * self);
void add_linked_list(LinkedList * self, Node * add);

#endif

