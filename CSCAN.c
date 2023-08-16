#include <stdio.h>
#include <stdlib.h>

int main() {
    int i, n, req[50], mov = 0;
    int current_position, index[50], min;
    int a[50], j = 0, mini, current_position1;
    
    // Input the number of requests
    printf("Enter the number of requests: ");
    scanf("%d", &n);
    
    // Input the current head position
    printf("Enter the current position: ");
    scanf("%d", &current_position);
    current_position1 = current_position;
    
    // Input the request order
    printf("Enter the request order:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &req[i]);
    }
    
    // Sorting the request order using Bubble Sort
    for (i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (req[j] > req[j + 1]) {
                int temp = req[j];
                req[j] = req[j + 1];
                req[j + 1] = temp;
            }
        }
    }
    
    int currentPositionIndex = 0;
    // Finding the index where the current position is located or should be placed
    for (i = 0; i < n; i++) {
        if (current_position <= req[i]) {
            currentPositionIndex = i;
            break;
        }
    }
    
    // Filling the sequence array 'a' based on the sorted request order
    for (i = currentPositionIndex; i < n; i++) {
        a[j] = req[i];
        j++;
    }
    for (i = 0; i < currentPositionIndex; i++) {
        a[j] = req[i];
        j++;
    }
    
    // Displaying the sequence and calculating total head movement
    printf("Sequence is: %d", current_position1);
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
