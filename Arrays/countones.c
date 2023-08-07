#include <stdio.h>

int main()
{
    unsigned char x = 15;
    //printf("%u\n",sizeof(x));
    char i=0;
    char count=0;
    for(i=0;i<8;i++)
    {
        if(x%2!=0)
        {
            count++;
        }
        x = x>>1;
    }
    printf("%u",count);
}
