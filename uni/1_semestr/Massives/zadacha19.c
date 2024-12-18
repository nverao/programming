#include <stdio.h>

int main(){
    int arr[100];
    int L= -1, M, n, x, t;
    FILE * fi;
    fi = fopen("inpuhw6.txt", "r");

    fscanf(fi, "%d", &n);
    for (int i = 0; i < n; i++){
        fscanf(fi, "%d", &arr[i]);
    }

    fscanf(fi, "%d", &x);

    int R = n;
    while (R - L > 1) {
        int M = (L + R) / 2;
        if (x > arr[M]) {
            L = M;
        } else {
            R = M;
        } 
    }
    arr[n] = x;
    for (int i = n; i > R; i--){
        t = arr[i];
        arr[i] = arr[i-1];
        arr[i-1] = t;
    }
    
    for (int i = 0; i < n+1; i++){
        printf("%d ", arr[i]);
    }

}
    