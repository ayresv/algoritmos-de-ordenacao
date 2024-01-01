#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#define TAMANHO_VETOR 10000

// FUNCOES AUXILIARES

void merge(int array[], int size)   
{
    int mid,i,j,k;
    int *temp;
    temp = (int*) malloc(size*sizeof(int));
    if (temp == NULL)
        exit(1);
    mid = size/2;
    i = 0;
    j = mid;
    k = 0;
    while (i < mid && j < size) {
        if (array[i] < array[j]) {
            temp[k] = array[i];
            ++i;
        }
        else {
            temp[k] = array[j];
            ++j;
        }
        ++k;
    }
    if (i == mid) {
        while (j < size) {
            temp[k] = array[j];
            ++j;
            ++k;
        }
    }
    else {
        while (i < mid) {
            temp[k] = array[i];
            ++i;
            ++k;
        }
    }
    for (i = 0; i < size; ++i)
        array[i] = temp[i];
    free(temp);
}

void preencherCrescente(int arr[], int n) 
{
    for (int i = 0; i < n; i++) {
        *(arr + i) = i;
    }
}

void preencherDecrescente(int arr[], int n) 
{
    for (int i = 0; i < n; i++) {
        *(arr + i) = n - i;
    }
}

void preencherAleatorio(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++) {
        arr[i] = rand();
    }
}



// FUNCOES SORT

void bubbleSort(int array[], int length)
{
    int i,j;
        for(i = length - 1; i > 0; i--) {
            for(j = 0; j < i; j++) {
                if(array[j] > array[j+1]) {
                    int temp;
                    temp = array[j];
                    array[j] = array[j+1];
                    array[j+1] = temp;
                }
            }
        }
}

void quickSort(int array[], int start, int end)
{
    int i,j,pivo,aux;
    i = start;
    j = end - 1;
    pivo = array[start];
    while(i <= j) {
        while(array[i] < pivo && i < end) i++;
        while(array[j] > pivo && j > start) j--;

        if(i <= j) {
            aux = array[i];
            array[i] = array[j];
            array[j] = aux;
            i++;
            j--;
        }
    }
    if(j > start)
        quickSort(array, start, j+1);
    if(i < end)
        quickSort(array, i, end);
}

void insertionSort(int array[], int length)
{
    int temp,j;
    
    for(int i = 1; i < length; i++) {
        temp = array[i];
        j = i - 1;
        while(j >= 0 && temp < array[j]) {
            array[j+1] = array[j];
            j--;
        }
        array[j+1] = temp;
    }
}

void selectionSort(int array[], int length)
{
    int min, temp;

    for(int i = 0; i < length; i++) {
        min = i;
        for(int j = i + 1; j < length; j++) {
            if(array[j] < array[min]) 
                min = j;
        }
        if(array[i] != array[min]) {
            temp = array[i];
            array[i] = array[min];
            array[min] = temp;
        }
    }
}

void mergeSort(int array[], int size) 
{
    int mid;

    if(size > 1) {
        mid = size/2;
        mergeSort(array, mid);
        mergeSort(array + mid, size - mid);
        merge(array, size);
    }
}

void heapSort(int a[], int n) 
{
    int i = n / 2, pai, filho, t;
    while(1) {
        if (i > 0) {
            i--;
            t = a[i];
        } else {
            n--;
            if (n <= 0) return;
            t = a[n];
            a[n] = a[0];
        }
        pai = i;
        filho = i * 2 + 1;
        while (filho < n) {
            if ((filho + 1 < n)  &&  (a[filho + 1] > a[filho]))
                filho++;
            if (a[filho] > t) {
                a[pai] = a[filho];
                pai = filho;
                filho = pai * 2 + 1;
            } else {
                break;
            }
        }
        a[pai] = t;
    }
}

