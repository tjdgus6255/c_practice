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
	if (root == NULL) { // root�� null�� ���
		root = (Node*)malloc(sizeof(Node));
		root->leftChild = root->rightChild = NULL;
		// root�� �ڽ� ��� �ʱ�ȭ 
		root->data = data; // root�� data ����
		return root;
	}
	else { // root�� null�� �ƴ� ���
		if (root->data > data) {  
			root->leftChild = insertNode(root->leftChild, data);
		}
		else {
			root->rightChild = insertNode(root->rightChild, data);
		}
		// root�� data ũ�⿡ ���� ���� / ������ ����
	}
	return root;
}

Node* searchNode(Node* root, int data) {
	if (root == NULL) return NULL;
	if (root->data == data) return root;
	else if (root->data > data) return searchNode(root->leftChild, data);
	else return searchNode(root->rightChild, data);
}

void preorder(Node* root) { // ������ȸ���
	if (root == NULL) return;
	printf("%d ", root->data);
	preorder(root->leftChild);
	preorder(root->rightChild);
}

Node* findMinNode(Node* root) { 
	Node* node = root;
	while (node->leftChild != NULL) { // ���� �ڽ� ��尡 null�� �� ������ �ݺ�
		node = node->leftChild;
	}
	return node; // ������ ���� �ڽ� ��� ��ȯ
}

Node* deleteNode(Node* root, int data) {
	Node* node = NULL;
	if (root == NULL) return NULL;
	if (root->data > data) root->leftChild = deleteNode(root->leftChild, data);
	else if (root->data < data) root->rightChild = deleteNode(root->rightChild, data);
	else { // ������ data�� ã�� ���
		if (root->leftChild != NULL && root->rightChild != NULL) { // ������ data�� �ڽ� ��带 2�� ���� �ִ� ���
			node = findMinNode(root->rightChild); 
			// �ڽ��� ������ �ڽ� ��忡�� ���� ���� ��带 ã��
			// ��, ������ ��� �ٷ� �������� ū ���
			root->data = node->data; // �ٷ� �������� ū ��带 ������ ����� �ڸ��� ����
			root->rightChild = deleteNode(root->rightChild, node->data);
		}
		else {
			node = (root->leftChild != NULL) ? root->leftChild : root->rightChild;
			// �ڽ� ��尡 �ϳ� �϶� �ڽ� ��带 �ٷ� ������ ��忡 ����
			free(root); // ������ ��� �Ҵ� ����
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
