#include <stdio.h>

int main()
{
    int a[10] = {2,5,7,8,7,6};
    int target = 22;
    int success = 0;
    
    int i=0,j = 0, sum = 0;
    while(i<=j && sum!=target) {
        if(sum<target) {
            sum += a[j];
            j++;
        } else if(sum>target) {
            sum -= a[i];
            i++;
        }
        if(sum==target) {
            success = 1;
            break;
        }
        if(j>5 || i>5) {
            success = 0;
            break;
        }
        
    }
    if(success==1)
        printf("%d %d\n", i,--j);
    else 
        printf("-1");

    return 0;
}
