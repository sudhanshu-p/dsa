/*Write a C program [menu driven] to implement a linked queue in constant time.(CO1)*/

/*The question didn't mention whether the list is singly or doubly so I took singly. 
Implementing it in doubly would not be much different*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
	int data;
	struct Node* next;
} Node;

void createHead (Node** head, int val);

void enqueue (Node* node, int val);
int dequeue (Node** head, Node* node);
int lengthOfQueue (Node* node);
void traverseQueue (Node* node);

void main() {
	int choice, temp;
	Node* head = NULL;
	while(1) {
		printf("Enter your choice: \n1: Enqueue\n2: Dequeue\n3: Print the queue\n-1: End Execution\nYour Choice: ");
		scanf("%d", &choice);
		if(choice == -1)
			break;
		switch(choice) {
			case 1:
				printf("You chose to enqueue an element.\n");
				printf("Enter the value: ");
				scanf("%d", &temp);
				if(lengthOfQueue(head) == 0)
					createHead (&head, temp);
				else
					enqueue(head, temp);
				printf("%d has been enqueued.\n", temp);
				break;
			case 2:
				printf("You chose to dequeue an element.\n");
				temp = dequeue (&head, head);
				printf("%d has been dequeued\n", temp);
				break;
			case 3: 
				if(lengthOfQueue(head) == 0) {
					printf("The queue is empty!\n");
					break;
				}
				printf("The queue is: \n");
				traverseQueue (head);
				break;
			default:
				printf("Invalid Choice! Try again!\n");
		}
	}
	printf("Goodbye\n");
}

void createHead (Node** head, int val) {
	Node* tempNode = (Node*) malloc(sizeof(Node));
	tempNode->data = val;
	tempNode->next = NULL;
	*head = tempNode;
}

void enqueue (Node* node, int val) {
	Node* tempNode = (Node*) malloc (sizeof(Node));
	tempNode->data = val;
	tempNode->next = NULL;
	while(node->next != NULL)
		node = node->next;
	node->next = tempNode;
}

int dequeue (Node** head, Node* node) {
	int temp = node->data;
	Node* tempNode = node->next;
	*head = tempNode;
	return temp;
}

int lengthOfQueue (Node* node) {
	int count = 0;
	while(node != NULL) {
		count++;
		node = node->next;
	}
	return count;
}

void traverseQueue (Node* node) {
	while(node != NULL) {
		printf("%d\t", node->data);
		node = node->next;
	}
	printf("\n");
}