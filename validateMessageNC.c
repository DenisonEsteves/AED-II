//CÓDIGO NÃO FINALIZADO!!!
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define ERROR '-1'


char messageValidator(int nPattern, char* message, char* pattern){
    int LEN_PATTERN = strlen(pattern), LEN_MESSAGE = strlen(message);
    
    if(nPattern > 1000 || LEN_MESSAGE > 1000 || LEN_PATTERN > 100){
        printf("Erro: a função deve receber como entrada um inteiro i (1 <= i <= 10^3) que representa o número de vezes que o padrão deve ocorrer, uma string na qual o padrão deve ser encontrado com até 10^3 caracteres, seguida do padrão a ser buscado com até 10^2 caracteres.\n");
        return ERROR;
    }
    int memory[3+1][21+1] = {};
    char patternRepeated[5] = {""};
    
    for(int i = 0; i < nPattern; i++) strcat(patternRepeated, pattern);
    for(int i = 1; i < LEN_PATTERN*nPattern + 1; i++){
      for(int j = 1; j < LEN_MESSAGE + 1; j++){
        if(patternRepeated[i] == message[j])
          memory[i][j] = 1 + memory[i-1][j-1];
        else
          memory[i][j] = max(memory[i-1][j],memory[i][j-1]);
      }
    }
    int longestCommumSubsequence = memory[4][21];
    if(longestCommumSubsequence == LEN_PATTERN*nPattern)
      return 'Y';
    else
      return 'N';
}

int max(int a, int b){
    int result = a > b ? a : b;
    return result;
}

int main(){
    char message[] = "some kind of text ok";
    char pattern[] = "ok";
    int nPattern = 2;
    printf("%c\n", messageValidator(nPattern, message, pattern));
    return 0;
}
