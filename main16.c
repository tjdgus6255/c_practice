#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX_SIZE 100000

int a[MAX_SIZE];
int founded = 0;

int search(int start, int end, int target) {
	if (start > end) return -9999; // 종료 조건
	int mid = (start + end) / 2; 
	if (a[mid] == target) return mid; // 중간 값이 target과 동일한 경우 중간 값 반환
	else if (a[mid] > target) return search(start, mid - 1, target);
	// 중간 값이  target보다 큰 경우 start ~ mid 직전 값에서 search 수행
	else return search(mid + 1, end, target); 
	// 중간 값이  target보다 작은 경우 mid 직후 값 ~ end에서 search 수행
}

int main(void) {
	int n, target;
	scanf("%d %d", &n, &target);
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);
	int result = search(0, n - 1, target);
	if (result != -9999) printf("%d번째 원소입니다.\n", result + 1);
	else printf("원소를 찾을 수 없습니다.\n");
	system("pause");
	return 0;
}