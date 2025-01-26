package apuesta;

import java.util.HashMap;
import java.util.Map;

public abstract class Evento {
    private final String nombre;
    private final double precioApuesta;
    protected final Map<String, Marcador> mapaApuestas;

    public Evento(String nombre, double precioApuesta) {
        this.nombre = nombre;
        this.precioApuesta = precioApuesta;
        this.mapaApuestas = new HashMap<>();
    }

    public String getNombre() {
        return nombre;
    }

    public double getPrecioApuesta() {
        return precioApuesta;
    }

    public int getNumeroApuestas() {
        return mapaApuestas.size();
    }

    public double getRecaudacion() {
        return getNumeroApuestas() * precioApuesta;
    }
    
    //Visibilidad protected porque es un metodo auxiliar de la plantilla
    protected abstract boolean esMarcadorAceptable(Marcador marcador);

    //Método plantilla
    public boolean apostar(String usuario, Marcador marcador) {
        if (!esMarcadorAceptable(marcador)) {
            return false;
        }
        if (mapaApuestas.containsKey(usuario)) {
            return false; // Un usuario no puede apostar dos veces.
        }
        mapaApuestas.put(usuario, marcador);
        return true;
    }

    @Override
    public String toString() {
        return "Evento: " + nombre +
               ", Precio Apuesta: " + precioApuesta +
               ", Número de Apuestas: " + getNumeroApuestas() +
               ", Recaudación: " + getRecaudacion();
    }
}
