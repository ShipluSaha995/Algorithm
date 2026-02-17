/*
Graph:

A graph is a non-linear data-structure used to represent relationship between objects 

A graph is defiend as G(V,E) Where,
        V = a finite set of vertices(nodes)
        E = a set of edges connecting pairs of vertices

we can say that, A Graph consits of a non-empty set of vertices or nodes V and a set of edges E.



A graph is a pictorial representation of a set of objects where some pairs of objects are connected by links 
The interconnected objects are represented by points termed as vertices or nodes and the links that connect
the vertices are called edges.

    Example:

        6------4-----2
               |     |    
               |     |    
               5-----3---1

    In this Graph= V{1,2,3,4,5,6}
                   E{{6,4},{4,2},{4,5},{5,3},{3,2},{3,1}}


There are two ways to create a graph 
1. Adjacecy matrix 
2. Adjacency list



*/

//Graph with Adjacency Matrix:

/*import java.util.*;
class CreateGraph{
    int V;
    int[][] arr;

    CreateGraph(int V){
        this.V=V;
        arr=new int[V][V];
    }

    void addEdge(int u, int v){
        if(u<0||v<0||u>=V||v>=V){
            return;
        }
        arr[u][v]=1;
        arr[v][u]=1;
    }

    void print(){
        for(int i=0; i<V; i++){
            for(int j=0; j<V; j++){
                System.out.print(arr[i][j]+" ");
            }
            System.out.println();
        }
        
    }
}

public class Graph{
    public static void main(String[] args) {
        Scanner sc= new Scanner(System.in);
        int V= sc.nextInt();

        CreateGraph g= new CreateGraph(V);
        int E= sc.nextInt();

        for(int i=0; i<E; i++){
            int u=sc.nextInt();
            int v=sc.nextInt();
            g.addEdge(u, v);
        }

        g.print();
    }
}
*/

// Graph with adjacency list 
/*
import java.util.*;

class Glist{
    int V;
    ArrayList<ArrayList<Integer>>adj;

    Glist(int V){
        this.V=V;
        adj = new ArrayList<>();
        
        for(int i=0; i<V; i++){
            adj.add(new ArrayList<>());
        }
    }

    void addEdge(int u, int v){
        if(u<0||v<0||u>=V||v>=V){
            return;
        }

        adj.get(u).add(v);
        adj.get(v).add(u);
    }

    void print(){
        for(int i=0; i<V; i++){
            System.out.print(i+"->");
            for(int  node:adj.get(i)){
                System.out.print(node +" ");
            }
             System.out.println();
        }
       
    }
}

public class Graph{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int V= sc.nextInt();
        int E = sc.nextInt();

        Glist g = new Glist(V);

        for(int i=0; i<E; i++){
            int u= sc.nextInt();
            int v= sc.nextInt();
            g.addEdge(u, v);
        }
        
        g.print();
    }
}

*/

/* Types of graphs

1. Undirected Graph 
2. Directed Graph
3. Weighted Graph
4. Complete Graph


*/


 // 1. Undirected Graph: An undirected graph is a graph where edges have no directions.
 
 //code :
/* 
 import java.util.*;

 class Graphlist{
    int V;
    ArrayList<ArrayList<Integer>>adj;

    Graphlist(int V){

        this.V=V;
        adj=new ArrayList<>();

        for(int i=0; i<V; i++){
            adj.add(new ArrayList<>());
        }
    }

    void addedge(int u, int v){
        if(u<0||v<0||u>=V||v>=V){
            return;
        }

        adj.get(u).add(v);
        adj.get(v).add(u);
    }

    void print(){
        for(int i=0; i<V; i++){
            System.out.print(i+"->");
            for(int node:adj.get(i)){
                System.out.print(node+" ");
            }
            System.out.println();
        }
    }
 }

 public class Graph{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int V = sc.nextInt();
        int E = sc.nextInt();

        Graphlist g = new Graphlist(V);

        for(int i =0; i<E; i++){
            int u= sc.nextInt();
            int v = sc.nextInt();

            g.addedge(u, v);
        }

        g.print();

    }
 }*/


// Directed Graph: A directed graph is a graph where edges have directions 

// code: 
/* 
import java.util.*;

class Glist{
    int V;
    ArrayList<ArrayList<Integer>>adj;

    Glist(int V){
        this.V=V;
        adj=new ArrayList<>();

        for(int i=0; i<V; i++){
            adj.add(new ArrayList<>());
        }
    }

    void addEdge(int u, int v){
        if(u<0||v<0||u>=V||u>=V){
            return;
        }

        adj.get(u).add(v);
    }

    void print(){
        for(int i=0; i<V; i++){
            System.out.print(i+"->");
            for(int node:adj.get(i)){
                System.out.print(node+" ");
            }
            System.out.println();
        }
    }
}

public class Graph{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int V = sc.nextInt();
        int E = sc.nextInt();

        Glist g = new Glist(V);

        for(int i=0; i<E; i++){
            int u = sc.nextInt();
            int v = sc.nextInt();

            g.addEdge(u, v);
        }

        g.print();
        sc.close();
    }
}*/

// Weighted Graph: A graph is known as weighted graph if a weight is assosiated with each edge.

