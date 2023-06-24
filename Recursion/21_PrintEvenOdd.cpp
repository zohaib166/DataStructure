#include <cstdio>
void printEven(int a, int b) {
    if(a>b) {
        return;
    } 
    b%2 == 0 ? printEven(a,b-2) : printEven(a,b-1);
    if(b%2==0) {
        printf("%d ", b);
    }
}

// void printEven(int a, int b) {
//     if(a>b) {
//         return;
//     } 
//     if(a%2==0) printf("%d ", a);
//     printEven(a+1,b);
// }

void printOdd(int a, int b) {
    if(a>b) {
        return;
    } 
    b%2 == 1 ? printOdd(a,b-2) : printOdd(a,b-1);
    if(b%2==1) {
        printf("%d ", b);
    }
}

int main()
{
    printEven(1,9);
    printf("\n");
    printOdd(30, 50);
}