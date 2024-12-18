#include <stdio.h>

int main(){ 
    int arr[100];
    int n, t;
    FILE* fi;
    fi = fopen("inputm.txt", "r");

    fscanf(fi, "%d", &n);
    for (int i = 0; i < n; i++){
        fscanf(fi, "%d ", &arr[i]);
    }
    
    for (int i = 0; i < n; i += 2){
        t = arr[i];
        arr[i] = arr[i + 1];
        arr[i + 1] = t;
    }

    for (int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
}

    