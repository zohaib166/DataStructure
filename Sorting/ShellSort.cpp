#include <cstdio>
#include <iostream>
using namespace std;

int main()
{
    int i,j,temp;
    int arr[] = {5,2,3,4,7,8};
    int N = sizeof(arr)/sizeof(arr[0]);
    int gap = N/2;
    for(gap=N/2; gap>=1; gap/=2) {
        for(i = gap; i<N; i++) 
        {
            j = i-gap;
            temp = arr[i];
            while(j>=0 && temp < arr[j]) {
                arr[j+gap] = arr[j];
                j = j - gap;
                
            }
            arr[j+gap] = temp;
        }
    }

    for(int i=0; i<N; i++) {
        printf("%d ", arr[i]);
    }
}