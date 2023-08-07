#include <stdio.h>
int main()
{
    int arr[10] = {2,3,4,5,6,7,8,9};
    int target_index = 5;
    int temp = arr[5];
    for(int i=4; i>=0; i--) {
        arr[i+1] = arr[i];
    }
    arr[0] = temp;
    for(int i=0;i<8;i++)
    {
        printf("%d ", arr[i]);
    }
}