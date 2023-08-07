#include <cstdio>

int main() {
    int arr[] = {1,1,2,2,2,3,3,4,4,4};
    int size = sizeof(arr)/sizeof(arr[0]);

    int count=1, countMax=1, i;
    int mode = 0;
    for(i=1;i<size;i++) {
        if(arr[i-1] == arr[i]) {
            count++;
        } else {
            if(countMax < count) {
                countMax = count;
                mode = arr[i-1];
            } 
            if(countMax == count) {
                mode = -1;
            }
            count = 1;
        }
    }
    if(countMax < count)
        mode = arr[i-1];
    printf("\n%d", mode);
}