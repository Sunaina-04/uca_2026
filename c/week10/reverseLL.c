// this file will contain logic to reverse a linkedlist
#include <stdio.h>
#include <stdlib.h>

// 1-->2-->33->4 --> null 

struct Node {
	int data;
	struct Node* next;
};

struct Node* reverseLL (struct Node* head) {
	if (head == NULL || head-> next == NULL) {
		return head;
	}	
	struct Node* newHead = reverseLL(head -> next);

	head -> next -> next = head;
	head -> next = NULL;

	return newHead;
}

void print(struct Node* head) {
	struct Node* temp = head;
	while (temp) {
		printf("%d ",temp -> data);
		temp = temp-> next;
	} 
	printf("NULL \n");
}

struct Node* createNode(int data){
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = data;
	newNode->next = NULL;
	return newNode;	
}

void freeList(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
	struct Node* head = createNode(1);
   	head->next = createNode(2);
   	head->next->next = createNode(3);
   	head->next->next->next = createNode(4);
   	head->next->next->next->next = createNode(5);
	printf("OG List: \n");
	print(head);
	head = reverseLL(head);
	printf("Reversed List: \n");
	print(head);
	freeList(head);
	return 0;
}
