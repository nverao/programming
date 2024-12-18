#include <stdio.h>
#include <math.h>

int main(){
    FILE* fi;
    fi = fopen("input1.txt", "r");
    int  sum = 0, e1, e2;
    int count = 0, flag = 0;

    fscanf(fi, "%d", &e1);
    while (fscanf(fi, "%d", &e2) == 1){
        if ((e2 > e1) && ( flag == 0)) {
            flag = 1;
            if (e1 % 2 == 0){
                sum += e1;
            }
        }
        if ((e2 > e1) && ( e2 % 2 == 0 )){
            sum += e2;
        }
        if (e2 <= e1){
            flag = 0;
        }
        e1 = e2;
    }
    printf("%d", sum);
}