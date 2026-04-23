// #include <bits/stdc++.h>
// using namespace std;

// struct Edge{
//     int u, v, weight;
// };

// vector<int> parent, rnk;

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

//     for(int i=0; i<E; i++){
//         int a = edge[i].u;
//         int b= edge[i].v;

//         if(findparent(a)!=findparent(b)){
//             cout<<a<<" - "<<b<<" : "<<edge[i].weight<<"\n";
//             totalcost+=edge[i].weight;
//             unionset(a,b);
//             edgeused++;

//             if(edgeused==V-1){
//                 break;
//             }
//         }
//     }

//     cout<<totalcost<<"\n";
// }

//second best mst:

#include <bits/stdc++.h>
using namespace std;

struct Edge{
    int u, v, weight;
};

vector<int>parent, rnk;

int findparent(int x){
    if(parent[x]!=x){
        parent[x]=findparent(parent[x]);
    }
    return parent[x];
}

void unionset(int a, int b){
    int rootA=findparent(a);
    int rootB=findparent(b);

    if(rootA!=rootB){
        if(rnk[rootA]<rnk[rootB]){
            parent[rootA]=rootB;
        }
        else if(rnk[rootA]>rnk[rootB]){
            parent[rootB]=rootA;
        }
        else{
            parent[rootA]=rootB;
            rnk[rootA]++;
        }
    }
}

bool cmpare(Edge a, Edge b){
    return a.weight<b.weight;
}

int dfs(int src, int dest, int parentNode, vector<vector<pair<int,int>>>&adj, int maxEdge){
    if(src==dest){
        return 1;
    }

    for(auto it:adj[src]){
        int next=it.first;
        int weight=it.second;

        if(next==parentNode){
            continue;
        }

        if(dfs(next, dest, src, adj, maxEdge)){
            maxEdge=max(maxEdge, weight);
            return 1;
        }
    }
    return 0;


}

int main(){
    int V, E;
    cin>>V>>E;

    vector<Edge>edge(E);

    for(int i=0; i<E; i++){
        cin>>edge[i].u>>edge[i].v>>edge[i].weight;
    }

    parent.resize(V);
    parent.resize(V,0);
    for(int i=0; i<E; i++){
        parent[i]=i;
    }
    sort(edge.begin(), edge.end(), cmpare);
    vector<Edge>mst;
    vector<bool>used(E,false);

    int totalcost=0;

    for(int i=0; i<E; i++){
        int u=edge[i].u;
        int v=edge[i].v;

        if(findparent(u)!=findparent(v)){
            unionset(u,v);
            mst.push_back(edge[i]);
            used[i]=true;
            totalcost+=edge[i].weight;
        }
    }

    vector<vector<pair<int,int>>> adj(V);

    for (auto e:mst){
        adj[e.u].push_back({e.v, e.weight});
        adj[e.v].push_back({e.u, e.weight});
    }

    int secondbest=INT_MAX;

    for(int i=0; i<E; i++){
        if(used[i]){
            continue;
        }
        int maxEdge=-1;
        dfs(edge[i].u,edge[i].v,-1,adj,maxEdge);
        int newcost=totalcost+edge[i].weight-maxEdge;
        if(newcost>totalcost){
            secondbest=min(secondbest,newcost);
        }
    }

    cout<<totalcost<<"\n";
    
     if (secondbest == INT_MAX)
        cout << "No Second Best MST exists\n";
    else
        cout << "Second Best MST cost: " << secondbest << endl;


    return 0;
}