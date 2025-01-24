package basico_super;

public class Main {
	
	public static void main(String[] args) {
		Vehiculo vehiculo = new Vehiculo("Peogeot", "406", 5);
		Coche coche = new Coche("Ibiza", "Seat 103", 8, 4);
		Bicicleta bicicleta = new Bicicleta("Bicix", "Mountain", 1, false);
		
		vehiculo.mostrarInformacion();
		coche.mostrarInformacion();
		bicicleta.mostrarInformacion();
		
	}
	
}
