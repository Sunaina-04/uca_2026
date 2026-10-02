#include <stdio.h>
#include <stdlib.h>

// 1-->2-->33->4 --> null 

struct Node {
        int data;
        struct Node* next;
};

void search (struct Node* head1, struct Node* head2) {
	if (head1 == NULL) {
		printf("Yes");
		return;
	}
	// temp to treat every node as a potential start
	
	struct Node* temp = head2;
	
	while (temp != NULL) {

		struct Node* temp1 = head1;
        	struct Node* temp2 = temp;
		
		while (temp1 != NULL && temp2 != NULL && temp1-> data == temp2-> data){
				temp1 = temp1-> next;
				temp2 = temp2-> next;
		}
		if (!temp1) {
			printf("YES");
			return;
		}
	
		temp = temp-> next;
	}
	printf("No");
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
	// 3->2->10->20->50
    struct Node* list2 = createNode(3);
    list2->next = createNode(2);
    list2->next->next = createNode(10);
    list2->next->next->next = createNode(30);
    list2->next->next->next->next = createNode(5);

    // 10->20
    struct Node* list1 = createNode(10);
    list1->next = createNode(20);

    printf("List 1 (Pattern): \n");
    print(list1);

    printf("List 2 (Target): \n");
    print(list2);

    printf("Result: ");
    search(list1, list2); // Output: Yes

    // Clean up memory
    freeList(list1);
    freeList(list2);

    return 0;
}
