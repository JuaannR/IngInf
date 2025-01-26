package fabrica;
import java.util.ArrayList;

public class Flota {

	private ArrayList<Vehiculo> vehiculostotales;

	//Creamos el Array List
	public Flota() {
		this.vehiculostotales = new ArrayList<>();		
	}
	
	//Método para añadir un Vehiculo al Array List
	public void agregaVehiculo(Vehiculo vehiculo) {
		vehiculostotales.add(vehiculo);
	}

	//Con esta funcion imprimimos todos los vehiculos, con todas sus caracteristicas,
	//que esten en el array list. El bucle for recorre, para elementos de tipo 
	//Vehiculo, le da el nombre temporal vehiculo, y recorre el array list objeto a objeto
	//Para cada objeto en cada iteracion, dentro del print, se hace una llamada al método
	//to string para mostrar en pantalla cada vehiculo con sus caracteristicas
	
	public void mostrarFlota() {
		for (Vehiculo vehiculo : vehiculostotales) {
			System.out.println(vehiculo.toString());
		}
	}

	
	//Aqui hacemos lo mismo, el for recorre objetos de tipo Vehiculo, dando el nombre temporal de vehiculo, por todo el array list
	// vehiculos totales. Para cada vehiculo, accedemos a su consumo, llamando a la funcion calcularConsumo, y vamos 
	//sumando esos consumos en una varible consumoTotal, definida en este mismo metodo
	
	public double calcularConsumoTotal(double km) {
		double consumoTotal=0;
		for (Vehiculo vehiculo : vehiculostotales) {
			consumoTotal = consumoTotal + vehiculo.calcularConsumo(km);
		}
		return consumoTotal;
	}




}
