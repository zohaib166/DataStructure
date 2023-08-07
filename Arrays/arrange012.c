#include <stdio.h>

void swap(int *x, int *y) {
    int temp;
    temp=*x;
    *x = *y;
    *y = temp;
}

int main()
{
    int a[10] = {2,1,1,0,0,2,1,0};
    int low=0, mid=0, high=7;

    while(mid<high) {
        switch (a[mid])
        {
        case 0:
            swap(&a[low++], &a[mid++]);
            break;
        case 1:
            mid++;
            break;
        case 2:
            swap(&a[mid], &a[high--]);
            break;
        }
    }

    for(int i=0;i<8;i++) {
        printf("%d ", a[i]);
    }
}