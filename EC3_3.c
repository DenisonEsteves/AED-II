#include <stdio.h>
#define n 3

int V[3] = {1,2,3};
int S[n];
void escreve(int S[], int ns){
    printf("(");
    for(int i = 0; i < ns-1; i++){
        if(S[i] != 0)
            printf("%d, ", S[i]);
    }
    if(S[ns-1] != 0)
        printf("%d)\n", S[ns-1]);
    else
        printf(")\n");
}

void GeraSub (int ns, int t, int soma){
    for(int i = t; i < n; i++){
        S[ns] = V[i];
        soma = soma + V[i];
        if(soma % 2 != 0){
            escreve(S, ns+1);
        }
        if (i<n-1){
            GeraSub(ns+1, i + 1, soma);
        }
        soma = soma - V[i];
    }
}

int main(){
    GeraSub (0, 0, 0);
}
