#include<stdio.h>
#include<stdlib.h>
typedef struct Node {
	int data;
	struct Node* next;
}Node;
Node* insertFirst(Node* head, int data) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->next = NULL;
	if (head == NULL) {
		return newNode;
	}
	newNode->next = head;
	return newNode;
}
Node* insertLast(Node* head, int data) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->next = NULL;
	if (head == NULL) {
		return newNode;
	}
	Node* current = head;
	while (current->next != NULL) {
		current = current->next;
	}
	current->next = newNode;
	return head;
}
void insertAfterValue(Node* head, int targetValue, int newData) {
	Node* current = head;
	while (current != NULL) {
		if (current->data == targetValue) {
			Node* newNode = (Node*)malloc(sizeof(Node));
			newNode->data = newData;
			newNode->next = current->next;
			current->next = newNode;
			return;
		}
		current = current->next;
	}
	printf("값 %d를 가진 노드를 찾을 수 없습니다. 삽입하지 않습니다. \n", targetValue);
}
Node* deleteHead(Node* head) {
	if (head == NULL) {
		printf("리스트가 비어있습니다. 삭제할 노드가 없습니다.\n");
		return NULL;
	}
	Node* temp = head;
	head = head->next;
	free(temp);
	return head;
}
Node* deleteLast(Node* head) {
	if (head == NULL) {
		printf("리스트가 비어있습니다. 삭제할 노드가 없습니다.\n");
		return NULL;
	}
	if (head->next == NULL) {
		free(head);
		return NULL;
	}
	Node* current = head;
	while (current->next->next != NULL) {
		current = current->next;
	}
	free(current->next);
	current->next = NULL;
	return head;
}
Node* deleteNode(Node* head, int targetValue) {
	if (head == NULL) {
		printf("리스트가 비어있습니다. 삭제할 노드가 없습니다.\n");
		return NULL;
	}
	if (head->data == targetValue) {
		Node* temp = head;
		head = head->next;
		free(temp);
		return head;
	}
	Node* current = head;
	while (current->next != NULL && current->next->data != targetValue) {
		current = current->next;
	}
	if (current->next == NULL) {
		printf("값 %d를 가진 노드를 찾을 수 없습니다.\n", targetValue);
		return head;
	}
	Node* temp = current->next;
	current->next = current->next->next;
	free(temp);
	return head;

}
void printList(Node* head) {
	Node* current = head;
	while (current != NULL) {
		printf("%d->", current->data);
		current = current->next;
	}printf("NULL\n");
}
int searchValue1(Node* head,int value) {
	int pos = 0;
	if (head == NULL) {
		printf("Head Node가 NULL입니다.\n");
		return -1;
	}
	Node* current = head;
	while (current!= NULL) {
		pos++;
		if (current->data == value) {
			return pos;
		}
			current = current->next;
	}
	printf("값이 없습니다.\n");
	return -1;
}
int searchValue2(Node* head, int value) {
	Node* current = head;
	Node* prev = NULL;

	while (current != NULL) {
		if (current->data == value) {
			if (prev != NULL) {
				printf("앞 노드의 값:%d\n", prev->data);
			}
			else {
				printf("앞 노드가 존재하지 않습니다.\n");
			}
			if (current->next != NULL) {
				printf("뒤 노드의 값:%d\n", current->next->data);

			}
			else {
				printf("뒤 노드가 없습니다.\n");
			}
			return;
		}
		prev = current;
		current = current->next;
		
	}
}
void freeList(Node* head) {
	Node* temp;
	while (head != NULL) {
		temp = head;
		head = head->next;
		free(temp);
	}
	printf("모든 노드가 제거되었습니다.\n");
}
int main() {
	Node* head = NULL;
	head = insertFirst(head, 30);
	head = insertFirst(head, 20);
	head = insertFirst(head, 10);
	head = insertLast(head, 70);
	head = insertLast(head, 80);
	head = insertLast(head, 90);
	insertAfterValue(head, 30, 40);
	insertAfterValue(head, 40, 50);
	insertAfterValue(head, 50, 60);

	head = deleteHead(head);
	head = deleteLast(head);
	head = deleteNode(head, 40);
	head = deleteNode(head, 70);
	head = deleteNode(head, 100);
	int pos = -1;
	int val = 30;
	pos = searchValue1(head, val);
	printf("%d의 위치는 %d번째\n", val, pos);
	searchValue2(head, val);
	freeList(head);
	return 0;
}