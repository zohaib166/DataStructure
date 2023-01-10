#include<iostream>
using namespace std;

//1x2+2x3+3x4+4x5+....

int s(int n) {
    int r;
    if(n==0) {
        return 0;
    }
    r = s(n-1) + n*(n+1);
    return r;
}
int main()
{
    printf("%d", s(5));
    return 0;
}