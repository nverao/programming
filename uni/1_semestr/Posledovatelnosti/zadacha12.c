#include <stdio.h>
#include <math.h>

int main(){
    FILE* fi;
    fi = fopen("input1.txt", "r");
    float  e1, e2, max;
    int maxi =0 , k = 0;

    fscanf(fi, "%f", &max);
    while (fscanf(fi, "%f", &e1) == 1){
        k++;
        if (e1 > max){
            max = e1;
            maxi = k;
            printf("%f %d\n", max, k);
        } 
    }
    printf("%f %d", max, maxi); 
}