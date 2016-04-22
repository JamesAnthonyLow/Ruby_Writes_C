#nt_search Makefile
LINKED_LIST_OBJ = linked_list.o node.o main.o
CFLAGS = -g -std=c99 

LINKED_LIST_PROGRAM = linked_list
PHONY = clean

CC := gcc 

$(LINKED_LIST_PROGRAM): $(LINKED_LIST_OBJ)
	$(CC) -o $(LINKED_LIST_PROGRAM) $(LINKED_LIST_OBJ) $(CFLAGS)

.PHONY : $(PHONY)
clean:
		rm $(PROGRAM) $(LINKED_LIST_OBJ) $(LINKED_LIST_PROGRAM) 
