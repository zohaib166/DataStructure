#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() 
{
    char *names[5];
    for(int i=0;i<5;i++) {
        char temp[20];
        printf("Enter name number %d", i+1);
        scanf("%s", temp);
        names[i] = (char*) malloc(strlen(temp));
        strcpy(names[i], temp);
    }

    for(int i=0;i<5;i++) {
        printf("%s\n", names[i]);
        free(names[i]);
    }
}