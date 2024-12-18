#include <stdio.h>
#include <math.h>

int main(){
    FILE* fi;
    fi = fopen("input1.txt", "r");
    float x, k, EPS = 0.0000001 ;
    int found = 0;

    fscanf(fi, "%f", &x);
    while (fscanf(fi, "%f", &k) == 1){
        //printf("%d", k);
        if (fabs(k-x) <= EPS){
            found = 1;
            break;
        }
    }

    if (found == 1) printf("YES"); 
    else printf("NO");

}

