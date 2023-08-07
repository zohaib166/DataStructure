#include <stdio.h>

void mergeArrays(int arr1[], int size1, int arr2[], int size2, int arr3[]) {
    int i=0,j=0,k=0;
    while(i<size1 && j<size2) {
        if(arr1[i]<arr2[j]) {
            arr3[k++] = arr1[i++];
        } else {
            arr3[k++] = arr2[j++];
        }
    }
    for(;i<size1;i++) {
        arr3[k++] = arr1[i]; 
    }
    for(;j<size2;j++) {
        arr3[k++] = arr2[j];
    }
}
int main()
{
    int arr1[] = {3,4,7,8,9};
    int size1 = sizeof(arr1)/sizeof(arr1[0]);
    int arr2[] = {1,6,12};
    int size2 = sizeof(arr2)/sizeof(arr2[0]);
    int size3 = size1+size2;
    int arr3[size3];
    mergeArrays(arr1, size1, arr2, size2, arr3);

    for(int i=0;i<size3; i++) {
        printf("%d ", arr3[i]);
    }
}