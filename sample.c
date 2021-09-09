#include<stdio.h>
#include<string.h>

main()
{
 char buf[11]="Rahul";

 char rbuf[] = {'R','a','h','u','l','\0'};

 printf("lenght: %d\t size: %d\n",strlen(buf),sizeof(buf));
 printf("lenght: %ld\t size: %d\n",strlen(rbuf),sizeof(rbuf));
 printf("%s",buf);
 printf("end");

 printf("\n%s",rbuf);
 printf("end2");


 
}
