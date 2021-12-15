#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define INF 99999999
#define MAX_SIZE 1001

typedef struct {
	int index;
	struct Node* next;
}Node;

typedef struct {
	Node* front;
	Node* rear;
	int count;
}Queue;

Node** a;
int n, m, c[MAX_SIZE]; // n : ����(���), m : ����, c : �湮 Ȯ�� ����

void addFront(Node* root, int index) {
	Node* node = (Node*)malloc(sizeof(Node));
	node->index = index;
	node->next = root->next;
	root->next = node;
}

void queuePush(Queue* queue, int index) {
	Node* node = (Node*)malloc(sizeof(Node));
	node->index = index;
	node->next = NULL;
	if (queue->count == 0) {
		queue->front = node; // queue�� ����ִٸ� front�� node ����
	}
	else {
		queue->rear->next = node; // queue�� ������� �ʴٸ� rear->next�� node ����
	} 
	queue->rear = node; // ��������� rear�� node ����
	queue->count++;
}

int queuePop(Queue* queue) {
	if (queue->count == 0) {
		printf("ť ����÷ο찡 �߻��߽��ϴ�.\n");
		return -INF;
	}
	Node* node = queue->front; // queue�� front���� node ������ ������ ����
	int index = node->index; // ������ node�� index�� index ������ ����
	queue->front = node->next; // ������ node�� ����Ű�� ���� node�� queue front�� ����
	free(node); // ������ node �Ҵ� ����
	queue->count--; 
	return index;
}

void bfs(int start) {
	Queue q;
	q.front = q.rear = NULL; // �ʱ�ȭ
	q.count = 0;
	queuePush(&q, start); // queue�� start index ����
	c[start] = 1; // start �湮 ó��
	while (q.count != 0) {
		int x = queuePop(&q);
		printf("%d", x);
		Node* cur = a[x]->next;
		while (cur != NULL) {
			int next = cur->index;
			if (!c[next]) {  // �ش� node�� �湮���� ���� ���¶��
				queuePush(&q, next); // queue�� ����
				c[next] = 1; // �湮 ó��
			}
			cur = cur->next;
		}
	}
}

int main(void) {
	scanf("%d %d", &n, &m);
	a = (Node**)malloc(sizeof(Node*) * (MAX_SIZE));
	for (int i = 1; i <= n; i++) {
		a[i] = (Node*)malloc(sizeof(Node));
		a[i]->next = NULL;
	}
	for (int i = 0; i < m; i++) {  // ������ ������ŭ ������ ����
		int x, y;
		scanf("%d %d", &x, &y);
		addFront(a[x], y); 
		addFront(a[y], x);
		// �� ���� ��带 ���� ����
	}
	bfs(1); // ������� nodedp ���� Ž�� ����
	system("pause");
	return 0;
}