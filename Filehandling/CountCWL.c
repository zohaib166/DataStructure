#include <stdio.h>
#include <ctype.h>

int main()
{
    FILE *fp;
    fp = fopen("data.txt", "r");
    char ch;
    int chars=0, lines=0, words=0;
    int space=0;
    while((ch=fgetc(fp))!=EOF) {
        chars++;
        if(ch=='\n') {
            lines++;
        }
        if(isspace(ch)) {
            space = 0;
        } else if(space==0) {
            words++;
            space = 1;
        }
    }
    printf("%d %d %d", chars, words, lines);
    fclose(fp);
}