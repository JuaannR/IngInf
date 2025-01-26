package apuesta;

import java.util.Objects;

public class Marcador {
    private final int tanteoLocal;
    private final int tanteoVisitante;

    public Marcador(int tanteoLocal, int tanteoVisitante) {
        this.tanteoLocal = tanteoLocal;
        this.tanteoVisitante = tanteoVisitante;
    }

    public int getTanteoLocal() {
        return tanteoLocal;
    }

    public int getTanteoVisitante() {
        return tanteoVisitante;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        Marcador marcador = (Marcador) o;
        return tanteoLocal == marcador.tanteoLocal &&
               tanteoVisitante == marcador.tanteoVisitante;
    }

    @Override
    public int hashCode() {
        return Objects.hash(tanteoLocal, tanteoVisitante);
    }

    @Override
    public String toString() {
        return "(" + tanteoLocal + ", " + tanteoVisitante + ")";
    }
}

//IMPLEMENTAR COMO RECORD!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!