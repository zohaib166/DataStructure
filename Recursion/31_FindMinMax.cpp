#include <cstdio>

int findMax(int *arr, int size) { 
    if(size==1) {
        return arr[0];
    }
    int x = findMax(arr, size-1);
    return arr[size-1] > x ? arr[size-1] : x;
}

int main()
{ 
    int arr[] = {5,6,17,8,9};
    printf("%d\n", findMax(arr, 5));
}