// /*undirected garaph adjacency matrix*/

// /*#include <bits/stdc++.h>
// using namespace std;

// class Graph{
// private:
//     int V;
//     vector<vector<int>> adj;

// public:
//     Graph(int vertices){
//         V=vertices;
//         adj.resize(V, vector<int>(V, 0));
//     }

//     void addEdge(int u, int v){
//         adj[u][v]=1;
//         adj[v][u]=1;
//     }

//     void display(){
//         for(int i=0; i<V; i++){
//             for(int j=0; j<V; j++){
//                 cout<<adj[i][j]<<" ";           
//             }
//             cout<<"\n";
//         }
//     }

// };

// int main(){
//     int V, E;
//     cin>>V>>E;

//     Graph g(V);
//     for(int i=0; i<E; i++){
//         int u, v;
//         cin>>u>>v;
//         g.addEdge(u,v);
//     }
//      g.display();
//     return 0;
// }

// */

// /* With adjacency list*/

// /*#include <bits/stdc++.h>
// using namespace std;

// class Graph{
// private:
//     int V;
//     vector<vector<int>>adj;
// public:
//     Graph(int vertices){
//         V=vertices;
//         adj.resize(V);
//     }

//     void addEdge(int u, int v){
//         adj[u].push_back(v);
//         adj[v].push_back(u);
//     }

//     void display(){
//         for(int i=0; i<V; i++){
//             cout<<i<<"->";
//             for(int v:adj[i]){
//                 cout<<v<<" ";
//             }
//             cout<<"\n";
//         }
//     }

// };

// int main(){
//     int V, E;
//     cin>>V>>E;

//     Graph g(V);
//     for(int i=0; i<E; i++){
//         int u, v;
//         cin>>u>>v;
//         g.addEdge(u,v);
//     }

//     g.display();
//     return 0;
// }*/

// //weighted 

// /*#include <bits/stdc++.h>
// using namespace std;

// class Graph{
// private:
//     int V;
//     vector<vector<pair<int,int>>>adj;
// public:
//     Graph(int vertices){
//         V=vertices;
//         adj.resize(V);
//     }

//     void addEdge(int u, int v, int w){
//         adj[u].push_back({v,w});
//         adj[v].push_back({u,w});
//     }

//     void dispaly(){
//         for(int i=0; i<V; i++){
//             cout<<i<<"->";
//             for(auto edge:adj[i]){
//                 cout<<"("<<edge.first<<", "<<edge.second<<") ";
//             }
//             cout<<"\n";
//         }
//     }
// };

// int main(){
//     int V,E;
//     cin>>V>>E;
//     Graph g(V);

//     for(int i=0; i<E; i++){
//         int u, v, w ;
//         cin>>u>>v>>w;

//         g.addEdge(u,v,w);
//     }

//     g.dispaly();
//     return 0;
// }*/

// //dfs

// /*#include <bits/stdc++.h>
// using namespace std;

// class Graph{
// private:    
//     int V;
//     vector<vector<int>>adj;
//     void dfs(int node, vector<bool>& visited){
//         visited[node]=true;
//         cout<<node<<" ";

//         for(int neighbor:adj[node]){
//             if(!visited[neighbor]){
//                dfs(neighbor, visited); 
//             }
//         }
//     }

// public:
//     Graph(int vertices){
//         V=vertices;
//         adj.resize(V);
//     }

//     void addEdge(int u, int v){
//         adj[u].push_back(v);
//         adj[v].push_back(u);
//     }

//     void DFS(int start){
//         vector<bool>visited(V, false);
//         dfs(start, visited);
//         cout<<"\n";
//     }

// };


// int main(){
//     int V,E;
//     cin>>V>>E;

//     Graph g(V);

//     for(int i=0; i<E; i++){
//         int u , v;
//         cin>>u>>v;
//         g.addEdge(u, v);

//     }

//     int start;
//     cin>>start;

//     g.DFS(start);
//     return 0;
// }*/

// //Topological sort

// /*#include <bits/stdc++.h>
// using namespace std;

// class Graph{
//     int V;
//     vector<vector<int>>adj;
// public:
//     Graph(int v){
//         V=v;
//         adj.resize(V);
//     }
//     void addEdge(int u, int v){
//         adj[u].push_back(v);
//     }

//     void dfs(int v, vector<bool>& visited, stack<int> &st){
//         visited[v]=true;
//         for(int u:adj[v]){
//             if(!visited[u]){
//                 dfs(u, visited, st);
//             }
//         }
//         st.push(v);
//     }

