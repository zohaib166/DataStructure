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
    
    int n = 5;
    cout << rfib(n);
    return 0;
}