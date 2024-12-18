#include <stdio.h>

int main(){
    int arr[100];
    int n, t, r, p = -100, k = 0;
    FILE * fi;
    fi = fopen("inputsort.txt", "r");

    fscanf(fi, "%d", &r);

    fscanf(fi, "%d", &n);
    for (int i = 0; i < n; i++){
        fscanf(fi, "%d", &arr[i]);
    }
    
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n - i; j++){
            if (arr[j - 1] > arr[j]){
                t = arr[j - 1];
                arr[j - 1] = arr[j];
                arr[j] = t;
            }
        }
    }

    for (int i = 0; i < n; i++){
        if ((arr[i] > r) && (arr[i] - p >= 3)){
            p = arr[i];
            k++;
        }
    }

    printf("%d", k);

}