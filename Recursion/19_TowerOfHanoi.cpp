#include<iostream>
using namespace std;

void ToH(int n, char a, char b, char c) {
    if(n>0) {
        ToH(n-1, a, c, b);
        printf("from %c to %c using %c\n", a, c, b);
        ToH(n-1, b, a, c);
    }
}
int main()
{
    ToH(3, 'A', 'B', 'C');
    return 0;
}