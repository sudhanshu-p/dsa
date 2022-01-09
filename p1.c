#include <stdio.h>
#include <stdlib.h>
#define MAX 12

int lengthOfArray(int *ptr) {       // gives length of array without -99
    int count = 0;
    while(*ptr!=-99){
        count++;
        ptr++;
    }
    return count;
}

void print(int *arr) {         
    int n = lengthOfArray(arr);
    printf("\nThe array is: ");
    for(int i=0; i<n; i++){
        printf("%d  ",*(arr+i));
    }
    printf("\n");
}

void create_new (int arr[], int n) {    // creates an array with -99 as the last element
    if(n>=MAX){
        printf("Too many elements\n");
        exit(0);
    }
    else{
        arr[0] = -99;
        printf("Enter %d elements: \n", n);
        for(int i=0; i<n; i++) {
            arr[i+1]=arr[i];
            scanf("%d",&arr[i]);
        }
    }
}

void copyArray(int a[], int b[]) {      // copies a to b
    int n = lengthOfArray(a),i;
    for (i = 0; i < n; i++) {
        b[i] = a[i];
    }
    b[i] = -99;
    if(lengthOfArray(b) == n)
        printf("Operation Succesfull");
    else
        printf("Error occured.");
}

int isFull(int *p) {                //1 if full, 0 if not full
    int check = lengthOfArray(p);
    if(check  == MAX -1) return 1;
    else return 0;
}

int isEmpty(int *p) {               //1 if empty, 0 if not empty
    int check = lengthOfArray(p);
    if(check == 0) return 1;
    else return 0;
}

void insertInArray(int val, int pos, int arr[]) {
    int n = lengthOfArray(arr);
    if(pos>n || isFull(arr) == 1)
        printf("Not possible to insert\n");
    else {
        int back = n;
        while (back >= pos) {
            arr[back+1] = arr[back];
            back--;
        }
        arr[pos] = val;
    }
}

void deleteFromArray(int pos, int arr[]) {
    int n = lengthOfArray(arr);
    if(pos>n || isEmpty(arr) == 1)
        printf("Deletion Not Possible.\n");
    else {
        int back = pos;
        while(back<n){
            arr[back]=arr[back+1];
            back++;
        }
    }
}



void selectionSort(int arr[]){
    int i, j, min_idx;
    int n = lengthOfArray(arr);
    for (i = 0; i < n-1; i++){
        min_idx = i;
        for (j = i+1; j < n; j++){
            if (arr[j] < arr[min_idx]){
                min_idx = j;
            }
        }
        int temp;
        temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;

    }
}

