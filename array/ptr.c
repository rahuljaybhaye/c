#include<stdio.h>
char *sptr = "embedded";	//global -> ro data section
int main()
{
	char str[10] = "system";
	char *ptr = "Programming";	//local  -> ro data section
	printf("%s\n",str);
	printf("%s\n",ptr);

	printf("%c\n",str[1]);
	printf("%c\n",ptr[1]);

	str[1]='a';
//	ptr[1]='b';  // writing to ro data -> permission denied-> segmentation fault

//	sptr[0] = 'n';	//ro data -> segmentation fault

}
