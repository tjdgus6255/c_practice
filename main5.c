#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define SIZE 10000
#define INF 99999999


typedef struct {
	int data;            // node ���� 
	struct Node* next;
}Node;

typedef struct {
	Node* top;          // stack ���� �� �ʱ�ȭ 
}Stack;                 // stack�� ó���� top�̶�� node�� ����

void push(Stack* stack, int data) {
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = data;        // ������ node�� data �Ҵ�
	node->next = stack->top;  // ������ node�� ���� node�� ������ top�� �ǵ��� ����
	stack->top = node;        // ������ node�� stack�� top�� �ǵ��� ����
}

int pop(Stack *stack) {
	if (stack->top == NULL) {
		printf("���� ����÷ο찡 �߻��߽��ϴ�.\n");
		return -INF;
	}
	Node* node = stack->top; // �ֻ�� node�� node ������ ������ ��Ƴ���
	int data = node->data;   // node ������ ������ ��� �ִ� ������, �� ���� �ֻ�� node�� �����͸� data ������ ����
	stack->top = node->next; // ���� �ֻ�� node�� ���� node�� �ֻ�� node�� ����
	free(node); // ���� �ֻ�� node�� �Ҵ� ����
	return data; // ���� �ֻ�� node�� data�� ��ȯ
}


void show(Stack* stack) {
	Node* cur = stack->top;
	printf("--- ������ �ֻ�� ---\n");
	while (cur != NULL) {
		printf("%d\n", cur->data);
		cur = cur->next;
	}
	printf("--- ������ ���ϴ� ---\n");
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