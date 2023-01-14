/*
Questão 1: Implementar um programa de Backtracking para gerar as 100 primeiras configurações para:
AR(100,3) = arranjos de 100 elementos com repetição, 3 a 3.
*/
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define CONFIGURATIONS_LIMIT 100
#define ELEMENTS_LIMIT 100
#define REPETITIONS_LIMIT 3

int CONFIGURATIONS_NUMBER = 0;
bool memory[ELEMENTS_LIMIT][ELEMENTS_LIMIT][ELEMENTS_LIMIT];

void backtracking(int configuration[], int index){
    if(CONFIGURATIONS_NUMBER == CONFIGURATIONS_LIMIT){
        return;
    }
    else if(index == REPETITIONS_LIMIT){
        if(!memory[configuration[0]][configuration[1]][configuration[2]]){
            print_configuration(configuration);
            memory[configuration[0]][configuration[1]][configuration[2]] = true;
            CONFIGURATIONS_NUMBER++;
        }
    }
    else{
        for(int element = 0; element < ELEMENTS_LIMIT; element++){
            configuration[index] = element;
            backtracking(configuration, index + 1);
        }
    }
}

void print_configuration(int configuration[]){
    printf("(");
    for(int i = 0; i <= REPETITIONS_LIMIT - 2; i++){
        printf("%d, ", configuration[i]);
    }
    printf("%d)\n", configuration[REPETITIONS_LIMIT - 1]);
}

int main(void){
    int configuration[REPETITIONS_LIMIT];
    memset(memory, false, sizeof(memory));
    backtracking(configuration, 0);
    return 0;
}
