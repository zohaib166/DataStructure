/*Get the position of the first occurrence of a sub-string in a string*/
#include <stdio.h>
#include <string.h>
int main()
{
    char str1[50] = "mathematics", str2[50] = "ma";
    
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int flag;
    for(int i=0;i<(len1-len2);i++) {
        flag = 1;
        for(int j=0;j<len2;j++) {
            if(str1[i+j]!=str2[j]) {
                flag = 0;
                break;
            }
        }
        if(flag==1) {
            printf("The substring exists at %d position\n", i);
        }
    }
    if(flag==0) {
        printf("Substring not found\n");
    }

    return 0;
}

