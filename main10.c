#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define SIZE 1000

int a[SIZE];

int swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void quickSort(int start, int end) {
	if (start >= end) return;
	int key = start, i = start + 1, j = end, temp;
	while (i <= j) { // 엇갈릴 때까지 반복합니다.
		while (i <= end && a[i] <= a[key]) i++; // 결과적으로 a[i] > a[key]를 만족하는 i 값이 들어감
		while (j > start && a[j] >= a[key]) j--; // 결과적으로 a[j] < a[key]를 만족하는 j 값이 들어감
		if (i > j) swap(&a[key], &a[j]); // 엇갈린 상태에서는 a[key]와 a[j]를 바꾸어줌
		else swap(&a[i], &a[j]); // 엇갈리지 않았다면 a[i]와 a[j]를 바꾸어줌
	}
	quickSort(start, j - 1); // 위의 과정을 수행한 후에는 재귀함수를 통해 부분적으로 수행
	quickSort(j + 1, end);
}

int main(void) {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);
	quickSort(0, n - 1);
	for (int i = 0; i < n; i++) printf("%d", a[i]);
	system("pause");
	return 0;
}