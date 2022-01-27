// Write C Program to implement Priority Queue using linked list. Modify base structure of Linked List by considering 
// priority as a member. Carry out insertion in ordered manner based on priority.

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int data;
	struct Node* next;
	int priority;
} Node;

int priorityInsert (Node** head, Node* node, int val, int priority);
void printList(Node* head);
void createList(Node** head, int val, int priority);

void main() {
	Node* head = NULL;
	int n, t1, t2, t3, c;
	printf("Enter how many elements do you want to initialize your Linked List with: ");
	scanf("%d", &n);
	printf("Enter the element: ");
	scanf("%d", &t1);
	printf("Enter the priority: ");
	scanf("%d", &t2);
	createList(&head, t1, t2);
	n--;
	while(n != 0) {
		printf("Enter element: ");
		scanf("%d", &t1);
		printf("Enter it's priority: ");
		scanf("%d", &t2);
		priorityInsert(&head, head, t1, t2);
		n--;
	}
	printf("The linked list is now initialized.\n");
	while(1) {
		printf("What operation do you want to carry out on this list?\n1: Insert an element\n2: Print the list\n-1: Exit\n");
		scanf("%d", &c);
		switch(c) {
			case 1:
				printf("You chose to insert an element.\n");
				printf("Enter the element to be inserted: ");
				scanf("%d", &t1);
				printf("Enter it's priority: ");
				scanf("%d", &t2);
				t3 = priorityInsert(&head, head, t1, t2);
				printf("The element was inserted at position %d\n", t3);
				break;
			case 2: 
				printf("You chose to print the list.\n");
				printf("The list is: \n");
				printList(head);
				break;
			case -1: 
				printf("Exiting program.\n");
				exit(0);
			default: 
				printf("Invalid choice.\n");
		}	
	}
}

void createList(Node** head, int val, int priority) {
	Node* tempNode = (Node*) malloc(sizeof(Node));
	tempNode->data = val;
	tempNode->priority = priority;
	*head = tempNode;
}

int priorityInsert (Node** head, Node* node, int val, int priority) {
	Node* newNode = (Node*) malloc (sizeof(Node));
	newNode->data = val;
	newNode->priority = priority;
	if(priority >= node->priority) {
		newNode->next = *head;
		*head = newNode;
		return 0;
	}
	int count = 1;
	Node* prev = (Node*) malloc (sizeof(Node));
	while(node->next != NULL) {
		if(priority >= node->priority){
			prev->next = newNode;
			newNode->next = node;
			return count;
		}
		count++;
		prev = node;
		node = node->next;
	}
	node->next = newNode;
	return count;

}

void printList (Node* node) {
	while(node != NULL) {
		printf("Value: %d \tPriority: %d\n", node->data, node->priority);
		node = node->next;
	}
}
