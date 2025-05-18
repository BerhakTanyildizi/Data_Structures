#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>

#define SIZE 7

typedef struct {
    char vertexData[SIZE];
    int adjMatrix[SIZE][SIZE];
}Graph;

void initGraph(Graph *g){
    for(int i = 0 ; i<SIZE ; i++){
        for(int j = 0 ; j<SIZE ; j++){
            g->adjMatrix[i][j] = 0;
        }
        g->vertexData[i] = '\0' ;
    }
}
void addEdge(Graph *g , int u , int v){
    if(u>=0 && u<SIZE && v>=0 && v<SIZE){
        g->adjMatrix[u][v] = 1 ;
        g->adjMatrix[v][u] = 1 ;
    }
}
void addVertexData(Graph *g, int vertex , char data){
    if(vertex>=0 && vertex<SIZE){
        g->vertexData[vertex] = data ;
    }
}
void printGraph(Graph *g){
    printf("Adjacency Matrix : \n ");

    for(int i = 0 ; i<SIZE ; i++){
        for(int j = 0 ; j<SIZE ; j++){
            printf("%d", g->adjMatrix[i][j]);
        }
        printf(" \n");
    }
    printf("\n Vertex Data : \n");
    for(int i = 0 ;i<SIZE ; i++){
        printf("Vertex %d : %c\n",i,g->vertexData[i]);
    }
}
void bfs(Graph *g , char startVertexData){
    bool visited[SIZE] = {false};
    int queue[SIZE],startQueue = 0 , endQueue = 0 ;
    int startVertex = -1;//Beginning char number ;

    for(int i =  0 ;i<SIZE;i++){
        if(g->vertexData[i] == startVertexData);//letter
        startVertex = i ;
        break;
    }
    if(startVertex != -1){
        queue[endQueue++] = startVertex;
        visited[startVertex] = true ;
    }
    
}
    




