#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 100 //배열크기


// 배열에 0~999 사이의 난수를 채움
void generateRandomData(int data[]) {
    for (int i = 0; i < SIZE; i++) {
        data[i] = rand() % 1000; // 0~999 범위의 난수 생성
    }
}

// 배열 출력 함수
// 배열의 모든 요소를 출력
void printArray(int data[]) {
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", data[i]);
    }
    printf("\n");
}


// 단계마다  최소값을 선택하여 정렬
void doSelectionSort(int data[]) {
    int arr[SIZE]; 
    for (int i = 0; i < SIZE; i++) arr[i] = data[i];

    printf("Selection Sort:\n");

    // Selection Sort 알고리즘
    for (int i = 0; i < SIZE - 1; i++) {
        int minIdx = i; // 현재 정렬되지 않은 부분에서 최소값의 인덱스
        for (int j = i + 1; j < SIZE; j++) {
            if (arr[j] < arr[minIdx]) { // 최소값을 찾음
                minIdx = j;
            }
        }

        // 최소값과 현재 위치의 값을 교환
        int temp = arr[i];
        arr[i] = arr[minIdx];
        arr[minIdx] = temp;

        // 특정 단계에서 배열 상태를 출력
        if (i == 9 || (i > 9 && (i - 9) % 20 == 0)) { // 10번째와 이후 20번째 단계마다 출력
            printf("Step %d: ", i + 1);
            printArray(arr);
            printf("\n");
        }
    }

    // 마지막 정렬 결과 출력
    printf("Step 99: ");
    printArray(arr);
    printf("\n");
}


// 20번씩 반복, 평균 비교 횟수를 계산
void doInsertionSort(int data[]) {
    int totalComparisons = 0; // 전체 비교 횟수
    int sorted[SIZE]; // 정렬할 배열

    for (int attempt = 0; attempt < 20; attempt++) { // 20번 반복
        for (int i = 0; i < SIZE; i++) sorted[i] = data[i]; // 데이터 복사

        int comparisons = 0; // 현재 시도에서의 비교 횟수
        for (int i = 1; i < SIZE; i++) {
            int key = sorted[i]; 
            int j = i - 1;
            while (j >= 0 && sorted[j] > key) { // 정렬된 부분에서 key보다 큰 값 이동
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

// Bubble Sort 구현 함수
// 20번 반복하여 평균 이동 횟수를 계산
void doBubbleSort(int data[]) {
    int totalMoves = 0; // 전체 이동 횟수
    int sorted[SIZE]; // 정렬할 배열

    for (int attempt = 0; attempt < 20; attempt++) { // 20번 반복
        for (int i = 0; i < SIZE; i++) sorted[i] = data[i]; // 데이터 복사

        int moves = 0; 
        for (int i = 0; i < SIZE - 1; i++) {
            for (int j = 0; j < SIZE - i - 1; j++) {
                if (sorted[j] > sorted[j + 1]) { 
                    int temp = sorted[j];
                    sorted[j] = sorted[j + 1];
                    sorted[j + 1] = temp;
                    moves += 3; // 교환은 3번의 이동으로 계산
                }
            }
        }

        totalMoves += moves; // 총 이동 횟수 누적
    }

   
    printf("Bubble Sort Move Average: %d\n", totalMoves / 20);

    
    printf("Bubble Sort Result: ");
    printArray(sorted);
}


int main() {
    srand(time(NULL)); 

    int randomData[SIZE]; 
    generateRandomData(randomData); // 데이터 채우기

    // Selection Sort 실행
    doSelectionSort(randomData);

    // Insertion Sort 실행
    doInsertionSort(randomData);
    printf("\n");

    // Bubble Sort 실행
    doBubbleSort(randomData);

    return 0;
}
