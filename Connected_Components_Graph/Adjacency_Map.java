import java.util.ArrayList;
import java.util.HashMap;
import java.util.LinkedList;

public class Adjacency_Map {

    private class Vertex{
        HashMap<String, Integer> nbrs = new HashMap<>();
    }

    HashMap<String, Vertex> vtces;

    public Adjacency_Map() {
        this.vtces = new HashMap<>();
    }

    public int numVertex(){
        return vtces.size();
    }

    public boolean containsVertex(String vname){
        return vtces.containsKey(vname);
    }

    public void addVertex(String value){
        Vertex vertex = new Vertex();
        vtces.put(value, vertex);
    }

    public void removeVertex(String vname){

        Vertex vertex = vtces.get(vname);

        ArrayList<String> keys = new ArrayList<>(vertex.nbrs.keySet());

        for (String key : keys){
            Vertex neighbour = vtces.get(key);
            neighbour.nbrs.remove(vname);
        }

        vtces.remove(vname);

    }

    public void display(){

        ArrayList<String> keys = new ArrayList<>(vtces.keySet());

        for (String key : keys){

            Vertex vertex = vtces.get(key);

            System.out.println(key + " -> " + vertex.nbrs);
        }

    }

    public int numEdges(){
        ArrayList<String> keys = new ArrayList<>(vtces.keySet());

        int count = 0;

        for (String key : keys){
            Vertex vertex = vtces.get(key);

            count += vertex.nbrs.size();
        }
        return count / 2;   // Each edge is counted twice
    }

    public boolean containsEdge(String A, String B){
        Vertex first = vtces.get(A);
        Vertex second = vtces.get(B);

        if(first == null || second == null || !first.nbrs.containsKey(B)) {
            return false;
        }
        return true;
    }

    public void addEdge(String first, String second, int weight){
        Vertex f = vtces.get(first);
        Vertex s = vtces.get(second);

        if(f == null || s == null || f.nbrs.containsKey(second)){
            return;
        }

        f.nbrs.put(second, weight);
        s.nbrs.put(first, weight);
    }

    public void removeEdge(String first, String second){

        Vertex f = vtces.get(first);
        Vertex s = vtces.get(second);

        if(f == null || s == null || !f.nbrs.containsKey(second)){
            return;
        }

        f.nbrs.remove(second);
        s.nbrs.remove(first);
    }


    private class Pair{
        String vname;
        String psf; // path so far
    }


    public boolean isConnected(){

        int flag = 0;

        HashMap<String, Boolean> processed = new HashMap<>();

        LinkedList<Pair> queue = new LinkedList<>();

        ArrayList<String> keys = new ArrayList<>(vtces.keySet());

        // for every node repeat the process
        for(String key : keys){

            if(processed.containsKey(key)){
                continue;
            }

//          if graph is disconnected, we will come in this region more than once
            flag++;

            // create a new pair
            Pair sp = new Pair();   // staring pair
            sp.vname = key;
            sp.psf = key;

            // put the new pair in queue

            queue.addLast(sp);

            while(!queue.isEmpty()){
                Pair rp = queue.removeFirst();  // removed pair

                if(processed.containsKey(rp.vname)){
                    continue;
                }

                processed.put(rp.vname, true);

                System.out.println(rp.vname + " via " + rp.psf);

                // neighbours

                Vertex rpvtx = vtces.get(rp.vname);
                ArrayList<String> nbrs = new ArrayList<>(rpvtx.nbrs.keySet());

                for(String nbr : nbrs){

                    // process only unprocessed neighbours
                    if(!processed.containsKey(nbr)){
                        Pair np = new Pair();
                        np.vname = nbr;
                        np.psf = rp.psf + nbr;

                        queue.addLast(np);
                    }
                }
            }
        }

        if(flag >= 2){
            return false;
        }
        return true;
    }

    // get connected components
    public ArrayList<ArrayList<String>> gCC(){

        ArrayList<ArrayList<String>> finalans = new ArrayList<>();

        HashMap<String, Boolean> processed = new HashMap<>();

        LinkedList<Pair> queue = new LinkedList<>();

        ArrayList<String> keys = new ArrayList<>(vtces.keySet());

        // for every node repeat the process
        for(String key : keys){

            if(processed.containsKey(key)){
                continue;
            }

            // for new component create a new arraylist
            ArrayList<String> subans = new ArrayList<>();

            // create a new pair
            Pair sp = new Pair();   // staring pair
            sp.vname = key;
            sp.psf = key;

            // put the new pair in queue

            queue.addLast(sp);

            while(!queue.isEmpty()){
                Pair rp = queue.removeFirst();  // removed pair

                if(processed.containsKey(rp.vname)){
                    continue;
                }

                processed.put(rp.vname, true);

                // adding vertices of a component
                subans.add(rp.vname);

                // neighbours

                Vertex rpvtx = vtces.get(rp.vname);
                ArrayList<String> nbrs = new ArrayList<>(rpvtx.nbrs.keySet());

                for(String nbr : nbrs){

                    // process only unprocessed neighbours
                    if(!processed.containsKey(nbr)){
                        Pair np = new Pair();
                        np.vname = nbr;
                        np.psf = rp.psf + nbr;

                        queue.addLast(np);
                    }
                }
            }

            // put in final answer
            finalans.add(subans);
        }
        return finalans;
    }

    public static void main(String[] args) {

        Adjacency_Map graph = new Adjacency_Map();

        graph.addVertex("A");
        graph.addVertex("B");
        graph.addVertex("C");
        graph.addVertex("D");
        graph.addVertex("E");
        graph.addVertex("F");
        graph.addVertex("G");
        graph.addVertex("H");


        graph.addEdge("A", "B", 3);
        graph.addEdge("A", "D", 2);
        graph.addEdge("B", "C", 4);
        graph.addEdge("D", "C", 4);
        graph.addEdge("D", "E", 10);
        graph.addEdge("F", "E", 9);
        graph.addEdge("G", "E", 8);
        graph.addEdge("F", "G", 6);

        graph.display();

        System.out.println(graph.gCC());
    }

}

/*
OUTPUT :

    A -> {B=3, D=2}
    B -> {A=3, C=4}
    C -> {B=4, D=4}
    D -> {A=2, C=4, E=10}
    E -> {D=10, F=9, G=8}
    F -> {E=9, G=6}
    G -> {E=8, F=6}
    H -> {}
    [[A, B, D, C, E, F, G], [H]]

*/


