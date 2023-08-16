#include <stdio.h>
#include <stdlib.h>

int main() {
    int RQ[100], i, j, n, TotalHeadMoment = 0, initial, size, move;

    // Input: Number of requests
    printf("Enter the number of Requests\n");
    scanf("%d", &n);

    // Input: Requests sequence
    printf("Enter the Requests sequence\n");
    for (i = 0; i < n; i++)
        scanf("%d", &RQ[i]);

    // Input: Initial head position
    printf("Enter initial head position\n");
    scanf("%d", &initial);

    // Input: Total disk size
    printf("Enter total disk size\n");
    scanf("%d", &size);

    // Input: Head movement direction (high: 1, low: 0)
    printf("Enter the head movement direction for high 1 and for low 0\n");
    scanf("%d", &move);

    // Sorting the request sequence using Bubble Sort
    for (i = 0; i < n; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (RQ[j] > RQ[j + 1]) {
                int temp;
                temp = RQ[j];
                RQ[j] = RQ[j + 1];
                RQ[j + 1] = temp;
            }
        }
    }

    // Find the index where the initial head position is smaller than or equal to a request
    int index;
    for (i = 0; i < n; i++) {
        if (initial < RQ[i]) {
            index = i;
            break;
        }
    }

    // Calculate total head movement based on the head movement direction
    if (move == 1) {
        // Moving in the high direction first, then low
        for (i = index; i < n; i++) {
            TotalHeadMoment = TotalHeadMoment + abs(RQ[i] - initial);
            initial = RQ[i];
        }
        for (i = index - 1; i >= 0; i--) {
            TotalHeadMoment = TotalHeadMoment + abs(RQ[i] - initial);
            initial = RQ[i];
        }
    } else {
        // Moving in the low direction first, then high
        for (i = index - 1; i >= 0; i--) {
            TotalHeadMoment = TotalHeadMoment + abs(RQ[i] - initial);
            initial = RQ[i];
        }
        for (i = index; i < n; i++) {
            TotalHeadMoment = TotalHeadMoment + abs(RQ[i] - initial);
            initial = RQ[i];
        }
    }

    // Display the total head movement
    printf("Total head movement is %d", TotalHeadMoment);

    return 0;
}
