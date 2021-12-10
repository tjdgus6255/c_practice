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
	int count; // 원소의 개수를 나타냄
}Queue;

void push(Queue* queue, int data) {
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = data;
	node->next = NULL;
	if (queue->count == 0) { // queue가 비어있으면 count를 0으로 만듬
		queue->front = node; // front에 node (삽입 초기화)
	}
	else {
		queue->rear->next = node; // 기존 rear의 다음 node에 삽입할 node가 들어옴
	}
	queue->rear = node; // 삽입할 node가 새로운 rear로 들어감
	queue->count++;
}

int pop(Queue* queue) {
	if (queue->count == 0) {
		printf("큐 언더플로우가 발생했습니다.\n");
		return -INF;
	}
	Node* node = queue->front; // 포인터 변수 node에 기존 front를 넣음
	int data = node->data; // front의 data를 data 변수에 할당
	queue->front = node->next; // 새로운 front는 기존 front의 next가 들어감
	free(node); // 기존 front였던 node 할당 해제
	queue->count--;
	return data;
}

void show(Queue* queue) {
	Node* cur = queue->front;
	printf("--- 큐의 앞 ---\n");
	while (cur != NULL) {
		printf("%d\n", cur->data);
		cur = cur->next;
	}
	printf("---- 큐의 뒤 ---\n");
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