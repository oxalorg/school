#include <stdio.h>
#include <stdlib.h>
#include<complex.h>    
#include<math.h>
#define M_PI 3.14159265358979323846264338327

double complex twiddle(int n, int k)
{
    // Calculate e^(-2 PI J K / N)
    return cexp(-I*2*M_PI*k/n)
}

void fft(int x[], int n) {
    int buf[8];
    for (int i = 0; i < 8; i++) {
        buf[i] = x[i];
    }
}

int main(int argc, char const* argv[])
{
    int n; // n point fft
    
    int x[8] = { 1, 1, 1, 1, 0, 0, 0, 0};
    int ans = {4, 0, 0, 0};
    fft(x, 8);

    return 0;
}
