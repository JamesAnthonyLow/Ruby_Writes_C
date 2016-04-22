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
