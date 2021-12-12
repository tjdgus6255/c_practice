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
	while (i <= j) { // ������ ������ �ݺ��մϴ�.
		while (i <= end && a[i] <= a[key]) i++; // ��������� a[i] > a[key]�� �����ϴ� i ���� ��
		while (j > start && a[j] >= a[key]) j--; // ��������� a[j] < a[key]�� �����ϴ� j ���� ��
		if (i > j) swap(&a[key], &a[j]); // ������ ���¿����� a[key]�� a[j]�� �ٲپ���
		else swap(&a[i], &a[j]); // �������� �ʾҴٸ� a[i]�� a[j]�� �ٲپ���
	}
	quickSort(start, j - 1); // ���� ������ ������ �Ŀ��� ����Լ��� ���� �κ������� ����
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