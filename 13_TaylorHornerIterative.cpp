#include<iostream>
using namespace std;
double e(int x, int n) {
    double s = 1.0;
    for(;n>0;n--) {
        s = 1+ (x/(double)n)*s;
    }
    return s;
}
int main()
{
    printf("%lf", e(1,10));
    return 0;
}