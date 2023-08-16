#include <stdio.h>
#include <stdlib.h>

int main() {
    int RQ[100], i, j, n, TotalHeadMoment = 0, initial, size, move;
    
    // Input the number of requests
    printf("Enter the number of Requests: ");
    scanf("%d", &n);
    
    // Input the requests sequence
    printf("Enter the Requests sequence:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &RQ[i]);
    
    // Input initial head position
    printf("Enter initial head position: ");
    scanf("%d", &initial);
    
    // Input total disk size
    printf("Enter total disk size: ");
    scanf("%d", &size);
    
    // Input the head movement direction (high: 1, low: 0)
    printf("Enter the head movement direction (high: 1, low: 0): ");
    scanf("%d", &move);
    
    // Sorting the request queue
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
    
    int index;
    // Finding the index where the initial head position is located or should be placed
    for (i = 0; i < n; i++) {
        if (initial < RQ[i]) {
            index = i;
            break;
        }
    }
    
    if (move == 1) {
        // Head movement direction is high
        for (i = index; i < n; i++) {
            TotalHeadMoment += abs(RQ[i] - initial);
            initial = RQ[i];
            printf("%d->", initial);
        }
        for (i = 0; i < index; i++) {
            TotalHeadMoment += abs(RQ[i] - initial);
            initial = RQ[i];
            printf("%d->", initial);
        }
    } else {
        // Head movement direction is low
        for (i = index - 1; i >= 0; i--) {
            TotalHeadMoment += abs(RQ[i] - initial);
            initial = RQ[i];
            printf("%d->", initial);
        }
        for (i = n - 1; i >= index; i--) {
            TotalHeadMoment += abs(RQ[i] - initial);
            initial = RQ[i];
            printf("%d->", initial);
        }
    }
    
    printf("Total head movement is %d\n", TotalHeadMoment);
    return 0;
}
