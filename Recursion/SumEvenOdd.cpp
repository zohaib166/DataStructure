#include <cstdio>
int addEven(int a, int b) {
    if(a>b) {
        return 0;
    } 
    if(b%2==0) {
        return b+addEven(a,b-2);
    } 
    return addEven(a,b-1);
}

int addOdd(int a, int b) {
    if(a>b) {
        return 0;
    } 
    if(b%2==1) {
        return b+addOdd(a,b-2);
    } 
    return addOdd(a,b-1);
}

int main()
{
    printf("%d ", addEven(2,9));
    printf("%d", addOdd(2,9));
}