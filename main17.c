#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int a[1001][1001];
int n, m;

// 무방향 비가중치 그래프와 인접 행렬
int main(void) {
	scanf("%d %d", &n, & m); // 노드와 간선의 갯수를 입력 받음
	for (int i = 0; i < m; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		a[x][y] = 1; 
		a[y][x] = 1;
		// 노드x와 노드y가 연결되었음을 나타냄
		// 방향성이 없으므로 서로 연결되도록 만들어줌
		// 간선의 갯수만큼 노드를 연결시킴
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
	system("pause");
	return 0;
}