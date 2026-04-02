/*
In graph theory strongly connected components is a maximal sub graph of a directed graph 
where every vertex is reachable from every other vertex in that component

strongly connected : directed and reachable in all vertex
weekly connected: undirected

*/

#include <bits/stdc++.h>
using namespace std;

vector<int>adj[1000], transpose[1000];
stack<int>st;
bool visited[100];

void dfs1(int node){
    visited[node]=true;
    for(int v: adj[node]){
        if(!visited[v]){
            dfs1(v);
        }
    }
    st.push(node);
}

void dfs2(int node){
    visited[node]=true;
    cout<<node<<" ";
    for(int v:transpose[node]){
        if(!visited[v]){
            dfs2(v);
        }
    }
}

int main(){
    int n, e;
    cin>>n>>e;

    for(int i=0; i<e; i++){
        int u, v;
        cin>>u>>v;
        adj[u].push_back(v);
        transpose[v].push_back(u);
    }

    for(int i=1; i<=n; i++){
        if(!visited[i]){
            dfs1(i);
        }
    }

    memset(visited, false, sizeof(visited));

    while(!st.empty()){
        int node=st.top();
        st.pop();

        if(!visited[node]){
            dfs2(node);
            cout<<"\n";
        }
    }

    return 0;
}