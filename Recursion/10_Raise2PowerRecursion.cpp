#include<iostream>
using namespace std;

int power(int m, int n) {
    if(n>0) {
        return power(m,n-1)*m;
    } else {
        return 1;
    }
}
int main()
{
    cout << power(2,5);
    return 0;
}