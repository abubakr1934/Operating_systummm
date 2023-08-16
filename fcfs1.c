#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, head, totalHeadMovement = 0;

    printf("Enter the number of requests: ");
    scanf("%d", &n);

    int requests[n];
    
    printf("Enter the request sequence:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &requests[i]);
    }

    printf("Enter the initial head position: ");
    scanf("%d", &head);

    // Calculate total head movement
    for (int i = 0; i < n; i++) {
        totalHeadMovement += abs(requests[i] - head);
        head = requests[i];
    }

    printf("Total head movement is %d\n", totalHeadMovement);

    return 0;
}
