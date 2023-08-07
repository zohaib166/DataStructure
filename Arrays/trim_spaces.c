#include <stdio.h>
int main()
{
    char str[50] = "  This is    a test   Program   ";
    int i=0, j=0, space = 1;
    while(str[j]!='\0') {
        if(str[j]!=' ' || (j>0 && str[j-1]!=' ')) {
            str[i] = str[j];  
            i++;
        }
        j++;
    }
    str[i] = '\0';
    printf("%s", str);
    return 0;
}