#Ruby_Writes_C

The purpose of this project is to experiment with using Ruby code to automate the process of writing C code.

For example the following code in ruby:

```ruby
##node.rb
class Node < C
  typedef(:data => {:type => :int}, 
          :next_node => {:type => :Node, :p => true})
  constructor(:data => {:set => true},
              :next_node => {:set => false})
end
```
Would be enough information to automatically generate the following two files in C:

```c
/**node.h**/
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

/**node.c**/
#include "node.h"

Node * new_node(int data, Node * next)
{
  Node * new = malloc(sizeof(Node));
  if(!new)
    fprintf(stderr, "Failed to allocate memory for %s\n", "Node");

  new->data = data;
  new->next = next;
  new->free = free_node;
  new->print = print_node;

  return new;
}

void free_node(Node * self)
{
  if(self->next)
    self->next->free(self->next);
  if(self)
    free(self);
}

void print_node(Node * self)
{
  printf("node: %x\n", (unsigned int)self);
  printf("data: %d\n\n", self->data);
  if(self->next)
    self->next->print(self->next);
}
```
