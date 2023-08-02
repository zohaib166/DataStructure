#include <cstdio>
#include <iostream>

typedef struct _rational{
    int numerator, denominator;
} RATIONAL;

int gcd(int x,int y) {
    int temp;
    while(y>0) {
        temp = y;
        y = x%y;
        x = temp;
    }
    return x;
}

void reduce(RATIONAL *r1) {
    int x = gcd(r1->numerator, r1->denominator);
    if(x>1) {
        r1->numerator /= x;
        r1->denominator /= x;
    }
}

void showRational(RATIONAL *r) {
    if(r->denominator != 1)
        std::cout << r->numerator << "/" << r->denominator << std::endl;
    else
        std::cout << r->numerator << std::endl;
}

RATIONAL add(RATIONAL *r1, RATIONAL *r2) {
    RATIONAL ans;
    if(r1->denominator == r2->denominator) {
        ans.numerator = r1->numerator + r2->numerator;
        ans.denominator = r1->denominator;
    } else {
        ans.denominator = r1->denominator * r2->denominator;
        ans.numerator = r1->numerator*r2->denominator + r2->numerator*r1->denominator;
    }
    reduce(&ans);
    return ans;
}

int main()
{
    RATIONAL r1 = {4,5};
    RATIONAL r2 = {1,5};
    reduce(&r1); reduce(&r2);
    showRational(&r1); showRational(&r2);
    RATIONAL add_ans = add(&r1,&r2);
    showRational(&add_ans);
}