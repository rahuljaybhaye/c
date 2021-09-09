/*
static <global_variable>  :- No affect

static <local_variable>  :- scope of variable even when fun terminate,
							but only access in that fun only where its declare

							thus, we can access previous value of varible memory which is part of function

							Not access to other part of program (other than function)

(vls)  scope:- local, visibility , life:- till end of program
*/


#include<stdio.h>

int sum()
{
	static int a = 10;
	int b = 22;
	printf("A:%d\t B:%d\n",a,b);

	a++;
	b++;
}

int main()
{
	int i;


	for(i=0;i<3;i++)
	{
		sum();
	}
	//printf("main fun, a:%d",a);
}
