package subastaConHerencia;

public class SubastaMinima extends Subasta {
	
	private double cantidadMinima;
	
	public SubastaMinima(String nombreProducto, String propietario, double cantidadMinima) {
		super(nombreProducto, propietario);
		this.cantidadMinima = cantidadMinima;
	}
	
	public double getCantidadMinima() {
		return cantidadMinima;
	}
	
	@Override
	public boolean ejecutar() {
		if (getPujaMayor() < cantidadMinima) {
			return false;
		}
		return super.ejecutar();
	}
	
	public void cerrar() {
		if (isAbierta()) {
		super.cerrar();
		}
	}
	
}
