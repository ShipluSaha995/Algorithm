/* BFS(Breadth First Serch) is a graph traversal algorithm that explores vertices levle by levle. It first 
visits all neighbours of a starting node then neighbors of those neighbors and so on.

key points : 
1. It uses QUEUE 
2. works for both undirected and directed graph
3. finds the shortest path in an directed graph
4. Before prcessing all vertices, insert the adjacency vertices in the queue.
5. do not insert visited vertices again 
6. do no repeat or reinsert alresdy inserted vertices
*/

/*#include <bits/stdc++.h>
using namespace std;

void bfs(int start, vector<vector<int>>& adj, int V){
    vector<bool>visited(V, false);
    queue<int>q;

    visited[start]=true;
    q.push(start);

    while(!q.empty()){
        int node = q.front();
        q.pop();
        cout<<node<<" ";

        for(int neighbor:adj[node]){
            if(!visited[neighbor]){
                visited[neighbor]=true;
                q.push(neighbor);
            }
        }

    }
}

int main(){
    int V, E;
    cin>>V>>E;

    vector<vector<int>>adj(V);

    for(int i=0; i<E; i++){
        int u, v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int start;
    cin>>start;
    bfs(start, adj, V);

    return 0;

}

*/

//DFS(Depth First Search)
/*
DFS is a graph Traversat Algorithm that explores a path as far as possible before back-tracking.
Starting from a source vertex, DFS visis an unvisited adjacent vertex and continues this proccess 
recursively until it reaches a vertex with no unvisited adjacent vertices.

Algorithm:
1. It use stack
2. Mark current node as visited
3. print the node
3. Recursively visits all unvisited adjacenty nodes
4. Backtrack when no unvisited neughbor exsists 

*/

#include <bits/stdc++.h>
using namespace std;

void dfs(int start, vector<vector<int>>&adj, int V){
    vector<bool>visited(V, false);
    stack<int>st;

    st.push(start);

    while(!st.empty()){
        int node = st.top();
        st.pop();

        if(!visited[node]){
            visited[node]=true;
            cout<<node<<" ";

            for(int i=adj[node].size()-1; i>=0; i--){
                int neighbor=adj[node][i];
                if(!visited[neighbor]){
                    st.push(neighbor);
                }
            }
        }
    }
}

int main(){
    int V, E;
    cin>>V>>E;
    vector<vector<int>>adj(V);

    for(int i=0; i<E; i++){
        int u, v;
        cin>>u>>v;

        adj[u].push_back(v);
        adj[v].push_back(u);

    }

    int start;
    cin>>start;

    dfs(start, adj, V);
    return 0;

}