#include <stdio.h>

int main()
{
    int arr[10] = {3,4,5,6,8,11,12,13,14,15};
    int i = 0;
    int diff = arr[0];
    for(i=0;i<10;i++) {
        if(arr[i]-i != diff) {
            while(diff < arr[i]-i) {
                printf("%d ", i+diff);
                diff++;
            }
        }
    }
}