#include <stdio.h>
#include <stdlib.h>

int main() {
    int r, a;
    int pageFaults = 0;  // Initialize the counter for page faults

    // Input the total number of references
    printf("Enter total references: ");
    scanf("%d", &r);

    int s[r];  // Array to store reference string
    printf("Enter reference String:\n");
    
    // Input the reference string values
    for (int i = 0; i < r; i++) {
        scanf("%d", &s[i]);
    }

    int frames = 3;  // Number of frames available in memory
    printf("We have 3 frames.\n");
    
    int pages = sizeof(s) / sizeof(int);  // Calculate the number of pages in the reference string
    printf("Reference String\tFrame 1\t\tFrame 2\t\tFrame 3\n");

    int temp[frames];
    
    // Initialize the frames with -1 (indicating empty)
    for (int i = 0; i < frames; i++) {
        temp[i] = -1;
    }

    // Loop through each page in the reference string
    for (int i = 0; i < pages; i++) {
        a = 0;

        // Check if the page is already in one of the frames
        for (int j = 0; j < frames; j++) {
            if (s[i] == temp[j]) {
                a++;
                pageFaults--;  // Decrement page faults as it's not a real page fault
            }
        }

        pageFaults++;  // Increment page faults counter

        // Check conditions for page replacement
        if ((pageFaults <= frames) && (a == 0)) {
            temp[i] = s[i];
        } else if (a == 0) {
            temp[(pageFaults - 1) % frames] = s[i];
        }

        // Print the current reference and frame contents
        printf("%d\t\t\t", s[i]);
        for (int j = 0; j < frames; j++) {
            if (temp[j] != -1)
                printf("%d\t\t", temp[j]);
            else
                printf("-\t\t");
        }
        printf("\n");
    }

    // Print the total number of page faults
    printf("\nPage Faults: %d\n", pageFaults);

    return 0;
}
