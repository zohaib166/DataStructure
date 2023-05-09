#include <stdio.h>

int main()
{
    FILE *fp;
    fp = fopen("data.txt", "w");
    int num = 5;
    for(int i=1;i<=10;i++) {
        fprintf(fp, "%d x %d = %d\n", num, i, num*i);
    }
    fclose(fp);
    
}