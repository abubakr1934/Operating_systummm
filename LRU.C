#include <stdbool.h>
#include <stdio.h>
#define NUM_FRAMES 3

// Define a structure representing a page
typedef struct {
    int number;     // Page number
    bool loaded;    // Flag indicating if the page is loaded in a frame
} Page;

// Function to find the index of the frame with the minimum counter value
int findMinCounter(Page frames[]) {
    int minIndex = 0;

    // Iterate through frames to find the frame with the smallest page number
    for (int i = 1; i < NUM_FRAMES; i++) {
        if (frames[i].number < frames[minIndex].number) {
            minIndex = i;
        }
    }
    return minIndex;
}

// Function to display the contents of frames
void displayFrames(Page frames[]) {
    for (int i = 0; i < NUM_FRAMES; i++) {
        if (frames[i].loaded) {
            printf("%d ", frames[i].number);  // Display page number if loaded
        } else {
            printf("- ");                    // Display '-' if not loaded
        }
    }
    printf("\n");
}

// Function to perform LRU page replacement
void lruPageReplacement(int pages[], int numPages) {
    Page frames[NUM_FRAMES] = {0};  // Initialize an array of frames
    int pageFaults = 0;             // Counter for page faults

    // Iterate through the list of pages
    for (int i = 0; i < numPages; i++) {
        int currentPage = pages[i];  // Get the current page number
        bool pageLoaded = false;     // Flag to check if the page is loaded

        // Iterate through frames to check if the page is already loaded
        for (int j = 0; j < NUM_FRAMES; j++) {
            if (frames[j].number == currentPage) {
                pageLoaded = true;   // Set the flag if page is already loaded
                break;
            }
        }

        // If the page is not loaded, perform page replacement
        if (!pageLoaded) {
            int replaceIndex = findMinCounter(frames);  // Find index to replace
            frames[replaceIndex].number = currentPage;  // Replace the page
            frames[replaceIndex].loaded = true;         // Mark the frame as loaded
            pageFaults++;                               // Increment page faults
        }

        // Display the frames after each page access
        displayFrames(frames);
    }

    // Display the total page faults at the end
    printf("Page faults: %d\n", pageFaults);
}

// Main function
int main() {
    int pages[] = {1, 2, 3, 4, 5, 6, 1, 2, 5, 1, 2, 3};
    int numPages = sizeof(pages) / sizeof(pages[0]);  // Calculate the number of pages
    lruPageReplacement(pages, numPages);              // Call the page replacement function
    return 0;
}
