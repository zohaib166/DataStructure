/*counts the number of words in a string*/
#include <stdio.h>
#define in 1
#define out 0

void main()
{
	char str[50];
	int state=out, count=0,i=0;
	printf("Enter a string\n");
	gets(str);
	while(str[i]!='\0')
	{
		if(str[i]==' ' || str[i]=='\t') {
			state=out;
		}
		else if(state==out){
			state=in;
			count++;
		}
		i++;
	}
	printf("No of words: %d",count);
}
