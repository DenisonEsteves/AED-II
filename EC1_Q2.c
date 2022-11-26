/*
Considere um vetor contendo somente os caracteres "V" e "F", no qual todos os "V"s 
são apresentados nas primeiras posições seguidos de todos os "F"s. Descreva um algoritmo 
e sua implementação (em Python, C ou C++), usando o paradigma Divisão e Conquista, que apresente 
como saída o número de "F"s existentes no vetor recebido. Por exemplo, se o algoritmo receber 
vetor = ["V", "V", "V", "V", "F", "F", "F"] sua saída será 3, 
já se receber vetor = ["V", "V", "V"] sua saída será 0.
*/

#include <stdio.h>

#define LENGTH 7

int fNumber();
char array[LENGTH] = "VVVVFFF";

int main(void){
    printf("F's number: %d", fNumber());
    return 0;
}

int fNumber(){
    for(int i = 0; i < LENGTH; i++)
        if(array[i] == 'F')
            return LENGTH - i;
    return 0;
}
