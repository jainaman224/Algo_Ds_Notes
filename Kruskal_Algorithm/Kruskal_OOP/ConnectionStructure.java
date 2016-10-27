package kruskal;

import java.util.HashMap;
import java.util.HashSet;

class ConnectionStructure {

    private final HashSet<Integer> conectados;
    private final HashMap<Integer, Vertice> conjunto;

    public ConnectionStructure(HashMap<Integer, Vertice> conjunto) {
        conectados = new HashSet<>();
        this.conjunto = conjunto;
    }

    public void conecta(Integer v) {
        conectados.add(v);
    }

    public boolean isCompletelyConnected() {
        exploraGrafo(this.conjunto.entrySet().iterator().next().getValue());
        return conectados.size() == conjunto.size();
    }

    private void exploraGrafo(Vertice v) {
        if (!estaVerticeConectado(v.getId())) {
            conecta(v.getId());
            for (Vertice value : v.getDifferentWays().values()) {
                exploraGrafo(value);
            }
        }
    }

    public boolean estaVerticeConectado(Integer v) {
        return conectados.contains(v);
    }

}
