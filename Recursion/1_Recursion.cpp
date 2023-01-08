#include<iostream>
using namespace std;

void func(int n) {
   
    if(n>0) {
        printf("%d ",n);
        func(n-1);
    }
        
}

int main()
{
    func(5);
    return 0;
}