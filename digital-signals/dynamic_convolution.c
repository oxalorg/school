#include<stdio.h>
#define N1 4
#define N2 3
#define N (N2+N1-1)

int x[N1] = {1,2,3,4};
int h[N2] = {2,3,4};


void mat_multiply(int a[][10], int b[][1], int m, int p, int n, int x_start, int y_start){
	int mult[10][1];
	int start = x_start + y_start;
	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){
			mult[i][j] = 0;
			for(int k = 0; k < p; k++){
				mult[i][j] += a[i][k]*b[k][j]; 
			}
			printf("%d %d", start++, mult[i][j]);
		}
        printf("\n");
	}
}

int main(){
    int hpad[N];
    int n1, n2, x_start, y_start;
    //input n1
    printf("Input n1, x_start\n");
    scanf("%d %d", &n1, &x_start);
    
    // input x[n]
    for(int i = 0; i <n1; i++){
        scanf("%d", &x[i]);
    }
    
    // input n2
    printf("Input n1, y_start\n");
    scanf("%d %d", &n2, &y_start);
    
    // input h[n]
    for(int i = 0; i <n2; i++){
        scanf("%d", &h[i]);
    }
    
    //----------------------//
    int n = n1 + n2 - 1;
    printf("padded h(n) matrix: \n");
    for(int i = 0; i < n; i++){
        hpad[i] = (i < n2 ? h[i] : 0);
                printf("%d", hpad[i]);
	}	

	int mat1[10][10];
	int mat2[10][1];

	// column first then row

	for(int i = 0; i < n1; i++){
		for(int j = 0; j < n; j++){
			mat1[(i+j)%n][i] = hpad[j];
		}
	}

	printf("\n\nPadded convoluted matrix\n");
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n1; j++){
            	printf("%d", mat1[i][j]);
        }
       printf("\n");
     }


	for(int i = 0; i < n1; i++){
		mat2[i][0] = x[i];
	}

    printf("\nn: y(n)\n");

	mat_multiply(mat1, mat2, n, n1, 1, x_start, y_start);
}
