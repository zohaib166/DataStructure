#include <cstdio>
int main()
{
    int i,j,temp;
    int arr[6] = {5,2,3,4,7,8};
    for(i = 0; i < 6; i++) 
    {
        for(j = i+1; j < 6; j++) {
            if(arr[i] > arr[j]) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    for(int i=0; i<6; i++)
    {
        printf("%d ", arr[i]);
    }
}