#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 100


void generateRandomData(int data[]) {
    for (int i = 0; i < SIZE; i++) {
        data[i] = rand() % 1000; 
    }

}


void printArray(int data[]) {
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", data[i]);
    }
    printf("\n");
}

void doSelectionSort(int data[]) {
    int arr[SIZE];
    for (int i = 0; i < SIZE; i++) arr[i] = data[i];

    printf("Selection Sort:\n");
    for (int i = 0; i < SIZE - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < SIZE; j++) {
            if (arr[j] < arr[minIdx]) {
                minIdx = j;
            }
        }
        
        int temp = arr[i];
        arr[i] = arr[minIdx];
        arr[minIdx] = temp;

        
        if (i == 9 || (i > 9 && (i - 9) % 20 == 0)) {
            printf("Step %d: ", i + 1);
            printArray(arr);
            printf("\n");

        }
    }

    printf("Step 99: ");
    printArray(arr);
    printf("\n");
}


void doInsertionSort(int data[]) {
    int totalComparisons = 0;
    int sorted[SIZE];

    for (int attempt = 0; attempt < 20; attempt++) {
        for (int i = 0; i < SIZE; i++) sorted[i] = data[i];

        int comparisons = 0;
        for (int i = 1; i < SIZE; i++) {
            int key = sorted[i];
            int j = i - 1;
            while (j >= 0 && sorted[j] > key) {
                sorted[j + 1] = sorted[j];
                j--;
                comparisons++;
            }
            sorted[j + 1] = key;
            comparisons++;
        }

        totalComparisons += comparisons;
    }

    printf("Insertion Sort Compare Average: %d\n", totalComparisons / 20);
    printf("Insertion Sort Result: ");
    printArray(sorted);
}


void doBubbleSort(int data[]) {
    int totalMoves = 0;
    int sorted[SIZE];

    for (int attempt = 0; attempt < 20; attempt++) {
        for (int i = 0; i < SIZE; i++) sorted[i] = data[i];

        int moves = 0;
        for (int i = 0; i < SIZE - 1; i++) {
            for (int j = 0; j < SIZE - i - 1; j++) {
                if (sorted[j] > sorted[j + 1]) {
                    int temp = sorted[j];
                    sorted[j] = sorted[j + 1];
                    sorted[j + 1] = temp;
                    moves += 3; 
                }
            }
        }

        totalMoves += moves;
    }

    printf("Bubble Sort Move Average: %d\n", totalMoves / 20);
    printf("Bubble Sort Result: ");
    printArray(sorted);
}

int main() {
    srand(time(NULL));

    int randomData[SIZE];
    generateRandomData(randomData);

    doSelectionSort(randomData);
    doInsertionSort(randomData);
    printf("\n");

    doBubbleSort(randomData);

    return 0;
}
