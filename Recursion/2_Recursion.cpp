#include<iostream>
using namespace std;

int func(int n) {
    if(n>0) {
        return func(n-1)+n;
    }
    return 0;
}

int main()
{
    printf("%d",func(4));
    return 0;
}