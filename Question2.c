#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define PASSWORD_LENGTH 8

int main(void) {
  char password[PASSWORD_LENGTH + 1];
  const char *charset = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()_+-=[]{}|;':,.<>?";
  bool has_lower = false, has_upper = false, has_digit = false, has_symbol = false;
  srand(time(NULL));
  for (int i = 0; i < PASSWORD_LENGTH; i++) {
    int index = rand() % (int) (sizeof charset - 1);
    char c = charset[index];
    if (c >= 'a' && c <= 'z') {
      has_lower = true;
    } else if (c >= 'A' && c <= 'Z') {
      has_upper = true;
    } else if (c >= '0' && c <= '9') {
      has_digit = true;
    } else {
      has_symbol = true;
    }
    password[i] = c;
  }
  if (!has_lower) {
    password[0] = 'a';
  }
  if (!has_upper) {
    password[1] = 'A';
  }
  if (!has_digit) {
    password[2] = '0';
  }
  if (!has_symbol) {
    password[3] = '!';
  }
  password[PASSWORD_LENGTH] = '\0';
  printf("Your random one-time password is: %s\n", password);
  return 0;
}
