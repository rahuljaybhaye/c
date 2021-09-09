#include<stdio.h>	//printf()
#include<string.h>

int main()
{
	char arr[] = "Python";		//array length calculate base on array initialize(No of elements contained in array)
	char str[10];		//strored in stack frame of main()-> read, write
//	str = "rahul";	//->  * Error: assignment to expression with array type
	/* strcpy(dst_addr,src_addr) , lib function copy string from source address to destination address*/

	strcpy(str,"rahul");		//Here "rahul" stored in ro data segment,we can't directly change from outside but after copying we can change

	str[0] = 's';
	printf("%s\n",str);
	strcpy(str,arr);		//Here both array stored at stack frame of main(), Thus we can changed string from outside
	printf("%s\n",arr);

	printf("%c",arr[0]);		//individual element print

	//scanf()
	printf("type any char\n");
	scanf("%c",&arr[0]);			//& required before arr[i]
	printf("your char is: %c\n",arr[0]);

	arr[1] = 'k';			// individual element assingment
	printf("%s\n",arr);

	//To take string input from shell
	printf("write your name\n");
	scanf("%s",str);
	printf("check your name: %s\n",str);

	// string lenght: excluding null char.
	printf("string length: %d\n",strlen(str));


	// string size:  (size of arry) size of whole string including null char
	printf("string(array) size: %d",sizeof(str));
}
