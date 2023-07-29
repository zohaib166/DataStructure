#include <cstdio>
#include <cmath>

void heapify(int A[], int size) {
    int j;
    for(int i = ceil(size/2); i > 0; i--) {
        j = i*2;
    
        if((j+1) <= size && A[j] < A[j+1]) j++;
    
        if(A[i] < A[j]) {
           int temp = A[i];
           A[i] = A[j];
           A[j] = temp;
        }
    }
}

void displayHeap(int A[], int size) {
    for(int i=1;i<=size; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
}


int main()
{
    int A[] = {0,30,20,10,7,25,15};
    heapify(A, 6);
    displayHeap(A, 6);
    return 0;
}

