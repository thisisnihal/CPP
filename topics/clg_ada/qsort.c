#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to partition the array
int partition(int l, int h, int a[]) {
    int temp;
    int p = a[l];
    int i = l;
    int j = h;

    while (i < j) {
        while (a[i] <= p && i < h) {
            i++;
        }
        while (a[j] > p && j > l) {
            j--;
        }
        if (i < j) {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }
    temp = a[l];
    a[l] = a[j];
    a[j] = temp;
    return j;
}

// Function to perform QuickSort
void quicksort(int l, int h, int a[]) {
    if (l < h) {
        int j = partition(l, h, a);
        quicksort(l, j - 1, a);
        quicksort(j + 1, h, a);
    }
}

int main() {
    FILE *fptr;
    fptr = fopen("results.csv", "w");
    if (fptr == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    srand(time(0));
    fprintf(fptr, "Number of Elements,Time Taken (seconds)\n");

    for (int n = 5000; n <= 50000; n += 5000) {
        int *arr = (int *)malloc(n * sizeof(int));
        if (arr == NULL) {
            printf("Memory not allocated.\n");
            exit(0);
        }

        for (int i = 0; i < n; i++) {
            arr[i] = rand();
        }

        clock_t start, end;
        double cpu_time_used;

        start = clock();
        quicksort(0, n - 1, arr);
        end = clock();

        cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
        printf("Time taken to sort %d elements: %f seconds\n", n, cpu_time_used);
        fprintf(fptr, "%d,%f\n", n, cpu_time_used);

        free(arr);
    }

    fclose(fptr);
    return 0;
}