#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int data;
	struct Node* prev;
	struct Node* next;
}Node;

Node* head, * tail;

void insert(int data) {
	Node* node = (Node*)malloc(sizeof(Node));  // node 할당
	node->data = data; // data 초기화
	Node* cur;
	cur = head->next;
	while (cur->data < data && cur != tail) {
		cur = cur->next;
	}
	Node* prev = cur->prev; // 삽입할 위치에 있는 node(기존 node)의 prev를 prev 포인터 변수에 담음
	prev->next = node; // 앞 node(prev 포인터 변수)의 next를 현재 삽입할 node로 설정
	node->prev = prev; // 현재 삽입할 node의 prev를 앞 node(prev 포인터 변수)로 잡음
	cur->prev = node; // 삽입할 위치에 있는 node(기존 node)의 prev는 현재 삽입할 node로 설정
	node->next = cur; // 현재 삽입할 node의 next는 삽입할 위치에 있는 node로 설정
}

void removeFront() {
	Node* node = head->next; // node 초기화 
	head->next = node->next; // 제거할 node가 가리키는 node를 head가 가리키도록 함
	Node* next = node->next; // 제거할 node가 가리키는 node를 next 포인터 변수에 담음
	next->prev = head; // 제거한 node의 다음 node의 prev를 head로 지정
	free(node); // 제거할 node의 할당 해제
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