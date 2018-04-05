
#include<iostream>
#include<cstring>
#include<climits>
#define NINF INT_MIN
using namespace std;
struct Stack
{
    int top;
    unsigned capcacity;
    int *arr;
};
struct Graph
{
    int V,E;
    int **adj;
};

struct Stack * createStack(unsigned capacity)
{
    struct Stack *s =new Stack();
    s->capcacity =capacity;
    s->top=-1;
    s->arr = new int[s->capcacity];
    return s;
}
int isfull(struct Stack *s)
{
    return (s->top == s->capcacity -1);
}
int isempty(struct Stack *s)
{
    return (s->top == -1);
}

void push(struct Stack *s,int item)
{
    if(isfull(s))
        return;

    s->arr[++s->top]=item;
}

int pop(struct Stack *s)
{
    if(isempty(s))
        return -32767;
    int item = s->arr[s->top--];
    return item;
}

struct Graph *matrix()
{
    int u,v,w;
    struct Graph *g =new Graph();
    cin >>g->V >> g->E;
    g->adj = new int*[g->V];
    for(int i=0;i<g->V;i++)
        g->adj[i] = new int[g->V];

    for(int i=0;i<g->V;i++)
        for(int j=0;j<g->V;j++)
            g->adj[i][j] = 0;

    for(int i=0;i<g->E;i++) {
        cin >> u >> v >>w ;
        g->adj[u][v] = w;
    }

    return g;

}
void topologicalUtil(struct Graph *g,struct Stack *s,int u,int *visit)
{
//    cout<<u<<" ";
    visit[u] = 1;
 //   push(s,u);
    for(int i=0;i<g->V;i++) {
        if(g->adj[u][i] && !visit[i])
            topologicalUtil(g,s,i,visit);
    }

    push(s,u);



}

void longestPath(struct Graph *g,struct Stack *s,int src)
{
    int *visit =new int[g->V];
 //   memset(visit,0,sizeof(visit));
    for(int i=0;i<g->V;i++)
        visit[i]=0;
    for(int i=0;i<g->V;i++) {             //convert the graph in topological order and store in stack
        if(!visit[i])
            topologicalUtil(g,s,i,visit);
    }

    int dist[g->V];
    for(int i=0;i<g->V;i++)
        dist[i]=NINF;

 /*   while(!isempty(s)) {
            int item = pop(s);
            cout<<item <<" ";

    }   */

    dist[src] =0;
    while(!isempty(s)) {
        int u=pop(s);
        if(dist[u]!=NINF) {
            for(int i=0;i<g->V;i++) {
                    if( g->adj[u][i]!=0 && dist[i] < dist[u] + g->adj[u][i])
                        dist[i] = dist[u] + g->adj[u][i];
 //                       cout<<dist[i]<<" ";
            }
        }

    }

    for(int i=0;i<g->V;i++)
        cout<<dist[i] <<" ";
 //   cout<<NINF;
}

void printmatrix(struct Graph *g)
{
    for(int i=0;i<g->V;i++) {
        for(int j=0;j<g->V;j++) {
            cout<<g->adj[i][j] <<" ";
        }
        cout<<endl;
    }
}

int main()
{
    struct Graph *g;
    g = matrix();
    struct Stack *s = createStack(g->V+1);
    longestPath(g,s,1);
//    topological(g,s);
    return 0;

}

/*
6 10
0 1 5
0 2 3
1 3 6
1 2 2
2 4 4
2 5 2
2 3 7
3 5 1
3 4 -1
4 5 -2
*/