int main() {
    int arr[TAMANHO_VETOR];
    double start, stop, elapsed; // variaveis para medir o tempo
    
    printf("=============== BUBBLE SORT ================ \n");

    preencherCrescente(arr, TAMANHO_VETOR);
    start = (double) clock() / CLOCKS_PER_SEC;
    bubbleSort(arr, TAMANHO_VETOR);
    stop = (double) clock() / CLOCKS_PER_SEC;
    elapsed = stop - start;
    printf("\nTempo total em segundos vetor preenchido crescente: %f\n", elapsed);
    
    preencherDecrescente(arr, TAMANHO_VETOR);
    start = (double) clock() / CLOCKS_PER_SEC;
    bubbleSort(arr, TAMANHO_VETOR);
    stop = (double) clock() / CLOCKS_PER_SEC;
    elapsed = stop - start;
    printf("\nTempo total em segundos vetor preenchido decrescente: %f\n", elapsed);
    
    preencherAleatorio(arr, TAMANHO_VETOR);
    start = (double) clock() / CLOCKS_PER_SEC;
    bubbleSort(arr, TAMANHO_VETOR);
    stop = (double) clock() / CLOCKS_PER_SEC;
    elapsed = stop - start;
    printf("\nTempo total em segundos vetor preenchido aleatoriamente: %f\n", elapsed);



    printf("=============== SELECTION SORT ================ \n");
    
    preencherCrescente(arr, TAMANHO_VETOR);
    start = (double) clock() / CLOCKS_PER_SEC;
    selectionSort(arr, TAMANHO_VETOR);
    stop = (double) clock() / CLOCKS_PER_SEC;
    elapsed = stop - start;
    printf("\nTempo total em segundos vetor preenchido crescente: %f\n", elapsed);
    
    preencherDecrescente(arr, TAMANHO_VETOR);
    start = (double) clock() / CLOCKS_PER_SEC;
    selectionSort(arr, TAMANHO_VETOR);
    stop = (double) clock() / CLOCKS_PER_SEC;
    elapsed = stop - start;
    printf("\nTempo total em segundos vetor preenchido decrescente: %f\n", elapsed);
    
    preencherAleatorio(arr, TAMANHO_VETOR);
    start = (double) clock() / CLOCKS_PER_SEC;
    selectionSort(arr, TAMANHO_VETOR);
    stop = (double) clock() / CLOCKS_PER_SEC;
    elapsed = stop - start;
    printf("\nTempo total em segundos vetor preenchido aleatoriamente: %f\n", elapsed);


    
    printf("================ INSERTION SORT =============== \n");
    
    preencherCrescente(arr, TAMANHO_VETOR);
    start = (double) clock() / CLOCKS_PER_SEC;
    insertionSort(arr, TAMANHO_VETOR);
    stop = (double) clock() / CLOCKS_PER_SEC;
    elapsed = stop - start;
    printf("\nTempo total em segundos vetor preenchido crescente: %f\n", elapsed);
    
    preencherDecrescente(arr, TAMANHO_VETOR);
    start = (double) clock() / CLOCKS_PER_SEC;
    insertionSort(arr, TAMANHO_VETOR);
    stop = (double) clock() / CLOCKS_PER_SEC;
    elapsed = stop - start;
    printf("\nTempo total em segundos vetor preenchido decrescente: %f\n", elapsed);
    
    preencherAleatorio(arr, TAMANHO_VETOR);
    start = (double) clock() / CLOCKS_PER_SEC;
    insertionSort(arr, TAMANHO_VETOR);
    stop = (double) clock() / CLOCKS_PER_SEC;
    elapsed = stop - start;
    printf("\nTempo total em segundos vetor preenchido aleatoriamente: %f\n", elapsed);



    printf("================ QUICK SORT ================== \n");
    
    preencherCrescente(arr, TAMANHO_VETOR);
    start = (double) clock() / CLOCKS_PER_SEC;
    quickSort(arr, 0, TAMANHO_VETOR);
    stop = (double) clock() / CLOCKS_PER_SEC;
    elapsed = stop - start;
    printf("\nTempo total em segundos vetor preenchido crescente: %f\n", elapsed);
    
    preencherDecrescente(arr, TAMANHO_VETOR);
    start = (double) clock() / CLOCKS_PER_SEC;
    quickSort(arr, 0, TAMANHO_VETOR);
    stop = (double) clock() / CLOCKS_PER_SEC;
    elapsed = stop - start;
    printf("\nTempo total em segundos vetor preenchido decrescente: %f\n", elapsed);
    
    preencherAleatorio(arr, TAMANHO_VETOR);
    start = (double) clock() / CLOCKS_PER_SEC;
    quickSort(arr, 0, TAMANHO_VETOR);
    stop = (double) clock() / CLOCKS_PER_SEC;
    elapsed = stop - start;
    printf("\nTempo total em segundos vetor preenchido aleatoriamente: %f\n", elapsed);


    
    printf("============ MERGE SORT ======================= \n");
    
    preencherCrescente(arr, TAMANHO_VETOR);
    start = (double) clock() / CLOCKS_PER_SEC;
    mergeSort(arr, TAMANHO_VETOR);
    stop = (double) clock() / CLOCKS_PER_SEC;
    elapsed = stop - start;
    printf("\nTempo total em segundos vetor preenchido crescente: %f\n", elapsed);
    
    preencherDecrescente(arr, TAMANHO_VETOR);
    start = (double) clock() / CLOCKS_PER_SEC;
    mergeSort(arr, TAMANHO_VETOR);
    stop = (double) clock() / CLOCKS_PER_SEC;
    elapsed = stop - start;
    printf("\nTempo total em segundos vetor preenchido decrescente: %f\n", elapsed);
    
    preencherAleatorio(arr, TAMANHO_VETOR);
    start = (double) clock() / CLOCKS_PER_SEC;
    mergeSort(arr, TAMANHO_VETOR);
    stop = (double) clock() / CLOCKS_PER_SEC;
    elapsed = stop - start;
    printf("\nTempo total em segundos vetor preenchido aleatoriamente: %f\n", elapsed);


    
    printf("============ HEAP SORT ======================== \n");

    preencherCrescente(arr, TAMANHO_VETOR);
    start = (double) clock() / CLOCKS_PER_SEC;
    heapSort(arr, TAMANHO_VETOR);
    stop = (double) clock() / CLOCKS_PER_SEC;
    elapsed = stop - start;
    printf("\nTempo total em segundos vetor preenchido crescente: %f\n", elapsed);
    
    preencherDecrescente(arr, TAMANHO_VETOR);
    start = (double) clock() / CLOCKS_PER_SEC;
    heapSort(arr, TAMANHO_VETOR);
    stop = (double) clock() / CLOCKS_PER_SEC;
    elapsed = stop - start;
    printf("\nTempo total em segundos vetor preenchido decrescente: %f\n", elapsed);
    
    preencherAleatorio(arr, TAMANHO_VETOR);
    start = (double) clock() / CLOCKS_PER_SEC;
    heapSort(arr, TAMANHO_VETOR);
    stop = (double) clock() / CLOCKS_PER_SEC;
    elapsed = stop - start;
    printf("\nTempo total em segundos vetor preenchido aleatoriamente: %f\n", elapsed);



    return 0;
}
