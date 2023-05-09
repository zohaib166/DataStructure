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
    fp = fopen("data.bin", "rb");

    struct myType x;

    // fwrite(&x, sizeof(struct myType), 1, fp);
    fread(&x, sizeof(struct myType), 1, fp);

    printf("%d %f %s", x.num, x.frac, x.str);

}