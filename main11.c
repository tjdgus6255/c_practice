#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX_VALUE 10001

int n, m;
int a[MAX_VALUE];

int main(void) {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) { scanf("%d", &m); a[m]++; } 
	// 어떤 값이 입력될 때마다 그 값에 해당하는 index의 값이 1씩 증가
	for (int i = 0; i < MAX_VALUE; i++) {
		while (a[i] != 0) { printf("%d ", i); a[i]--; }
	}
	system("pause");
	return 0;
}