#include <stdio.h>

int main()
{
    FILE* fp;
    fp = fopen("data.txt", "r");
    char ch;
    int i=0;
    while((ch=fgetc(fp))!=EOF) {
        printf("%c", ch);
    }

    fclose(fp);
}