//     void topology(){
//         vector<bool>visited(V, false);
//         stack<int>st;

//         for(int i=0; i<V; i++){
//             if(!visited[i]){
//                 dfs(i, visited, st);
//             }
//         }

//         while(!st.empty()){
//             cout<<st.top()<<" ";
//             st.pop();
//         }
//         cout<<"\n";
//     }
// };

// int main(){
//     int V, E;
//     cin>>V>>E;
//     Graph g(V);

//     for(int i=0; i<E; i++){
//         int  u, v;
//         cin>>u>>v;
//         g.addEdge(u, v);
//     }
//     g.topology();
//     return 0;
// }


// */

// /*#include <bits/stdc++.h>
// using namespace std;

// class Graph{
//     int V;
//     vector<vector<int>> adj;

// public:
//     Graph(int v){
//         V=v;
//         adj.resize(V);
//     }
//     void addEdge(int u, int v){
//         adj[u].push_back(v);
//     }

//     void dfs1(int v, vector<bool> & visited, stack<int>st){
//         visited[v]=true;
//         for(int u:adj[v]){
//             if(!visited[u]){
//                 dfs1(u, visited, st);
//             }
//         }
//         st.push(v);
//     }

//     void dfs2(int v, vector<bool>& visited, vector<vector<int>>& transpose){
//         cout<<v<<" ";
//         visited[v]=true;
//         for(int u:transpose[v]){
//             if(!visited[u]){
//                 dfs2(u, visited,transpose);
//             }
//         }
//     }

//     void scc(){
//         stack<int>st;
//         vector<bool>visited(V, false);

//         for(int i=0; i<V; i++){
//             if(!visited[i]){
//                 dfs1(i, visited, st);
//             }
//         }

//         vector<vector<int>> transpose(V);

//         for(int i=0; i<V; i++){
//             for(int j: adj[i]){
//                 transpose[j].push_back(i);
//             }
//         }

//         fill(visited.begin(), visited.end(), false);

//         while(!st.empty()){
//             int v= st.top();
//             st.pop();

//             if(!visited[v]){
//                 dfs2(v, visited, transpose);
//                 cout<<"\n";
//             }
//         }
//     }
// };


// int main(){
//     int V, E;

//     cin>>V>>E;

//     Graph g(V);
//     for(int i=0; i<E; i++){
//         int u, v;
//         cin>>u>>v;
//         g.addEdge(u,v);
//     }
//     g.scc();
// }*/

// // #include <bits/stdc++.h>
// // using namespace std;

// // class Graph {
// // private:
// //     int V;
// //     vector<vector<int>> graph;

// // public:
// //     Graph(int v) {
// //         V = v;
// //         graph.resize(V, vector<int>(V));
// //     }

// //     void inputGraph() {
// //         cout << "matrix:\n";
// //         for (int i = 0; i < V; i++)
// //             for (int j = 0; j < V; j++)
// //                 cin >> graph[i][j];
// //     }

// //     int primMST(int skipU = -1, int skipV = -1) {
// //         vector<bool> selected(V, false);
// //         selected[0] = true;

// //         int edges = 0;
// //         int totalWeight = 0;

// //         while (edges < V - 1) {
// //             int minWeight = INT_MAX;
// //             int x = -1, y = -1;

// //             for (int i = 0; i < V; i++) {
// //                 if (selected[i]) {
// //                     for (int j = 0; j < V; j++) {
// //                         if (!selected[j] && graph[i][j] != 0) {

// //                             if ((i == skipU && j == skipV) || (i == skipV && j == skipU))
// //                                 continue;

// //                             if (graph[i][j] < minWeight) {
// //                                 minWeight = graph[i][j];
// //                                 x = i;
// //                                 y = j;
// //                             }
// //                         }
// //                     }
// //                 }
// //             }

// //             if (x == -1 || y == -1)
// //                 return INT_MAX;

// //             selected[y] = true;
// //             totalWeight += graph[x][y];
// //             edges++;
// //         }

// //         return totalWeight;
// //     }

// //     void findSecondBestMST() {
// //         int mstWeight = primMST();
// //         int secondBest = INT_MAX;

// //         for (int i = 0; i < V; i++) {
// //             for (int j = i + 1; j < V; j++) {

// //                 if (graph[i][j] != 0) {
// //                     int weight = primMST(i, j);

// //                     if (weight > mstWeight && weight < secondBest)
// //                         secondBest = weight;
// //                 }
// //             }
// //         }

