package fabrica;

public class Vehiculo {
	private String matricula;
	private String marca;
	private double consumoPorKm;
	
	public Vehiculo(String matricula, String marca, double consumoPorKm) {
		this.matricula = matricula;
		this.marca = marca;
		this.consumoPorKm = consumoPorKm;
	}

	public double calcularConsumo(double km) {
		return consumoPorKm * km;
		
	}
	
	@Override	//Indica al compilador que estamos sobreescribiendo o reemplazando
				// un método heredado de la clase padre. No es obligatorio 
				//pero facilita una posible deteccion de errores y da legibilidad
	
	public String toString() {
		return "Vehículo{" +
				"matricula = " + matricula +
				", marca = " + marca +
				", consumoPorKm = " + consumoPorKm +
		"}";
	}
	
	//Con esta funcion, luego podremos imprimir en un array list creado en la clase flota
	//un vehiculo con todos sus atributos, a diferencia del ejemplo de array list
	// de biblioteca, que solo imprimiamos el nombre del libro
	
	
	
	public String getMatricula() {
		return matricula;
	}
	
	public String getMarca() {
		return marca;
	}
	
	public double getConsumoPorKm() {
		return consumoPorKm;
	}
}
