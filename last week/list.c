#include <stdio.h> 
#include <stdlib.h>

int main(void) {
    
    int *list = malloc(3 * sizeof(int));  // malloc 을 이용해 메모리 할당 
    if (list == NULL) // list에 아무것도 없을경우 
    {
        return 1; // 1 반환 
    } 
    
    list[0] = 1 ;
    list[1] = 2 ;
    list[2] = 3 ;
    // 메모리 할당 후  이 세개의 값을 저장하는 코드 
    
    
    int *tmp = malloc(4 * sizeof(int));
    if(tmp == NULL) {
        return 1 ; 
    }
    
    //오래된 배열에서 새로운 배열로 정수 이동 
    for(int i = 0 ; i < 4 ; i++) {
        tmp[i] = list [i];
    }
    
    tmp[3] = 4 ;
    
    free(list); //메모리 할당 해제 
    
    list = tmp;
    
    
    for (int i =0; i < 4 ; i++)
    {
        printf("%i\n" , list[i]);
    }
}