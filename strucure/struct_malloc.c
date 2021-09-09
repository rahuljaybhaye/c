/* Dynamic memory allocation for structure by using malloc()

*/

#include<stdio.h> 		//printf()
#include<string.h>		//strcpy()
#include<stdlib.h>		//malloc()

struct teacher
{
	char name[20];
	int id;
};
int main()
{
	struct teacher *ptr;

	printf("struct size:%ld\n",sizeof(struct teacher));

	// structure memory will create in heap segment(dynamic mem. creation)
	ptr = malloc(sizeof(struct teacher));

	// update  structure member
	strcpy(ptr->name,"Gawande sir");
	ptr->id = 01;

	//Reading structure member
	printf("name:%s\t, id:%d\n",ptr->name,ptr->id);


}
