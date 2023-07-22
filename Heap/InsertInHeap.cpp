#include <cstdio>
#include <cstdlib>
#define MAX 9

int heapInsert(int A[], int size, int key) {
    if(size == MAX) {
        return -1;
    }
    int i = 0;
    i = size+1;
    A[i] = key;
    while(i>1 && key > A[i/2]) {
        A[i] = A[i/2];
        i = i/2;
    }
    A[i] = key;
    return size+1;
}

void printHeap(int A[], int size) {
    for(int i=1;i<=size;i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
}

int main() {
    int A[MAX] = {0,30,20,15,5,10,12,6};
    int size = 7; //this is actually current last index as we are ignoring index 0
    size = heapInsert(A, size, 40);
    printHeap(A, size);
    size = heapInsert(A, size, 35);
    printHeap(A, size);
    size = heapInsert(A, size, 10);
    printf("Overflow: %d ", size);
}