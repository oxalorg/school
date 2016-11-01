#include<stdio.h>
#include<complex.h>    
#include<math.h>
#define M_PI 3.14159265358979323846264338327

int main(){
    int npoint, n;
    double complex x[10];
    double complex w[8];
    double complex dft[10];
    scanf("%d %d", &npoint, &n);
    
    for(int i = 0; i < n; i++){
        int rl, img;
        scanf("%d %d", &rl, &img);
        x[i] = rl + img * I;
    }

    for(int k = 0; k < npoint; k++){
        // calculate e^(-j*2pi*k/N);
        w[k] = cexp((-I*2*M_PI/npoint*k));
    }
    
    for(int i = 0; i < n; i++){
        dft[i] = 0;
        for(int j = 0; j < n; j++){
            dft[i] += x[j] * w[(j*i)%npoint];
        }
    }
    
    for(int i = 0; i < n; i++){
        printf("%f + j * %f\n", creal(dft[i]), cimag(dft[i]));
        printf("Magnitude: %f\n", cabs(dft[i]));
        printf("Phase difference: %f\n---\n", atan(creal(dft[i])/cimag(dft[i])));    
    }
    
    
    return 0;
}

