#include <stdio.h>
#include <stdbool.h>

int main(void) {
  int n;
  printf("Enter the upper limit for the prime numbers: ");
  scanf("%d", &n);
  bool prime[n + 1];
  for (int i = 2; i <= n; i++) {
    prime[i] = true;
  }
  for (int i = 2; i * i <= n; i++) {
    if (prime[i]) {
      for (int j = i * i; j <= n; j += i) {
        prime[j] = false;
      }
    }
  }
  printf("The prime numbers between 2 and %d (inclusive) are:\n", n);
  for (int i = 2; i <= n; i++) {
    if (prime[i]) {
      printf("%d ", i);
    }
  }
  printf("\n");
  return 0;
}