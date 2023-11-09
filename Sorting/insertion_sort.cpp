#include <cstdio>

int main()
{
    int i,j,temp;
    int arr[6] = {5,2,3,4,7,8};
    for(i = 1; i < 6; i++) 
    {
        j = i-1;
        temp = arr[i];
        while(j>=0 && temp<arr[j]) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp;
    }

    for(int i=0; i<6; i++)
    {
        printf("%d ", arr[i]);
    }
}