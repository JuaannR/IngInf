package basico_super;

public class Vehiculo {
	
	private String marca;
	private String modelo;
	private int anyo;
	
	public Vehiculo(String marca, String modelo, int anyo) {
		this.marca = marca;
		this.modelo = modelo;
		this.anyo = anyo;
	}
	
	public void mostrarInformacion() {
		System.out.println("Marca: " + marca);
        System.out.println("Modelo: " + modelo);
        System.out.println("Año: " + anyo);
        System.out.println("Tipo: " + tipoVehiculo()); 
    
	}
	
	public String tipoVehiculo() {
		return "Vehiculo generico ";
	}
	
}
