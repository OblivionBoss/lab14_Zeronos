#include <iostream>
#include <cmath>
using namespace std;

void stat(const double[],int,double[]);

int main(){
    double A[] = {1.2,3.5,6.9,7.8,12.5,0.5};
    int N = sizeof(A)/sizeof(A[0]);
    double B[6];
    stat(A,N,B);
    cout << "Arithmetic Mean = " << B[0];
    cout << "\nStandard Deviation = " << B[1];
    cout << "\nGeometric Mean = " << B[2];
    cout << "\nHarmonic Mean = " << B[3];
    cout << "\nMax = " << B[4];
    cout << "\nMin = " << B[5];
    return 0;
}

void stat(const double A[],int N,double B[]){
    double sum = 0,sumdev = 0,geoval = 1,sumhar = 0;
    double min = A[0],max = A[0],invpw = (1.0/N);
    for(int i = 0; i < N; i++){
        sum += A[i];
    }
    B[0] = sum / N;
    for(int j = 0; j < N; j++){
        sumdev += pow(A[j] - B[0],2);
    }
    B[1] = sqrt(sumdev / N);
    for(int k = 0; k < N; k++){
        geoval = geoval*A[k];
    }
    B[2] = pow(geoval,invpw);
    for(int l = 0; l < N; l++){
        sumhar += (1/A[l]);
    }
    B[3] = N / sumhar;
    for(int m = 0; m < N; m++){
        if(A[m] > max){
            max = A[m];
        }
        if(A[m] < min){
            min = A[m];
        }
    }
    B[4] = max;
    B[5] = min;
}