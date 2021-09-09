/*			union
	*** union same like sturcture except following

		1. union  max memory size - element which occupying max size amoung all elements
			// save memory

		2. If we modify one member then other member also affected
*/
#include<stdio.h>

struct student
{
	char c;
	int id;
	int rank;
}s1;

union employee
{
	char c;
	int id;
	int rank;
};

int main()
{

	union employee e1 = {'A',76,8};

	printf("union, employee data: c:%d, id:%d, rank:%d\n",e1.c,e1.id,e1.rank);

	// structure allocated mem. size - *apporx sum of all element size
	// memory wastage
	printf("strct size: %ld\n",sizeof(s1));

	// union  max memory size - element which occupying max size amoung all elements
	// save memory
	printf("union size: %ld\n",sizeof(e1));

	//struct member address - all different
	printf("struct elements addresses: %x, %x, %x\n",&s1.c,&s1.id,&s1.rank);

	//union member address - all same
	printf("union elements addresses: %x, %x, %x\n",&e1.c,&e1.id,&e1.rank);

	// modifying union member:- If we modify one member then other member also affected
	e1.c = 'a';
	e1.id = 11;
	e1.rank = 2;

	printf("union, employee data: c:%d, id:%d, rank:%d\n",e1.c,e1.id,e1.rank);
}
