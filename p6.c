#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int data;
	struct Node* next;
	struct Node* prev;
} Node;

void traverse (Node* node) {
	while(node != NULL) {
		printf("%d\t", node->data);
		node = node->next;
	}
	printf("\n");
}

void reverseTraversal(Node* node) {
	while(node->next != NULL)
		node = node->next;
	while(node != NULL) {
		printf("%d\t", node->data);
		node = node->prev;
	}
	printf("\n");
}

int lengthOfList (Node* node) {
	int count = 0;
	while(node != NULL){
		count++;
		node = node->next;
	}
	return count;
}

void insertDoubly (Node** head, Node* node, int val, int choice, int c2){
	Node* tempNode = (Node *) malloc (sizeof(Node));
	tempNode->data = val;
	tempNode->next = NULL;
	tempNode->prev = NULL;
	if(node == NULL) {
		*head = tempNode;
		return;
	}
	switch(choice) {
		case 1: 
			tempNode->next = node;
			node->prev = tempNode;
			*head = tempNode;
			return;
		case 2: 
			if(c2 < lengthOfList (node)) {
				Node* previous = node;
				while(node->next != NULL) {
					previous = node;
					node = node->next;
				}
				previous->next = tempNode;
				node->prev = tempNode;
				tempNode->prev = previous;
				tempNode->next = node;
				return;
			}
			else {
				printf("That element does not exist!\n");
				return;
			}
		case 3:
			while(node->next!= NULL) {
				node = node->next;
			}
			node->next = tempNode;
			tempNode->prev = node;
			return;
		default:
			printf("Invalid choice! \n");
			return;
	}
}

int deleteDoubly (Node** head, Node* node, int choice, int loc) {
	int temp;
	if(lengthOfList(node) == 1) {
		temp = node->data;
		*head = NULL;
		return temp;
	}
	Node* tempNode = (Node*) malloc (sizeof(Node));
	int count = 0;
	switch(choice) {
		case 1:
			tempNode = node;
			tempNode = tempNode->next;
			tempNode->prev = NULL;
			*head = tempNode;
			return node->data;
		case 2: 
			if(loc >= lengthOfList(node)) 
				return NULL;
			while(count < loc){
				node = node->next;
				count++;
			}
			tempNode = node->prev;
			temp = node->data;
			node = node->next;
			tempNode->next = node;
			node->prev = tempNode;
			return temp;
		case 3: 
			while(node->next != NULL)
				node = node->next;
			tempNode = node->prev;
			tempNode->next = NULL;
			return node->data;
	}
}

int main() {
	Node* head = (Node*) malloc (sizeof(Node));
	head = NULL;
	int c1, c2;
	while(1) {
		printf("Enter your choice: \n1: Insertion\n2: Deletion\n3: Print the list\nYour Choice: ");
		scanf("%d", &c1);
		if(c1 == -1)
			break;
		switch(c1) {
			case 1: 
				printf("You chose insertion. Enter the element you want to insert: ");
				scanf("%d", &c2);
				int temp;
				printf("Enter where you want to insert \n1: At the start\n2: In the middle\n3: At the end\nYour choice: ");
				scanf("%d", &temp);
				if(temp == 2) {
					printf("Enter where you want to insert: ");
					scanf("%d", &temp);
					insertDoubly (&head, head, c2, 2, temp);
					break;
				}
				insertDoubly (&head, head, c2, temp, 99);
				break;
			case 2:
				if(lengthOfList(head) == 0) {
					printf("The list is Empty!\n");
					break;
				}
				printf("You chose deletion. Enter how you want to delete: \n1: The start\n2: In the middle\n3: The end\nYour choice: ");
				scanf("%d", &c2);
				if(c2 == 2) {
					printf("Enter where you want to delete: ");
					scanf("%d", &temp);
					temp = deleteDoubly (&head, head, 2, temp);
					printf("Element deleted: %d\n", temp);
					break;
				}
				temp = deleteDoubly (&head, head, c2, 9999);
				printf("Element deleted: %d\n", temp);
				break;
			case 3: 
				if(lengthOfList(head) == 0) {
					printf("The list is Empty!\n");
					break;
				}
				printf("Enter the way you want the list printed: \n1: Forward\n2: Reverse\nYour choice: ");
				scanf("%d", &c2);
				switch(c2) {
					case 1: 
						printf("The linked list is: \n");
						traverse(head);
						break;
					case 2: 
						printf("The linked list reversed is: \n");
						reverseTraversal(head);
						break;
					default:
						printf("Invalid choice.\n");
				}
				break;
			default:
				printf("Noi\n");
		}
	}
	printf("Goodbye\n");
}