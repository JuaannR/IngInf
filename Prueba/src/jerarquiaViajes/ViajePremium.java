package jerarquiaViajes;

import java.time.LocalDate;

public class ViajePremium extends Viaje {

    public ViajePremium(String propietario, String coche, String ruta, LocalDate fechaSalida, int plazasOfrecidas) {
        super(propietario, coche, ruta, fechaSalida, plazasOfrecidas);
    }

    public boolean cancelarReserva(String usuario) {
        Reserva reserva = getReservaPorUsuario(usuario);
        if (reserva != null && LocalDate.now().isBefore(getFechaSalida().minusDays(1))) {
            listaReservas.remove(reserva);
            return true;
        }
        return false;
    }

    @Override
    public ViajePremium clone() {
        ViajePremium copia = (ViajePremium) super.clone();
        copia.listaReservas.clear(); // Cancelar reservas en la copia
        return copia;
    }
}
