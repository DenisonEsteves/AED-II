#include <stdio.h>
#include <stdlib.h>

int compara(const void *a, const void *b) {
  // Função de comparação para o qsort
  int x = *(int*)a;
  int y = *(int*)b;
  if (x < y) return -1;
  if (x > y) return 1;
  return 0;
}

int main(int argc, char *argv[]) {
  // Ler w e n do usuário
  int w, n;
  printf("Entre com w e n: ");
  scanf("%d %d", &w, &n);

  // Alocar um array de tamanho n para armazenar os frascos
  int *frascos = malloc(n * sizeof(int));
  
  // Ler os tamanhos dos frascos do usuário
  printf("Entre com os tamanhos dos frascos: ");
  for (int i = 0; i < n; i++) {
    scanf("%d", &frascos[i]);
  }

  // Ordenar o array de frascos em ordem crescente
  qsort(frascos, n, sizeof(int), compara);

  // Contar o número de frascos necessários
  int contador = 0;
  while (w > 0) {
    contador++;
    w -= frascos[--n];
  }

  // Imprimir o resultado
  printf("Número mínimo de frascos: %d\n", contador);

  // Liberar a memória alocada
  free(frascos);

  return 0;
}

/*
Provando que o algoritmo guloso está correto:

Considere um conjunto de frascos {F1, F2, ..., Fn} que usa um número menor de frascos do que a solução encontrada pelo algoritmo. Ordenemos os frascos em ordem crescente de tamanho. Se o maior frasco Fk em {F1, F2, ..., Fn} for menor ou igual ao menor frasco F1 na solução encontrada pelo algoritmo, então podemos substituir F1 por Fk e obter uma solução ainda melhor. Isso contradiz nossa suposição de que a solução de {F1, F2, ..., Fn} é a melhor possível, portanto essa solução não existe.

Se, por outro lado, o maior frasco Fk em {F1, F2, ..., Fn} for maior do que o menor frasco F1 na solução encontrada pelo algoritmo, então podemos substituir Fk por F1 e obter uma solução ainda melhor. Novamente, isso contradiz nossa suposição de que a solução de {F1, F2, ..., Fn} é a melhor possível, portanto essa solução também não existe.

Como não conseguimos encontrar nenhuma solução que use um número menor de frascos do que a solução encontrada pelo algoritmo, podemos concluir que o algoritmo está correto.
*/
