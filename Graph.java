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


