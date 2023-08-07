#include <stdio.h>
int main()
{
    int arr[] = {1,1,2,2,2,3,3};
    int i=0,j=1;
    while(j<7) {
        if(arr[j]!=arr[i]) {
            arr[i+1] = arr[j];
            i++;
        }
        j++;
    }

    for(int k=0; k<=i; k++)
    {
        printf("%d ", arr[k]);
    }
}