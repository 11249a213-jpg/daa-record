AIM:
To implement the minimum spanning tree of a given weighted connected graph by selecting edges in increasing order of weight without forming cycles by the krushals algorithm

Kruskal’s Algorithm :

1. List all edges of the graph  
2. Sort edges in increasing order of weight  
3. Pick the smallest edge  
4. Add it to the tree  
5. Pick the next smallest edge  
6. Add it only if it does NOT form a cycle  
7. Repeat until (V − 1) edges are selected  

PROGRAM:
#include <stdio.h>

#define V 5
#define E 6

int parent[V];

// Find the representative (leader) of the set containing vertex v
int findLeader(int v)
{
    while (parent[v] != v)
        v = parent[v];
    return v;
}

// Merge two disjoint sets
void mergeSets(int u, int v)
{
    int a = findLeader(u);
    int b = findLeader(v);
    parent[a] = b;
}

// Bubble sort to organize edges by weight
void sortEdges(int edges[E][3])
{
    int i, j, k;

    for (i = 0; i < E - 1; i++)
    {
        for (j = 0; j < E - i - 1; j++)
        {
            if (edges[j][2] > edges[j + 1][2])
            {
                for (k = 0; k < 3; k++)
                {
                    int temp = edges[j][k];
                    edges[j][k] = edges[j + 1][k];
                    edges[j + 1][k] = temp;
                }
            }
        }
    }
}

void kruskal(int edges[E][3])
{
    sortEdges(edges);

    for (int i = 0; i < V; i++)
        parent[i] = i;

    int count = 0, cost = 0;

    printf("Selected Edges:\n");

    for (int i = 0; i < E; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        int w = edges[i][2];

        // If leaders are different, no cycle is formed
        if (findLeader(u) != findLeader(v))
        {
            printf("%d -- %d (Weight: %d)\n", u, v, w);
            mergeSets(u, v);
            cost += w;
            count++;
        }

        if (count == V - 1)
            break;
    }

    printf("Total Cost: %d\n", cost);
}

int main()
{
    int edges[E][3] = {
        {0, 1, 2},
        {0, 2, 3},
        {1, 2, 5},
        {1, 3, 3},
        {2, 4, 4},
        {3, 4, 2}
    };

    kruskal(edges);

    return 0;
}
