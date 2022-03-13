#include<stdio.h>
#include<stdlib.h>

void dfs (int n, int graph[][n], int visited[], int s);
void bfs (int n, int graph[][n], int visit[], int x);

int main() {
    int n;
    printf("Enter the number of nodes in the graph: ");
    scanf("%d", &n);
    int arr [n][n];
    int visited [n];
    printf("Enter the Adjacency Matrix: \n");
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            scanf("%d", &arr[i][j]);
    int c, l=1, val;
    while(1) {
        printf("\n----------------\nNow select the search you want to perform: \n1: Depth First Search\n2: Breadth First Search\n-1: Exit\nYour Choice: ");
        scanf("%d", &c);
        if(c == -1)
            break;
        for(int i=0; i<n; i++)
        visited[i]=0;
        switch(c) {
            case 1: 
                printf("Enter a source node for DFS\n");
                scanf("%d",&val);
                printf("DFS:\n ");
                dfs(n, arr, visited, val);
                printf("\n");
                break;
 
            case 2: 
                printf("Enter a source node for BFS\n");
                scanf("%d",&val);
                printf("BFS:\n");
                bfs(n, arr, visited, val);
                break;
            default: 
                printf("Enter a valid choice\n");
        }
    }
    printf("Goodbye!");
}

void dfs(int n, int graph[][n], int visited[], int s) {
    int j=0;
    visited[s]=1;
    printf("%d , ",s);
    for(int j=0; j<n ; j++)
        if(graph[s][j]==1 && visited[j]==0)
            dfs(n,graph,visited,j);
}

void bfs(int n, int graph[][n], int visit[], int x) {
    printf("%d, ",x);
    int q[n], f = -1, r = -1, visit_count = 0;
    visit[x]=1;
    f = f + 1;
    r = r + 1;
    q[r]=x;
    while(f<=r) {
        x=q[f];
        f=f+1;
        visit_count=0;
        while(visit_count<n) {
            if(graph[x][visit_count]==1 && visit[visit_count]==0) {
                visit[visit_count]=1;
                r=r+1;
                q[r]=visit_count;
                printf("%d, ",visit_count);
            }
            visit_count=visit_count+1;
        }
    }
    printf("\n");
}
