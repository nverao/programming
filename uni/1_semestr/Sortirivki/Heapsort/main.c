#include <stdio.h>

void add(int *heap, int *heap_n, int x) {
    heap[*heap_n] = x;
    int current = *heap_n;
    int parent = *heap_n / 2;
    printf("%d %d %d\n", *heap_n, x, parent);
    while (parent >= 1 && (heap[current] < heap[parent])) {
        int t;
        t = heap[current];
        heap[current] = heap[parent];
        heap[parent] = t;
        current /= 2;
        parent /= 2;
    }
    (*heap_n)++;
}


int delete(int *heap, int *heap_n) {
    printf("%d\n", *heap_n);
    for (int i = 1; i < *heap_n; i++) {
        printf("%d ", heap[i]);
    }
    printf("\n");
    if (*heap_n >= 2) {
        int return_value = heap[1];
        heap[1] = heap[*heap_n];
        int curr = 1;
        while (curr * 2 < *heap_n) {
            int min_child = curr*2;
            if (min_child + 1 <= *heap_n) {
                if (heap[min_child] > heap[min_child + 1]){
                    min_child += 1;
                }
            }
            if (heap[curr] > heap[min_child]) {
                int t;
                t = heap[curr];
                heap[curr] = heap[min_child];
                heap[min_child] = t;
            }
            curr = min_child;
        }
        *heap_n -= 1;
        return return_value;
    } else if (*heap_n == 1){
        return heap[1];
        *heap_n -= 1;
    } else {
        return __INT_MAX__;
    }
}

void heapSort(int *arr, int n) {
    int heap[101];
    int heap_n = 1;
    for(int i = 0; i < n; i++) {
        add(heap, &heap_n, arr[i]);
    }
    printf("\n%d\n", heap_n);
    for (int i = 0; i <= n; i++) {
        arr[i] = delete(heap, &heap_n);
    }
}

int main() {
    int arr[100], n;
    FILE *fi;
    fi = fopen("input.txt", "r");
    fscanf(fi, "%d", &n);
    for (int i = 0; i < n; i++) {
        fscanf(fi, "%d", &arr[i]);
    }

    heapSort(arr, n);

    FILE *fo;
    fo = fopen("output.txt", "w");
    for (int i = 0; i <= n; i++) {
        fprintf(fo, "%d ", arr[i]);
    }
    fclose(fi);
    fclose(fo);
}