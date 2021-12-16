#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define TABLE_SIZE 10007
#define INPUT_SIZE 5000

typedef struct {
	int id;
	char name[20];
}Student;

typedef struct { // 체이닝 기법은 연결리스트를 사용함
	Student* data;
	struct Bucket* next;
}Bucket;

// 해시 테이블을 초기화합니다.
void init(Student** hashTable) {
	for (int i = 0; i < TABLE_SIZE; i++) {
		hashTable[i] = NULL;
	}
}

// 해시 테이블의 메모리를 반환합니다.
void destructor(Student** hashTable) {
	for (int i = 0; i < TABLE_SIZE; i++) {
		if (hashTable[i] != NULL) {
			free(hashTable[i]);
		}
	}
}

int isExist(Bucket** hashTable, int id) {
	int i = id % TABLE_SIZE;
	if (hashTable[i] == NULL) return 0;
	else {
		Bucket* cur = hashTable[i]; // 해시 테이블을 포인터 변수로 받아서
		while (cur != NULL) { 
			if (cur->data->id == id) return 1; 
			// 현재 data의 id가 확인하고자 하는 id와 동일한 경우 1 반환
			cur = cur->next;
		}
	}
	return 0;
}

void add(Bucket** hashTable, Student* input) {
	int i = input->id % TABLE_SIZE;
	if (hashTable[i] == NULL) { // 해시 테이블의 해당 위치가 빈 공간일 경우
		hashTable[i] = (Bucket*)malloc(sizeof(Bucket));
		hashTable[i]->data = input;
		hashTable[i]->next = NULL;
		// 동적 할당 후 data 삽입
	}
	else { // 해시 테이블의 해당 위치가 빈 공간이 아닌 경우
		Bucket* cur = (Bucket*)malloc(sizeof(Bucket));
		cur->data = input; 
		cur->next = hashTable[i];
		hashTable[i] = cur;
		// 해당 위치에 그대로 삽입
	}
}

// 해시 테이블에 존재하는 모든 데이터를 출력합니다.
void show(Bucket** hashTable) {
	for (int i = 0; i, TABLE_SIZE; i++) {
		if (hashTable[i] != NULL) {
			Bucket* cur = hashTable[i];
			while (cur != NULL) {
				printf("키: [%d] 이름: [%s]\n", i, cur->data->name);
				cur = cur->next;
			}
		}
	}
}

int main(void) {
	Bucket **hashTable;
	hashTable = (Bucket**)malloc(sizeof(Bucket) * TABLE_SIZE);
	init(hashTable);

	for (int i = 0; i < INPUT_SIZE; i++) {
		Student* student = (Student*)malloc(sizeof(Student));
		student->id = rand() % 1000000; // 랜덤값으로 id를 정함
		sprintf(student->name, "사람%d", student->id); // 학생의 이름은 '사람 + 번호'
		if (!isExist(hashTable, student->id)) { // 중복되는 ID는 존재하지 않도록 함
			add(hashTable, student);
		}
	}

	show(hashTable);
	destructor(hashTable); // 할당 해제
	system("pause");
	return 0;
}