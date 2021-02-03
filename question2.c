#include <stdio.h>
#define SIZE 500000

int main(int argc, char * argv[]) {
    int n; 
    int sum = 0;
    scanf("%d", &n);

    // 1부터 N의 숫자중 K가 빠진 배열
    int partArr[SIZE];
    int lengthOfPartArr = n-1;

    for(int i=0; i < lengthOfPartArr; i++){
        scanf("%d", &partArr[i]);
    }
    
    // 1~n까지의 합(sum)
    for(int i=0; i<n; i++){
        sum += (i+1);
    }
    // sum에서 모든 배열의 값 빼기
    for(int i=0; i<lengthOfPartArr; i++){
        sum -= partArr[i];
    }
    
    int result = sum;
    printf("K = %d\n", result);

    return 0;
}
