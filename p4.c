#include <stdio.h>
#include <stdlib.h>
#define MAX 5

//Stack Operations: 
int isEmptyStack(int* top);
int isFullStack(int* top);
void push(int *top, int *arr, int val) ;
int pop(int *top, int* arr);
int peek(int* top, int* arr);
void displayStack(int* top, int* arr);

//Queue Operations: 
int isEmptyQueue(int* front, int* rear);
int isFullQueue(int* rear);
void enqueue(int* front, int* rear, int *arr, int val);
void dequeue(int* front, int* rear);
void displayQueue(int* front, int* rear, int* arr);

//Circular Queue Operations:
int isEmptyCirc(int* front, int* rear);
int isFullCirc(int* front, int* rear);
void makeCircle(int* front, int* rear);
void enqueueCirc(int* front, int* rear, int* arr, int val);
void dequeueCirc(int* front, int* rear);
void displayQueueCirc(int* front, int* rear, int* arr);


int main() {
	int sc, oc, temp, top = -1, front = 0, rear = 0;
	int* arr;
	arr = (int*) calloc(MAX, sizeof(int));
	while(1) {
		front = 0;
		rear = 0;
		printf("Enter the type of data structure you want to implement: \n1: Stack\n2: Queue\n3: Circular Queue\n4: Exit\nYour Choice: ");
		scanf("%d", &sc);
		switch(sc) {
			case 1:
				//Code for Implementing Stack
				while(1) {
					printf("\n----------------\nEnter which functionality you'd like to use: \n1: Push\n2: Pop\n3: Check Top Value\n4: Print the entire Stack\n-1: go back to the data structure selection\nYour Choice: ");
					scanf("%d", &oc);
					if(oc == -1) {
						printf("Returning to ds selection.\n");
						break;
					}
					switch(oc) {
						case 1: 
							//Code for stack push
							printf("Enter the value to be pushed: ");
							scanf("%d", &temp);
							push(&top, arr, temp);
							printf("Pushed successful\n");
							break;
						case 2: 
							//Code for stack pop
							temp = pop(&top, arr);
							if(temp == -1) 
								printf("Stack is Empty");
							else
								printf("Element popped: %d", temp);
							// top--;
							break;
						case 3:
							//Code for printing top value
							temp = peek(&top, arr);
							if(temp == -1) 
								printf("Stack is Empty");
							else
								printf("Top of the stack is: %d\n", temp);
							break;
						case 4: 
							//Code for printing stack
							displayStack(&top, arr);
							break;
						default: 
							printf("Invalid Choice. Try again\n");
					}
				}
				break;
			case 2: 
				//Code for Implementing Queue
				while(1) {
					printf("\n----------------\nEnter which functionality you'd like to use: \n1: Enqueue\n2: Dequeue\n3: Display Queue\n-1: go back to the data structure selection\nYour Choice: ");
					scanf("%d", &oc);
					if(oc == -1) {
						printf("Returning to ds selection.\n");
						break;
					}
					switch(oc) {
						case 1: 
							printf("Enter the value to be enqueued: ");
							scanf("%d", &temp);
							enqueue(&front, &rear, arr, temp);
							// rear++;
							printf("Enqueued successful\n");
							break;
						case 2: 
							dequeue(&front, &rear);
							// front++;
							break;
						case 3: 
							displayQueue(&front, &rear, arr);
							break;
						default: 
							printf("Invalid Choice. Try again\n");
					}
				}
				break;
			case 3: 
				//Code for Implementing Circular Queue
				while(1) {
					printf("\n----------------\nEnter which functionality you'd like to use: \n1: Enqueue\n2: Dequeue\n3: Print the entire Circular Queue\n-1: go back to the data structure selection\nYour Choice: ");
					scanf("%d", &oc);
					if(oc == -1) {
						printf("Returning to ds selection.\n");
						break;
					}
					switch(oc) {
						case 1: 
							printf("Enter the value to be enqueued: ");
							scanf("%d", &temp);
							enqueueCirc(&front, &rear, arr, temp);
							break;
						case 2: 
							dequeueCirc(&front, &rear);
							break;
						case 3:
							displayQueueCirc(&front, &rear, arr);
							break;
						default: 
							printf("Invalid Choice. Try again\n");
					}
				}
				break;
			case 4: exit(0);
			default: 
				printf("Invalid Choice. plese enter a valid choice.\n");
		}
	}
}

int isEmptyStack(int* top) {
	if(*top == 0) return 1;
	return 0;
}

int isFullStack(int* top) {
	if(*top == MAX - 1) return 1;
	return 0;
}

void push(int* top, int* arr, int val) {
	if(isFullStack(top)) {
		printf("Stack is full\n");
		return;
	}
	*top += 1;
	arr[*top] = val;
}

int pop(int* top, int* arr) {
	if(isEmptyStack(top)) return -1;
	int temp = arr[*top];
	*top -= 1;
	return temp;
}

int peek(int* top, int* arr) {
	if(isEmptyStack(top)) return -1;
	return arr[*top];
}

void displayStack(int *top, int* arr) {
	if(isEmptyStack(top)) {
		printf("Stack is empty\n");
		return;
	}
	printf("Stack is: ");
	for(int i = *top; i >= 0; i--)
		printf("%d  ", arr[i]);
}

int isEmptyQueue(int* front, int* rear) {
	// printf("%d and %d\n", *front, *rear);
	if(*front == *rear) return 1;
	return 0;
}

int isFullQueue(int* rear) {
	if(*rear == MAX-1) return 1;
	return 0;
}

void enqueue(int* front, int* rear, int*arr, int val) {
	if(isFullQueue(rear)) {
		printf("Queue is full!\n");
		return;
	}
	// printf("%d\n", *rear);
	arr[*rear] = val;
	*rear += 1;
	// printf("%d\n", *rear);
}

void dequeue(int* front, int* rear) {
	if(isEmptyQueue(front, rear)) {
		printf("Queue is empty!\n");
		return;
	}
	*front += 1;
}

void displayQueue(int* front, int* rear, int* arr) {
	if(isEmptyQueue(front, rear)) {
		printf("Queue is empty!\n");
		return;
	}
	printf("Queue is: ");
	for(int i = *front; i < *rear; i++)
		printf("%d  ", arr[i]);
}

int isEmptyCirc(int* front, int* rear) {
	if(*rear == *front) return 1;
	return 0;
}

int isFullCirc(int* front, int* rear) {
	printf("%d and %d\n", *front, *rear);
	if(*front == *rear - 1 || (*front == MAX && *rear == 0)) return 1;
	return 0;
}

void enqueueCirc(int* front, int* rear, int* arr, int val) {
	if(isFullCirc(front, rear)) {
		printf("Too many elements. Can't add more\n");
		return;
	}
	if(*front == MAX - 1)
		*front = 0;
	arr[*front] = val;
	*front += 1;
}

void dequeueCirc(int* front, int* rear) {
	if(isEmptyCirc(front, rear)) {
		printf("Queue is empty!\n");
		return;
	}
	if(*rear == MAX - 1)
		*rear = 0;
	*rear = *rear + 1;
}

void displayQueueCirc (int* front, int* rear, int* arr) {
	for(int i = *rear; i < *front; i++) {
		printf("%d ", arr[i]);
	}
	if(*front < *rear) {
		for(int i = 0; i < *front; i++) {
			printf("%d\n", arr[i]);
		}
	}
}