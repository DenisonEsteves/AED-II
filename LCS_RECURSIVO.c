#include <stdio.h>
#include <string.h>

#define MAX_LEN 100

// Função recursiva para calcular LCS
int LCS(char* X, char* Y, int m, int n) {
  if (m == 0 || n == 0)
    return 0;
  if (X[m-1] == Y[n-1])
    return 1 + LCS(X, Y, m-1, n-1);
  else
    return max(LCS(X, Y, m, n-1), LCS(X, Y, m-1, n));
}

int main() {
  char X[MAX_LEN+1];
  char Y[MAX_LEN+1];

  printf("Digite a primeira string: ");
  scanf("%s", X);
  printf("Digite a segunda string: ");
  scanf("%s", Y);

  int m = strlen(X);
  int n = strlen(Y);

  printf("O tamanho da LCS é %d\n", LCS(X, Y, m, n));

  return 0;
}
