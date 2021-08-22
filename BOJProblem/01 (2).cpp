#define _CRT_SECURE_NO_WARNINGS
#if 0
#include <stdio.h>
#include <stdlib.h>

struct AdjListNode
{
    int dest;
    struct AdjListNode* next;
};
 
struct AdjList
{
    struct AdjListNode *head;
};
 
struct Graph
{
    int V;
    struct AdjList* array;
};
 
struct AdjListNode* newAdjListNode(int dest)
{
    struct AdjListNode* newNode = (struct AdjListNode*) malloc(sizeof(struct AdjListNode));
    newNode->dest = dest;
    newNode->next = NULL;
    return newNode;
}
 
struct Graph* createGraph(int V)
{
    struct Graph* graph = (struct Graph*) malloc(sizeof(struct Graph));
    graph->V = V;
 
    graph->array = (struct AdjList*) malloc(V * sizeof(struct AdjList));
 
    int i;
    for (i = 0; i < V; ++i)
        graph->array[i].head = NULL;
 
    return graph;
}
 
void addEdge(struct Graph* graph, int src, int dest)
{
    
    struct AdjListNode* newNode = newAdjListNode(dest);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;
    newNode = newAdjListNode(src);
    newNode->next = graph->array[dest].head;
    graph->array[dest].head = newNode;
}
 
void printGraph(struct Graph* graph)
{
    int v;
    for (v = 0; v < graph->V; ++v)
    {
        struct AdjListNode* pCrawl = graph->array[v].head;
        printf("\n Adjacency list of vertex %d\n head ", v);
        while (pCrawl)
        {
            printf("-> %d", pCrawl->dest);
            pCrawl = pCrawl->next;
        }
        printf("\n");
    }
}
int main()
{
    int V = 5;
    struct Graph* graph = createGraph(V);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);
    printGraph(graph);
 
    return 0;
}
#endif

#if 0
#include<iostream>
#include <list>
 
using namespace std;
class Graph
{
    int V;
    list<int> *adj;
public:
    Graph(int V);
    void addEdge(int v, int w);
 
    void BFS(int s);
};
 
Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}
 
void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
}
 
void Graph::BFS(int s)
{
    bool *visited = new bool[V];
    for(int i = 0; i < V; i++){
        visited[i] = false;
    }
    
    list<int> queue;
    visited[s] = true;
    queue.push_back(s);
    list<int>::iterator i;
 
    while(!queue.empty())
    {
        s = queue.front();
        cout << s << " ";
        queue.pop_front();

        for (i = adj[s].begin(); i != adj[s].end(); ++i)
        {
            if (!visited[*i])
            {
                visited[*i] = true;
                queue.push_back(*i);
            }
        }
    }
}
 
int main()
{
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
 
    cout << "Following is Breadth First Traversal " << "(starting from vertex 2) \n";
    g.BFS(2);
 
    return 0;
}
#endif

#if 0
#include <iostream>
#include <list>
#include <map>

using namespace std;
class Graph
{
public:
    map<int, bool> visited;
    map<int, list<int>> adj;
 
    void addEdge(int v, int w);
 
    void DFS(int v);
};
 
void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
}
 
void Graph::DFS(int v)
{
    visited[v] = true;
    cout << v << " ";
 
 
    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
    {
        if (!visited[*i])
        {
            DFS(*i);
        }
    }
    
}
 
int main()
{

    Graph g;
    g.addEdge(0, 1);
    g.addEdge(0, 9);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(9, 3);
 
    cout << "Following is Depth First Traversal (starting from vertex 2) \n";
    g.DFS(2);
 
    return 0;
}
#endif

#if 0
#include <iostream>
#include <set>
using namespace std;
 
struct Graph {
    int V;
    set<int, greater<int> >* adjList;
};
Graph* createGraph(int V)
{
    Graph* graph = new Graph;
    graph->V = V;
 
    graph->adjList = new set<int, greater<int> >[V];
 
    return graph;
}
void addEdge(Graph* graph, int src, int dest)
{
    
    graph->adjList[src].insert(dest);
 

    graph->adjList[dest].insert(src);
}
void printGraph(Graph* graph)
{
    for (int i = 0; i < graph->V; ++i) {
        set<int, greater<int> > lst = graph->adjList[i];
        cout << endl << "Adjacency list of vertex "<< i << endl;
 
        for (auto itr = lst.begin(); itr != lst.end(); ++itr)
        {
            cout << *itr << " ";
        }
        cout << endl;
    }
}
 
void searchEdge(Graph* graph, int src, int dest)
{
    auto itr = graph->adjList[src].find(dest);
    if (itr == graph->adjList[src].end())
    {
        cout << endl << "Edge from " << src << " to " << dest << " not found." << endl;
    }
    else
    {
        cout << endl << "Edge from " << src << " to " << dest << " found." << endl;
    }
}
 
int main()
{
    int V = 5;
    struct Graph* graph = createGraph(V);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);
 
    printGraph(graph);
    
    searchEdge(graph, 2, 1);
    searchEdge(graph, 0, 3);
 
    return 0;
}
#endif
