#include <cstdio>
int main()
{
    int a[10] = {7,6,5,4,3,2,1};
    int i, j, min, temp;
    for(i=0;i<7;i++) 
    {
        min = i;
        for(j=i+1;j<7;j++) 
        {
            if(a[j]<a[min]) {
                min = j;
            }
        }
        temp = a[i];
        a[i] = a[min];
        a[min] = temp;
    }
    for(int i=0;i<7;i++) {
        printf("%d ", a[i]);
    }
}