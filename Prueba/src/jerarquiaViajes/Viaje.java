package jerarquiaViajes;

import java.time.LocalDate;
import java.util.ArrayList;
import java.util.Objects;

public class Viaje implements Cloneable {

    private static final int PLAZAS_OFRECIDAS_POR_DEFECTO = 1;
    private static final int PLAZAS_RESERVADAS = 1;

    private final String codigoViaje;
    private final String propietario;
    private final String coche;
    private final String ruta;
    private final LocalDate fechaSalida;
    private final int plazasOfrecidas;
    protected ArrayList<Reserva> listaReservas;

    public Viaje(String propietario, String coche, String ruta, LocalDate fechaSalida, int plazasOfrecidas) {
        this.codigoViaje = java.util.UUID.randomUUID().toString();
        this.propietario = propietario;
        this.coche = coche;
        this.ruta = ruta;
        this.fechaSalida = fechaSalida;
        this.plazasOfrecidas = plazasOfrecidas;
        this.listaReservas = new ArrayList<>();
    }

    public Viaje(String propietario, String coche, String ruta, LocalDate fechaSalida) {
        this(propietario, coche, ruta, fechaSalida, PLAZAS_OFRECIDAS_POR_DEFECTO);
    }
    
    public LocalDate getFechaSalida() {
        return fechaSalida;
    }


    public String getCodigoViaje() {
        return codigoViaje;
    }

    public int getPlazasDisponibles() {
        return plazasOfrecidas - listaReservas.stream().mapToInt(Reserva::numPlazas).sum();
    }

    public Reserva realizarReserva(String usuario, int numPlazas) {
        if (getPlazasDisponibles() >= numPlazas &&
                fechaSalida.isAfter(LocalDate.now()) &&
                getReservaPorUsuario(usuario) == null) {
            Reserva nuevaReserva = new Reserva(usuario, numPlazas, codigoViaje);
            listaReservas.add(nuevaReserva);
            return nuevaReserva;
        }
        return null;
    }

    public Reserva realizarReserva(String usuario) {
        return realizarReserva(usuario, PLAZAS_RESERVADAS);
    }

    public Reserva getReservaPorUsuario(String usuario) {
        return listaReservas.stream()
                .filter(reserva -> reserva.usuario().equals(usuario))
                .findFirst()
                .orElse(null);
    }

    @Override
    public String toString() {
        return "Viaje{" +
                "codigoViaje='" + codigoViaje + '\'' +
                ", propietario='" + propietario + '\'' +
                ", coche='" + coche + '\'' +
                ", ruta='" + ruta + '\'' +
                ", fechaSalida=" + fechaSalida +
                ", plazasOfrecidas=" + plazasOfrecidas +
                ", listaReservas=" + listaReservas +
                '}';
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (!(o instanceof Viaje viaje)) return false;
        return Objects.equals(codigoViaje, viaje.codigoViaje);
    }

    @Override
    public int hashCode() {
        return Objects.hash(codigoViaje);
    }

    @Override
    protected Viaje clone() {
        try {
            Viaje copia = (Viaje) super.clone();
            copia.listaReservas = new ArrayList<>(listaReservas);
            return copia;
        } catch (CloneNotSupportedException e) {
            throw new AssertionError(); // Esto no debería suceder
        }
    }
}
