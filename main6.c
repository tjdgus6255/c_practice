#include <stdio.h>
#define SIZE 10000
#define INF 99999999

int queue[SIZE];
int front = 0; // 0 index를 가리키도록 함
int rear = 0; // 0 index를 가리키도록 함

void push(int data) {
	if (rear >= SIZE) {
		printf("큐 오버플로우가 발생했습니다.\n");
		return;
	}
	queue[rear++] = data; // queue의 현재 rear에 data를 삽입한 후 rear index 증가
}

int pop() {
	if (front == rear) {
		printf("큐 언더플로우가 발생했습니다.\n");
		return INF;
	}
	return queue[front++]; // queue의 현재 front에 있는 data를 return 한 후 front index 증가
}

void show() {
	printf("--- 큐의 앞 ---\n");
	for (int i = front; i < rear; i++) {
		printf("%d\n", queue[i]);
	}
	printf("--- 큐의 뒤 ---\n");
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