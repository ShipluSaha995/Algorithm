/*undirected garaph adjacency matrix*/

/*#include <bits/stdc++.h>
using namespace std;

class Graph{
private:
    int V;
    vector<vector<int>> adj;

public:
    Graph(int vertices){
        V=vertices;
        adj.resize(V, vector<int>(V, 0));
    }

    void addEdge(int u, int v){
        adj[u][v]=1;
        adj[v][u]=1;
    }

    void display(){
        for(int i=0; i<V; i++){
            for(int j=0; j<V; j++){
                cout<<adj[i][j]<<" ";           
            }
            cout<<"\n";
        }
    }

};

int main(){
    int V, E;
    cin>>V>>E;

    Graph g(V);
    for(int i=0; i<E; i++){
        int u, v;
        cin>>u>>v;
        g.addEdge(u,v);
    }
     g.display();
    return 0;
}

*/

/* With adjacency list*/

/*#include <bits/stdc++.h>
using namespace std;

class Graph{
private:
    int V;
    vector<vector<int>>adj;
public:
    Graph(int vertices){
        V=vertices;
        adj.resize(V);
    }

    void addEdge(int u, int v){
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void display(){
        for(int i=0; i<V; i++){
            cout<<i<<"->";
            for(int v:adj[i]){
                cout<<v<<" ";
            }
            cout<<"\n";
        }
    }

};

int main(){
    int V, E;
    cin>>V>>E;

    Graph g(V);
    for(int i=0; i<E; i++){
        int u, v;
        cin>>u>>v;
        g.addEdge(u,v);
    }

    g.display();
    return 0;
}*/

//weighted 

/*#include <bits/stdc++.h>
using namespace std;

class Graph{
private:
    int V;
    vector<vector<pair<int,int>>>adj;
public:
    Graph(int vertices){
        V=vertices;
        adj.resize(V);
    }

    void addEdge(int u, int v, int w){
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }

    void dispaly(){
        for(int i=0; i<V; i++){
            cout<<i<<"->";
            for(auto edge:adj[i]){
                cout<<"("<<edge.first<<", "<<edge.second<<") ";
            }
            cout<<"\n";
        }
    }
};

int main(){
    int V,E;
    cin>>V>>E;
    Graph g(V);

    for(int i=0; i<E; i++){
        int u, v, w ;
        cin>>u>>v>>w;

        g.addEdge(u,v,w);
    }

    g.dispaly();
    return 0;
}*/

//dfs

/*#include <bits/stdc++.h>
using namespace std;

class Graph{
private:    
    int V;
    vector<vector<int>>adj;
    void dfs(int node, vector<bool>& visited){
        visited[node]=true;
        cout<<node<<" ";

        for(int neighbor:adj[node]){
            if(!visited[neighbor]){
               dfs(neighbor, visited); 
            }
        }
    }

public:
    Graph(int vertices){
        V=vertices;
        adj.resize(V);
    }

    void addEdge(int u, int v){
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void DFS(int start){
        vector<bool>visited(V, false);
        dfs(start, visited);
        cout<<"\n";
    }

};


int main(){
    int V,E;
    cin>>V>>E;

    Graph g(V);

    for(int i=0; i<E; i++){
        int u , v;
        cin>>u>>v;
        g.addEdge(u, v);

    }

    int start;
    cin>>start;

    g.DFS(start);
    return 0;
}*/

//Topological sort

/*#include <bits/stdc++.h>
using namespace std;

class Graph{
    int V;
    vector<vector<int>>adj;
public:
    Graph(int v){
        V=v;
        adj.resize(V);
    }
    void addEdge(int u, int v){
        adj[u].push_back(v);
    }

    void dfs(int v, vector<bool>& visited, stack<int> &st){
        visited[v]=true;
        for(int u:adj[v]){
            if(!visited[u]){
                dfs(u, visited, st);
            }
        }
        st.push(v);
    }

    void topology(){
        vector<bool>visited(V, false);
        stack<int>st;

        for(int i=0; i<V; i++){
            if(!visited[i]){
                dfs(i, visited, st);
            }
        }

        while(!st.empty()){
            cout<<st.top()<<" ";
            st.pop();
        }
        cout<<"\n";
    }
};

int main(){
    int V, E;
    cin>>V>>E;
    Graph g(V);

    for(int i=0; i<E; i++){
        int  u, v;
        cin>>u>>v;
        g.addEdge(u, v);
    }
    g.topology();
    return 0;
}


*/

#include <bits/stdc++.h>
using namespace std;

class Graph{
    int V;
    vector<vector<int>> adj;

public:
    Graph(int v){
        V=v;
        adj.resize(V);
    }
    void addEdge(int u, int v){
        adj[u].push_back(v);
    }

    void dfs1(int v, vector<bool> & visited, stack<int>st){
        visited[v]=true;
        for(int u:adj[v]){
            if(!visited[u]){
                dfs1(u, visited, st);
            }
        }
        st.push(v);
    }

    void dfs2(int v, vector<bool>& visited, vector<vector<int>>& transpose){
        cout<<v<<" ";
        visited[v]=true;
        for(int u:transpose[v]){
            if(!visited[u]){
                dfs2(u, visited,transpose);
            }
        }
    }

    void scc(){
        stack<int>st;
        vector<bool>visited(V, false);

        for(int i=0; i<V; i++){
            if(!visited[i]){
                dfs1(i, visited, st);
            }
        }

        vector<vector<int>> transpose(V);

        for(int i=0; i<V; i++){
            for(int j: adj[i]){
                transpose[j].push_back(i);
            }
        }

        fill(visited.begin(), visited.end(), false);

        while(!st.empty()){
            int v= st.top();
            st.pop();

            if(!visited[v]){
                dfs2(v, visited, transpose);
                cout<<"\n";
            }
        }
    }
};


int main(){
    int V, E;

    cin>>V>>E;

    Graph g(V);
    for(int i=0; i<E; i++){
        int u, v;
        cin>>u>>v;
        g.addEdge(u,v);
    }
    g.scc();
}