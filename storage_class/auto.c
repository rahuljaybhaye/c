/* Automatic i.e. auto :- local variable (No need to define as auto)
		initial value: garbage
		scope :- till end of block/function
		mem: stack (RAM)
*/

#include<stdio.h>

int main()
{
	int a; //auto
	char c;

	printf("%d\t %c\n",a,c);
}
