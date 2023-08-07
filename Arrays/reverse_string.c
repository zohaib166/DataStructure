/*Reversing a string and saving it in another array*/
#include <stdio.h>
int main() {
	char str[20] = "australia";
	char rev_str[20];
	int i,j,len;
	for(i=0; str[i]!='\0';i++);
	len = i;
	i--;
	for(j=0; j<len; j++) {
		rev_str[j] = str[i];
		i--;
	}
	rev_str[j] = '\0';
	printf("%s", rev_str);
}
