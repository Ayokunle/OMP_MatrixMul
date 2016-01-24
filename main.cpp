 #include <iostream>
#include <cstdlib>
#include <ctime>
#include <omp.h>

using namespace std;

void matmul(double **A, double **B, double **C, int size){

    //double start = omp_get_wtime();
    srand(time(0));

    #pragma omp parallel
    {

        #pragma omp single
        {
        #pragma omp task
        {
            cout<<"Matrix A"<<endl;
            //#pragma omp parallel for
            for(int i=0; i<size; i++){
                for(int j=0; j<size; j++){
                    A[i][j] = rand() % (9 - 1) + 1;
                    std::cout<< A[i][j] << " ";
                }
                std::cout << endl;
            }
            std::cout << endl;

        }

        #pragma omp task
        {
            cout<<"Matrix B"<<endl;

            //#pragma omp parallel for
            for(int i=0; i<size; i++){
                for(int j=0; j<size; j++){
                    B[i][j] = rand() % (9 - 1) + 1;
                    std::cout<< B[i][j] << " ";
                }
                std::cout << endl;
            }
            std::cout << endl;
        }

        #pragma omp task
        {
            cout<<"Matrix C"<<endl;
            int s = 0;

            //#pragma omp parallel for
            for(int i=0; i<size; i++){
                for(int j=0; j<size; j++){
                    for(int k=0; k< size; k++){
                        s = s + A[i][k] * B[k][j];
                    }
                    cout<< s <<" ";
                    s=0;
                }
                cout<<endl;
            }
        }
    }
    }

    //double end = omp_get_wtime();
     //double t = end - start;
    //cout <<"Time: "<< t << endl;
}

int main(){

    int size = 3;
    double **A, **B, **C;

    A = new double *[size];
    B = new double *[size];
    C = new double *[size];
    int i = 0;

    for(i = 0; i <size; i++){
        A[i] = new double[size];
        B[i] = new double[size];
        C[i] = new double[size];
    }

    clock_t start;
    start = clock();

    matmul(A, B, C, size);

    //std::cout << "Time: " << (std::clock() - start) / (float)(CLOCKS_PER_SEC)/1000000000 << " ns" << std::endl;
    string x;
    cin>> x;
    return 0;
}
