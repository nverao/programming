#include <stdio.h>

int main(){
    int arr1[100], arr2[100];
    int n, t;
    FILE * fi;
    fi = fopen("inputsort.txt", "r");

    fscanf(fi, "%d", &n);
    for (int i = 0; i < n; i++){
        fscanf(fi, "%d %d", &arr1[i], &arr2[i]);
    }
    
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n - i; j++){
            if (arr2[j - 1] < arr2[j]){
                t = arr2[j - 1];
                arr2[j - 1] = arr2[j];
                arr2[j] = t;
                t = arr1[j - 1];
                arr1[j - 1] = arr1[j];
                arr1[j] = t;
            }
        }
    }

    for (int i = 0; i < n; i++){
        printf("%d %d \n", arr1[i], arr2[i]);
    }

}