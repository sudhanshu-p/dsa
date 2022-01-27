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
void removeByValue (Node** head, Node* node, int val);
void removeByPriority (Node** head, Node* node, int val);
void removeByIndex (Node** head, Node* node, int val);
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
		printf("What operation do you want to carry out on this list?\n1: Insert an element\n2: Remove an element\n3: Print the list\n4: Exit\n");
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
				printf("You chose to remove an element.\n");
				printf("Select how you want to remove an element: \n1: Using the value\n2: Using the priority\n3: Using it's index\n");
				scanf("%d", &t1);
				switch(t1) {
					case 1: 
						printf("You chose to remove an element by it's value\n");
						printf("Enter the value: ");
						scanf("%d", &t2);
						removeByValue(&head, head, t2);
						printf("Removed all elements of value %d\n", t2);
						break;
					case 2:
						printf("You chose to remove an element by priority\n");
						printf("Enter the priority: ");
						scanf("%d", t2);
						removeByPriority(&head, head, t2);
						printf("Removed all elements of priority %d\n", t2);
						break;
					case 3: 
						printf("You chose to remove an element by it's index\n");
						printf("Enter the index: ");
						scanf("%d", &t2);
						removeByIndex(&head, head, t2);
						printf("Removed all elements of index %d\n", t2);
						break;
					default: 
						printf("Invalid choice.\n");
				}
				break;
			case 3: 
				printf("You chose to print the list.\n");
				printf("The list is: \n");
				printList(head);
				break;
			case 4: 
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