package kruskal;

import java.util.HashMap;
import java.util.HashSet;

public class LoopDetector {

    /*
        Máximo orden de ejecución: exploraGrafo O(numeroAristasSolucion)
        Contenedor que ocupa la mayor cantidad de memoria id_vecinos:
    */

    private final HashMap<Integer, HashSet<Integer>> id_vecinos;
    private boolean hayBucles;
    private final AristContainer aristas;

    public LoopDetector(AristContainer aristas) {
        this.hayBucles = false;
        this.aristas = aristas;
        this.id_vecinos = new HashMap<>();
    }

    public boolean hasLoops() {
        exploraGrafo();
        return hayBucles;
    }

    private void exploraGrafo() {
        for (Arista arista : aristas) {
            conectaAmbosVertices(arista);
            if (hayBucles) {
                return;
            }
        }
    }

    private void conecta(Integer vertice, Integer vecino) {
        if (estaVerticeConectado(vertice)) {
            if (esteVecinoHaPasadoDosVeces(vertice, vecino)) {
                hayBucles = true;
            }
        } else {
            HashSet<Integer> vecinos = new HashSet<>();
            vecinos.add(vecino);
            id_vecinos.put(vertice, vecinos);
        }
    }

    private boolean estaVerticeConectado(Integer v) {
        return id_vecinos.containsKey(v);
    }

    private boolean esteVecinoHaPasadoDosVeces(Integer vertice, Integer vecino) {
        return this.id_vecinos.get(vertice).contains(vecino);
    }

    private void conectaAmbosVertices(Arista arista) {
        conecta(arista.getU(), arista.getV());
        conecta(arista.getV(), arista.getU());
    }

}
