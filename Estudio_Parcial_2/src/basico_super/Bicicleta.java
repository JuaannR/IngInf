package basico_super;

public class Bicicleta extends Vehiculo {
	private boolean tieneManchas;
	
	public Bicicleta(String marca, String modelo, int anyo, boolean tieneManchas) {
		super(marca, modelo, anyo);
		this.tieneManchas = tieneManchas;
	}
	
	@Override
	public String tipoVehiculo() {
		return super.tipoVehiculo() + "Bicicleta";
	}
	
	@Override
	public void mostrarInformacion() {
		super.mostrarInformacion();
		System.out.println("Tiene manchas: " + tieneManchas);
	}
}
