/* External storage class:-

	extern <global_variable_name>;

		Its used only to tell compiler variable is define elsewhere in program, we are only using that variable

		compiler will not allocate any memory to varible which is declared as extern

		vls:	scope: global, life:- until program terminate
		memory: data segment

	points to remember:
		1. Before declaring variable as extern, it should be previously declared global variable only
		2. compiler not allocate mem to extern variable, only for referance
		3. we cant initialize value to extern variable at time of declaration
		4. we can change value of extern variable throught program (global variable)

*/



#include<stdio.h>


/* // error: extern.c:(.text+0x7): undefined reference to `a'
int main()
{
	extern short a;
	printf("%d\n",a);
}
*/



/*

short a;
int main()
{

	//extern.c:16:15: error: ‘a’ has both ‘extern’ and initializer

	extern short a = 2;
	printf("%d\n",a);
}
*/


/*	//we can assign value  to extern variable after extern declaration

short a;
int main()
{

	extern short a;
	a = 5;
	printf("%d\n",a);
}

*/


// We can initialize global varibale before its extern declaration
short a= 30;

int show()
{
	//extern int b;
	printf("show fun, a:%d\n",a);

	printf("show , b:%d\n",b);
}
int main()
{

	//int b = 22;

	printf("before extern, a:%d\n",a);
	extern short a;


	a = 10;
	printf("after extern, a:%d\n",a);

	//printf("after extern, b:%d\n",b);

	show();
}

