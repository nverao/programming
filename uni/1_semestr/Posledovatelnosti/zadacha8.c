#include <stdio.h>
#include <math.h>

int main(){
    FILE* fi;
    fi = fopen("input1.txt", "r");
    float e1, e2, EPS = 0.0000001 ;
    int flag = 1;

    fscanf(fi, "%f", &e1);
    while (fscanf(fi, "%f", &e2) == 1){
        printf("%f %f\n", e1, e2);
        if (( e1 > e2) || ( fabs(e1 - e2) <=EPS )){
            flag = 0;
            break;
        } 
        e1 = e2;
    } 
    /*if (flag == 1) printf("YES");
    else printf("NO");*/
    flag == 1 ? printf("YES") : printf("NO") ;






}