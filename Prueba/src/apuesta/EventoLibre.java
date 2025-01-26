package apuesta;

public class EventoLibre extends Evento {

    public EventoLibre(String nombre, double precioApuesta) {
        super(nombre, precioApuesta);
    }

    @Override
    protected boolean esMarcadorAceptable(Marcador marcador) {
        return !mapaApuestas.containsValue(marcador);
    }
}
