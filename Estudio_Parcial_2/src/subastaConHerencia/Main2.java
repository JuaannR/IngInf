package subastaConHerencia;
import java.util.Collections;
import java.util.LinkedList;

public class Main2 {
	
	public static void main(String[] args) {
		
		String usuario1 = "Juan";
		String usuario2 = "Enrique";
		
		SubastaLimitada limitada = new SubastaLimitada("Disco duro multimedia", usuario1, 1);
		SubastaTemporal temporal = new SubastaTemporal("Teclado", usuario1, 3);
		SubastaMinima minima = new SubastaMinima("Impresora", usuario1, 100);
		
		//Vamos a utilizar una LinkedList
		/* Estructura de datos enlazada, donde los elementos se guardan en un nodo,
		   que contendrá, el elemento y un puntero al siguiente nodo (siguiente elemento de la lista)
		 */
		
		//1º lo declaramos, creando un LinkedList vacio
		LinkedList<Subasta> listaSubastas = new LinkedList<Subasta>();
		
		//1- Agregar todo de golpe: //	Collections.addAll(nombreLista, elemenos a añadir separados por comas)
		Collections.addAll(listaSubastas, limitada, temporal, minima);
		
		//2- Agregar 1 por uno como si de un ArrayList se tratase
		/* listaSubastas.add(limitada);
		   listaSubastas.add(temporal);
		   listaSubastas.add(minima);
		 */
		
		for (Subasta subasta : listaSubastas) {
			System.out.println("Nombre producto: " + subasta.getNombreProducto());
			System.out.println("Enrique ha pujado los 10 euros?: " + subasta.pujar(usuario2, 10));
			System.out.println("Enrique ha pujado los 20 euros?: " + subasta.pujar(usuario2, 20));
			
			//instanceof me permite aplicar metodos sobre una sola subclase 
			if (subasta instanceof SubastaLimitada) {
				SubastaLimitada subastaLimitada = (SubastaLimitada) subasta;	//Convierto de Subasta a SubastaLimitada
				System.out.println("Número de pujas pendientes: " + subastaLimitada.getPujasPendientes());	
				//Aplico el metodo concreto de SubastaLimitada
			}
			
			if (subasta.isAbierta()) {
				boolean ejecutado = subasta.ejecutar();
				
				if (ejecutado) {
					System.out.println("Ejecutado");
				} else {
					System.out.println("No se puede ejecutar");
				}
			}
			
		}
		
		
	}
	
	
	
}
