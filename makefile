p16 : p16.c
	cc p16.c -o p16

p15-2 : p15-2.c
	cc p15-2.c -o p15-2

p15 : ds p15.h p15.c
	cc pe_linked_list.o pe_stack.o p15.c -o p15

ds : pe_linked_list pe_stack 

pe_linked_list : pe_linked_list.h pe_linked_list.c
	cc -c pe_linked_list.c

pe_stack : pe_linked_list pe_stack.h pe_stack.c
	cc -c pe_stack.c

