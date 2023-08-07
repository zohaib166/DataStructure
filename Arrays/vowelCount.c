/*Count the number of vowels in a string*/
#include<stdio.h>
int main()
{
	char str[50] = "aeiouAEIOU";
	int vowel_count=0, consonant_count=0, i = 0;
	while(str[i]!='\0') {
        switch(str[i]) {
            case 'o':
            case 'O':
            case 'a':
            case 'A':
            case 'e':
            case 'E':
            case 'i':
            case 'I':
            case 'u':
            case 'U':
                vowel_count++;
                break;
            default:
                if((str[i]>='a' && str[i]<='z') || (str[i]>='A' && str[i]<='Z')) {
                    consonant_count++;
                }
                break;
        }
        i++;
    }
    printf("Vowel Count: %d\n", vowel_count);
    printf("Consonant Count: %d\n", consonant_count);
}
