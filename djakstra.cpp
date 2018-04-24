#include<iostream>
using namespace std;
#define V 9
//int G[V][V];

int minDistance(int dist[],bool sptset[])
{
    int min = 32767;
    int min_ind;
    for(int v=0; v < V;v++) {
        if(sptset[v] ==false && dist[v] <=min) {
            min = dist[v];
            min_ind = v;
        }
    }
    return min_ind;
}

int printSolution(int dist[])
{
   printf("Vertex   Distance from Source\n");
   for (int i = 0; i < V; i++)
      printf("%d tt %d\n", i, dist[i]);
}
void dijkstra(int G[V][V],int src)
{
    bool sptset[V];
    int dist[V];
    for(int i =0;i < V;i++) {
       sptset[i] =false;
       dist[i] = 32767;
    }

    dist[src] = 0;
    for(int i =0; i < V-1; i++) {
        int u = minDistance(dist,sptset);
        sptset[u] = true;

        for(int v = 0; v < V ; v++) {
            if(!sptset[v] && G[u][v] && dist[u]!=32767 && dist[v] > dist[u] + G[u][v])
                dist[v] = dist[u] + G[u][v];
        }
    }
    printSolution(dist);
}
int main()
{
   int G[V][V] = {
                      {0, 4, 0, 0, 0, 0, 0, 8, 0},
                      {4, 0, 8, 0, 0, 0, 0, 11, 0},
                      {0, 8, 0, 7, 0, 4, 0, 0, 2},
                      {0, 0, 7, 0, 9, 14, 0, 0, 0},
                      {0, 0, 0, 9, 0, 10, 0, 0, 0},
                      {0, 0, 4, 14, 10, 0, 2, 0, 0},
                      {0, 0, 0, 0, 0, 2, 0, 1, 6},
                      {8, 11, 0, 0, 0, 0, 1, 0, 7},
                      {0, 0, 2, 0, 0, 0, 6, 7, 0}};
    dijkstra(G, 0);

    return 0;

}
