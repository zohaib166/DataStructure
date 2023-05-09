#include <stdio.h>

int main()
{
    FILE* fp;
    fp = fopen("data.txt", "w");
    char ch;
    char text[100];
    int i=0;
    
    while((ch = fgetc(stdin))!=EOF && i<99) {
        text[i++] = ch;
    }

    text[i]='\0';

    for(i=0;text[i]!='\0';i++) {
        fputc(text[i], fp);
    }
    fclose(fp);
}