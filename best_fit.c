#include<stdio.h>
int main() {
    int fragment[20], p[20], nb, np, temp, lowest = 999;
    int b[20];
    int barray[20], parray[20];

    // Input the number of blocks and processes
    printf("Enter the number of blocks:\n");
    scanf("%d", &nb);
    printf("Enter the number of process:\n");
    scanf("%d", &np);

    // Input the size of each block
    printf("Enter the size of the blocks\n");
    for (int i = 1; i <= nb; i++) {
        printf("Block No %d ", i);
        scanf("%d", &b[i]);
    }

    // Input the size of each process
    printf("Enter the size of the process\n");
    for (int i = 1; i <= np; i++) {
        printf("Process NO %d ", i);
        scanf("%d", &p[i]);
    }

    // Initialize arrays
    for (int i = 1; i <= np; i++) {
        parray[i] = 0;
    }

    for (int i = 1; i <= np; i++) {
        for (int j = 1; j <= nb; j++) {
            if (barray[j] != 1) {
                temp = b[j] - p[i];
                if (temp >= 0 && lowest > temp) {
                    parray[i] = j;
                    lowest = temp;
                }
            }
        }
        fragment[i] = lowest;
        barray[parray[i]] = 1;
        lowest = 1000;
    }

    // Output the result
    printf("\nProcess_no\tProcess_size\tBlock_no\tBlock_size\tFragment");
    for (int i = 1; i <= np && parray[i] != 0; i++) {
        printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d", i, p[i], parray[i], b[parray[i]], fragment[i]);
    }
    printf("\n");
    return 0;
}
