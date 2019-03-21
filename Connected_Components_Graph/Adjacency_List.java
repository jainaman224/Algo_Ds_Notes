import java.util.*;

public class Adjacency_List<T> {

    private LinkedList<Vertex> vertices;

    public Adjacency_List() {
        vertices = new LinkedList<>();
    }

    public void addVertex(T value){
        vertices.add(new Vertex((value)));
    }

    public void addEdge(T first, T second){
        Vertex f = get(first);
        Vertex s = get(second);

        if(f != null && s != null){
            f.neighbours.add(s);
            s.neighbours.add(f);
        }
    }

    public void display(){
        for(Vertex vertex : vertices){
            System.out.print(vertex.value + " -> ");
            for(Vertex neighbour : vertex.neighbours){
                System.out.print(neighbour.value + " ");
            }
            System.out.println();
        }
    }

    private Vertex get(T value){
        for(Vertex vertex : vertices){
            if(vertex.value.equals(value)){
                return vertex;
            }
        }
        return null;
    }

    public void connectedComponents(){

        Set<Vertex> processed = new HashSet<>();
        Queue<Vertex> queue = new LinkedList<>();

        for(Vertex vertex : vertices){
            if(processed.contains(vertex)){
                continue;
            }

            processed.add(vertex);
            queue.add(vertex);

            while(!queue.isEmpty()){
                Vertex front = queue.remove();

                System.out.print(front.value + " ");

                for(Vertex neighbour : front.neighbours){
                    if(!processed.contains(neighbour)){
                        processed.add(neighbour);
                        queue.add(neighbour);
                    }
                }
            }

            System.out.println();
        }
    }

    public LinkedList<LinkedList<Vertex>> connectedComponentsLL(){

        Set<Vertex> processed = new HashSet<>();
        Queue<Vertex> queue = new LinkedList<>();

        LinkedList<LinkedList<Vertex>> list = new LinkedList<>();

        for(Vertex vertex : vertices){
            if(processed.contains(vertex)){
                continue;
            }

            processed.add(vertex);
            queue.add(vertex);

            LinkedList<Vertex> level = new LinkedList<>();

            while(!queue.isEmpty()){
                Vertex front = queue.remove();

                level.add(front);

                for(Vertex neighbour : front.neighbours){
                    if(!processed.contains(neighbour)){
                        processed.add(neighbour);
                        queue.add(neighbour);
                    }
                }
            }
            list.add(level);
        }
        return list;
    }

    private class Vertex{
        private T value;
        private LinkedList<Vertex> neighbours;

        public Vertex(T value) {
            this.value = value;
            neighbours = new LinkedList<>();
        }
    }

    public static void main(String[] args) {

        Adjacency_List<Character> graph = new Adjacency_List<>();

        graph.addVertex('A');
        graph.addVertex('B');
        graph.addVertex('C');
        graph.addVertex('D');
        graph.addVertex('E');
        graph.addVertex('F');

        graph.addEdge('A', 'B');
        graph.addEdge('A', 'C');
        graph.addEdge('C', 'D');
        graph.addEdge('A', 'D');
        graph.addEdge('E', 'F');

        graph.display();

        graph.connectedComponents();

    }

}

/*
OUTPUT :

    A -> B C D
    B -> A
    C -> A D
    D -> C A
    E -> F
    F -> E
    A B C D
    E F

*/
