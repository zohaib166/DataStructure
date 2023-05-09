#include <stdio.h>

int main()
{
    FILE *fp;
    fp = fopen("data.txt", "r");
    int num, i , res;
    while(fscanf(fp,"%d x %d = %d", &num, &i, &res)==3) {
        printf("%d x %d = %d\n", num, i, res);
    }
    fclose(fp);
    
}