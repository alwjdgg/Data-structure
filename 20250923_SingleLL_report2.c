#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<stdlib.h>
#include<string.h>
typedef struct Node {
	char name[100];
	char number[20];
	struct Node* next;
}Node;
Node*ContactAdd(Node* head, char*name, char*number) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	strcpy(newNode->name, name);
	strcpy(newNode->number, number);
	newNode->next=head;
	printf("연락처: %s[%s] 추가\n", name, number);
	return newNode;
}
void ContactSearch(Node* head, char *name) {
	Node* current=head;
	while (current!=NULL) {
		if (strcmp (current->name,name)==0) {
			printf("%s의 연락처:%s", name, current->number);
			return;
		}
		current=current->next;
	} 
	printf("%s 이름의 연락처가 없습니다.\n", name);
}
Node*ContactDelete(Node* head, char* name) {
	Node* current = head;
	Node* prev = NULL;
	while (current != NULL) {
		if (strcmp(current->name, name) == 0) {
			if (prev == NULL) {
				head = current->next;
			}
			else {
				prev->next = current->next;
			}
			printf("삭제완료: %s의 전화번호 - %s\n", current->name, current->number);
			free(current);
			return head;
		}
		prev = current;
		current = current->next;
	}
	if (head == NULL) {
		printf("연락처가 비어있습니다. 삭제할 연락처가 없습니다.\n");
		return NULL;
	}
	printf("%s의 연락처가 없습니다.\n", name);
}
void printList(Node* head) {
	Node* current = head;
	while (current != NULL) {
		printf("이름:%s, 연락처:%s\n", current->name,current->number);
		current = current->next;
	}printf("NULL\n");
}
void freeList(Node* head) {
	Node* temp;
	while (head != NULL) {
		temp = head;
		head = head->next;
		free(temp);

	}
	printf("모든 메모리 해제\n");
}
int main() {
	int menu;
	Node* head = NULL;
	char name[20];
	char number[20];
	while(1){
	printf("\n전화번호부 관리\n");
	printf("1.새로운 연락처 추가2.연락처 검색 3.연락처 삭제 4.현재 전화번호부 출력5. 종료\n");
	scanf("%d", &menu);
	switch (menu) {
	case 1:
		printf("이름: ");
		scanf("%s", name);
		printf("전화번호: ");
		scanf("%s", number);
		head=ContactAdd(head, name, number);
		break;
	case 2:
		printf("이름 ");
		scanf("%s", name);
		ContactSearch(head, name);
		break;
	case 3:
		printf("이름: ");
		scanf("%s", name);
		head = ContactDelete(head, name);
		break;
	case 4:
		printList(head);
		break;
	case 5:
		freeList(head);
		break;
	default:
		printf("잘못된 값 입력. 다시 입력하세요.\n");
		break;
	}
	}
	return 0;
}