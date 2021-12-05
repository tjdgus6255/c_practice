#include <stdio.h>
#define INF 10000 

int arr[INF]; 
int count = 0;

void addBack(int data) {
	arr[count] = data;      // arr list 뒤에 data를 넣음
	count++;
}

void addFirst(int data) {
	for (int i = count; i >= 1; i--) {
		arr[i] = arr[i - 1];      // arr list를 한칸씩 뒤로 미룸
	arr[0] = data;
	count++;
}

void show() {
	for (int i = 0; i < count; i++) {
		printf("%d ", arr[i]);      // arr list가 포함하는 원소를 모두 보여줌
	}
}

void removeMy(int index) {
	for (int i = count; i > index; i--) {
		arr[i - 1] = arr[i];
	}
	count--;
}

void removeAt(int index) {
	for (int i = index; i < count - 1; i++) {
		arr[i] = arr[i + 1];
	}
	count--;
}

int main(void) {
	addFirst(4);
	addFirst(5);
	addFirst(1);
	addBack(7);
	addBack(6);
	addBack(8);
	show();
	printf("\n");
	removeMy(2);
	show();
	system("pause");
	return 0;
}