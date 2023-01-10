#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
    //static memory allocation 
    int A[3][4] = {{1,2,3,4},{5,6,7,8},{8,9,5,6}};
    //dynamic memory allocation C++ style
    int *B[3];
    B[0] = new int[4];
    B[1] = new int[4];
    B[2] = new int[4];
    
    int **C;
    C = new int*[3];
    C[0] = new int[4];
    C[1] = new int[4];
    C[1] = new int[4];

    //dynamic memory allocation C style
    int *D[3];
    D[0] = (int*) malloc(4*sizeof(int));
    D[1] = (int*) malloc(4*sizeof(int));
    D[2] = (int*) malloc(4*sizeof(int));

    int **E;
    E = (int**) malloc(3*sizeof(int*));
    E[0] = (int*) malloc(4*sizeof(int));
    E[1] = (int*) malloc(4*sizeof(int));
    E[2] = (int*) malloc(4*sizeof(int));
    return 0;
}