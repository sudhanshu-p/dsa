// Write C program to find the middle of a given Linked List. 
// Given a singly linked list, find middle of the linked list. For example, if given linked list is 1→2→3→4→5 then output should be 3. 
// If there are even nodes, then there would be two middle nodes, print second middle element. For example, if given linked list is 
// 1→2→3→4→5→6 then output should be 4.

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int data;
	struct Node* next;
} Node;

void createList (Node** node, int val);
int lengthOfList (Node* node);
int midOfList (Node* node, int length);
void traverse (Node* node);

void insertAtStart (Node** head, int data);
void insertAtPos (Node* node, int data, int loc);
void insertAtEnd (Node* node, int data);

void deleteStart (Node** head, Node* node);
void deleteAtPos (Node* node, int loc);
void deleteEnd (Node* node);

void main() {
	Node* head = NULL;
	int n, t1, t2, c2, c3;
	printf("Enter how many elements do you want to initialize your Linked List with: ");
	scanf("%d", &n);
	printf("Enter the element: ");
	scanf("%d", &t1);
	createList(&head, t1);
	n--;
	while(n != 0) {
		printf("Enter element: ");
		scanf("%d", &t1);
		insertAtEnd (head, t1);
		n--;
	}
	while(1) {
		printf("\n----------------\nNow select the operation you want to perform: \n1: Find the mid of the list\n2: Insert an element in the list\n3: Delete an element from the list\n4: Print the list\n-1: Exit\nYour Choice: ");
		scanf("%d", &c2);
		switch(c2) {
			case 1: 
				t1 = lengthOfList (head);
				t1 = midOfList(head, t1);
				printf("MIddle of the linked list is: %d\n", t1);
				break;
			case 2: 
				printf("You chose to insert an element.\n");
				printf("Enter the element you want to insert: ");
				scanf("%d", &t1);
				printf("Select where you want to insert:\n1: At the beginning\n2: At a specific position\n3: At the end\nYour Choice: ");
				scanf("%d", &c3);
				switch(c3) {
					case 1: 
						printf("Inserting %d at the beginning\n", t1);
						insertAtStart (&head, t1);
						break;
					case 2: 
						printf("Enter the position where you want to insert: ");
						scanf("%d", &t2);
						printf("Inserting %d at the %d position.\n", t1, t2);
						insertAtPos(head, t1, t2);
						break;
					case 3: 
						printf("Inserting %d at the end.\n", t1);
						insertAtEnd(head, t1);
						break;
					default: 
						printf("Invalid Choice.\n");
						break;
				}
				break;
			case 3: 
				printf("You chose to delete an element.\n");
				printf("Enter from where you want to delete:\n1: At the start\n2: At a specific position\n3: At the end\nYour Choice: ");
				scanf("%d", &c3);
				switch(c3) {
					case 1: 
						printf("Deleting the 1st element\n");
						deleteStart(&head, head);
						break;
					case 2: 
						printf("Enter the position of the element you want to delete: ");
						scanf("%d", &t1);
						deleteAtPos(head, t1);
						break;
					case 3: 
						printf("Deleting the last element\n");
						deleteEnd(head);
						break;
					default:
						printf("Invalid Choice.\n");
						break;
				}
				break;
			case 4: 
				traverse (head);
				break;
			case -1:
				printf("Exiting program.\n");	
				exit(0);
			default: 
				printf("Invalid Choice\n");
				break;
			}
	}
}

void createList(Node** head, int val) {
	Node* tempNode = (Node*) malloc(sizeof(Node));
	tempNode->data = val;
	*head = tempNode;
}

int lengthOfList (Node* node) {
	int count = 0;
	if(node == NULL)
		return 0;
	while(node != NULL) {
		node = node-> next;
		count++;
	}
	return count;
}

int midOfList (Node* node, int length) {
	int num = length % 2 == 0 ? (length / 2) + 1 : (length + 1) / 2;
	while(num != 1) {
		node = node->next;
		num--;
	}
	return node->data;
}

void traverse (Node* node) {
	printf("The linked list is: ");
	while(node != NULL) {
		printf("%d  ", node->data);
		node = node->next;
	}
	printf("\n");
}

void insertAtStart (Node** head, int data) {
	Node* newNode = (Node*) malloc (sizeof(Node));
	newNode->data = data;
	newNode->next = *head;
	*head = newNode;
	printf("Insertion successfull\n");
}

void insertAtPos(Node* node, int data, int loc) {
	Node* newNode = (Node*) malloc(sizeof(Node));
	Node* prev;
	prev = node;
	newNode->data = data;
	int count = 0;
	while(count != loc && node != NULL) {
		prev = node;
		node = node->next;
		count++;
	}
	if(node == NULL) {
		printf("Cannot insert.\n");
		return;
	}
	prev->next = newNode;
	newNode->next = node;
	printf("Insertion successfull\n");
	return;
}

void insertAtEnd(Node* node, int data) {
	if(node == NULL) {
		node->data = data;
		return;
	}
	Node* newNode = (Node*) malloc(sizeof(Node));
	newNode->data = data;
	while(node->next != NULL) {
		node = node->next;
	}
	node->next = newNode;
}

void deleteStart (Node** head, Node* node) {
	if(node == NULL) {
		printf("List is Empty!\n");
		return;
	}
	*head = node->next;
}

void deleteAtPos(Node* node, int loc) {
	if(node == NULL) {
		printf("List is Empty!\n");
		return;
	}
	Node* prev;
	int count = 0;
	while(count!= loc && node != NULL) {
		prev = node;
		node = node->next;
		count ++;
	}
	if(node == NULL) {
		printf("Can't delete an element that doesn't exist\n");
		return;
	}
	prev->next = node->next;
}

void deleteEnd (Node* node) {
	if(node == NULL) {
		printf("List is Empty!\n");
		return;
	}
	Node* prev;
	while(node->next != NULL) {
		prev = node;
		node = node->next;
	}
	prev->next = NULL;
}