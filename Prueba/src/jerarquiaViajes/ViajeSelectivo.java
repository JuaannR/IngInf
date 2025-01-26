package jerarquiaViajes;

import java.time.LocalDate;
import java.util.HashSet;

public class ViajeSelectivo extends Viaje {

    private HashSet<String> usuariosVetados;

    public ViajeSelectivo(String propietario, String coche, String ruta, LocalDate fechaSalida, int plazasOfrecidas) {
        super(propietario, coche, ruta, fechaSalida, plazasOfrecidas);
        this.usuariosVetados = new HashSet<>();
    }

    public void vetarUsuario(String usuario) {
        usuariosVetados.add(usuario);
    }

    public void quitarVetoUsuario(String usuario) {
        usuariosVetados.remove(usuario);
    }

    @Override
    public Reserva realizarReserva(String usuario, int numPlazas) {
        if (usuariosVetados.contains(usuario)) {
            return null;
        }
        return super.realizarReserva(usuario, numPlazas);
    }

    @Override
    public String toString() {
        return super.toString() + ", usuariosVetados=" + usuariosVetados;
    }

    @Override
    public ViajeSelectivo clone() {
        ViajeSelectivo copia = (ViajeSelectivo) super.clone();
        copia.usuariosVetados = new HashSet<>(usuariosVetados);
        return copia;
    }
}
