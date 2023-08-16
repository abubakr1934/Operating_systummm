#include <stdio.h>

void firstFit(int blockSize[], int m, int processSize[], int n) {
    int i, j;
    int allocation[n];

    // Initialize allocation array with -1 to indicate not allocated
    for (i = 0; i < n; i++) {
        allocation[i] = -1;
    }

    // Iterate through each process and allocate to a suitable block
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            if (blockSize[j] >= processSize[i]) {
                allocation[i] = j;
                blockSize[j] -= processSize[i];
                break;
            }
        }
    }

    printf("\nProcess No.\tProcess Size\tBlock no.\n");
    for (int i = 0; i < n; i++) {
        printf(" %i\t\t\t", i + 1);
        printf("%i\t\t\t\t", processSize[i]);
        if (allocation[i] != -1) {
            printf("%i", allocation[i] + 1); // Block numbers are 1-indexed
        } else {
            printf("Not Allocated");
        }
        printf("\n");
    }
}

int main() {
    int m; // Number of memory blocks
    int n; // Number of processes

    int blockSize[] = {100, 500, 200, 300, 600}; // Sizes of memory blocks
    int processSize[] = {212, 417, 112, 426};    // Sizes of processes

    m = sizeof(blockSize) / sizeof(blockSize[0]);
    n = sizeof(processSize) / sizeof(processSize[0]);

    // Call the firstFit function
    firstFit(blockSize, m, processSize, n);

    return 0;
}
