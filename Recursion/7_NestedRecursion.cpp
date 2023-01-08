#include<iostream>
using namespace std;

int func(int n) {
    if(n>10) {
        return n-1;
    } else {
        return func(func(n+2));
    }
}
int main()
{
    int x = func(7);
    printf("%d",x);
    return 0;
}