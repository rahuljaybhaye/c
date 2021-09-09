/********** Access stucture by using pointer(structure <struct_name> type)
 Once we applied arrow operator to address then we can access(read & write) entire memory at that address


*/

#include<stdio.h>	//printf()
#include<string.h>	//strcpy()
struct laptop
{

	char name[8];
	char cpu[12];
	int ram;
};

int main()
{
	struct laptop l1;
	struct laptop *ptr;

	ptr = &l1;

	// storing value to stucture variable using applying arrow operator to pointer

	ptr->ram = 4;


	//error: assignment to expression with array type
	//ptr->name= "Lenovo";

	strcpy(ptr->name,"HP");
	strcpy(ptr->cpu,"CortexM8");

	printf("name:%s\t, cpu:%s\t,ram:%d\n",ptr->name,ptr->cpu,ptr->ram);


}

