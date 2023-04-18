#include <cstdio>

int helper(int num, int rev) {
    if(num==0) {
        return rev;  
    } 
    rev = rev * 10 + num%10;
    return helper(num/10, rev);
}

int checkPalindrome(int num) {
    printf("%d ", helper(num, 0));
    return num == helper(num, 0);
}

int main()
{
    printf("%d", checkPalindrome(1331));
}