package kruskal;

import java.util.HashMap;
import java.util.Objects;

public class Vertice {

    private final Integer id;
    private final HashMap<Integer, Vertice> ways;

    public Vertice(Integer id) {
        this.id = id;
        ways = new HashMap<>();
    }

    public Integer getId() {
        return id;
    }

    public void link(Vertice v) {
        if (!ways.containsKey(v.getId())) {
            ways.put(v.getId(), v);
        }
    }

    public HashMap<Integer, Vertice> getDifferentWays() {
        return ways;
    }

    @Override
    public boolean equals(Object obj) {
        if (obj == null) {
            return false;
        }
        if (getClass() != obj.getClass()) {
            return false;
        }
        final Vertice other = (Vertice) obj;
        return Objects.equals(this.id, other.id);
    }

}
