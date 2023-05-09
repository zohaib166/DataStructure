#include <stdio.h>

int main()
{
    FILE *fp;
    fp = fopen("data.txt", "w");
    char buffer[10][100];

    for(int i=0;i<5;i++) {
        fgets(buffer[i], 100, stdin);
        fputs(buffer[i], fp);
    }
    fclose(fp);
    
}