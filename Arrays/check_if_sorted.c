#include <stdio.h>
int main()
{
    int arr[] = {1,1,8,3,4,5};
    int i;
    for(i=1;i<6;i++)
    {
        if(arr[i] < arr[i-1]) {
            break;
        }
    }
    if(i==6) {
        printf("Array is sorted");
    } else {
        printf("Array is not sorted");
    }
}