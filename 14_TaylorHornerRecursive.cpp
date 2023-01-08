#include<iostream>
using namespace std;

double e(int x, int n) {
    static double s = 1;
    if(n==0) {
        return s;
    }
    s = 1+(x/(double)n)*s;
    return e(x,n-1);
}
int main()
{
    printf("%lf", e(1,10));
    return 0;
}