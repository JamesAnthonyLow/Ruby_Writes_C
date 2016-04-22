#ifndef NODE_H
#define NODE_H

#include <stdlib.h>
#include <stdio.h>

typedef struct Node {
  int data;
  struct Node * next;
  void (*free)(struct Node *);
  void (*print)(struct Node *);
} Node;

extern Node * new_node(int data, Node * next);
void free_node(Node * self);
void print_node(Node * self);

#endif
