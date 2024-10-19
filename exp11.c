#include <stdio.h>
#include <stdlib.h>

#define MAX 20
int graph[MAX][MAX] , visited[MAX];
int n;

void BFS(int start) {
    int queue[MAX],front = -1 , rear = -1;
    queue[++rear] = start;
    visited[start] = -1;
    
    while (front != rear){
        front++;
        int current = queue[front];
        printf("%d" , current);
        
        for(int i = 0; i < n; i++){
            if(graph[current][i] == 1 && !visited[i]){
                queue[++rear] = i;
                visited[i] = 1;
            }
        }
    }
}

void DFS(int start){
    visited[start] = 1;
    printf("%d", start);
    
    for ( int i = 0; i< n; i++){
        if(graph[start][i] == 1 && !visited[i]){
            DFS(i);
        }
    }
}
int main() {
    int edges, u ,v;
    printf("enter the number of vertices:");
    scanf("%d",&n);
    for(int i = 0;i<n;i++){
        for(int j =0;j<n;j++){
            graph[i][j] = 0;
        }
        visited[i] = 0;
    }
  printf("Enter no . of edges : ");
  scanf("%d", &edges);
  printf("Enter the edges (u v):\n");
  for(int i =0;i< edges; i++){
      scanf("%d %d",&u ,&v);
      graph[u][v] = 1;
  }
  printf("BFS starting from vertex 0:\n");
    BFS(0);
  
for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }
printf("\nDFS starting from vertex 0:\n");
    DFS(0);
   
    return 0;
}
