#include <stdio.h>

int main(){
    int arr[100];
    int n, t, k = 0;
    FILE * fi;
    fi = fopen("inputsort.txt", "r");

    fscanf(fi, "%d", &n);
    for (int i = 0; i < n; i++){
        fscanf(fi, "%d", &arr[i]);
    }

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n - i; j++){
            if (arr[j-1] > arr[j]){
                k++;
                t = arr[j-1];
                arr[j-1] = arr[j];
                arr[j] = t;
            }
        }
    }
    
    for (int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("%d", k);
}