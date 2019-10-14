// Implementing Quicksort in C. 
// Works with user defined arrays. 

#include<stdio.h>
#include<stdlib.h>

int* allocate(int* ptr, int size);
void quicksort(int arr[], int low, int high);
void swap(int* i, int* j);
int partition(int arr[], int low, int high);
void printList(int arr[], int size);
void insert(int* arr, int size);

int main() {
    int size;
    printf("Please Insert the size of the array: ");
    scanf("%d", &size);

    int* arr = allocate(arr, size);

    insert(arr, size);

    quicksort(arr, 0, size-1);
    printList(arr, size);

    free(arr);
    return 0;
}

int* allocate(int* ptr, int size){ // Allocates memory to an array. 
    ptr = (int*)malloc(size*sizeof(int));
    if(ptr == NULL){
        printf("Allocation Unsuccessful\n");
        exit(0);
        return NULL;
    }
    printf("Allocation successful\n");
    return ptr;
}

void insert(int* arr, int size){ // Insert function for the array. 
    int num;
    for(int i = 0; i < size ; i++){
        printf("Please insert a number: ");
        scanf("%d", &num);
        *(arr + i) = num;
    }
}

void printList(int arr[], int size){ // Prints all items in sorted array, removing repeating items. 
    // Check for repetition first. 
    int* newArr = (int*)malloc(size*sizeof(int));
    if(newArr == NULL){
        printf("Allocation unsuccessful in printList");
        exit(0);
    }
    printf("Allocation Successful in printList\n");

    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            if(arr[i] == newArr[j]){
                break;
            }else{
                newArr[j] = arr[i];
                printf("%d\n", arr[i]);
                break;
            }
        }
    }
    free(newArr);
}

void swap(int* i, int* j){
    int temp = *i;
    *i = *j;
    *j = temp;
}

void quicksort(int arr[], int low, int high){ // Quicksort algorithm, choosing pivot to be the last element. 
    if(low < high){
        int pi = partition(arr, low, high);

        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
    printf("Finished sorting\n");
}

int partition(int arr[], int low, int high){
    int pivot = arr[high];

    int i = (low - 1);

    for (int j = low; j < high; j++){
        if(arr[j] < pivot){
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i+1], &arr[high]);
    return(i+1);
}