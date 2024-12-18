#include <stdio.h>

int zadacha(FILE* fi, int *avr){
    int F, len = 1;
    int  e1, e2;
    int count = 0, flag = 0;

    F = fscanf(fi, "%d", &e1);
    if (F == EOF){
        return 2;
    }
    if (F != 1){
        return 1;
    }
    while (1){  
        F = fscanf(fi, "%d", &e2);
        if (F != 1) {
            if (F == EOF){
            break;
            }
            if ((F == 0) || (len < 2)){
                return 1;
            }
        }
        len++;
        if ((e2 > e1) && ( flag == 0)) {
            flag = 1;
            count++;
        }
        if (e2 <= e1){
            flag = 0;
        }
        e1 = e2;
    }

    *avr = count;
    return 0;
}

int main(void){
    FILE *fi, *o;
    int s, avr;
    fi = fopen("input17.txt", "r");
    if (!fi){ 
        fprintf(stderr,"Can't open file 'input.txt' \n"); 
        return -1;
    }s = zadacha(fi, &avr); 
            
    if (s){ 
        switch (s){ 
        case 1: 
        fprintf(stderr, "Wrong data in the input file.\n"); 
        break; 
        case 2: 
        fprintf(stderr, "The input file is empty.\n"); 
        }
        return -1; 
        } 
            
        fclose(fi); 
        o = fopen("output17.txt", "w"); 
            
        if (!o) { 
            fprintf(stderr, "Can't open file 'output.txt'.\n"); 
            return -1; 
        } 
            
        fprintf(o,"%d\n", avr); 
            
        return 0; 
    }

        