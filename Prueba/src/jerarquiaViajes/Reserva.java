package jerarquiaViajes;

import java.time.LocalDate;
import java.util.Objects;

public record Reserva(String usuario, int numPlazas, LocalDate fecha, String codigo) {
    public Reserva(String usuario, int numPlazas, String codigo) {
        this(usuario, numPlazas, LocalDate.now(), codigo);
    }

    @Override
    public String toString() {
        return "Reserva{" +
                "usuario='" + usuario + '\'' +
                ", numPlazas=" + numPlazas +
                ", fecha=" + fecha +
                ", codigo='" + codigo + '\'' +
                '}';
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (!(o instanceof Reserva reserva)) return false;
        return numPlazas == reserva.numPlazas &&
                Objects.equals(usuario, reserva.usuario) &&
                Objects.equals(fecha, reserva.fecha) &&
                Objects.equals(codigo, reserva.codigo);
    }

    @Override
    public int hashCode() {
        return Objects.hash(usuario, numPlazas, fecha, codigo);
    }
}
