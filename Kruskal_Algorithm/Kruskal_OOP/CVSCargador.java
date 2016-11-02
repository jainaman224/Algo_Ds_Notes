package kruskal;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;

public class CVSCargador {

    private BufferedReader lector = null;

    public CVSCargador(String ruta) {
        try {
            this.lector = new BufferedReader(new FileReader(ruta));
        } catch (FileNotFoundException ex) {
            System.out.println("File not found");
        }
    }

    public Grafo carga() {

        String line = readLine();
        String[] splitLine;
        Arista arista;
        Vertice a, b;
        AristContainer contAristas = new AristContainer();
        VerticesSet vertices = new VerticesSet();

        while (line != null) {
            //si comienza por # es un comentario y nos lo saltamos
            if ((line.length() > 0) && (line.charAt(0) != '#')) {
                splitLine = line.split(",");
                a = translateLineToVertice(splitLine, 0);
                b = translateLineToVertice(splitLine, 1);

                if (a != null && b != null) {
                    if (vertices.contains(a)) {
                        a = vertices.getVertice(a.getId());
                    }
                    if (vertices.contains(b)) {
                        b = vertices.getVertice(b.getId());
                    }
                    a.link(b);
                    b.link(a);
                }
                vertices.addVertice(a);
                vertices.addVertice(b);

                arista = genArista(splitLine);
                if (arista != null) {
                    contAristas.addArista(arista);
                }
            }

            line = readLine();
        }

        Grafo resultado = new Grafo(vertices.size());
        resultado.addAristsContainer(contAristas);
        resultado.addVerticesSet(vertices);

        return resultado;
    }

    private String readLine() {
        String line;
        try {
            line = lector.readLine();
        } catch (IOException ex) {
            line = null;
        }

        return line;
    }

    private Integer[] traduceLinea(String[] lineaPartida) {

        //si es Inf entonces no existe arista pero existen los vértices
        for (int i = 0; i < lineaPartida.length; i++) {
            if (lineaPartida[i].equalsIgnoreCase("Inf")) {
                lineaPartida[i] = "-1";
            }
        }

        Integer[] resultado = {
            Integer.parseInt(lineaPartida[0]),
            Integer.parseInt(lineaPartida[1]),
            Integer.parseInt(lineaPartida[2])
        };

        if (resultado[0] < 0) {
            resultado[0] = null;
        } else if (resultado[1] < 0) {
            resultado[1] = null;
        } else if (resultado[2] < 0) {
            resultado[2] = null;
        }

        return resultado;
    }

    private Vertice translateLineToVertice(String[] lineaPartida, int i) {

        if (Character.isDigit(lineaPartida[i].charAt(0))) {
            return new Vertice(Integer.parseInt(lineaPartida[i]));
        }
        return null;

    }

    private Arista genArista(String[] lineaPartida) {
        Integer[] lineaTraducida = traduceLinea(lineaPartida);
        if (lineaTraducida[0] != null
                && lineaTraducida[1] != null
                && lineaTraducida[2] != null) {
            return new Arista(
                    lineaTraducida[0],
                    lineaTraducida[1],
                    lineaTraducida[2]
            );
        }
        return null;
    }
}
