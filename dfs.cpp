#include<iostream>
using namespace std;
struct Stack
{
    int top;
    unsigned capacity;
    int *arr;
};
struct Graph
{
    int E,V;
    int **adj;
};

struct Stack * createStack(unsigned capacity)
{
        struct Stack *s = new Stack();
        s->capacity =capacity;
        s->top = -1;
        s->arr = new int[sizeof(s->capacity)];
        return s;
}

int isempty(struct Stack *s)
{
    return (s->top == -1);
}

int isfull(struct Stack *s)
{
    return (s->top == s->capacity -1);
}

void push(struct Stack *s,int item)
{
    if(isfull(s))
        return;
    s->arr[++s->top] = item;
}

int pop(struct Stack *s)
{
    if(isempty(s))
        return -32767;

    int item = s->arr[s->top--];
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

void dfsUtil(struct Graph *g,struct Stack *s,int src,bool vist[])
{
//    vist[src] =1;
    push(s,src);

    while(!isempty(s))
    {
        int u = pop(s);
        if(!vist[u] ) {
            cout<<u<<endl;
            vist[u]=true;
        }

        for(int v=0; v < g->V;v++) {
            if(g->adj[u][v] && vist[v] == false)
                push(s,v);
        }
    }
}

void dfs(struct Graph *g,struct Stack *s)
{
    bool *vist =new bool();
    for(int i=0; i < g->V; i++)
        vist[i] =false;

    for(int i =0 ; i < g->V; i++)
        if(vist[i] == false)
            dfsUtil(g,s,i,vist);

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
    struct Graph *g;
    struct Stack *s = createStack(1000);
    g = matrix();
    printmatrix(g);
    dfs(g,s);
}

