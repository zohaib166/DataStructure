#include <stdio.h>
int main() 
{
    char num[10];
    printf("Enter a number: ");
    scanf("%s",num);
    int i = 0, valid = 1;
    while(num[i]!='\0') {
        if(!(num[i] >= '0' && num[i] <= '9')) {
            valid = 0;
            break;
        }
        i++;
    }
    printf(valid?"Valid":"InValid");
}