#include <stdio.h>
int main()
{
    int arr[10] = {1,2,3,4,5,6};
    int k = 4;
    int n = 6;
    int temp[10];
    int i;
    for(i = 0; i<k; i++) {
        temp[i] = arr[i];
    }
    int j=0;
    for(int i=k; i<n; i++)
    {
        arr[j] = arr[i];
        j++;
    }
    i = 0;
    for(; j<n;j++)
    {
        arr[j] = temp[i];
        i++;
    }
    for(i=0; i<n; i++) {
        printf("%d ", arr[i]);
    }
}