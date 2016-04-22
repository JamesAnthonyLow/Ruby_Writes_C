#include "node.h"
#include "linked_list.h"

int main()
{
  LinkedList * list;
  Node * a, * b, * c;

  list = new_linked_list();

  a = new_node(1, NULL);
  b = new_node(2, NULL);
  c = new_node(3, NULL);

  list->add(list, a);
  list->add(list, b);
  list->add(list, c);

  list->print(list);
  list->free(list);
}
