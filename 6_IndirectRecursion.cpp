#include <iostream>
using namespace std;

void func2(int n);
void func1(int n) {
    if(n>0) {
        printf("%d ",n);
        func2(n-1);
    }
}
void func2(int n) {
    if(n>0) {
        printf("%d ",n);
        func1(n/2);
    }
}
int main() {
    func1(20);
}

