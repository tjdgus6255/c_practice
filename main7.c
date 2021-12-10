#include <stdio.h>
#include <stdlib.h>
#define INF 99999999

typedef struct {
	int data;
	struct Node* next;
}Node;

typedef struct {
	Node* front;
	Node* rear;
	int count; // ������ ������ ��Ÿ��
}Queue;

void push(Queue* queue, int data) {
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = data;
	node->next = NULL;
	if (queue->count == 0) { // queue�� ��������� count�� 0���� ����
		queue->front = node; // front�� node (���� �ʱ�ȭ)
	}
	else {
		queue->rear->next = node; // ���� rear�� ���� node�� ������ node�� ����
	}
	queue->rear = node; // ������ node�� ���ο� rear�� ��
	queue->count++;
}

int pop(Queue* queue) {
	if (queue->count == 0) {
		printf("ť ����÷ο찡 �߻��߽��ϴ�.\n");
		return -INF;
	}
	Node* node = queue->front; // ������ ���� node�� ���� front�� ����
	int data = node->data; // front�� data�� data ������ �Ҵ�
	queue->front = node->next; // ���ο� front�� ���� front�� next�� ��
	free(node); // ���� front���� node �Ҵ� ����
	queue->count--;
	return data;
}

void show(Queue* queue) {
	Node* cur = queue->front;
	printf("--- ť�� �� ---\n");
	while (cur != NULL) {
		printf("%d\n", cur->data);
		cur = cur->next;
	}
	printf("---- ť�� �� ---\n");
}

int main(void) {
	Queue queue;
	queue.front = queue.rear = NULL;
	queue.count = 0;
	push(&queue, 7);
	push(&queue, 5);
	push(&queue, 4);
	pop(&queue);
	push(&queue, 6);
	pop(&queue);
	show(&queue);
	system("pause");
	return 0;
}