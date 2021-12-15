#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 1001

typedef struct {
	int index;
	struct Node* next;
}Node;

Node** a;
int n, m, c[MAX_SIZE]; // n : ����(���), m : ����, c : �湮 Ȯ�� ����

void addFront(Node* root, int index) {
	Node* node = (Node*)malloc(sizeof(Node));
	node->index = index;
	node->next = root->next;
	root->next = node;
}

void dfs(int x) {
	if (c[x]) return; // �ش� ��带 �湮�� ���� ���� ��� ����
	c[x] = 1; // �湮�� ���� ���ٸ� �湮 ó��
	printf("%d ", x);
	Node* cur = a[x]->next; // �ش� ��忡 ����Ǿ� �ִ� ������ �湮
	while (cur != NULL) {
		int next = cur->index;
		dfs(next); // ��������� ����
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