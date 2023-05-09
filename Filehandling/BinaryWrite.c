#include <stdio.h>
#include <string.h>
struct myType {
    int num;
    float frac;
    char str[10];
};
int main()
{
    FILE *fp;
    fp = fopen("data.bin", "wb");

    struct myType x;
    x.num = 23;
    x.frac = 3.4f;
    strcpy(x.str, "hello");

    fwrite(&x, sizeof(struct myType), 1, fp);
    fclose(fp);
}