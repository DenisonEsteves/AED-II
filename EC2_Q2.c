//Enunciado: https://dontpad.com/UAS89CY

#include <stdio.h>
#include <string.h>

char messageValidator(int nPattern, char* message, char* pattern){
    int LEN_PATTERN = strlen(pattern), LEN_MESSAGE = strlen(message), LEN_PATTERN_CONCATENED = LEN_PATTERN*nPattern;

    if(nPattern > 1000 || LEN_MESSAGE > 1000 || LEN_PATTERN > 100){
        printf("Erro: a função deve receber como entrada um inteiro i (1 <= i <= 10^3) que representa o número de vezes que o padrão deve ocorrer, uma string na qual o padrão deve ser encontrado com até 10^3 caracteres, seguida do padrão a ser buscado com até 10^2 caracteres.\n");
        return;
    }
    
    int memory[LEN_PATTERN_CONCATENED + 1][LEN_MESSAGE + 1];
    memset(memory, 0, (LEN_PATTERN_CONCATENED + 1)*(LEN_MESSAGE + 1)*sizeof(int) );

    char PatternConcatened[LEN_PATTERN_CONCATENED + 1];
    memset(PatternConcatened, 0, (LEN_PATTERN_CONCATENED + 1)*sizeof(char) );

    for(int i = 0; i < nPattern; i++) strcat(PatternConcatened, pattern);

    for(int i = 1; i < LEN_PATTERN_CONCATENED + 1; i++){ for(int j = 1; j < LEN_MESSAGE + 1; j++){
        if(PatternConcatened[i - 1] == message[j - 1])
          memory[i][j] = 1 + memory[i-1][j-1];
        else
          memory[i][j] = memory[i - 1][j] > memory[i][j-1] ? memory[i - 1][j] : memory[i][j-1];
      }
    }
    
    int longestCommumSubsequence = memory[LEN_PATTERN_CONCATENED][LEN_MESSAGE];
    
    if(longestCommumSubsequence == LEN_PATTERN_CONCATENED)
        return 'Y';
    else
        return 'N';
}

int main(){
    char message[] = "SOME KIND OF TEXT OK";
    char pattern[] = "OK";
    int nPattern = 2;
    
    printf("%c\n", messageValidator(nPattern, message, pattern));
    
    return 0;
}
