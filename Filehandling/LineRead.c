#include <stdio.h>

int main()
{
    FILE *fp;
    fp = fopen("data.txt", "r");
    char buffer[100];

    while(fgets(buffer, 100, fp) != NULL) {
        printf("%s", buffer);
    }
    fclose(fp);
    
}