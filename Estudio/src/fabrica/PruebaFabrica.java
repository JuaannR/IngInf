package fabrica;

public class PruebaFabrica {

	public static void main(String[] args) {
		
		Flota flota1 = new Flota();	// Array List de Vehículos
		
		Vehiculo v1 = new Vehiculo("3356MKH", "Renault", 0.06);
		Vehiculo v2 = new Vehiculo("2469DJF", "Peugeot", 0.08);
		Vehiculo v3 = new Vehiculo("4590LLM", "Ferrari", 0.03);
		
		flota1.agregaVehiculo(v1);
		flota1.agregaVehiculo(v2);
		flota1.agregaVehiculo(v3);
		
		flota1.mostrarFlota();
		
		
		System.out.println("El consumo total de los vehiculos de la flota 1 es: " + flota1.calcularConsumoTotal(100) + " litros");
		
	}
	
	
	
}
