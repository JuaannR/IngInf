package apuesta;

import java.util.HashSet;
import java.util.Set;

public class EventoRestringido extends Evento {
    private final Set<Marcador> opciones;

    public EventoRestringido(String nombre, double precioApuesta, Set<Marcador> opciones) {
        super(nombre, precioApuesta);
        this.opciones = new HashSet<>(opciones);
    }

    @Override
    protected boolean esMarcadorAceptable(Marcador marcador) {
        return opciones.contains(marcador);
    }

    public int getNumeroApuestasPorMarcador(Marcador marcador) {
        int count = 0;
        for (Marcador m : mapaApuestas.values()) {
            if (m.equals(marcador)) {
                count++;
            }
        }
        return count;
    }
    
    //PROGRAMAR HACIA LA INTERFAZ
    // public Set<Marcador> getOpciones() {
    // 		return Collections.unmodifiableSet(opciones);
    //		}
}
