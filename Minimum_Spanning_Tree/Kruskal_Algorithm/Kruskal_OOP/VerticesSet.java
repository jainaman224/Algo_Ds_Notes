package kruskal;

import java.util.HashMap;

public class VerticesSet {

    final private HashMap<Integer, Vertice> conjunto;

    public VerticesSet() {
        this.conjunto = new HashMap<>();
    }

    public void addVertice(Vertice v) {
        if (v == null) {
            return;
        }
        if (!conjunto.containsKey(v.getId())) {
            conjunto.put(v.getId(), v);
        }
    }

    public boolean esConexo() {
        return new ConnectionStructure(conjunto).isCompletelyConnected();
    }

    public boolean contains(Vertice v) {
        return conjunto.containsValue(v);
    }

    public void enlaza(Vertice a, Vertice aAñadir) {
        conjunto.get(a.getId()).link(aAñadir);

    }

    public int size() {
        return this.conjunto.size();
    }

    public Vertice getVertice(Integer id) {
        return conjunto.get(id);
    }
}
