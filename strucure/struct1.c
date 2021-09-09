#include<stdio.h>


/* structure defination:
 syntax 1: firstly  creat structure then create its variable
	Memory in RAM not allocated to structure until we create structure variable

	memory(RAM) location for structure:
			A. Globally variable creation :
				 1. Only create structure variable -> BSS segment
				2. Create struture variable and pass members value simultaneously -> Data segment

			B. Locally structure variable creation:
					1. create variable			- stack segment
					2. create and pass value to member - stack segment
*/
struct student
{
	char name[10];
	char class_name;
	int rollno;
};

// syntax 2nd: creat structure and its variable at same time

struct employee
{
	char name[10];
	int sallary;
	int id;
}e1;

int main()
{
	// method 1: Passed argument to structure according to sequence of structure member
	struct student s1= {"Ram",'a',22};

	// method 2: Passed argument to structure with any sequence
	struct student s2= {.rollno = 100,
						.name = "Shambhu",
						.class_name = 'b'};

	printf("name: %s, rollno: %d, class:%c\n",s1.name,s1.rollno,s1.class_name);

	printf("name: %s, rollno: %d, class:%c\n",s2.name,s2.rollno,s2.class_name);


	printf("size: %d bytes\n",sizeof(s1));

	// access and modify structure member using dot operator (on structure variable )
	e1.id= 11;

	printf("employee id: %d\n",e1.id);

}
