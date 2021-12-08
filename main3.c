#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int data;
	struct Node* prev;
	struct Node* next;
}Node;

Node* head, * tail;

void insert(int data) {
	Node* node = (Node*)malloc(sizeof(Node));  // node �Ҵ�
	node->data = data; // data �ʱ�ȭ
	Node* cur;
	cur = head->next;
	while (cur->data < data && cur != tail) {
		cur = cur->next;
	}
	Node* prev = cur->prev; // ������ ��ġ�� �ִ� node(���� node)�� prev�� prev ������ ������ ����
	prev->next = node; // �� node(prev ������ ����)�� next�� ���� ������ node�� ����
	node->prev = prev; // ���� ������ node�� prev�� �� node(prev ������ ����)�� ����
	cur->prev = node; // ������ ��ġ�� �ִ� node(���� node)�� prev�� ���� ������ node�� ����
	node->next = cur; // ���� ������ node�� next�� ������ ��ġ�� �ִ� node�� ����
}

void removeFront() {
	Node* node = head->next; // node �ʱ�ȭ 
	head->next = node->next; // ������ node�� ����Ű�� node�� head�� ����Ű���� ��
	Node* next = node->next; // ������ node�� ����Ű�� node�� next ������ ������ ����
	next->prev = head; // ������ node�� ���� node�� prev�� head�� ����
	free(node); // ������ node�� �Ҵ� ����
}

void show() {
	Node* cur = head->next;
	while (cur != tail) {
		printf("%d ", cur->data);
		cur = cur->next;
	}
}

int main(void) {
	head = (Node*)malloc(sizeof(Node));
	tail = (Node*)malloc(sizeof(Node));
	head->next = tail;
	head->prev = head;
	tail->next = tail;
	tail->prev = head;
	insert(2);
	insert(1);
	insert(3);
	insert(9);
	insert(7);
	removeFront();
	show();
	system("pause");
	return 0;
}