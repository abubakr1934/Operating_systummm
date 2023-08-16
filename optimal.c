#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, size, page;
    
    // Input the total number of pages and size of the frame
    printf("Enter Total number of pages: ");
    scanf("%d", &n);
    printf("Enter size of frame: ");
    scanf("%d", &size);
    
    int count[n + 1];
    for (int i = 0; i <= n; i++) {
        count[i] = 0;
    }
    
    int arr[n];
    int table[size];
    int tab = 0;
    
    // Input page numbers
    for (int i = 0; i < n; i++) {
        printf("Enter page number: ");
        scanf("%d", &page);
        arr[i] = page;
    }
    
    // Initialize the page table with -1
    for (int i = 0; i < size; i++) {
        table[i] = -1;
    }
    
    int hit = 0;
    int miss = 0;
    
    for (int i = 0; i < n; i++) {
        if (tab < size) {
            // If there's space in the table, add the page to the table
            miss += 1;
            table[tab] = arr[i];
            tab = tab + 1;
            count[arr[i]] = 1;
        } else {
            if (count[arr[i]] == 0) {
                // Page fault, find a replacement
                miss += 1;
                int c = 0, found, flag = 0;
                
                // Find a page to replace based on the farthest page in the future
                for (int j = i; j < n; j++) {
                    if (count[arr[j]] == 1) {
                        if (c == size - 1) {
                            found = arr[j];
                            flag = 1;
                            break;
                        }
                        c++;
                    }
                }
                
                if (flag == 0) {
                    found = arr[n - 1];
                }
                
                // Replace the page in the table
                for (int j = 0; j < size; j++) {
                    if (table[j] == found) {
                        count[arr[i]] = 1;
                        count[found] = 0;
                        table[j] = arr[i];
                        break;
                    }
                }
            } else {
                // Page hit
                hit += 1;
            }
        }
    }
    
    // Output the results
    printf("Total hit: %d\n", hit);
    printf("Total Miss: %d\n", miss);

    return 0;
}
