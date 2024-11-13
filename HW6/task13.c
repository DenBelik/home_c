#include <stdio.h>
#include <inttypes.h>



float module(float x) {
    return (x < 0) ? -x : x;
}

float pow(float num, int st) {
    float res = 1;
    if (st == 0) {
        return 1;
    }
    for (int i = 0; i < st; ++i) {
        res *= num;
    }
    return res;
}

float fact(int n) {
    float res = 1;
    for (int i = n; i > 1; i--) {
        res *= i;
    }
    return res;
}

float cosinus(float x) {
    float err = 1;
    float sum = err;
    int n = 0;
    int sign = -1;
    while(module(err) > 0.001) {
        n += 2;
        err = pow(x, n) / fact(n);
        sum += sign * err;
        sign = -sign;
    }

    return sum;
}


int main(void) {   
    float a;
    scanf("%f", &a);
    a = (a * pi) / 180;
    printf("%.3f", cosinus(a));
}