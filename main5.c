#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define SIZE 10000
#define INF 99999999


typedef struct {
	int data;            // node 정의 
	struct Node* next;
}Node;

typedef struct {
	Node* top;          // stack 정의 및 초기화 
}Stack;                 // stack은 처음에 top이라는 node를 가짐

void push(Stack* stack, int data) {
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = data;        // 삽입할 node에 data 할당
	node->next = stack->top;  // 삽입할 node의 다음 node가 기존의 top이 되도록 설정
	stack->top = node;        // 삽입할 node가 stack의 top이 되도록 설정
}

int pop(Stack *stack) {
	if (stack->top == NULL) {
		printf("스택 언더플로우가 발생했습니다.\n");
		return -INF;
	}
	Node* node = stack->top; // 최상단 node를 node 포인터 변수에 담아놓음
	int data = node->data;   // node 포인터 변수가 담고 있는 데이터, 즉 기존 최상단 node의 데이터를 data 변수에 저장
	stack->top = node->next; // 기존 최상단 node의 다음 node를 최상단 node로 설정
	free(node); // 기존 최상단 node는 할당 해제
	return data; // 기존 최상단 node의 data를 반환
}


void show(Stack* stack) {
	Node* cur = stack->top;
	printf("--- 스택의 최상단 ---\n");
	while (cur != NULL) {
		printf("%d\n", cur->data);
		cur = cur->next;
	}
	printf("--- 스택의 최하단 ---\n");
}
int main(void) {
	Stack stack;
	stack.top = NULL;
	show(&stack);
	push(&stack, 7);
	push(&stack, 5);
	push(&stack, 4);
	pop(&stack);
	push(&stack, 6);
	pop(&stack);
	show(&stack);
	system("pause");
	return 0;
}