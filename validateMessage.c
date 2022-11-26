/*
Proponha e implemente um algoritmo (usando C, C++ ou Python) que ajude Bob a identificar se as 
mensagens recebidas foram enviadas por Alice. Seu programa deve receber como entrada um inteiro 
i (1 <= i <= 10^3) que representa o número de vezes que o padrão deve ocorrer, uma string na qual 
o padrão deve ser encontrado com até 10^3 caracteres, seguida do padrão a ser buscado com até 10^2 caracteres. 
A saída do seu programa deve ser: ‘Y’, se o padrão foi encontrado i vezes na string fornecida; ‘N’, caso contrário.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char validateMessage(char*,char*,int);

int main(){
    int patternNumber = 10;
    char* pattern = "ok";
    char* message = "Lorem Ipsum is simply dummy text of the printing and typesetting industry ok. Lorem Ipsum has been the industry's standard dummy text ever since the 1500s ok, when an unknown printer took a galley of type and scrambled it to make a type specimen book ok. It has survived not only five centuries ok, but also the leap into electronic typesetting ok, remaining essentially unchanged ok. It was popularised in the 1960s with the release of Letraset sheets containing Lorem Ipsum passages ok, and more recently with desktop publishing software like Aldus PageMaker including versions of Lorem Ipsum ok.";
    printf("%c\n", validateMessage(message, pattern, patternNumber));

    return 0;
}

char validateMessage(char* message, char* pattern, int patternNumber){
    int LEN_MESSAGE = strlen(message);
    int LEN_PATTERN = strlen(pattern);
    char* magnifier = (char*) malloc(LEN_PATTERN*sizeof(char));

    for(int i = 0, externSimilarities = 0; i < LEN_MESSAGE - LEN_PATTERN; i++){
        for(int j = 0, internSimilarities = 0; j < LEN_PATTERN; j++){
            magnifier[j] = message[i+j];
            if(magnifier[j] == pattern[j])
                internSimilarities++;
            if(internSimilarities == LEN_PATTERN)
                externSimilarities++;
        }
        if(externSimilarities == patternNumber)
           return 'Y';
    }
    return 'N';
}
