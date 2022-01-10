#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int data;
	struct Node* next;
} Node;

void addNode (Node** head, int data) {
	Node* newNode = (Node*) malloc (sizeof(Node));
	newNode->data = data;
	newNode->next = *head;
	*head = newNode;
}

void insertNode(Node** head, Node* node, int data, int loc) {
	Node* newNode = (Node*) malloc(sizeof(Node));
	Node* prev;
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

void deleteNode(Node** head, Node* node, int loc) {
	Node* prev;
	int count = 0;
	while(count != loc && node != NULL) {
		prev = node;
		node = node->next;
		count++;
	}
	if(node == NULL) {
		printf("Cannot delete.\n");
		return;
	}
	node = node->next;
	prev->next = node;
	printf("Deletion successfull\n");
	return;
}

void traverse (Node* node) {
	printf("The linked list is: ");
	while(node != NULL) {
		printf("%d  ", node->data);
		node = node->next;
	}
	printf("\n");
}

void main() {
	Node* head = NULL;
	int data, c, loc;
	while(1) {
		printf("Choose an option\n1: Add a node\n2: Insert a node\n3: Delete a node\n4: Print the list\n-1: Exit\nYour Choice: ");
		scanf("%d", &c);
		switch(c) {
			case 1:
				printf("Enter the data to be added: ");
				scanf("%d", &data);
				addNode (&head, data);
				break;
			case 2:
				printf("Enter the data to be inserted: \n");
				scanf("%d", &data);
				printf("Enter where you want this data to be inserted: ");
				scanf("%d", &loc);
				insertNode(&head, head, data, loc);
				break;
			case 3:
				printf("Enter the location you want to delete: ");
				scanf("%d", &loc);
				deleteNode(&head, head, loc);
				break;
			case 4: 
				traverse(head);
				break;
			case -1:
				exit(0);
			default:
				printf("Invalid Choice.\n");
		}
	}
}