void bubbleSort(int arr[]) {
    int i, j;
    int n = lengthOfArray(arr);
    for (i = 0; i < n-1; i++){
        for (j = 0; j < n-i-1; j++){
            if (arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void linearSearch(int arr[], int x){
    int i;
    int n = lengthOfArray(arr);
    for (i = 0; i < n; i++){
        if (arr[i] == x){
            printf("%d is at %d\n", x, i+1);
            return;
        }
    }
    printf("%d is not there in the array\n", x);
}

void binarySearch(int arr[], int x){
    int n = lengthOfArray(arr);
    int lb = 0, hb = n-1, mid;
    while (lb <= hb){
        mid = (lb + hb)/2;
        if (arr[mid] == x){
            printf("%d is at index %d\n", x, mid +1);
            return;
        }
        else if (arr[mid] < x){
            lb = mid + 1;
        }
        else{
            hb = mid - 1;
        }
    }
    printf("%d is not present in the array\n", x);
}

void mergeWithSort(int a[]) {
    int n = lengthOfArray(a), m;
    printf("Enter the number of elements in the array: ");
    scanf("%d",&m);
    if(m+n> MAX) {
        printf("Too many elements\n");
        return;
    }
    int* b;
    b = (int *) calloc (m,sizeof(int));
    create_new(b, m);
    int i,j;
    for(i=0; i<m; i++) {
        n = lengthOfArray(a);
        for(j=0; j < n; j++) {
            if(b[i]<a[j]) {
                insertInArray(b[i], j, a);
                break;
            }
            if(j == n) {
                a[j+1] = a[j];
                a[j] = b[i];
            }
        }
    }
}

int main() {
    int n, *arr, sorted = 0, pos, *arrCpy, copied = 0;
    printf("Enter the number of elements in the array: ");
    scanf("%d",&n);
    arr = (int *) calloc (MAX,sizeof(int));
    create_new(arr, n);
    while(1){
        int choice;
        printf("Enter a choice:\n1: Insert an element in the array\n2: Delete an element from the array\n3: Copy the array\n4: Restore to copied checkpoint\n5: ort the array\n6: Search an element in the array\n7: Print the length of the array\n8: Print the array\n8: Restore to copied checkpoint\n9: Merge an array with this array\n10: End task\nYour Choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("You chose to insert an element\n");
                printf("Where do you want to insert the element: ");
                int val;
                scanf("%d",&pos);
                printf("Enter the element you want to insert: ");
                scanf("%d",&val);
                insertInArray(val,pos,arr);
                n = lengthOfArray(arr);
                print(arr);
                break;
            case 2: 
                printf("You chose to delete an element from the array.\n");
                print(arr);
                printf("Which element do you want to delete: ");
                scanf("%d",&pos);
                deleteFromArray(pos, arr);
                n = lengthOfArray(arr);
                break;
            case 3: 
                printf("You selected to copy the array.\n");
                n = lengthOfArray(arr);
                arrCpy = (int *) calloc (n,sizeof(int));
                copyArray(arr, arrCpy);
                printf("The array has been copied.\n");
                printf("Copied Array: ");
                print(arrCpy);
                copied = 1;
                break;
            case 4: 
                if(copied == 1) {
                    printf("Restoring to the checkpoint.\n");
                    copyArray(arrCpy, arr);
                    n = lengthOfArray(arr);
                    print(arr);
                }
                else printf("No checkpoint found\n");
                break;
            case 5:
                printf("Select which method to sort the array with:\n1:Selection Sort\n2:Bubble Sort\nYour Choice:");
                int sortChoice;
                scanf("%d",&sortChoice);
                switch(sortChoice){
                    case 1: 
                        printf("You chose to sort by selection sort.");
                        selectionSort(arr);
                        print(arr);
                        sorted = 1;
                        break;
                    case 2:
                        printf("You chose to sort by Bubble Sort.");
                        bubbleSort(arr);
                        print(arr);
                        sorted = 1;
                        break;
                    default:
                        printf("Please select a valid choice.");
                }
                break;
            case 6:  
                printf("Enter the element to be found: ");
                int ele;
                scanf("%d", &ele);
                printf("Select which method you want to use for searching:\n1:Linear Search\n2:Binary Search\nYour Choice: ");
                int searchChoice;
                scanf("%d",&searchChoice);
                switch(searchChoice){
                    case 1:
                        printf("You chose to search by Linear Search.");
                        linearSearch(arr, ele);
                        break;
                    case 2:
                        if(sorted == 1){
                            printf("You chose to search by Binary Search.");
                            binarySearch(arr, ele);
                        }
                        else {
                            printf("Binary Search requires a sorted array. Please sort the array first.\n");
                        }
                        break;
                    default:
                        printf("Please select a valid choice.");
                }
                break;
            case 7:
                printf("Length of array is: %d\n",lengthOfArray(arr));
                break;
            case 8:
                print(arr);
                break;
            case 9: 
                printf("You selected to merge an array.\n");
                int m;
                if(sorted == 1) mergeWithSort(arr);
                else printf("Please sort the 1st array first.\n");
                break;
                print(arr);
                break;
            case 10:
                printf("Ending program.\n");
                exit(0);
            default:
                printf("Please select a valid choice\n");
        }
    }
}
