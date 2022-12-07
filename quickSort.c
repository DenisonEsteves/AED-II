//Implementação do Quick Sort em C

#include <stdio.h>

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int array[], int begin, int end){
    int pivot = array[end], swapIndex = (begin - 1);
  
    for(int currentIndex = begin; currentIndex <= end - 1; currentIndex++){
        if(array[currentIndex] < pivot){
            swapIndex++;
            swap(&array[swapIndex], &array[currentIndex]);
        }
    }
  
    swap(&array[swapIndex + 1], &array[end]);
  
    return (swapIndex+1);
}

void quickSort(int array[], int begin, int end){
    if(begin < end){
        int pivot = partition(array, begin, end);
        quickSort(array, begin, pivot - 1);
        quickSort(array, pivot + 1, end);
    }
}

void printArray(int array[], int size){
	for (int i = 0; i < size; i++)
		printf("%d ", array[i]);
	printf("\n");
}

int main(){
	int array[] = {10, 7, 8, 9, 1, 5, -1000, 1000};
	int n = sizeof(array) / sizeof(array[0]);
  
	quickSort(array, 0, n - 1);
  
	printf("Sorted array: \n");
  
	printArray(array, n);
  
	return 0;
}
