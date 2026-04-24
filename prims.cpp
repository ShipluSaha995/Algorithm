#include <bits/stdc++.h>
using namespace std;

int main(){
    int V,E;
    cin>>V>>E;

    vector<pair<int,int>>adj[V];
    for(int i=0;  i<E; i++){
        int u,v,w;
        cin>>u>>v>>w;

        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }

    vector<bool>visited(V,false);

    priority_queue<tuple<int,int,int>, vector<tuple<int,int, int>>, greater<tuple<int,int,int>>>pq;
    pq.push({0,0,-1});

    int totalcost =0;
    
    while(!pq.empty()){
        auto [weight,node, parent]=pq.top();
        pq.pop();

        if(visited[node]){
            continue;
        }

        visited[node]=true;
        totalcost+=weight;

        if(parent != -1) {
            cout << parent << " - " << node << " : " << weight << "\n";
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