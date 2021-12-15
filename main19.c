#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 1001

typedef struct {
	int index;
	struct Node* next;
}Node;

Node** a;
int n, m, c[MAX_SIZE]; // n : 정점(노드), m : 간선, c : 방문 확인 변수

void addFront(Node* root, int index) {
	Node* node = (Node*)malloc(sizeof(Node));
	node->index = index;
	node->next = root->next;
	root->next = node;
}

void dfs(int x) {
	if (c[x]) return; // 해당 노드를 방문한 적이 있을 경우 종료
	c[x] = 1; // 방문한 적이 없다면 방문 처리
	printf("%d ", x);
	Node* cur = a[x]->next; // 해당 노드에 연결되어 있는 노드들을 방문
	while (cur != NULL) {
		int next = cur->index;
		dfs(next); // 재귀적으로 수행
		cur = cur->next;
	}
}

int main(void) {
	scanf("%d %d", &n, &m);
	a = (Node**)malloc(sizeof(Node*) * (MAX_SIZE));
	for (int i = 1; i <= n; i++) {
		a[i] = (Node*)malloc(sizeof(Node));
		a[i]->next = NULL;
	}
	for (int i = 0; i < m; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		addFront(a[x], y);
		addFront(a[y], x);
	}
	dfs(1);
	system("pause");
	return 0;
}