/*import java.util.*;

class Edge{
    int to, weight;

    Edge(int to, int weight){
        this.to=to;
        this.weight=weight;
    }
}

class Weight{
    int V;
    ArrayList<ArrayList<Edge>> adj;
    
    Weight(int V){
        this.V = V;
        adj = new ArrayList<>();
        
        for(int i = 0; i < V; i++){
            adj.add(new ArrayList<>());
        }
    }

    void addEdge(int u, int v, int w){
        if(u<0||v<0||u>=V||v>=V){
            return;
        }

        adj.get(u).add(new Edge(v, w));
    }

    void print(){
        for(int i=0; i<V; i++){
            System.out.print(i+"->");
            for(Edge e:adj.get(i)){
                System.out.print("("+e.to+","+e.weight+")");
            }
            System.out.println();
        }
    }
}

public class Graph{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int V = sc.nextInt();
        int E = sc.nextInt();

        Weight we = new Weight(V);

        for(int i=0; i<E; i++){
            int u = sc.nextInt();
            int v = sc.nextInt();
            int w = sc.nextInt();

            we.addEdge(u,v,w);
        }

        we.print();
        sc.close();

    }
}*/


// Complete Graph: Complete graph in which every vertex is directly connected to evry other vertex.
/*
key point :
1. It has the maximum number of edges.
2. For undirected graph wtih n vertices, the maximum number of edges is n(n-1)/2.
3. For the direcrted graph with n vertices, the maximum number of edges is n(n-1).

*/

/*import java.util.*;
class CGraph{
    int V;
    ArrayList<ArrayList<Integer>>adj;

    CGraph(int V){
        this.V=V;
        adj=new ArrayList<>();

        for(int i=0; i<V; i++){
            adj.add(new ArrayList<>());
        }

        for(int i=0; i<V; i++){
            for(int j=0; j<V; j++){
                if(i!=j){
                    adj.get(i).add(j);
                }
            }
        }
    }

    void print(){
        for(int i=0; i<V; i++){
            System.out.print(i+"-> ");
            for(int node:adj.get(i)){
                System.out.print(node+" ");
            }
            System.out.println();
        }
    }
}

public class Graph{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int V = sc.nextInt();

        CGraph g = new CGraph(V);

        g.print();
        sc.close();
    }
}*/


// Degree 
/*
Degree of a vertex = number of edges incident to it.

0 — 1
|   |
2 — 3

IN directed graph dgree is split into to parts 
1. In degree: Number of edges coming into vertex
2. Out degree: Number of edges going out of a vertex.

0 → 1 → 2
↓
3

Degree = indegree + outdegree

*/

// Path

/*
The path is a sequence of vertices  that connect two nodes in a graph
The length of a path is the number of edges it contains.

simple path: No vertex is repeated

0 → 1 → 2 → 3   ✅
0 → 1 → 2 → 1   ❌

Closed Path: Starting and the ending vertex are the same

0 → 1 → 2 → 0

Cycle: a closed simple path no repeated vertex except first = last

0 → 1 → 2 → 0

Direcetd path : Direction of the edges must be followed

0 → 1 → 3   ✅
1 → 0 → 3   ❌

Undirected Path : Edges can be traversed in both ways 

0-1-2-3-5-6

*/

//BFS 

/*
BFS(Breadth First Serch) is a graph traversal algorithm that explores vertices levle by levle. It first 
visits all neighbours of a starting node then neighbors of those neighbors and so on.

key points : 
1. It uses QUEUE 
2. works for both undirected and directed graph
3. finds the shortest path in an directed graph
4. Before prcessing all vertices, insert the adjacency vertices in the queue.
5. do not insert visited vertices again 
6. do no repeat or reinsert alresdy inserted vertices


*/
/* 
import java.util.*;

class BFS{
    int V;
    ArrayList<ArrayList<Integer>>adj;
    
    BFS(int V){
        this.V=V;
        adj=new ArrayList<>();
        
        for(int i=0; i<V; i++){
            adj.add(new ArrayList<>());

        }
    }

    void addEdge(int u, int v){
        adj.get(u).add(v);
        adj.get(v).add(u);
    }

    void bfs(int start){
        boolean[] visited = new boolean[V];
        Queue<Integer>queue=new ArrayDeque<>();

        visited[start]=true;
        queue.add(start);

        while(!queue.isEmpty()){
            int node = queue.poll();
            System.out.print(node+" ");
            
            for(int neighbor:adj.get(node)){
                if(!visited[neighbor]){
                    visited[neighbor]=true;
                    queue.add(neighbor);
                }
            }
        }
    }
}

public class Graph{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);

        int V = sc.nextInt();
        int E = sc.nextInt();

        BFS b = new BFS(V);

        for(int i =0; i<E; i++){
            int u = sc.nextInt();
            int v = sc.nextInt();

            b.addEdge(u,v);
        }

        int start = sc.nextInt();
        b.bfs(start);
    }
}*/

import java.util.*;

class DFS {
    int V;
    ArrayList<ArrayList<Integer>> adj;

    DFS(int V) {
        this.V = V;
        adj = new ArrayList<>();
        for(int i = 0; i < V; i++)
            adj.add(new ArrayList<>());
    }

    void addEdge(int u, int v) {
        adj.get(u).add(v);
        adj.get(v).add(u);   
    }

    void dfs(int start) {
        boolean[] visited = new boolean[V];
        dfsUtil(start, visited);
    }

    void dfsUtil(int v, boolean[] visited) {
        visited[v] = true;
        System.out.print(v + " ");

        for(int neighbor : adj.get(v)) {
            if(!visited[neighbor])
                dfsUtil(neighbor, visited);
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("vertices: ");
        int V = sc.nextInt();

        System.out.print("edges: ");
        int E = sc.nextInt();

        DFS d = new DFS(V);

        System.out.println("Nodes:");
        for(int i = 0; i < E; i++) {
            int u = sc.nextInt();
            int v = sc.nextInt();
            d.addEdge(u, v);
        }

        System.out.print("starting: ");
        int start = sc.nextInt();

    
        d.dfs(start);
    
    }
}
