#include <cstdio>
#include <iostream>
using namespace std;

int getMax(int arr[], int n) {
    int m = arr[0];
    for(int i=1;i<n;i++) {
        if(m < arr[i]) {
            m = arr[i];
        }
    }
    return m;
}

int main()
{
    int i,j,temp;
    int arr[] = {100,210,321,434,221,121};
    int N = sizeof(arr)/sizeof(arr[0]);   

    int m = getMax(arr, N);
    int exp;
    for(exp = 1; m / exp > 0; exp*=10) {
        for(i = 1; i < N; i++) {
            j = i-1;
            temp = arr[i];
            while(j >= 0 && (temp/exp)%10 < (arr[j]/exp)%10) {
                arr[j+1] = arr[j];
                j--;
            }
            arr[j+1] = temp;
        }
    }
    for(int i=0; i<N; i++) {
        printf("%d ", arr[i]);
    }
}