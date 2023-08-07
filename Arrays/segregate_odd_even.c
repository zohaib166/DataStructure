#include <stdio.h>
int main()
{
    int arr[10] = {2,3,4,5,6,7,8,9};
    int i = 0, j = 7;
    int temp;
    while(i<j)
    {
        while(arr[i]%2==0 && i<j) {
            i++;
        }
        while(arr[j]%2!=0 && i<j) {
            j--;
        }
        if(i<j) {
            temp = arr[j];
            arr[j] = arr[i];
            arr[i] = temp;
            i++;j--;
        }
    }
    for(int i=0;i<8;i++) {
        printf("%d ", arr[i]);
    }
}