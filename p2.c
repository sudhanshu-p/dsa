#include<stdio.h>
#include<stdlib.h>
#include <time.h>
#define MAX 10000000

int length(int *arr)
{
    int x = 0;
 
    while (arr[x] != -99)
    {
        x++;
    }
 
    return x;
}
void traverse(int arr[])
{
    int N = length(arr);
 
    printf("Elements Are : \n");
 
    for (int i = 0; i < N; i++)
    {
        printf("%d  ", arr[i]);
    }
 
    printf("\n");
}
void count_best(int *arr, int n)
{
    printf("Best Array created\n");
    int yo=rand()/500;
    for (int a = 0; a < n; a++)
    {
        arr[a] =yo;
    }
   
    arr[n] = -99;
}


void count_worst(int* arr,int n)
{
    printf("Worst Array created\n");
    for (int a = 0; a < n; a++)
    {
        arr[a] = (n*100) - a + 5;
    }
    arr[n] = -99;

}

void best(int *arr, int n)
{
    printf("Best Array created\n");
    for (int a = 0; a < n; a++)
    {
        arr[a] = a + 1;
    }
    arr[n] = -99;
}


void worst(int *arr, int n)
{
    printf("worst array created\n");
    for (int a = 0; a < n; a++)
    {
        arr[a] = n - a + 5;
    }
    arr[n] = -99;
}


void average(int *arr, int n)
{
    printf("average array created\n");
    int temp;
    for (int a = 0; a < n; a++)
    {
        temp = rand();
        arr[a] = temp;
    }
    arr[n] = -99;
}


void almost_best(int *arr, int n)
{
    printf("Almost best array created\n");
    int k=rand()%100,l=0;
    int gap=n/5;
 
    for (int a = 0; a < n-1; a++)
    {
        arr[a] = k;
        k++;
    }
    k=rand()%100;
    while(l<n)
    {
        arr[l]=k;
        l=l+gap;
    }
 
    arr[n] = -99;
}




void insertion_sort(int *arr)
{
    int i, temp, j, n = length(arr);
    clock_t t1, t2;
    double cpu_time_used;
    t1 = clock();
    for (i = 0; i < n; i++)
    {
        temp = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > temp)
        {
 
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = temp;
    }
  t2 = clock();
    cpu_time_used = (((double)(t2 - t1)) / CLOCKS_PER_SEC);
    printf("\ntime used by cpu is: %lf\n", cpu_time_used);
    printf("sorted\n");
}

void selection_sort(int *arr)
{
    int i, temp, min, j, n = length(arr);
    double cpu_time_used;
    clock_t t1, t2;
    t1 = clock();
    for (i = 0; i < n - 1; i++)
    {
        min = i;
        for (j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }
        temp = arr[min];
        arr[min] = arr[i];
        arr[i] = temp;
    }
    t2 = clock();
    cpu_time_used = (((double)(t2 - t1)) / CLOCKS_PER_SEC);
    printf("\ntime used : %lf\n", cpu_time_used);
    printf("The Array is sorted\n");
}

void shell_sort(int a[])
{
    int n = length(a);
    double cpu_time_used;
    clock_t t1, t2;
   
    int m;
    printf("Enter the number to make gap size n/?:\n");
    scanf("%d",&m);
t1 = clock();
    for (int gap = n / m; gap > 0; gap /=m)
    {
        for (int i = gap; i < n; i += 1)
        {
            int temp = a[i];
            int j;
            for (j = i; j >= gap && a[j - gap] > temp; j -= gap)
            {
                a[j] = a[j - gap];
            }
            a[j] = temp;
        }
    }
     t2 = clock();
    cpu_time_used = (((double)(t2 - t1)) / CLOCKS_PER_SEC);
    printf("\ntime used : %lf\n", cpu_time_used);
    printf("The Array is sorted\n");
}

void bubble_sort (int a[])
{
 
    int i,j,temp,n=length(a);
    double cpu_time_used;
    clock_t t1, t2;
    t1 = clock();
    for(i = 0 ; i < n - 1; i++)
 
   {
        for(j = 0 ; j < n-i-1; j++)
         {
            if(a[j] > a[j+1])
            {
               temp=a[j];
               a[j]=a[j+1];
               a[j+1]=temp;
            }
         }
   }
    t2 = clock();
    cpu_time_used = (((double)(t2 - t1)) / CLOCKS_PER_SEC);
    printf("\ntime used : %lf\n", cpu_time_used);
    printf("The Array is sorted\n");
 
}


int max_element(int a[], int n) {  
   int max = a[0];  
   for(int i = 1; i<n; i++) {  
      if(a[i] > max)  
         max = a[i];  
   }  
   return max;
}  
 
void counting_sort(int a[],int n)
{  
   double cpu_time_used;
    clock_t t1, t2;
    t1 = clock();
   int *output;  
   int m = max_element(a, n);  
   int* count;  
   output = (int *)calloc(n+1, sizeof(int));
    count = (int *)calloc(m+1, sizeof(int));
 
  for (int i = 0; i <= m; ++i)  
  {  
    count[i] = 0;  
  }  
   
  for (int i = 0; i < n; i++)
  {
    count[a[i]]++;
  }
  int pp=0;
 
   for(int i = 1; i<=m; i++)
   {
       while(count[i]>0){
        output[pp]=i;
        count[i]--;
        pp++;
       }
   }
 
   for(int i = 0; i<n; i++)
   {  
        a[i] = output[i];
   }
   t2 = clock();
    cpu_time_used = (((double)(t2 - t1)) / CLOCKS_PER_SEC);
    printf("\ntime used : %lf\n", cpu_time_used);
    printf("The Array is sorted\n");
 
}

