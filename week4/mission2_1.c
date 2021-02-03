#include <stdio.h>
#include <stdlib.h>

#define N 5

void bubbleSort(int * arr);
int averageD(int * arr);
int medianD(int * arr);
int shortestD(int * arr);

int main(void) {
    int friends[N] = {1, 9374, 18, 3, 100};

    bubbleSort(friends); // 중앙값을 구하기 위해서 정렬 먼저 해야함.

    printf("Average of friends : %d\n", averageD(friends));
    printf("Median of friends : %d\n", medianD(friends));
    printf("David's house should be located %d!\n", shortestD(friends));

    return 0;
}

// 배열 오름차순 정렬하는 함수(버블정렬)
void bubbleSort(int * arr) {
    int temp;

    for (int i=0; i<N; i++) {
        for (int j=0; j<N-i-1; j++) {
          if (arr[j] > arr[j+1]) {
            temp = arr[j];
            arr[j] = arr[j+1];
            arr[j+1] = temp;
          }
        }
    }
}

int averageD(int * arr) { // 배열의 평균값 구하는 함수
    int sum=0;
    for(int i=0; i<N; i++) {
        sum += arr[i];
    }
    int average = sum / N;
    return average;
}

int medianD(int * arr) { // 배열의 중앙값 구하는 함수
    if(N%2 == 0) { // arr 원소개수가 짝수일 때
        return (arr[N/2] + arr[N/2 + 1]) / 2;
    }
    else { // arr 원소개수가 홀수일 때
        return arr[N/2];
    }
}

int shortestD(int * arr) {
    int sumAverage = 0;
    int sumMedian = 0;

    for(int i=0; i<N; i++) { // 평균일 때, 친구들 집까지의 거리의 합
        sumAverage += abs(averageD(arr) - arr[i]);
    }

    for(int i=0; i<N; i++) { // 중앙값일 때, 친구들 집까지의 거리의 합
        sumMedian += abs(medianD(arr) - arr[i]);
    }

    if(sumAverage > sumMedian) // 평균과 중앙값일 때 친구들 집까지 거리의 합 비교
        return medianD(arr);
    else
        return averageD(arr);

}
