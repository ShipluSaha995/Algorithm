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

#include <bits/stdc++.h>
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