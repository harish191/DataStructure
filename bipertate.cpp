#include<iostream>
using namespace std;
struct Queue {
    int rear,front,size;
    unsigned capacity;
    int *arr;
};

struct Graph {
    int V;
    int E;
    int **adj;
};

struct Queue * createqueue(unsigned capacity)
{
        struct Queue *q = new Queue();
        q->capacity = capacity;
        q->front = q->size =0;
        q->rear = capacity -1;
        q->arr = new int[sizeof(q->capacity)];
        return q;

}
int isempty(struct Queue *q)
{
    return (q->size ==0);
}
int isfull(struct Queue *q)
{
    return (q->size == q->capacity);
}

void enqueue(struct Queue *q,int data)
{
    if(isfull(q))
        return;
    q->rear = (q->rear + 1)%q->capacity;
    q->arr[q->rear] = data;
    q->size = q->size +1;
}

int dequeue(struct Queue *q)
{
    if(isempty(q))
        return -32767;
    int item = q->arr[q->front];
    q->front =(q->front + 1)%q->capacity;
    q->size = q->size -1;
    return item;
}
struct Graph * matrix()
{
    int u,v,w,i,j;
    struct Graph *G =new Graph();
    cout << "enter the no of vertices and edges"<<endl;
    cin >> G->V >> G->E;
    G->adj =new int*[sizeof(G->V)];
    for(i=0; i < G->V; i++)
        G->adj[i] = new int[sizeof(G->V)];

    for( i=0; i < G->V; i++) {
        for( j=0; j<G->V; j++) {
            G->adj[i][j]=0;
        }
    }

    cout<<"enter the edges"<<endl;
    for( i=0; i<G->E;i++) {
        cin >>u >>v ;
        G->adj[u][v]=1;
        G->adj[v][u]=1;
    }

    return G;

}

bool isbipartiteUtil(struct Graph *g,struct Queue *q,int src,int clr[])
{
    int u;
//    int clr[g->V];
//    for(int i=0;i<g->V;i++)
//        clr[i]=-1;
    clr[src] =1;
    enqueue(q,src);
    while(!isempty(q))
    {
        u = dequeue(q);
        if(g->adj[u][u] == 1)
            return false;

        for(int v=0; v < g->V; v++ ) {
            if( g->adj[u][v] && clr[v] == -1) {
                clr[v] = 1 - clr[u];
                enqueue(q,v);
            }
            else if(g->adj[u][v] && clr[u] == clr[v])
                return false;
        }
    }
    return true;

}

bool isbipartite(struct Graph *g,struct Queue * q)
{
    int clr[g->V];
    for(int i=0; i < g->V; i++)
        clr[i] = -1;

    for(int i = 0; i < g->V; i++) {
        if(clr[i] == -1)
            if(isbipartiteUtil(g,q,i,clr) == false)
                return false;
    }

    return true;
}
void printmatrix(struct Graph *G)
{
    for(int i=0; i<G->V;i++) {
        for(int j=0; j<G->V; j++) {
            cout<<G->adj[i][j] <<" ";
        }
        cout<<endl;
    }
}
int main()
{
    struct Graph * G;
    struct Queue * q = createqueue(1000);
    G = matrix();
 //   printmatrix(G);
    isbipartite(G,q) ? cout<<"yes" : cout<<"no";
    return 0;
}
