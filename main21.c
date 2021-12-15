#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define INF 99999999
#define MAX_SIZE 1001

typedef struct {
	int data;
	struct Node* leftChild;
	struct Node* rightChild;
}Node;

Node* insertNode(Node* root, int data) {
	if (root == NULL) { // root가 null인 경우
		root = (Node*)malloc(sizeof(Node));
		root->leftChild = root->rightChild = NULL;
		// root의 자식 노드 초기화 
		root->data = data; // root에 data 삽입
		return root;
	}
	else { // root가 null이 아닌 경우
		if (root->data > data) {  
			root->leftChild = insertNode(root->leftChild, data);
		}
		else {
			root->rightChild = insertNode(root->rightChild, data);
		}
		// root의 data 크기에 따라 왼쪽 / 오른쪽 선택
	}
	return root;
}

Node* searchNode(Node* root, int data) {
	if (root == NULL) return NULL;
	if (root->data == data) return root;
	else if (root->data > data) return searchNode(root->leftChild, data);
	else return searchNode(root->rightChild, data);
}

void preorder(Node* root) { // 전위순회방식
	if (root == NULL) return;
	printf("%d ", root->data);
	preorder(root->leftChild);
	preorder(root->rightChild);
}

Node* findMinNode(Node* root) { 
	Node* node = root;
	while (node->leftChild != NULL) { // 왼쪽 자식 노드가 null이 될 때까지 반복
		node = node->leftChild;
	}
	return node; // 마지막 왼쪽 자식 노드 반환
}

Node* deleteNode(Node* root, int data) {
	Node* node = NULL;
	if (root == NULL) return NULL;
	if (root->data > data) root->leftChild = deleteNode(root->leftChild, data);
	else if (root->data < data) root->rightChild = deleteNode(root->rightChild, data);
	else { // 삭제할 data를 찾은 경우
		if (root->leftChild != NULL && root->rightChild != NULL) { // 삭제할 data가 자식 노드를 2개 갖고 있는 경우
			node = findMinNode(root->rightChild); 
			// 자신의 오른쪽 자식 노드에서 가장 작은 노드를 찾음
			// 즉, 삭제할 노드 바로 다음으로 큰 노드
			root->data = node->data; // 바로 다음으로 큰 노드를 삭제할 노드의 자리에 삽입
			root->rightChild = deleteNode(root->rightChild, node->data);
		}
		else {
			node = (root->leftChild != NULL) ? root->leftChild : root->rightChild;
			// 자식 노드가 하나 일때 자식 노드를 바로 삭제할 노드에 담음
			free(root); // 삭제할 노드 할당 해제
			return node;
		}
	}
	return root;
}

int main(void) {
	Node* root = NULL;
	root = insertNode(root, 30);
	root = insertNode(root, 17);
	root = insertNode(root, 48);
	root = insertNode(root, 5);
	root = insertNode(root, 23);
	root = insertNode(root, 37);
	root = insertNode(root, 50);
	root = deleteNode(root, 30);
	preorder(root);
	system("pause");
	return 0;
}
