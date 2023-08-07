#include <stdio.h>
int main()
{
    int a[][3] = {{4,2,3},{4,9,6},{7,8,9}};
    int b[3][3][3] = {{{1,2,3},{4,5,6},{7,8,9}},{{1,2,3},{4,5,6},{7,8,9}},{{1,2,3},{4,5,6},{7,8,9}}};

    for(int i=0;i<3;i++) {
        for(int j=0;j<3;j++) {
            printf("%d ", *(*(a+i)+j));
            //printf("%d ", *(*a + i*3+j));
        }
        printf("\n");
    }

    printf("\n");

    // for(int i=0;i<3;i++) {
    //     for(int j=0;j<3;j++) {
    //         for(int k=0;k<3;k++) {
    //             //printf("%d ", *(*(*(b+i)+j)+k));          
    //         }
    //         printf("\n");
    //     }
    //     printf("\n");
    // }
}