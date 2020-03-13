import java.util.ArrayList;
import java.util.Collection;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.Map;
import java.util.Set;
import java.util.*;

class Graph {
    private class Vertex {
        String name;
        HashMap<Vertex, Integer> nbrs;

        Vertex(String name) {
            this.name = name;
            this.nbrs = new HashMap<>();
        }

        public boolean equals(Object other) {
            Vertex ov = (Vertex) other;
            return this.name.equals(ov.name);
        }

        public void display() {
            String str = "";
            str = this.name + "=>";
            Set<Map.Entry<Vertex, Integer>> nbrs = this.nbrs.entrySet();
            for (Map.Entry<Vertex, Integer> nbr : nbrs) {
                str = str + nbr.getKey().name + "(" + nbr.getValue() + "),";
            }
            str = str + "END";
            System.out.println(str);

        }
    }

    HashMap<String, Vertex> vtces;

    public Graph() {
        this.vtces = new HashMap<>();
    }

    public int numvertices() {
        return this.vtces.size();
    }

    public void addVertex(String name) {
        if (this.vtces.containsKey(name)) {
            return;
        }

        Vertex vtx = new Vertex(name);
        this.vtces.put(name, vtx);
    }

    public void removeVertex(String name) {
        if (!this.vtces.containsKey(name)) {
            return;
        }

        Vertex vtx = this.vtces.get(name);
        Set<Vertex> nbrs = vtx.nbrs.keySet();
        for (Vertex nbr : nbrs) {
            nbr.nbrs.remove(vtx);
        }

        this.vtces.remove(name);

    }

    public int numedges() {
        int rv = 0;
        Collection<Vertex> vtces = this.vtces.values();
        for (Vertex vtx : vtces) {
            rv = rv + vtx.nbrs.size();
        }
        rv = rv / 2;
        return rv;
    }

    public void addEdge(String name1, String name2, int cost) {
        Vertex vtx1 = this.vtces.get(name1);
        Vertex vtx2 = this.vtces.get(name2);
        if (vtx1 == null || vtx2 == null || vtx1.nbrs.containsKey(vtx2)) {
            return;
        }

        vtx1.nbrs.put(vtx2, cost);
        vtx2.nbrs.put(vtx1, cost);

    }

    public void removeEdge(String name1, String name2) {
        Vertex vtx1 = this.vtces.get(name1);
        Vertex vtx2 = this.vtces.get(name2);
        if (vtx1 == null || vtx2 == null || !vtx1.nbrs.containsKey(vtx2)) {
            return;
        }

        vtx1.nbrs.remove(vtx2);
        vtx2.nbrs.remove(vtx1);

    }

    public void display() {
        Collection<Vertex> vtces = this.vtces.values();
        for (Vertex vtx : vtces) {
            vtx.display();
        }
        System.out.println("*****************");
    }
}

class client {

    public static void main(String[] args) {
        Scanner scn=new Scanner(System.in);
        // TODO Auto-generated method stub
        Graph graph = new Graph();
        int No_Of_Vertices=scn.nextInt();
        while(No_Of_Vertices-->0){
            String s=scn.next();
            graph.addVertex(s);
        }
        int No_Of_Edges=scn.nextInt();
        // edges are added to hashmap with weight
        while(No_Of_Edges-->0){
            String v1=scn.next();
            String v2=scn.next();
            int cost=scn.nextInt();
            graph.addEdge(v1, v2,cost);
        }
        graph.display();
    }

}

/*
  Sample Input:
  5
  A
  B
  C
  D
  E
  4
  A B 10
  C D 8
  E C 7
  A E 4
  Sample Output:
  A=>B(10),E(4),END
  B=>A(10),END
  C=>D(8),E(7),END
  D=>C(8),END
  E=>C(7),A(4),END
  *****************
 */
