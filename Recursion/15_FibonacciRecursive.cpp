#include<iostream>
using namespace std;
//0 1 1 2 3 5
int rfib(int n) {
    if(n<=1) {
        return n;
    }
    return rfib(n-2) + rfib(n-1);
}

int main()
{
    for(int i=0;i<10;i++) {
        F[i] = -1;
    }
    int n = 5;
    cout << mfib(n);
    return 0;
}