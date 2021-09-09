/********************** Access structure from function *******************
	type1 : Passing individual element to funtion
	type2 : Passing entire structure to function
	type3 : Passing structure address

*/

#include<stdio.h>		//printf()
#include<string.h>		// strcpy()

// function declaration
int display(char *,int);		// get individual element
struct smps show(struct smps);	// get entire structure
int show_ptr(struct smps *);		// get  structure address

struct smps
{
	char name[8];
	int price;
};

//1. function defination:- fun to pass individual element of structure
int display(char *ptr, int cost)
{
	printf("Display, smps name: %s, price: %d\n",ptr,cost);

	printf("modifying name\n");
	// modifying structure element (due to address)
	strcpy(ptr,"10v,12A");
}

//2. function defination:- fun to pass entire structure
struct smps show(struct smps p2)
{
	printf("Show, smps name: %s, price: %d\n",p2.name,p2.price);

	printf("modifying price\n");
	p2.price = 1000;
	return p2;
}



//3. function defination:- fun to pass structure address
int show_ptr(struct smps *ptr)
{
	printf("Show_ptr, smps name: %s, price: %d\n",ptr->name,ptr->price);

	printf("modifying price\n");
	ptr->price = 1200;
}

int main()
{
	// create  structure variable and assigning value to its member
	struct smps p1= {.price= 500,.name="5V,5A"};

	//1. function invocation  - passing individual element of structure
	display(p1.name,p1.price);

	//2. function invocation  - passing entire structure
	p1 = show(p1);

	printf("After show fun, smps name: %s, price: %d\n",p1.name,p1.price);

	//3. function invocation  - passing structure address
	show_ptr(&p1);

	printf("After show_ptr fun, smps name: %s, price: %d\n",p1.name,p1.price);
}
