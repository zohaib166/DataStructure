/*Program to toggle case*/
#include <stdio.h>
int main() {
	char str[10] = "HpLlO";
	int i=0;
	while(str[i] != '\0') {
		if(str[i] >= 65 && str[i] <=90)
			str[i] = str[i]+32;
		else if(str[i] >= 97 && str[i] <=122)
			str[i] = str[i] - 32;
		else {
			printf("Failure : the string should contain alphabets only\n");
			return 1;
		}
		i++;
	}
	printf("%s", str);
	return 0;
}
