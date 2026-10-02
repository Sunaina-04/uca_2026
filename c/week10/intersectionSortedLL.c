#include <stdio.h>
#include <stdlib.h>

// 1-->2-->33->4 --> null 

struct Node {
        int data;
        struct Node* next;
};

struct Node* createNode(int data){
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = data;
        newNode->next = NULL;
        return newNode;
}

void print(struct Node* head) {
        struct Node* temp = head;
        while (temp) {
                printf("%d ",temp -> data);
                temp = temp-> next;
        }
        printf("NULL \n");
}

struct Node* intersection(struct Node* l1, struct Node* l2) {
	if (l1 == NULL || l2 == NULL) {
		return NULL;
	}

	struct Node* temp1 = l1;
        struct Node* temp2 = l2;
	struct Node* newHead = createNode(0);
	struct Node* temp = newHead;

	while (temp1 != NULL && temp2 != NULL) {
		if(temp1-> data < temp2-> data) {
			temp1 = temp1->next;
		}
		else if(temp1-> data == temp2-> data){
			struct Node* newNode = createNode(temp1-> data);	
			temp -> next = newNode;
			temp = temp-> next;
			temp1 = temp1-> next;
			temp2 = temp2-> next;
		}else {
			temp2 = temp2 -> next;
	
		}
	}
//	print(newHead);
//	struct Node result = newHead-> next;
	return newHead->next;
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
	// 1->2->3->4->5->6->null
    struct Node* list2 = createNode(1);
    list2->next = createNode(2);
    list2->next->next = createNode(2);
    list2->next->next->next = createNode(2);
    list2->next->next->next->next = createNode(5);
    list2->next->next->next->next->next = createNode(6);

    // 2->4->6->8
    struct Node* list1 = createNode(2);
    list1->next = createNode(2);
    list1->next->next = createNode(6);
    list1->next->next->next = createNode(8);


    struct Node* head = intersection(list1, list2);

    print(head);
    
    // Clean up memory
    freeList(list1);
    freeList(list2);
    freeList(head);

    return 0;
}
