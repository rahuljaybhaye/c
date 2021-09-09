#include<stdio.h>

main()
{
/*
	int a = 0;
	unsigned char b= 0;
	char ch = 'A';
	int no= 49;

	printf("ch: %c,%d",ch,ch);
	printf("no: %c,%d",no,no);

	//Ascii values
	for(a= 0;a<=256;a++)
	{
		printf("%d: %c\t",a,a);

	}
*/
	//checking boundary condition

	//1. signed char(by default) (range : -128 to 0 to 255)
	char ch =127;
	ch = ch + 1;
	printf("first ch: %d\n",ch);

	ch = 127;
	ch = ch + 2;
	printf("second ch: %d\n",ch);

	signed char p =0;
	p = p - 1;
	printf("p: %d\n",p);

	signed char q = -128;
	q = q - 1;
	printf("q: %d\n",q);

	// unsigned char(range : 0 to 255)

	unsigned char m;
	m = 127;
	m = m + 1;
	printf("first m: %d\n",m);

	m = 255;
	m = m + 1;
	printf("second m: %d\n",m);

	m = 0;
	m = m - 4;
	printf("third m: %d\n",m);



/*	// intger value results for char

	char x =0;
	printf("%c\t %d\n",x,x);

	char y ='0';
	printf("%c\t %d\n",y,y);

*/
}
