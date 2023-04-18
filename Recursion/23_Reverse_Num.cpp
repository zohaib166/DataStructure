#include <cstdio>

int reverse(int num) {
    static int rev = 0;
    if(num!=0) {
        rev = rev * 10 + num%10;
        reverse(num/10);
    } 
    return rev;
}

int main()
{
    printf("%d", reverse(1234));
}