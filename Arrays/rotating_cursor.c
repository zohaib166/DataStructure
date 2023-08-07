#include <stdio.h>

void delay() {
    for(int i=0;i<10000;i++) {
        for(int j=0;j<5000;j++) { }
    }
}
int main() {
    char cursor[4] = {'|','/','-','\\'};
    for(int i=0;i<75;i++) {
        printf(".%c\b", cursor[i%4]);
        delay();
    }
}