package kruskal;

public class Grafo {

    private final int numVertices;
    private AristContainer aristas;
    private final PartitionStructure partitionStructure;
    private VerticesSet vertices;

    public Grafo(int numVertices) {
        this.numVertices = numVertices;
        partitionStructure = new PartitionStructure(numVertices);
    }

    public int getNumVertices() {
        return numVertices;
    }

    public PartitionStructure getPartitionEstructure() {
        return partitionStructure;
    }

    public void addAristsContainer(AristContainer contenedorAristas) {
        this.aristas = contenedorAristas;
    }

    public AristContainer getAristas() {
        return aristas;
    }

    public void addVerticesSet(VerticesSet vertices) {
        this.vertices = vertices;
    }

    public boolean isConexo() {
        return vertices.esConexo();
    }
}
