#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define N 10

int main() {
  srand(time(0));

  int X[2][N], Y[2][N];
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < N; j++) {
      X[i][j] = rand();
      Y[i][j] = rand();
    }
  }
  long double answer = 0;
  for (int i = 0; i < N; i++) {
    long double x_diff = (long double) X[1][i] - (long double) X[0][i];
    long double y_diff = (long double) Y[1][i] - (long double) Y[0][i];
    answer += sqrt(fabs(x_diff * x_diff - y_diff * y_diff));
  }
  answer /= N;
  printf("The answer of the equation is %Lf\n", answer);
  return 0;
}