// //         cout << "MST Weight: " << mstWeight << endl;
// //         cout << "Second Best MST Weight: " << secondBest << endl;
// //     }
// // };

// // int main() {
// //     int V;

// //     cout << "vertices: ";
// //     cin >> V;

// //     Graph g(V);
// //     g.inputGraph();
// //     g.findSecondBestMST();

// //     return 0;
// // }

// /*#include <bits/stdc++.h>
// using namespace std;

// class Graph {
// private:
//     struct Edge {
//         int u, v, w;
//     };

//     int V, E;
//     vector<Edge> edges;
//     vector<int> parent;

// public:
//     Graph(int V, int E) {
//         this->V = V;
//         this->E = E;
//         parent.resize(V);

//         for(int i = 0; i < V; i++)
//             parent[i] = i;
//     }

//     void addEdge(int u, int v, int w) {
//         edges.push_back({u, v, w});
//     }

//     int find(int x) {
//         if(parent[x] == x)
//             return x;
//         return parent[x] = find(parent[x]);
//     }

//     void unite(int a, int b) {
//         parent[find(a)] = find(b);
//     }

//     static bool compareEdge(Edge a, Edge b) {
//         return a.w < b.w;
//     }

//     void KruskalMST() {
//         sort(edges.begin(), edges.end(), compareEdge);

//         int totalWeight = 0;
//         cout << "\nEdges in MST:\n";

//         for(auto &e : edges) {
//             int u = find(e.u);
//             int v = find(e.v);

//             if(u != v) {
//                 unite(u, v);
//                 cout << e.u << " - " << e.v << " : " << e.w << endl;
//                 totalWeight += e.w;
//             }
//         }

//         cout << "Total MST Weight = " << totalWeight << endl;
//     }
// };

// int main(){

//     int V, E;

//     cout << "vertices: ";
//     cin >> V;

//     cout << "edges: ";
//     cin >> E;

//     Graph g(V, E);

//     cout << "edges:\n";

//     for(int i = 0; i < E; i++) {
//         int u, v, w;
//         cin >> u >> v >> w;
//         g.addEdge(u, v, w);
//     }

//     g.KruskalMST();

//     return 0;
// }*/


// //topological sort

// #include <bits/stdc++.h>
// using namespace std;

// void dfs(int node, vector<vector<int>> &adj, vector<bool>&visited, stack<int>&st){
//     visited[node]=true;
//     for(int neighbor:adj[node]){
//         if(!visited[neighbor]){
//             dfs(neighbor, adj, visited, st);
//         }
//     }

//     st.push(node);
// }

// void topology(int V, vector<vector<int>>&adj){
//     vector<bool>visited(V, false);
//     stack<int>st;

//     for(int i=0; i<V; i++){
//         if(!visited[i]){
//             dfs(i, adj, visited, st);
//         }
//     }
//     while(!st.empty()){
//         cout<<st.top()<<" ";
//         st.pop();
//     }
// }

// int main(){
//     int V, E;
//     cin>>V>>E;

//     vector<vector<int>>adj(V);
//     for(int i=0; i<E; i++){
//         int u, v ;
//         cin>>u>>v;
//         adj[u].push_back(v);
//     }
//     topology(V, adj);
//     return 0;
// }

//kruskal algo

// #include <bits/stdc++.h>
// using namespace std;

// struct Edge{
//     int u, v, weight;
// };

// vector<int>parent,rnk;

// int findparent(int x){
//     if(parent[x]!=x){
//         parent[x]=findparent(parent[x]);
//     }
//     return parent[x];
// }

// void unionset(int a, int b){
//     int rootA=findparent(a);
//     int rootB=findparent(b);

//     if(rootA!=rootB){
//         if(rnk[rootA]<rnk[rootB]){
//             parent[rootA]=rootB;
//         }
//         else if(rnk[rootA]>rnk[rootB]){
//             parent[rootB]=rootA;
//         }
//         else{
//             parent[rootB]=rootA;
//             rnk[rootA]++;
//         }
//     }
// }

// bool compare(Edge a, Edge b){
//     return a.weight<b.weight;
// }

// int main(){
//     int V, E;
//     cin>>V>>E;
//     vector<Edge>edge(E);

//     for(int i=0; i<E; i++){
//         cin>>edge[i].u>>edge[i].v>>edge[i].weight;
//     }

//     parent.resize(V);
//     rnk.resize(V,0);

//     for(int i=0; i<V; i++){
//         parent[i]=i;
//     }

//     sort(edge.begin(), edge.end(), compare);

