package subastas;
import java.util.ArrayList;

public class Subasta {

	//constante para incrementar la puja mayor en 1 euro
	private static final double INCREMENTA_PUJA = 1.0;	
	
	//Atributos
	private final String nombreProducto;
	private final String propietario;
	private boolean abierta;
	private ArrayList<Puja> listaPujas;
	//private double pujaMayor;	//Propiedad calculable
	
	
	public Subasta(String nombreProducto, String propietario ) {
		this.nombreProducto = nombreProducto;
		this.propietario = propietario;
		this.abierta = true;
		this.listaPujas = new ArrayList<>();
	}
	
	public String getNombreProducto() {
		return nombreProducto;
	}
	
	public String getPropietario() {
		return propietario;
	}
	
	public boolean isAbierta() {
		return abierta;
	}
	
	//Copia defensiva del Array List
	public ArrayList<Puja> getPujas() {
		return new ArrayList<Puja>(listaPujas);
	}
		
	//Si el array list de pujas esta vacio no hay pujas. Si no hay pujas, la mayor puja es de 0 
	//Como el array list esta ordenado de menor a mayor, es decir, cada posicion del array contiene una puja más alta, ya que así lo
	//vamos a declarar en el método pujar a continuación, podemos acceder a la última puja con listaPujas.getLast y con getCantidad obtener
	// la cantidad, que será la mayor puja.
	public double getPujaMayor() {
		if (listaPujas.isEmpty()) {		
			return 0;					
		}
		return listaPujas.getLast().getCantidad();
			// en vez de getLast() se puede hacer listaPujas.size() -1 para acceder al ultimo elemento del array
		
	}
	
	/* 
	    public double getPujaMayor() {
	    double max = 0; 
	    if (listaPujas.isEmpty()) {  // Verificamos si la lista está vacía, igual que antes.
	        return max;  			// SE PUEDE SUPRIMIR, YA QUE SI LA LISTA ES VACIA, NO ENTRAMOS AL BUCLE Y DEVOLVEMOS 0
	    }
	    // Recorremos la lista de pujas
	    for (Puja puja : listaPujas) {
	        if (puja.getCantidad() > max) {  // Si encontramos una puja mayor que max
	            max = puja.getCantidad();  // Actualizamos max con esa cantidad
	        }
	    }
	    return max;  // Devolvemos la cantidad máxima encontrada
	}
*/
	
	public boolean pujar(String pujador, double cantidad) {
		if (abierta == false || pujador == propietario || cantidad < getPujaMayor()) {
			return false;
		}
		Puja puja1 = new Puja(pujador, cantidad);
		listaPujas.add(puja1);
		return true;
	}
	
	public boolean pujar(String pujador) {
		double pujaMax = getPujaMayor();
		double newPujaMax = pujaMax + INCREMENTA_PUJA;
		return pujar(pujador, newPujaMax);
	}
	
	public boolean ejecutar() {
		if (abierta == false || listaPujas.size() == 0 ) {
			return false;
		}
		abierta = false;
		return true;
	}
	
	//Añadido para mostrar lista de pujas
	public void mostrarPujas() {
		for (Puja puja : listaPujas) {
			System.out.println(puja.toString());
		}
	}
	
}
