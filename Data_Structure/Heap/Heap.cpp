#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>

#define HEAP_SIZE 256
#define ARRAY_SIZE 10

using namespace std;

int heap[HEAP_SIZE];
int heapCnt = 0;

void init() {
	heapCnt = 0;
}

int size() {
	return heapCnt;
}

void swap(int* a, int* b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void push(int data) {
	//Heap의 가장 끝에 데이터 추가
	heap[++heapCnt] = data;
	
	//Child와 Parent를 비교하여 인덱스 수정(최소 힙 or 최대 힙)
	int child = heapCnt;
	int parent = child / 2;

	while ((child > 1) && (heap[parent] < heap[child])) {	//최대 힙
		swap(&heap[parent], &heap[child]);
		child = parent;
		parent = child / 2;
	}
}

int pop() {
	int result = heap[1];		//힙의 가장 첫 번 째 원소

	//첫 번째 원소를 힙의 가장 끝의 원소와 바꾸고 heapCnt-- 로 해당 인덱스 제거
	swap(&heap[1], &heap[heapCnt]);
	heapCnt--;

	//Child와 Parent를 비교하여 인덱스 수정(최소 힙 or 최대 힙)
	int parent = 1;
	int child = parent * 2;

	if (child + 1 <= heapCnt) {
		child = (heap[child] > heap[child + 1]) ? child : child + 1;
	}

	while ((child <= heapCnt) && (heap[parent] < heap[child])) {
		swap(&heap[parent], &heap[child]);

		parent = child;
		child = child * 2;
		if (child + 1 <= heapCnt) {
			child = (heap[child] > heap[child + 1]) ? child : child + 1;
		}
	}

	return result;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	freopen("input.txt", "r", stdin);

	return 0;
}
