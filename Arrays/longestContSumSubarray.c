#include <stdio.h>
#include <limits.h>
int main() {
    int a[] = {-2, -3, 4, -1, -2, 1, 5, -3};
    int size = sizeof(a)/sizeof(a[0]);
    int final_sum = INT_MIN, current_sum = 0;
    for(int i=0;i<size;i++) {
        current_sum += a[i];
        if(current_sum < 0) {
            current_sum = 0;
        }
        if(final_sum<current_sum) {
            final_sum = current_sum;
        }
    }

    printf("Current Sum: %d,  Final Sum: %d", current_sum, final_sum);
}