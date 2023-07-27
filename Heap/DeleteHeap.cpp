/**
 * @file DeleteHeap.cpp
 * @author Zohaib Hasan
 * @brief This code deletes from a heap and in turn performs heap sort
 * @version 0.1
 * @date 2023-07-24
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <cstdio>

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}
int deleteHeap(int A[], int n) {
    int i = 1,j;
    int val = A[1];
    int temp = A[n];
    A[1] = A[n];
    j = 2*i;

    //Storing elements to be deleted at the last 
    A[n] = val;

    while(j<n-1) {
        if(A[j]<A[j+1]) {
            j++;
        }
        if(A[i]<A[j]) {
            swap(&A[i], &A[j]);
            i = j;
            j = 2*i;
        } else 
            break;
    }
    return val;
}

void displayHeap(int A[], int n) {
    for(int i=1;i<=n;i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
}

int main() {
    int A[] = {0,40,20,30,10,8,25,27};
    int size=7;
    
    for(int i=7; i>2;i--) {
        deleteHeap(A,i);
    }

    for(int i=1; i<=7; i++) {
        printf("%d ", A[i]);
    }
}