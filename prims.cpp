// #include <bits/stdc++.h>
// using namespace std;

// int main(){
//     int V,E;
//     cin>>V>>E;

//     vector<pair<int,int>>adj[V];
//     for(int i=0;  i<E; i++){
//         int u,v,w;
//         cin>>u>>v>>w;

//         adj[u].push_back({v,w});
//         adj[v].push_back({u,w});
//     }

//     vector<bool>visited(V,false);

//     priority_queue<tuple<int,int,int>, vector<tuple<int,int, int>>, greater<tuple<int,int,int>>>pq;
//     pq.push({0,0,-1});

//     int totalcost =0;
    
//     while(!pq.empty()){
//         auto [weight,node, parent]=pq.top();
//         pq.pop();

//         if(visited[node]){
//             continue;
//         }

//         visited[node]=true;
//         totalcost+=weight;

//         if(parent != -1) {
//             cout << parent << " - " << node << " : " << weight << "\n";
//         }

//         for(auto neighbor : adj[node]){
//             int next=neighbor.first;
//             int w=neighbor.second;

//             if(!visited[next]){
//                 pq.push({w,next,node});
//             }
//         }
//     }
//     cout<<totalcost<<"\n";
//     return 0;
// }

#include<bits/stdc++.h>
using namespace std;

// Simple Prim function
int prim(int V, vector<pair<int,int>> adj[], int skipU, int skipV) {
    vector<bool> visited(V, false);

    // {weight, node, parent}
    priority_queue<tuple<int,int,int>,
                   vector<tuple<int,int,int>>,
                   greater<tuple<int,int,int>>> pq;

    pq.push({0, 0, -1});

    int cost = 0, count = 0;

    while(!pq.empty()) {
        auto [w, node, parent] = pq.top();
        pq.pop();

        if(visited[node]) continue;

        // skip this edge if needed
        if(parent != -1 &&
           ((parent == skipU && node == skipV) ||
            (parent == skipV && node == skipU))) {
            continue;
        }

        visited[node] = true;
        cost += w;
        count++;

        for(auto it : adj[node]) {
            if(!visited[it.first]) {
                pq.push({it.second, it.first, node});
            }
        }
    }

    if(count != V) return INT_MAX; // not valid MST
    return cost;
}

int main() {
    int V, E;
    cin >> V >> E;

    vector<pair<int,int>> adj[V];

    for(int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;

        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    // Step 1: Get MST + store edges
    vector<bool> visited(V, false);

    priority_queue<tuple<int,int,int>,
                   vector<tuple<int,int,int>>,
                   greater<tuple<int,int,int>>> pq;

    pq.push({0, 0, -1});

    int mstCost = 0;
    vector<pair<int,int>> mstEdges;

    while(!pq.empty()) {
        auto [w, node, parent] = pq.top();
        pq.pop();

        if(visited[node]) continue;

        visited[node] = true;
        mstCost += w;

        if(parent != -1)
            mstEdges.push_back({parent, node});

        for(auto it : adj[node]) {
            if(!visited[it.first]) {
                pq.push({it.second, it.first, node});
            }
        }
    }

    // Step 2: Try removing each MST edge
    int secondBest = INT_MAX;

    for(auto e : mstEdges) {
        int cost = prim(V, adj, e.first, e.second);

        if(cost > mstCost)
            secondBest = min(secondBest, cost);
    }

    // Output
    cout << "MST: " << mstCost << endl;

    if(secondBest == INT_MAX)
        cout << "No second MST\n";
    else
        cout << "Second MST: " << secondBest << endl;

    return 0;
}