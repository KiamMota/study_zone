
// int main() {
//   int arr[8];
//   int size = 7;
//   printf("array de %i de tamanho \n", size);
//   int metade = size / 2;
//   int esquerda = metade;
//   int direita = size - metade;
//   int n1 = metade - esquerda + 1;

//   printf("metade: %d \n", metade);
//   printf("esquerda: %d \n", esquerda);
//   printf("direita: %d \n", direita);
//   printf("n1 %d \n", n1);
  
// }

#include <stdio.h>

 void merge(int arr[], int left, int mid, int right) {
    /* n1 subtrai o valor do meio pelo do left e adiciona mais 1 (c é zero-based) */
    int n1 = mid - left + 1;
    /* n2 a lógica é direita menos o meio, então se dir = 5 e meio = 5, dir = 0; */
    int n2 = right - mid;
    int L[n1], R[n2];

    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int main() {

    
    /* faz um array de inteiros com x elementos */  
    int arr[] = {38, 27, 43, 3, 9, 82, 10};
    /* aqui ele faz algo interessante: ele faz um sizeof do arr que retorna o tamahno do array em bytes
    depois, divide pelo tamanho de um elemento, retornado em bytes, se o array tem x elementos do tipo inteiro:
    tamanho = 4 / sizeof(x[0]); */
    int n = sizeof(arr) / sizeof(arr[0]);

    /*lança pra função: o merge sort*/
    mergeSort(arr, 0, n - 1);
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");
    return 0;
}
