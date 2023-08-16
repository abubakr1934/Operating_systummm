#include <stdio.h>

#define P 5
#define R 3

// Banker's Algorithm function
void bankerAlgorithm(int available[], int max[][R], int allocation[][R], int need[][R]) {
    int finish[P] = {0};  // Track finished processes
    int safeSequence[P];   // Store safe execution sequence
    int work[R];           // Temporary available resources

    // Initialize work with available resources
    for (int i = 0; i < R; i++) {
        work[i] = available[i];
    }

    int count = 0;
    while (count < P) {  // Loop until all processes are accounted for
        int found = 0;

        // Check each process if it can execute safely
        for (int p = 0; p < P; p++) {
            if (!finish[p]) {  // If the process is not finished
                int j;

                // Check if resources needed by process can be satisfied
                for (j = 0; j < R; j++) {
                    if (need[p][j] > work[j]) {
                        break;
                    }
                }

                if (j == R) {  // If resources can be satisfied
                    // Update work with allocated resources
                    for (int k = 0; k < R; k++) {
                        work[k] += allocation[p][k];
                    }
                    safeSequence[count++] = p;  // Add process to safe sequence
                    finish[p] = 1;  // Mark process as finished
                    found = 1;
                }
            }
        }

        if (!found) {
            printf("The system is in an unsafe state\n");
            return;
        }
    }

    // Output safe sequence
    printf("Safe sequence: ");
    for (int i = 0; i < P; i++) {
        printf("%d ", safeSequence[i]);
    }
    printf("\n");
}

int main() {
    int available[R] = {3, 3, 2};
    int max[P][R] = {
        {7, 5, 3},
        {3, 2, 2},
        {9, 0, 2},
        {2, 2, 2},
        {4, 3, 3}
    };
    int allocation[P][R] = {
        {0, 1, 0},
        {2, 0, 0},
        {3, 0, 2},
        {2, 1, 1},
        {0, 0, 2}
    };
    int need[P][R];

    // Calculate the need array
    for (int i = 0; i < P; i++) {
        for (int j = 0; j < R; j++) {
            need[i][j] = max[i][j] - allocation[i][j];
        }
    }

    // Call the Banker's Algorithm function
    bankerAlgorithm(available, max, allocation, need);

    return 0;
}
