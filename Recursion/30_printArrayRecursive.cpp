#include <cstdio>
void printArray(int *arr, int last) {
    if(last>0) printArray(arr, last-1);
    printf("%d ", *(arr+last));
}
int main()
{
    int arr[] = {5,6,7,8,9};
    printArray(arr, 4);
}