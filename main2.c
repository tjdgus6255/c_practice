#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int data;              // ����ü ����
	struct Node* next;
} Node;

Node* head;     // node�� ���ۺκ�

void addFront(Node* root, int data) { // root�� ������ ����� ��ġ
	Node* node = (Node*)malloc(sizeof(Node));    // data�� ���� node ����
	node->data = data;   // node�� data ����
	node->next = root->next;   // node�� ������ �� ���� ������ ��ġ�� ��尡 ����Ű�� ���� ��带 ����
	root->next = node;   // ������ ��ġ�� ���� ���� ������ node�� ����Ű���� ��
}

void removeFront(Node* root) { // ������ ����� ���� ���..? 
	Node* front = root->next;  // ������ ��带 ����Ű�� ������ ������ ����
	root->next = front->next;  // ������ ��尡 ����Ű�� ��带 root ��� ���� ���� ����
	free(front); // ������ ����� �Ҵ� ����
}

// head�� �Ҵ� ������ ���� ���� �ʾƵ� ��
// ������ �����ϰ� ������ �� ��

void freeAll(Node* root) {
	Node* cur = head->next;  // head�� ����Ű�� ���� ��带 �޴� ������ ������ ����
	while (cur != NULL) {
		Node* next = cur->next;    // ���� ��尡 ����Ű�� ���� ��带 �޴� ������ ������ ����
		free(cur);  // ���� ��� �Ҵ� ����
		cur = next;  // ���� ��尡 �ٽ� ���� ��尡 ��
	}
}

void showAll(Node* root) {
	Node* cur = head->next;    // freeAll �Լ����� ����� ����� �̿��Ͽ� ��ü ���Ҹ� ���
	while (cur != NULL) {
		printf("%d ", cur->data);
		cur = cur->next;
	}
}
int main(void) {
	head = (Node*)malloc(sizeof(Node));      // �����Ҵ����� head ����
	/*Node* node1 = (Node*)malloc(sizeof(Node));    //   ''
	node1->data = 1;
	Node *node2 = (Node*)malloc(sizeof(Node));    //   ''
	node2->data = 2;
	head->next = node1;        // head���� node1����
	node1->next = node2;       // node1���� node2��
	node2->next = NULL;        // node2�� ������ ����̹Ƿ� null�� ����Ű���� ��
	Node* cur = head->next;    // head->next ���� ������ cur ������ ���� ����
	while (cur != NULL) {
		printf("%d\n", cur->data);   // ���� ��尡 ������ �ִ� �����͸� ���
		cur = cur->next;    // ���� ��尡 ����Ű�� ���� ���� �̵�
	}*/
	head->next = NULL; // head next�� �ʱⰪ���δ� null�� �־��־����
	addFront(head, 2);
	addFront(head, 1);
	addFront(head, 7);
	addFront(head, 9);
	addFront(head, 8);
	removeFront(head);
	showAll(head);
	freeAll(head);
	system("pause");
	return 0;
}