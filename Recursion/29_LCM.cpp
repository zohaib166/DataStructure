#include <cstdio>

int RLCM(int a, b) {
    
}

int LCM(int a, int b) {
    int max = a>b?a:b;
    if(a%b == 0 || b%a==0) {
        return max;
    }
    while(!(max%a==0 && max%b==0)) {
        max++;
    }
    return max;
}
int main() {
    printf("%d", LCM(12,34));
}