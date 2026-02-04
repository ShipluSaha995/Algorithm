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

import java.util.*;

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
}