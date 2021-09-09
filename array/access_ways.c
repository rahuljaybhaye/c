#include<stdio.h>	//printf()

int main()
{
	int i;
	int *ptr;              /*integer pointer to stored integer variable address (Address memory of all datatype same, but variable memory different
 					-> If compiler see int type pointer then at time of dereferencing search variable of 4 byte memory)*/
	int arr[5]={10,20,30,40};
	ptr = arr;		//array name gives array base address

	printf("First way\n");
	for(i=0;i<5;i++)
	{
		printf("arr[%d]:%d\t",i,*ptr);
	//	arr = arr + 1;    -> * Error: assignment to expression with array type
		ptr = ptr + 1;
	}


	printf("\nsecond way\n");
	ptr = arr;
	for(i=0;i<5;i++)
	{
		//printf("arr[%d]:%d\t",i,ptr[i]);	//i = index value/ subscript value

		printf("arr[%d]:%d\t",i,arr[i]);
	}

	printf("\nThird way\n");
	ptr = arr;
	for(i=0;i<5;i++)
	{
	//	printf("arr[%d]:%d\t",i,*(ptr + i));
		printf("arr[%d]:%d\t",i,*(arr + i));

	}


	printf("\nForth way\n");
	ptr = arr;
	for(i=0;i<5;i++)
	{
	//	printf("arr[%d]:%d\t",i,i[ptr]);	//we can applied subcript value to pointer/array
		printf("arr[%d]:%d\t",i,i[arr]);
	}

	printf("\nFifth way\n");
	ptr = arr;
	for(i=0;i<5;i++)
	{
	//	printf("arr[%d]:%d\t",i,*(i + ptr));
		printf("arr[%d]:%d\t",i,*(i + arr));

	}





}
