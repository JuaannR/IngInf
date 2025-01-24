package basico_super;

public class Coche extends Vehiculo{
	private int numPuertas;
	
	public Coche(String marca, String modelo, int anyo, int numPuertas) {
		super(marca, modelo, anyo);
		this.numPuertas = numPuertas;
	}
	
	@Override
	public String tipoVehiculo() {
		return super.tipoVehiculo() + "Coche";
	}
	
	@Override
	public void mostrarInformacion() {
		super.mostrarInformacion();
		 System.out.println("Número de puertas: " + numPuertas);
	}
}
