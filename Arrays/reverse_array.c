#include <stdio.h>
int main() {
    int arr[10] = {1,11,5,7,9,3,5,10,8,2};
    int i = 0, j = 9;
    int temp;
    while(i<j) {
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
        i++; j--;
    }

    for(int i=0;i<10;i++) {
        printf("%d ", arr[i]);
    }
}