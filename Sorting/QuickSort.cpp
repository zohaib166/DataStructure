#include <iostream>
using namespace std;

int partition(int arr[], int low, int high) {
    int pivot = arr[low];
    int i = low;
    int j = high;

    while(i<j) {
        while(i <= high && arr[i] <= pivot) i++;
        while(j >= low && arr[j] > pivot) j--;
        if(i<j) {
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[low], arr[j]);

    return j;
}

void quickSort(int arr[], int low, int high) {
    int pIndex;
    if(low < high) {
        pIndex = partition(arr, low, high);
        quickSort(arr, low, pIndex-1);
        quickSort(arr, pIndex+1, high);
    }
}

int main() {
    int arr[] = {4,2,7,5,9,8,1,6};
    int n = sizeof(arr)/sizeof(int);

    for(auto x: arr) {
        cout << x << " ";
    }

    cout << endl;
    quickSort(arr, 0, n-1);

    for(auto x: arr) {
        cout << x << " ";
    }
}