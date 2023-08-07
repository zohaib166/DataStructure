#include <stdio.h>

int main()
{
    char *str = "finding";
    int bitset = 0, x;
    for(int i=0; str[i]!='\0'; i++) {
        x = 1;
        x = x << (str[i]-97);
        if((bitset & x) > 0) { 
            printf("%c is duplicate\n", str[i]);
        } else {
            bitset |= x;
        }
    }
}