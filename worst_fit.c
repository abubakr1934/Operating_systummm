#include <stdio.h>
#include <stdlib.h>

void worstFit(int mem_partition[], int process[], int blocks, int p) {
    int IF = 0, EF = 0;  // Variables to track internal and external fragmentation
    int occupy[blocks], allocation[p];  // Arrays to track occupied blocks and process allocation

    // Initialize allocation array with -1 (not allocated)
    for (int i = 0; i < p; i++) {
        allocation[i] = -1;
    }

    // Initialize occupy array with 0 (not occupied)
    for (int i = 0; i < blocks; i++) {
        occupy[i] = 0;
    }

    // Loop through each process
    for (int i = 0; i < p; i++) {
        int index = -1;

        // Find the worst-fit block for the current process
        for (int j = 0; j < blocks; j++) {
            if (mem_partition[j] >= process[i] && !occupy[j]) {
                if (index == -1)
                    index = j;
                else if (mem_partition[index] < mem_partition[j])
                    index = j;
            }
        }

        // Allocate the process to the worst-fit block if found
        if (index != -1) {
            allocation[i] = index;
            occupy[index] = 1;
            mem_partition[index] -= process[i];
            IF += mem_partition[index];  // Update internal fragmentation
        }
    }

    // Calculate external fragmentation
    for (int i = 0; i < blocks; i++) {
        if (!occupy[i]) {
            EF += mem_partition[i];
        }
    }

    // Print allocation details
    printf("\nProcess No.\tProcess Size\tBlock no.\n");
    for (int i = 0; i < p; i++) {
        printf("%d \t\t\t %d \t\t\t", i + 1, process[i]);
        if (allocation[i] != -1)
            printf("%d\n", allocation[i] + 1);
        else
            printf("Not Allocated\n");
    }

    // Print fragmentation details
    printf("\n");
    printf("Internal Fragmentation is : %d\n", IF);
    printf("External Fragmentation is : %d\n", EF);
}

int main() {
    int mem_partition[6];  // Array to store memory partitions
    int p;  // Number of processes

    printf("Enter total Processes: ");
    scanf("%d", &p);

    int process[p];  // Array to store process sizes

    printf("Enter Partitions:\n");
    for (int i = 0; i < 6; i++) {
        printf("Enter Partition %d: ", i + 1);
        scanf("%d", &mem_partition[i]);
    }

    printf("Enter Process Size:\n");
    for (int i = 0; i < p; i++) {
        printf("Enter Process Size %d: ", i + 1);
        scanf("%d", &process[i]);
    }

    printf("\n");
    
    int blocks = 6;
    worstFit(mem_partition, process, blocks, p);  // Call worstFit function
    return 0;
}
