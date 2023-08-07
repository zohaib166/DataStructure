#include <stdio.h>
#include <limits.h>
int main()
{
    int arr[] = {8,4,6,7,3,2};
    int largest = arr[0], slargest = -1;
    int smallest = arr[0], ssmallest = INT_MAX;
    for(int i=1;i<6; i++)
    {
        if(arr[i]>largest) {
            slargest = largest;
            largest = arr[i];
        } else if(arr[i]>slargest) {
            slargest = arr[i];
        }

        if(arr[i]<smallest) {
            ssmallest = smallest;
            smallest = arr[i];
        } else if(arr[i]>ssmallest) {
            ssmallest = arr[i];
        }
    }

    printf("%d %d\n", largest, slargest);
    printf("%d %d\n", smallest, ssmallest);
}