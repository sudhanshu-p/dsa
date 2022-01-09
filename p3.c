#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void randomInput(int* arr, int n) {
	srand(time(0));
	for(int i = 0; i < n; i++)
		arr[i] = rand()/100;
}

void ascInput(int* arr, int n) {
	srand(time(0));
	int k = rand()%1000;
	for(int i = 0; i < n; i++) 
		arr[i] = k + i;
}

void decInput (int* arr, int n) {
	srand(time(0));
	int k = rand()%1000;
	for(int i = 0; i < n; i++) 
		arr[i] = k - i;
}

void merge (int *arr, int l, int m, int u) {
	int i, j = 0, k = l;
	int n1 = m - l + 1, n2 = u - m ;
	// int arr1 [arr1I], arr2 [arr2I];
	int *arr1, *arr2;
	arr1 = (int *) calloc (n1, sizeof(int) );
	arr2 = (int *) calloc (n2, sizeof(int) );
	for(i = 0; i < n1; i++)
		arr1[i] = arr[l + i];
	for(i = 0; i < n2; i++)
		arr2[i] = arr[m + 1 + i];
	i = 0;

	while (i < n1 && j < n2) {
		if(arr1[i] < arr2[j]) {
			arr[k] = arr1[i];
			i++;
		}
		else {
			arr[k] = arr2[j];
			j++;
		}
		k++;
	}

	while(i < n1) {
		arr[k] = arr1[i];
		i++;
		k++;
	}
	while(j < n2) {
		arr[k] = arr2[j];
		j++;
		k++;
	}
}
void mergeSort (int *arr, int l, int u) {
	if(l >= u) return;
	int m = l + ( (u - l) /2 );
	mergeSort (arr, l, m);
	mergeSort (arr, m + 1, u);
	merge(arr, l, m, u);
}

int partition (int arr[], int beg, int end) {
	int left = beg, right = end, loc = beg, flag = 0;
	while(flag == 0) {
		while(arr[loc] <= arr[right] && loc != right) right--;
		if(loc == right) flag = 1;
		else if(arr[loc] > arr[right]) {
			int temp = arr[loc];
			arr[loc] = arr[right];
			arr[right] = temp;
			loc = right;
		}
		if(flag == 0) {
			while(arr[loc] >= arr[left] && loc != left) left++;
			if(loc == left) flag = 1;
			else if (arr[loc] < arr[left]) {
				int temp = arr[loc];
				arr[loc] = arr[left];
				arr[left] = temp;
				loc = left;
			}
		}
	}
	return loc;
}

void quickSort (int arr[], int beg, int end) {
	if (beg >= end) return;
	int loc = partition(arr, beg, end);
	quickSort (arr, beg, loc - 1);
	quickSort (arr, loc + 1, end);
}

int main() {
	int *arr, n, c1, c2;
	time_t t1, t2;
	printf("Enter size: ");
	scanf("%d", &n);
	arr = (int *) calloc (n, sizeof(int));
	while(1) {
		printf("Enter your choice for array: \n1: Best Case\n2: Average Case\n3: Worst Case\n4: Exit\nYour Choice:");
		scanf("%d", &c1);
		switch(c1) {
			case 1:
				randomInput(arr, n);
				printf("Enter your choice of sort: \n1: Quick Sort\n2: Merge Sort\n3: Go back\nYour Choice: ");
				scanf("%d", &c2);
				if(c2 == 3) break;
				switch(c2) {
					case 1:
						printf("You chose Quick Sort\n");
						t1 = clock();
						quickSort(arr, 0, n-1);
						t2 = clock();
						printf("Time used: %f\n", ((double)(t2-t1))/CLOCKS_PER_SEC);
						break;
					case 2: 
						printf("You chose Merge Sort\n");
						t1 = clock();
						quickSort(arr, 0, n-1);
						t2 = clock();
						printf("Time used: %f\n", ((double)(t2-t1))/CLOCKS_PER_SEC);
						break;
					default:
						printf("Invalid Option.\n");
				}
				break;
			case 2:
				decInput(arr, n);
				printf("Enter your choice of sort: \n1: Quick Sort\n2: Merge Sort\n3: Go back\nYour Choice: ");
				scanf("%d", &c2);
				if(c2 == 3) break;
				switch(c2) {
					case 1:
						printf("You chose Quick Sort\n");
						t1 = clock();
						quickSort(arr, 0, n-1);
						t2 = clock();
						printf("Time used: %f\n", ((double)(t2-t1))/CLOCKS_PER_SEC);
						break;
					case 2: 
						printf("You chose Merge Sort\n");
						t1 = clock();
						quickSort(arr, 0, n-1);
						t2 = clock();
						printf("Time used: %f\n", ((double)(t2-t1))/CLOCKS_PER_SEC);
						break;
					default:
						printf("Invalid Option.\n");
				}
				break;
			case 3:
				ascInput(arr, n);
				printf("Enter your choice of sort: \n1: Quick Sort\n2: Merge Sort\n3: Go back\nYour Choice: ");
				if(c2 == 3) break;
				scanf("%d", &c2);
				switch(c2) {
					case 1:
						printf("You chose Quick Sort\n");
						t1 = clock();
						quickSort(arr, 0, n-1);
						t2 = clock();
						printf("Time used: %f\n", ((double)(t2-t1))/CLOCKS_PER_SEC);
						break;
					case 2: 
						printf("You chose Merge Sort\n");
						t1 = clock();
						quickSort(arr, 0, n-1);
						t2 = clock();
						printf("Time used: %f\n", ((double)(t2-t1))/CLOCKS_PER_SEC);
						break;
					default:
						printf("Invalid Option.\n");
				}
				break;
			case 4:
				printf("Ending Program.");
				exit(0);
			default:
				printf("Invalid Option!\n");
		}
	}
	return 0;
}