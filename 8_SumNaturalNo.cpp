#include<iostream>
using namespace std;

int sumRecursive(int n) {
    if(n==0) {
        return 0;
    } else {
        return sumRecursive(n-1)+n;
    }
}
int main()
{
    printf("%d", sumRecursive(5));
    return 0;
}