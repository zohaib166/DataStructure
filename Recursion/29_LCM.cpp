#include <cstdio>

int RLCM(int a, int b) {
    static int max = a>b?a:b;
    if(max%b == 0 && max%a==0) {
        return max;
    }
    //printf("%d--", max);
    max++;
    return RLCM(a,b);
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
    printf("%d\n", LCM(12,34));
    printf("%d", RLCM(12,34));
}