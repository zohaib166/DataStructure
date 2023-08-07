#include<stdio.h>
void multiply(int[],int,int*);
int main()
{
    int result[100]={2,3,4};
    int i,x=20;
    int size = 3;
    multiply(result,x,&size);
    for(i=size-1;i>=0;i--)
    {
        printf("%d",result[i]);
    }
}

void multiply(int res[], int x, int *len)
{
    int i,carry=0,prod=0;
    for(i=0;i<*len;i++)
    {
        prod = res[i]*x+carry;
        res[i] = prod % 10;
        carry = prod/10;
    }

    while(carry)
    {
        res[*len] = carry%10;
        carry = carry/10;
        (*len)++;
    }
    printf("length: %d\n",*len);
}
