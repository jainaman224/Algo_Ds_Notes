package kruskal;

public class Kruskal {

    public static void main(String[] args) {

        /* Let the given graph is :
     (1)____1___(2)
    /  \       /  \
   3    4     4    6
  /      \   /      \
 /        \ /        \
(0)___5___(5)____5___(3)
 \         |         /
  \        |        /
   \       |       /
    \      2      /
     6     |     8
      \    |    /
       \   |   /
        \  |  /
         \ | /
          (4)
*/

        Vertice zero = new Vertice(0);
        Vertice one = new Vertice(1);
        Vertice two = new Vertice(2);
        Vertice three = new Vertice(3);
        Vertice four = new Vertice(4);
        Vertice five = new Vertice(5);

        zero.link(one);
        zero.link(five);
        zero.link(four);
        one.link(zero);
        one.link(five);
        one.link(two);
        two.link(five);
        two.link(three);
        two.link(one);
        three.link(two);
        three.link(five);
        three.link(four);
        four.link(zero);
        four.link(five);
        four.link(three);
        five.link(zero);
        five.link(one);
        five.link(two);
        five.link(three);
        five.link(four);


        Arista a = new Arista(1, 2, 1);
        Arista b = new Arista(2, 3, 6);
        Arista c = new Arista(3, 4, 8);
        Arista d = new Arista(4, 0, 6);
        Arista e = new Arista(0, 1, 3);
        Arista f = new Arista(1,5,4);
        Arista g = new Arista(2,5,4);
        Arista h = new Arista(5,3, 5);
        Arista i = new Arista(5,4,2);
        Arista j = new Arista(5,0,5);

        VerticesSet vertSet = new VerticesSet();
        vertSet.addVertice(five);
        vertSet.addVertice(four);
        vertSet.addVertice(three);
        vertSet.addVertice(two);
        vertSet.addVertice(one);
        vertSet.addVertice(zero);

        AristContainer artContainer = new AristContainer();
        artContainer.add(a);
        artContainer.add(b);
        artContainer.add(c);
        artContainer.add(d);
        artContainer.add(e);
        artContainer.add(f);
        artContainer.add(g);
        artContainer.add(h);
        artContainer.add(i);
        artContainer.add(j);

        Grafo graph = new Grafo(6);

        graph.addAristsContainer(artContainer);
        graph.addVerticesSet(vertSet);




        //System.out.println(g.esConexo());
        if (graph.isConexo()) {

            showNumVertices(graph);
            AristContainer solution = kruskal(graph);
            salidaKruskal(solution);
            checkOutputForLoops(new LoopDetector(solution).hasLoops());

        } else {
            System.out.println("El grafo pasado en la entrada no es conexo.");
        }

    }

    private static AristContainer kruskal(Grafo g) {
        int n = g.getNumVertices();
        AristContainer T = new AristContainer();
        //La inicialización ya está echa sola al crear Grafo

        Arista[] sortedAristas = g.getAristas().getSortedAristContainer();
        int uconj, vconj;

        for (Arista arista : sortedAristas) {
            uconj = g.getPartitionEstructure().seek(arista.getU());
            vconj = g.getPartitionEstructure().seek(arista.getV());

            if (uconj != vconj) {
                g.getPartitionEstructure().merge(uconj, vconj);
                T.addArista(arista);
            }
            if (T.size() >= n) {
                break;
            }
        }
        return T;
    }

    private static void showNumVertices(Grafo g) {
        System.out.println("Num vértices:" + g.getNumVertices());

    }

    private static void salidaKruskal(AristContainer solucion) {
        solucion.getSortedAristContainer();
        for (Arista arista : solucion) {
            System.out.println("Arista: " + arista.getU() + ", " + arista.getV() + "; weight: " + arista.getPeso());
        }
    }

    private static void checkOutputForLoops(boolean tieneBucles) {
        if (tieneBucles) {
            System.out.println("Has loops");
        } else {
            System.out.println("Do not has loops");
        }
    }
}
