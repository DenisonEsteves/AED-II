/*
Dado um array A com elementos a1, a2, ..., an. Suponha que mais da metade dos elementos de A 
são iguais, os quais chamaremos de maioria. Descreva um algoritmo usando o paradigma Divisão e Conquista 
para encontrar o valor desse elemento que representa a maioria dos elementos de A. Para isso, defina os 
subproblemas de seu algoritmo, identificando a entrada e a saída de seus subproblemas. Com base nessa definição, 
descreva o algoritmo que resolve o problema e apresente sua implementação (em Python, C ou C++). 
*/

#include <stdio.h>
#include <stdlib.h>

#define LENGTH 10
#define BEGIN 0
#define HALF LENGTH/2

int* searchMajorith(int[], int, int);

int main(void){
    int A[LENGTH] = {1,2,2,2,2,2,2,5,5,5};
    int* majority = searchMajorith(A, BEGIN, A[BEGIN]);

    printf("Majority: %d, with %d repetitions", majority[0], majority[1]);

    return 0;
}

int* searchMajorith(int A[], int begin, int key){
    if(begin > LENGTH - 1){
        printf("This array is not quality for this algorithm.");
        exit(1);
    }
    else{
        int repetitions = 0;
        for(int i = begin + 1; i < LENGTH; i++)
            if(A[i] == key)
                repetitions++;
        if(repetitions >= HALF){
            int* output = (int*) malloc(2*sizeof(int));
            output[0] = key;
            output[1] = repetitions;
            return output;
        }
        else{
            begin++;
            searchMajorith(A, begin, A[begin]);
        }
    }
}
