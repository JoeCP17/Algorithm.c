#include <stdio.h>
#include <string.h>

// 시간 복잡도 O(N^2)

char temp[10];  //배열 저장 공간1
char temp2[10];  //배열 저장공간 2
int count=0;  // 두개의 문자를 비교하여 같을경우 카운트 증가해주는 변수 
int len=5; // 각 지정된 문자열 5의 길이 계산 변수

int main(void) {
  
  scanf("%s", temp);  
  scanf("%s", temp2);
  
  int c; // 버블 정렬을 위한 임시 변수 저장공간 선언 
  
  // 정렬1 버블정렬 
  for(int i=0;i<len;i++){
    for(int j=0;j<len-i-1;j++){
      if(temp[j]>temp[j+1]){
        c=temp[j];
        temp[j]=temp[j+1];
        temp[j+1]=c;
      }
    }
  }
   // 정렬 2 버블 정렬 
  for(int i=0;i<len;i++){
    for(int j=0;j<len-i-1;j++){
      if(temp2[j]>temp2[j+1]){
        c=temp2[j];
        temp2[j]=temp2[j+1];
        temp2[j+1]=c;
      }
    }
  }
   // 정렬된 두 배열을 비교하여 같을시 카운트 증가 
  for(int i=0;i<len;i++){
    if(temp[i]==temp2[i]) count++;
  }
   // 만약 5라면 두개의 배열이 다 같은경우임으로 true 출력
  if(count==5)  printf("True\n");
  // 그게 아니라면 다른수가있는 것이므로 false 출력 
  else  printf("False\n");
  
}
