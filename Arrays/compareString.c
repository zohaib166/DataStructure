#include <stdio.h>

int main()
{
    char str1[] = "widower";
    char str2[] = "widow";
    int i=0,j=0;
    while(str1[i]!='\0' && str2[i]!='\0') {
        if(str1[i]!=str2[j]) {
            break;
        }
        i++;j++;
    }
    if(str1[i]>str2[j]) {
        printf("1");
    } else if(str1[i]<str2[j]) {
        printf("-1");
    } else {
        printf("0");
    }
}