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
    int A[MAX] = {0};
    int size = 0; //this is actually current last index as we are ignoring index 0
    int x;
    printf("How many elements do you want to insert: ");
    scanf("%d", &x);
    if(x>MAX) {
        printf("Too many elements\n");
        exit(-1);
    }
    int n;
    for(int i=1;i<=x;i++) {
        scanf("%d", &n);
        size = heapInsert(A, size, n);
    }
    printHeap(A, x);
}