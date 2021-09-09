#include<stdio.h>

int main()
{
	//structure defination
	struct company
	{
		char name[10];
		int turnover;
	};

	// structure variable locally created-> mem : will create in stack segmemt
	struct company c1;

	// string cant assign to char array address directly, but indiviual char can pass to char array element
	//c1.name[0] = 's';
	//printf("name:%c\n",c1.name[0]);

	// to copy whole string into structure member
	strcpy(c1.name,"IOTronix");

	c1.turnover = 10;

	printf("name:%s, turnover:%d\n",c1.name,c1.turnover);
}
