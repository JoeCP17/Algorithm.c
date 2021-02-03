#include <stdio.h>
#include <cs50.h>

const int QUEUE_SIZE = 10; //큐 사이즈
string QUEUE[QUEUE_SIZE] = {0,}; //문자열을 담는 큐. 기본값은 널값
int front = 0; // 첫 데이터가 담긴 인덱스, 비어 있을 시 혹은
int rear = 0; // 마지막 데이터가 담긴 인덱스

//인덱스 순환 증가하게 하는 함수. 예를 들어 길이10인 큐에서 9 다음은 다시 0으로 감
int indexPlus(int num){
    if (num == QUEUE_SIZE-1){ // 큐의 마지막 인덱스이면 0으로 돌아감
        return 0;
    } else {
        return num+1;
    }
}

//큐가 비어있으면 -1, 큐가 보통상태면 0, 큐가 가득찼으면 1 반환하는 함수를 정의함
int queueCheck(void){
    if (front == rear){ //front와 rear가 같을 때 큐가 비어있을 수도 있고, 데이터가 1개만 있을 수도 있음.
        if (QUEUE[front] == 0){ //front 인덱스를 검사해서 비어있으면 빈 큐
            return -1;
        }
        return 0; // 비어있지 않으면 데이터가 1개 있는 큐니까 0 반환
    } else if(indexPlus(rear) == front ) { // 마지막 번호의 다음 번호가 front이면 큐가 가득 찼다고 볼 수 있음
        return 1;
    } else {
        return 0;
    }
}

//맨 뒤에 추가
void add(string name){
    if(queueCheck() != 1){
        if(queueCheck() == -1 ){
            QUEUE[rear] = name;  // 비어있는 큐에 처음 데이터를 넣을 때는 front, rear 인덱스가 변하지 않음
        } else {
            rear = indexPlus(rear); // 데이터가 있는 큐에 데이터를 넣을 때는 front인덱스에 +1
            QUEUE[rear] = name;
        }
    } else {
        printf("Queue가 가득 찼습니다.\n");
    }
}

string pop(){
    if(queueCheck() == -1 ){
        printf("Queue가 비어 있습니다.\n");
        return "";
    } else if(front == rear){  //큐가 비어있지 않은데 front와 rear가 같다면 큐가 데이터 1개 있는 것임. 그러면 front인덱스의 변화가 없음.
        string result = QUEUE[front];
        QUEUE[front] = 0;
        return result;
    } else {  // 보통의 경우에는 front의 데이터를 꺼내고 front인덱스를 1증가시킴.
        string result = QUEUE[front];
        QUEUE[front] = 0;
        front = indexPlus(front);
        return result;
    }
}


void display(){
    int f = front; //front, rear값에 영향을 주지 않기 위해 복사해서 사용.
    int r = rear;
    int cnt = 0;  //무한루프를 방지하기 위한 변수

    if(queueCheck() == -1){
        printf("Queue가 비어 있습니다.\n");
        return;
    } else {
        do {
            printf("%s ", QUEUE[f]);
            f = indexPlus(f);
            cnt++;
        }while(QUEUE[f] != 0 && cnt < QUEUE_SIZE );  // 널 문자가 아니고, cnt가 큐 사이즈(10)를 넘지 않을떄까지 반복
        printf("\n");
    }
}

int main(void){
    int num;
    bool quit = false;
    string s;

    printf("Queue프로그램\n");
    do{
        printf("\n");
        num = get_int("1)add   2)pop   3)display   4)quit : ");
        switch(num){
            case 1:
                s = get_string("이름을 입력하세요 : ");
                add(s);
                break;
            case 2:
                if(queueCheck() != -1){
                    printf("나온 이름 : %s \n", pop());
                } else {
                    printf("Queue가 비어 있습니다.\n");
                }
                break;
            case 3:
                display();
                break;
            case 4:
                quit = true;
                break;
            default :
                printf("1 ~ 4사이의 값을 입력하세요\n");
        }
    }while(quit == false);
}
