#include <stdio.h>
#include <string.h>

#define MAX_LEN 100

// Função que calcula o LCS das sequências X[0..m-1] e Y[0..n-1]
int LCS(char X[], char Y[], int m, int n)
{
    int L[MAX_LEN+1][MAX_LEN+1];  // matriz para armazenar os resultados da tabela de programação dinâmica

    // Preenche a tabela de programação dinâmica
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0)
                L[i][j] = 0;
            else if (X[i-1] == Y[j-1])
                L[i][j] = L[i-1][j-1] + 1;
            else
                L[i][j] = max(L[i-1][j], L[i][j-1]);
        }
    }

    // A resposta é o último elemento da tabela de programação dinâmica
    return L[m][n];
}

// Função para encontrar o máximo de dois números inteiros
int max(int a, int b)
{
    return (a > b) ? a : b;
}

int main()
{
    char X[] = "AGGTAB";
    char Y[] = "GXTXAYB";
    int m = strlen(X);
    int n = strlen(Y);
    printf("Tamanho do LCS = %d\n", LCS(X, Y, m, n));
    return 0;
}
