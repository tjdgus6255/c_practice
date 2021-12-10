#include <stdio.h>
#define SIZE 10000
#define INF 99999999

int queue[SIZE];
int front = 0; // 0 index�� ����Ű���� ��
int rear = 0; // 0 index�� ����Ű���� ��

void push(int data) {
	if (rear >= SIZE) {
		printf("ť �����÷ο찡 �߻��߽��ϴ�.\n");
		return;
	}
	queue[rear++] = data; // queue�� ���� rear�� data�� ������ �� rear index ����
}

int pop() {
	if (front == rear) {
		printf("ť ����÷ο찡 �߻��߽��ϴ�.\n");
		return INF;
	}
	return queue[front++]; // queue�� ���� front�� �ִ� data�� return �� �� front index ����
}

void show() {
	printf("--- ť�� �� ---\n");
	for (int i = front; i < rear; i++) {
		printf("%d\n", queue[i]);
	}
	printf("--- ť�� �� ---\n");
}

int main(void) {
	push(7);
	push(5);
	push(4);
	pop();
	push(6);
	pop();
	show();
	system("pause");
	return 0;
}