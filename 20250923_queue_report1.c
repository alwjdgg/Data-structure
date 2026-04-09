#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdbool.h>

#define SIZE 30
typedef struct {
	int data[SIZE];
	int front;
	int rear;
}LinearQueue;

void initQueue(LinearQueue* q) {
	q->front = 0;
	q->rear = -1;
}
bool isEmpty(LinearQueue* q) {
	return q->rear < q->front;
}
bool isfull(LinearQueue* q) {
	return q->rear == SIZE - 1;
}
bool enqueue(LinearQueue* q, int value) {
	if (isfull(q)) {
		printf("큐가 가득 찼습니다.\n");
		return false;
	}
	q->rear++;
	q->data[q->rear] = value;
	return true;
}
int dequeue(LinearQueue* q) {
	if (isEmpty(q)) {
		printf("큐가 비어있습니다.\n");
		return -1;

	}
	int value = q->data[q->front];
	q->front++;
	if (isEmpty(q)) {
		initQueue(q);
	}
	return value;
}
void printQueue(LinearQueue* q) {
	if (isEmpty(q)) {
		printf("큐가 비어있습니다.\n");
		return;
	}
	printf("queue data: ");
	for (int i = q->front; i <= q->rear; i++) {
		printf("%d ", q->data[i]);
	}
}
int main() {
	LinearQueue q;
	int choice;
	int number;
	initQueue(&q);
	while (1) {
		printf("\n-----메뉴-----\n");
		printf("1.삽입 2.제거 3.큐 데이터 출력 4.종료\n ");
		scanf("%d", &choice);
		switch (choice) {
		case 1: 
			printf("큐에 넣을 숫자 입력: ");
			scanf("%d", &number);
			enqueue(&q, number);
			break;
		case 2:
			number=dequeue(&q);
			if (number != -1)printf("deque value: %d\n", number);
			break;
		case 3:
			printf("큐의 현재 데이터: ");
			printQueue(&q);
			break;
		case 4:
			printf("프로그램 종료");
			return 0;


		}
		
	}
	

}