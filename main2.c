#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int data;              // 구조체 생성
	struct Node* next;
} Node;

Node* head;     // node의 시작부분

void addFront(Node* root, int data) { // root는 삽입할 노드의 위치
	Node* node = (Node*)malloc(sizeof(Node));    // data를 담을 node 생성
	node->data = data;   // node에 data 삽입
	node->next = root->next;   // node의 다음에 올 노드로 삽입할 위치의 노드가 가리키는 다음 노드를 넣음
	root->next = node;   // 삽입할 위치의 노드는 새로 생성한 node를 가리키도록 함
}

void removeFront(Node* root) { // 삭제할 노드의 이전 노드..? 
	Node* front = root->next;  // 삭제할 노드를 가리키는 포인터 변수를 만듬
	root->next = front->next;  // 삭제할 노드가 가리키는 노드를 root 노드 다음 노드로 설정
	free(front); // 삭제할 노드의 할당 해제
}

// head의 할당 해제는 굳이 하지 않아도 됨
// 완전히 제거하고 싶으면 할 것

void freeAll(Node* root) {
	Node* cur = head->next;  // head가 가리키는 다음 노드를 받는 포인터 변수를 만듬
	while (cur != NULL) {
		Node* next = cur->next;    // 현재 노드가 가리키는 다음 노드를 받는 포인터 변수를 만듬
		free(cur);  // 현재 노드 할당 해제
		cur = next;  // 다음 노드가 다시 현재 노드가 됨
	}
}

void showAll(Node* root) {
	Node* cur = head->next;    // freeAll 함수에서 사용한 방식을 이용하여 전체 원소를 출력
	while (cur != NULL) {
		printf("%d ", cur->data);
		cur = cur->next;
	}
}
int main(void) {
	head = (Node*)malloc(sizeof(Node));      // 동적할당으로 head 정의
	/*Node* node1 = (Node*)malloc(sizeof(Node));    //   ''
	node1->data = 1;
	Node *node2 = (Node*)malloc(sizeof(Node));    //   ''
	node2->data = 2;
	head->next = node1;        // head에서 node1으로
	node1->next = node2;       // node1에서 node2로
	node2->next = NULL;        // node2는 마지막 노드이므로 null을 가리키도록 함
	Node* cur = head->next;    // head->next 값을 가지는 cur 포인터 변수 생성
	while (cur != NULL) {
		printf("%d\n", cur->data);   // 현재 노드가 가지고 있는 데이터를 출력
		cur = cur->next;    // 현재 노드가 가리키는 다음 노드로 이동
	}*/
	head->next = NULL; // head next의 초기값으로는 null을 넣어주어야함
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