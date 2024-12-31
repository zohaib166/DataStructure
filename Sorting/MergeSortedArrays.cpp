/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>

using namespace std;

int main()
{
    int arr1[] = {3,6,9,10}; int n1 = sizeof(arr1)/sizeof(int);
    int arr2[] = {5,7,8,11,13}; int n2 = sizeof(arr2)/sizeof(int);
    
    int arr3[9];
    
    int i=0,j=0,k=0;
    while(i<n1 && j<n2) {
        if(arr1[i] <= arr2[j]) {
            arr3[k++] = arr1[i++];
        } else if(arr1[i] >= arr2[j]) {
            arr3[k++] = arr2[j++];
        }
    }
    
    for(;i<n1;i++) {
        arr3[k++] = arr1[i];
    }
    for(;j<n2;j++) {
        arr3[k++] = arr2[j];
    }
    
    for(int i=0;i<k;i++) {
        cout <<arr3[i] << " ";
    }
}