//     int totalcost=0;
//     int edgeused=0;

//     for(int i=0;i<E; i++){
//         int a=edge[i].u;
//         int b=edge[i].v;

//         if(findparent(a)!=findparent(b)){
//             cout<<a<<"-"<<b<<":"<<edge[i].weight<<"\n";
//             totalcost+=edge[i].weight;
//             unionset(a,b);
//             edgeused++;

//             if(edgeused==V-1){
//                 break;
//             }
//         }
//     }

//     cout<<totalcost<<"\n";
//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;

// struct Edge{
//     int u ,v , weight;
// };

// vector<int>parent,rnk;

// int findparent(int x){
//     if(parent[x]!=x){
//         parent[x]=findparent(parent[x]);
//     }
//     return parent[x];
// }

// void unionset(int a , int b){
//     int rootA=findparent(a);
//     int rootB=findparent(b);

//     if(rootA!=rootB){
//         if(rnk[rootA]<rnk[rootB]){
//             parent[rootA]=rootB;
//         }
//         else if(rnk[rootA]>rnk[rootB]){
//             parent[rootA]=rootB;
//         }
//         else{
//             parent[rootA]=rootB;
//             rnk[rootA]++;
//         }
//     }
// }

// bool compare(Edge a , Edge b){
//     return a.weight<b.weight;
// }


// int dfs(int src, int dest, int parentNode, vector<vector<pair<int,int>>>&adj, int maxEdge){
//     if(src==dest){
//         return 1;
//     }
//     for(auto it:adj[src]){
//         int next=it.first;
//         int weight=it.second;

//         if(next==parentNode){
//             continue;
//         }

//         if(dfs(next, dest, src, adj,maxEdge)){
//             maxEdge=max(maxEdge, weight);
//             return 1;
//         }
//     }
//     return 0;
// }



// int main(){
//     int V,E;
//     cin>>V>>E;

//     vector<Edge>edge(E);
//     for(int i=0; i<E; i++){
//         cin>>edge[i].u>>edge[i].v>>edge[i].weight;
//     }

//     parent.resize(V);
//     parent.resize(V,0);
//     for(int i=0;i<E; i++){
//         parent[i]=1;
//     }
//     sort(edge.begin(),edge.end(),compare);
//     vector<Edge>mst;
//     vector<bool>used(E, false);

//     int totalcost=0;

//     for(int i=0; i<E; i++){
//         int u=edge[i].u;
//         int v=edge[i].v;

//         if(findparent(u)!=findparent(v)){
//             unionset(u,v);
//             mst.push_back(edge[i]);
//             used[i]=true;
//             totalcost+=edge[i].weight;
//         }
//     }

//     vector<vector<pair<int,int>>> adj(V);
//     for(auto e: mst){
//         adj[e.u].push_back({e.v, e.weight});
//         adj[e.v].push_back({e.u, e.weight});
//     }
//     int secondbest=INT_MAX;

//     for(int i=0; i<E; i++){
//         if(used[i]){
//             continue;
//         }
//         int maxEdge=-1;
//         dfs(edge[i].u, edge[i].v,-1,adj,maxEdge);
//         int newcost=totalcost+edge[i].weight-maxEdge;
//         if(newcost>totalcost){
//             secondbest=min(secondbest,newcost);
//         }
//     }

//     cout<<totalcost<<"\n";
//     if(secondbest==INT_MAX){
//         cout<<"no\n";

//     }
//     else{
//         cout<<secondbest<<"\n";
//     }

//     return 0;
    

// }


#include <bits/stdc++.h>
using namespace std;

int main(){
    int V,E;
    cin>>V>>E;

    vector<pair<int,int>>adj[V];
    for(int i=0; i<E; i++){
        int u,v,w;
        cin>>u>>v>>w;

        adj[i].push_back({v,w});
        adj[i].push_back({u,w});
    }

    vector<bool>visited(V,false);

    priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>>pq;
    pq.push({0,0,-1});

    int totalcost=0;

    while(!pq.empty()){
        auto[weight,node,parent]=pq.top();
        pq.pop();

        if(visited[node]){
            continue;
        }

        visited[node]=true;
        totalcost+=weight;

        if(parent!=-1){
            cout<<parent<<"-"<<node<<":"<<weight<<"\n";
        }

        for(auto neighbor : adj[node]){
            int next=neighbor.first;
            int w=neighbor.second;

            if(!visited[next]){
                pq.push({w,next,node});
            }
        }
    }
    cout<<totalcost<<"\n";
    return 0;
}