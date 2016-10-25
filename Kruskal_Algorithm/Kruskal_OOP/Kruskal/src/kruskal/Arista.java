package kruskal;

public class Arista implements Comparable<Arista> {

    private final Integer u;
    private final Integer v;

    public int getU() {
        return u;
    }

    public int getV() {
        return v;
    }
    private final int weight;

    public Arista(int a, int b, int peso) {
        this.u = a;
        this.v = b;
        this.weight = peso;
    }

    public int getPeso() {
        return this.weight;
    }

    @Override
    public int compareTo(Arista o) {
        if (this.weight == o.weight) {
            return 0;
        }
        return this.weight - o.weight;
    }

    @Override
    public boolean equals(Object arista) {
        if (!(arista instanceof Arista)) {
            return false;
        }
        Arista o = (Arista) arista;
        if (this.getU() == o.getU() && this.getV() == o.getV()) {
            return true;
        } else if (this.getU() == o.getV() && this.getV() == o.getU()) {
            return true;
        }
        return false;
    }

}
