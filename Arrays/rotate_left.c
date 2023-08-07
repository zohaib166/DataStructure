#include <stdio.h>
int main() {
    int arr[10] = {2,3,4,5,6,7};
    int size = 6;
    int temp = arr[0];
    for(int i=1;i<size;i++) {
        arr[i-1] = arr[i];
    }
    arr[size-1] = temp;

    for(int i=0;i<size; i++) {
        printf("%d ", arr[i]);
    }
}