int main()
{
    int sorting_choice,l,*arr,n,m,o,p,q,r;
    printf("Enter size of array:\n");
    scanf("%d",&n);
    arr = (int *)calloc(MAX, sizeof(int));
    start : while (1)
    {
        printf("Choose sorting method:\n");
        printf("1. Insertion\n2. Selection sort\n3. Shell sort\n4. Counting sort\n5. Bubble sort\n6. Exit\n");
        scanf("%d",&sorting_choice);
        switch (sorting_choice)
       {
           case 1:
            printf("Insertion sort :\n");
            while(1)
            {
            printf("\n1. best case input\n2. worst case input\n3. average case input\n4. almost best case input\n5. exiting to sorting method menu\n");
            scanf("%d",&l);
            switch (l)
               {
                    case 1:
                       
                        best(arr, n);
                        insertion_sort(arr);
                        break;
                    case 2:
    
                        worst(arr, n);
                        insertion_sort(arr);
                        break;
                    case 3:
    
                        average(arr, n);
                        insertion_sort(arr);
                        break;
    
                    case 4:
    
                       almost_best(arr, n);
                        insertion_sort(arr);
                        break;
    
                    case 5:
                        goto start;
                        break;
                    
    
            
                default:
                    printf("\nEnter correct choice\n");
                break;
               }
            }
            break;
    
        case 2:
            printf("Selection sort :\n");
            while(1)
            {
                printf("For inputs\n1. best case input\n2. worst case input\n3. average case input\n4. almost best case input\n5. exiting to sorting method menu\n");
            scanf("%d",&m);
            switch (m)
               {
                    case 1:
                       
                        best(arr, n);
                        selection_sort(arr);
                        break;
                    case 2:
    
                        worst(arr, n);
                        selection_sort(arr);
                        break;
                    case 3:
    
                        average(arr, n);
                        selection_sort(arr);
                        break;
    
                    case 4:
    
                       almost_best(arr, n);
                        selection_sort(arr);
                        break;
    
                    case 5:
                        goto start;
                        break;
                    
    
            
                default:
                    printf("\nEnter correct choice\n");
                break;
               }
            }
            break;
    
        case 3:
            printf("Shell sort selected:\n");
            while(1)
            {
                printf("For inputs\n1. best case input\n2. worst case input\n3. average case input\n4. almost best case input\n5. exiting input menu\n");
            scanf("%d",&o);
            switch (o)
               {
                    case 1:
                       
                        best(arr, n);
                        shell_sort(arr);
                        break;
                    case 2:
    
                        worst(arr, n);
                        shell_sort(arr);
                        break;
                    case 3:
    
                        average(arr, n);
                        shell_sort(arr);
                        break;
    
                    case 4:
    
                       almost_best(arr, n);
                        shell_sort(arr);
                        break;
    
                    case 5:
                        goto start;
                        break;
                    
    
            
                default:
                    printf("\nEnter correct choice\n");
                break;
               }
            }
            break;
    
        case 4:
            printf("Counting sort :\n");
            while(1)
            {
                printf("For inputs\n1. best case input\n2. worst case input\n3. average case input\n4. almost best case input\n5. exiting to sorting method input menu\n");
            scanf("%d",&p);
            switch (p)
               {
                    case 1:
                       
                        count_best(arr, n);
                        counting_sort(arr,n);
                        break;
                    case 2:
     
                        count_worst(arr, n);
                        counting_sort(arr,n);
                        break;
                    case 3:
     
                        average(arr, n);
                        counting_sort(arr,n);
                        break;
     
                    case 4:
     
                       almost_best(arr, n);
                        counting_sort(arr,n);
                        break;
     
                    case 5:
                        goto start;
                        break;
                    
    
            
                default:
                    printf("\nEnter correct choice\n");
                break;
               }
            }
            break;
    
        case 5:
            printf("Bubble sort :\n");
            while(1)
            {
                printf("For inputs\n1. best case input\n2. worst case input\n3. average case input\n4. almost best case input\n5. exiting to sorting method input menu\n");
            scanf("%d",&q);
            switch (q)
               {
                    case 1:
                       
                        best(arr, n);
                        bubble_sort(arr);
                        break;
                    case 2:
     
                        worst(arr, n);
                        bubble_sort(arr);
                        break;
                    case 3:
     
                        average(arr, n);
                        bubble_sort(arr);
                        break;
     
                    case 4:
                       almost_best(arr, n);
                        bubble_sort(arr);
                        break;
     
                    case 5:
                        goto start;
                        break;
                    
    
            
                default:
                    printf("\nEnter correct choice\n");
                break;
               }
            }
            break;
    
        case 6:
             exit(0); 
             break;
    
        default:
            break;
       }


    }
    

}