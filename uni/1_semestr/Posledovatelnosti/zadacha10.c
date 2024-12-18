#include <stdio.h>

int avarge(FILE *fi, int *avr);
int avarge(FILE *fi, int *avr){
  int a, b, F, k = 1, len = 1;

  int  e1, e2;
  int count = 1;

  F = fscanf(fi, "%d", &e1);
  if (F == EOF) {
    return 2;
  }
  while (1){
    F = fscanf(fi, "%d", &e2);
    if (F == EOF) {
      break;
    } else if (F != 1) {
      return 1;
    }
    if ( e2 > e1){
        count++;
    }
    else if (e1 > e2) {
      return 1;
    }
    len++;
    e1 = e2;
  }
  if (len < 2)
    return 2;
  *avr = count;
  return 0;
}

int main(void) {
  FILE *fi, *o;
  int s, avr;
  fi = fopen("input10.txt", "r");

  if (!fi) {
    fprintf(stderr, "Can't opne file 'input.txt' \n");
    return -1;
  }

  s = avarge(fi, &avr);

  if (s) {
    switch (s) {
    case 1:
      fprintf(stderr, "Wrong data in the input file.\n");
      break;
    case 2:
      fprintf(stderr, "The input file is empty.\n");
    }
    return -1;
  }

  fclose(fi);
  o = fopen("output10.txt", "w");

  if (!o) {
    fprintf(stderr, "Can't open file 'output.txt'.\n");
    return -1;
  }

  fprintf(o, "%d\n", avr);

  return 0;
}