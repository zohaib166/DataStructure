#include<iostream>
using namespace std;
//When there is no operation after recursion it is called Tail Recursion
void func_tail(int n) {
    if(n>0) {
        printf("%d ",n);
        func_tail(n-1);
    }   
}
//When all the executable statements after recursive call it is called Head Recursion
void func_head(int n) {
    if(n>0) {
        func_head(n-1);
        printf("%d ",n);
    }   
}
int main()
{
    func_tail(5);
    printf("\n");
    func_head(5);
}