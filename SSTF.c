#include <math.h>
#include <stdio.h>

int main() {
    int i, n, req[50], mov = 0;
    int current_position, index[50], min;
    int a[50], j = 0, mini, current_position1;

    // Input the number of requests and the current position
    printf("Enter the number of requests: ");
    scanf("%d", &n);
    printf("Enter the current position: ");
    scanf("%d", &current_position);
    current_position1 = current_position;

    printf("Enter the request order:\n");
    // Input the request order
    for (i = 0; i < n; i++) {
        scanf("%d", &req[i]);
    }

    // Find the nearest request and build the movement sequence
    for (int k = 0; k < n; k++) {
        for (i = 0; i < n; i++) {
            index[i] = abs(current_position - req[i]);
        }
        min = index[0];
        mini = 0;

        // Find the index of the nearest request
        for (i = 1; i < n; i++) {
            if (min > index[i]) {
                min = index[i];
                mini = i;
            }
        }

        // Store the selected request in the sequence
        a[j] = req[mini];
        j++;
        current_position = req[mini];
        req[mini] = 999;  // Mark the request as processed
    }

    // Output the sequence of requests and the total head movement
    printf("Sequence is: ");
    printf("%d", current_position1);
    mov = mov + abs(current_position1 - a[0]);
    printf(" -> %d", a[0]);
    for (i = 1; i < n; i++) {
        mov = mov + abs(a[i] - a[i - 1]);
        printf(" -> %d", a[i]);
    }
    printf("\n");
    printf("Total head movement = %d\n", mov);

    return 0;
}
