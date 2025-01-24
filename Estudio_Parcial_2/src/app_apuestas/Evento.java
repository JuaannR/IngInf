package app_apuestas;
import java.util.HashMap;

public abstract class Evento {
	private static final int NUM_APUESTAS_INICIALES = 0;
	
	private String nombre;
	private double precioApuesta;
	private HashMap<String, Marcador> mapaApuestas;
	private int numApuestas;
	// recaudacion -> calculable
	
	public Evento(String nombre, double precioApuesta){
		this.nombre = nombre;
		this.precioApuesta = precioApuesta;
		this.mapaApuestas = new HashMap<>();
		this.numApuestas = NUM_APUESTAS_INICIALES;
	}
	
	public String getNombre() {
		return nombre;
	}
	
	public double getPrecioApuesta() {
		return precioApuesta;
	}
	
	public HashMap<String, Marcador> getMapaApuestas() {
		return mapaApuestas;
	}
	
	public int getNumApuestas() {
		return numApuestas;
	}
	
	public double getRecaudacion() {
		return precioApuesta * numApuestas;
	}
	

	public boolean apostar(String usuario, Marcador marcador) {
		if (marcadorAceptable(marcador)) {
			mapaApuestas.put(usuario, marcador);
			numApuestas++;
			return true;
		} else {
			return false;
		}
	}
	
	//Metodo plantilla
	protected abstract boolean marcadorAceptable(Marcador marcador);
	
}
