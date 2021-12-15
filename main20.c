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
int n, m, c[MAX_SIZE]; // n : 정점(노드), m : 간선, c : 방문 확인 변수

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
		queue->front = node; // queue가 비어있다면 front에 node 삽입
	}
	else {
		queue->rear->next = node; // queue가 비어있지 않다면 rear->next에 node 삽입
	} 
	queue->rear = node; // 결과적으로 rear에 node 삽입
	queue->count++;
}

int queuePop(Queue* queue) {
	if (queue->count == 0) {
		printf("큐 언더플로우가 발생했습니다.\n");
		return -INF;
	}
	Node* node = queue->front; // queue의 front값을 node 포인터 변수에 삽입
	int index = node->index; // 제거할 node의 index를 index 변수에 삽입
	queue->front = node->next; // 제거할 node가 가리키는 다음 node를 queue front에 삽입
	free(node); // 제거할 node 할당 해제
	queue->count--; 
	return index;
}

void bfs(int start) {
	Queue q;
	q.front = q.rear = NULL; // 초기화
	q.count = 0;
	queuePush(&q, start); // queue에 start index 삽입
	c[start] = 1; // start 방문 처리
	while (q.count != 0) {
		int x = queuePop(&q);
		printf("%d", x);
		Node* cur = a[x]->next;
		while (cur != NULL) {
			int next = cur->index;
			if (!c[next]) {  // 해당 node를 방문하지 않은 상태라면
				queuePush(&q, next); // queue에 삽입
				c[next] = 1; // 방문 처리
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
	for (int i = 0; i < m; i++) {  // 간선의 갯수만큼 연결을 만듬
		int x, y;
		scanf("%d %d", &x, &y);
		addFront(a[x], y); 
		addFront(a[y], x);
		// 두 개의 노드를 각각 연결
	}
	bfs(1); // 만들어진 nodedp 대해 탐색 시작
	system("pause");
	return 0;
}