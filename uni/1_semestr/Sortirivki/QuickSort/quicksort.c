#include <stdio.h>
#include <stdlib.h>

void quickSort(int *a, int left, int right) {
    if (left > right) return;
    int i = left;
    int j = right;
    int p = a[(left+right)/2];
    while(i <= j) {
        while(a[i] < p) i++;
        while(a[j] > p) j--;
        int t = a[i];
        a[i] = a[j];
        a[j] = t;
        i++;
        j--;
    }
    quickSort(a, left, j);
    quickSort(a, i, right);
}



int main() {

    FILE *fi;
    fi = fopen("input.txt", "r");
    double n, l, r, m;
    fscanf(fi, "%lf", &n); // 2
    l = 0;
    r = n;
    while(r-l > 0.000001) {
        m = (r+l)/2;
        if (m*m > n) {
            r = m;
        } else {
            l = m;
        }
    }
    printf("%lf", l);
    fclose(fi);
}