#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main(){
    srand(time(0));

    const int ARRAY_SIZE = 10;
    int A[ARRAY_SIZE];
    for(int i = 0; i < ARRAY_SIZE; i++){
        A[i] = rand();
    }

    double mean = 0;
    for(int i = 0; i < ARRAY_SIZE; i++){
        mean += A[i];
    }
    mean /= ARRAY_SIZE;

    double variance = 0;
    for(int i = 0; i < ARRAY_SIZE; i++){
        variance += pow(A[i] - mean, 2);
    }
    variance /= ARRAY_SIZE;

    double stddev = sqrt(variance);

    printf("The mean value is %f\nThe variance value is %f\nThe standard deviation value is %f\n", mean, variance, stddev);

    return 0;
}
