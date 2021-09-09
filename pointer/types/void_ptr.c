#include<stdio.h>

main()
{
	void *ptr;
	char *chr;
	short *shr;
	printf("ptr: %d\t,chr: %d\t, shr: %d\t",sizeof(ptr),sizeof(chr),sizeof(shr));
	char a = 'a';
	ptr = &a;
	printf("%p\n %ld",ptr,sizeof(ptr));

}
