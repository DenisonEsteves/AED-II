#include <stdio.h>

#define N 20
#define TRUE 1
#define FALSE 0

int S[N] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};

int sum_between_one_to_N_equals(int);

int main(void){
    if(sum_between_one_to_N_equals(10))
        printf("True.");
    else
        printf("False.");
    return 0;
}

int sum_between_one_to_N_equals(int key){
    for(int begin = 0; begin < N; begin++){
        for(int end = begin, sum = 0; end <= N; end++){
            sum += S[end];
            if(sum == key)
                return TRUE;
        }
    }
    return FALSE;
}