/*Find whether a given string is a palindrome or not.*/
#include <stdio.h>

int main()
{
	char str[20] = "madam";
	int i,j=0;
	int flag = 0;
	for(i=0; str[i]!='\0';i++);
	i--;
	for(; i>=0; i--)
	{
		if(str[i]!=str[j])
		{
			flag = 1;
			break;
		}
		else
			j++;
	}
	if(flag == 0)
		printf("The word is a palindrome\n");
	else
		printf("The word is not a palindrome\n");

}
