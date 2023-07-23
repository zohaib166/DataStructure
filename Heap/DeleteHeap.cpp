#include <cstdio>

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}
int deleteHeap(int A[], int n) {
    int i = 1,j;
    int temp = A[n];
    A[1] = A[n];
    j = 2*i;
    while(j<n) {
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
    A[n] = temp;
    return n-1;
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
    int orig_size = size;
    displayHeap(A, size);
    size = deleteHeap(A, size);
    displayHeap(A, size);
    size = deleteHeap(A, size);
    displayHeap(A, size);
    size = deleteHeap(A, size);
    displayHeap(A, size);
    size = deleteHeap(A, size);
    displayHeap(A, size);
    size = deleteHeap(A, size);
    displayHeap(A, size);

}