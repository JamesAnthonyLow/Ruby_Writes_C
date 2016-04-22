#include "linked_list.h"

LinkedList * new_linked_list(void)
{
  LinkedList * new = malloc(sizeof(LinkedList));
  if(!new)
    fprintf(stderr, "Failed to allocate memory for %s\n", "LinkedList");

  new->free = free_linked_list;
  new->print = print_linked_list;
  new->add = add_linked_list;
  new->head = NULL;

  return new;
}

void free_linked_list(LinkedList * self)
{
  if(self->head)  
    self->head->free(self->head);
  if(self)
    free(self);
}

void print_linked_list(LinkedList * self)
{
  printf("linked_list: %x\n\n", (unsigned int)self);
  if(self->head)
    self->head->print(self->head);
}

void add_linked_list(LinkedList * self, Node * add)
{
  add->next = self->head;
  self->head = add;
}
