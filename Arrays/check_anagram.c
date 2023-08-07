#include <stdio.h>

int main()
{
    char str1[] = "verbose";
    char str2[] = "observe";
    unsigned char letter_count[26] = {0};
    for(int i=0;str1[i]!='\0';i++) {
        letter_count[str1[i]-97]++;
    }
    int flag = 1;
    for(int i=0;str1[i]!='\0';i++) {
        if(letter_count[str2[i]-97] > 0) {
            letter_count[str2[i]-97]--;
        } else {
            flag = 0;
            break;
        }
    }
    printf(flag?"Anagram":"Not Anagram");
}