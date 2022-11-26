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
