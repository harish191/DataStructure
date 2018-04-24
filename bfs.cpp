#include<iostream>
using namespace std;
struct Queue
{
    int rear,front,size;
    unsigned capacity;
    int *arr;
};
struct Graph
{
    int E,V;
    int **adj;
};

struct Queue * createqueue(unsigned capacity)
{
        struct Queue *q = new Queue();
        q->capacity = capacity;
        q->front = q->size = 0;
        q->rear = q->capacity - 1;
        q->arr = new int[sizeof(q->capacity)];
        return q;
}

int isfull(struct Queue *q)
{
    return (q->size == q->capacity);
}

int isempty(struct Queue *q)
{
    return (q->size == 0);
}

void enqueue(struct Queue *q,int data)
{
    if(isfull(q))
        return;
    q->rear = (q->rear + 1)%q->capacity;
    q->arr[q->rear] = data;
    q->size++;

}

int dequeue(struct Queue *q)
{
    if(isempty(q))
        return -32767;
    int item = q->arr[q->front];
    q->front = (q->front +1)%q->capacity;
    q->size--;
    return item;
}

struct Graph * matrix()
{
        int u,v;
        struct Graph *g = new Graph();
        cout<<"enter the no of vertices and edges"<<endl;
        cin>> g->V >> g->E;
        g->adj = new int*[sizeof(g->V)];
        for(int i=0;i < g->V; i++)
            g->adj[i] = new int[sizeof(g->V)];
        for(int i=0; i < g->V; i++)
            for(int j=0; j < g->V; j++)
                g->adj[i][j] =0;

        cout<<"enter the value of edges"<<endl;
        for(int i =0; i < g->E; i++) {
            cin >> u >> v;
            g->adj[u][v] = 1;
        }

        return g;
}

void bfs(struct Graph *g,struct Queue *q,int src)
{
    bool *vist = new bool(g->V);
    for(int i=0; i < g->V; i++)
        vist[i] = false;

    vist[src] =true;
    enqueue(q,src);
    while(!isempty(q)) {
        int u = dequeue(q);
        cout<<u <<" ";
        for(int v =0; v < g->V; v++) {
            if(g->adj[u][v] && vist[v] == false) {
                vist[v] =true;
                enqueue(q,v);
            }

        }

    }
}

int main()
{
    struct Graph *g;
    struct Queue *q = createqueue(1000);
    g = matrix();
    bfs(g,q,2);
}

