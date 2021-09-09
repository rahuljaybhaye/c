/*
	stored info in register of cpu
	we cant access address of register variable

	vls:
		scope: local (only within function where difine)

		life:- till end of function
*/

#include<stdio.h>

int show()
{
	register char c = 'R';
	printf("%d",a);

}

int main()
{
	register int a = 5;		// register variable
	int b= 2;				//local or auto variable

	printf("%d\n",a);

	printf("%p",&b);

	// We can't access the address of register variable
	//printf("%p",&a);
	show();

}
