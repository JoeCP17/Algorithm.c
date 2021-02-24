#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct stackNode {
    int data;
    struct stackNode* next;
} StackNode;

StackNode* createStackNode(int data) {
    StackNode* node = (StackNode*)malloc(sizeof(StackNode));
    memset(node, 0, sizeof(StackNode));
    node->data = data;
    node->next = NULL;
    return node;
}

int isEmpty(StackNode* root) {
    return !root;
}

void push(StackNode** root, int data) {
    if(*root == NULL) {
        *root = createStackNode(data);
        printf("%d pushed to stack\n", data);
    } else {
        StackNode* node = (StackNode*)malloc(sizeof(StackNode));
        memset(node, 0, sizeof(StackNode));
        node->data = data;
        node->next = *root;
        *root = node;
        printf("%d pushed to stack\n", data);
    }
}

int pop(StackNode** root) {
    // stack이 비었을 때
    if (isEmpty(*root))
        return -9999;
    int popped;
    popped = (*root)->data;
    *root = (*root)->next;
    return popped;
}

int peek(StackNode** root) {
    if (isEmpty(*root))
        return -9999;
    return (*root)->data;
}

int main() {
    StackNode* root = NULL;

    push(&root, 10);
    push(&root, 20);
    push(&root, 30);
    push(&root, 40);

    printf("%d pop from stack\n", pop(&root));
    printf("%d pop from stack\n", pop(&root));

    push(&root, 50);
    printf("%d peeked from stack\n", peek(&root));
    printf("%d pop from stack\n", pop(&root));
    printf("%d pop from stack\n", pop(&root));
    printf("%d pop from stack\n", pop(&root));

    return 0;
}