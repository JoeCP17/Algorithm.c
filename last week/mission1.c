#include <stdio.h>
#include <stdlib.h>

typedef struct stack{
    int top;
    int capacity;
    int* array;
} Stack;

Stack* createStack(int capacity) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int *)malloc(stack->capacity*sizeof(int));
    return stack;
}

int isFull(Stack* stack) {
    return stack->top == stack->capacity-1;
}

int isEmpty(Stack* stack) {
    return stack->top == -1;
}

void push(Stack* stack, int item) {
    if (isFull(stack))
        return;
    stack->array[++stack->top] = item;
    printf("%d pushed to stack\n", item);
}


int pop(Stack* stack) {
    if (isEmpty(stack)) {    // 공백일 경우 
        return -9999;  // 문제에서 -9999라고 표현되어있어 return 을 통해 이를 표현
    }
    else {   // 비어있지 않은 경우 
        return (stack -> array[stack->top--]);  // stack에서 하나를 꺼내야 하므로 array 안에 있는 top 값을 빼낸다.
    }
    
 }

int peek(Stack* stack) {
    if(isEmpty(stack)) {  // 위와 동일 
        return -9999;
    }
    return stack->array[stack->top]; //top 위치의 값을 알아야하기 때문에 array안에 있는 top 값을 return 시킨다.
}

int main() {
    Stack* stack = createStack(100);

    push(stack, 10);
    push(stack, 20);
    push(stack, 30);
    push(stack, 40);

    printf("%d pop from stack\n", pop(stack));
    printf("%d pop from stack\n", pop(stack));

    push(stack, 50);
    printf("%d pop from stack\n", pop(stack));
    printf("%d pop from stack\n", pop(stack));
    printf("%d pop from stack\n", pop(stack));
    printf("%d pop from stack\n", pop(stack));
    return 0;
}