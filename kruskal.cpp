#include<bits/stdc++.h>
using namespace std;

struct Edge{
    int u, v, weight;
};

vector<int> parent;

int findparent(int x){
    if(parent[x]==x){
        return x;
    }

    return parent[x]=findparent(parent[x]);
}

void unionset(int a, int b){
    int rootA=findparent(a);
    int rootB=findparent(b);
    parent[rootA]=rootB;
}

bool compare(Edge a, Edge b){
    return a.weight<b.weight;
}

int main(){
    int V, E;
    cin>>V>>E;
    vector<Edge>edge(E);

    for(int i=0;i<E; i++){
        cin>>edge[i].u>>edge[i].v>>edge[i].weight;
    }

    parent.resize(V);
    for(int i=0; i<V; i++){
        parent[i]=i;
    }

    sort(edge.begin(), edge.end(), compare);

    int totalcost=0;

    for(int i=0; i<E; i++){
        int u=edge[i].u;
        int v=edge[i].v;

        if(findparent(u)!=findparent(v)){
            cout<<u<<"-"<<v<<": "<<edge[i].weight<<"\n";
            totalcost+=edge[i].weight;
            unionset(u,v);
        }

    }
    cout<<totalcost<<"\n";
    return 0;
}