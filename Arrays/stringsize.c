/*Find the size of the string*/
#include<stdio.h>
int main()
{
	char str[50] = "mathematical";
	int i;
	for(i=0; str[i]!='\0'; i++);
	printf("Size of the String is %d", i);
}
