package junio24;

import java.time.LocalDate;
import java.time.format.DateTimeParseException;
import java.util.Collection;
import java.util.Collections;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.List;
import java.util.Scanner;
import java.util.function.Function;

public class Util {
	// ¿STATIC PARA PODER USAR EN EL MAIN? SI NO SE PONE ECLIPSE LO RECUERDA
	public static Collection<Vino> registrarVino() {
		List<Vino> vinosAnadidos = new LinkedList<Vino>();
		
		Scanner scanner = new Scanner(System.in);
		boolean seguir = true;
		
		do {
			System.out.println("Introcude el nombre del vino: ");
			String nombre = scanner.nextLine();
			System.out.println("Introduce la fecha de producción del vino (YYYY-MM-DD): ");
			String fecha = scanner.nextLine();
			
			//SI NO QUEREMOS USAR EL CONSTRUCTOR POR DEFECTO, HABRÍA QUE PEDIR MÁS DATOS
			try {
				LocalDate date = LocalDate.parse(fecha);
				vinosAnadidos.add(new Vino(date, nombre));
				System.out.printf("Se ha creado el vino %s\n", nombre);
			} catch (DateTimeParseException e) {
				System.out.println("Fecha no valida. El formato es YYYY-MM-DD");
			}
			
			System.out.println("¿Quiere agregar otro vino más? (S/N)");
			String respuesta = scanner.nextLine();
			
			if (respuesta.equals("N")) {
				seguir = false;
			}
			
		} while (seguir);
		
		scanner.close();
		
		return Collections.unmodifiableList(vinosAnadidos);
	}
		
		// EJ 6
		
	public static <V> void buscarReemplazar(Collection<V> coleccion, V dato, Function<V, V> funcion) {
	    List<V> nuevaColeccion = new LinkedList<V>();  //LISTA DE DATOS GENERICOS T
	    V datoCambiado = funcion.apply(dato); 		   // APLICAMOS LA FUNCION AL DATO QUE QUEREMOS (PASADO COMO PARAMETRO)
	    
	    Iterator<V> iterador = coleccion.iterator();   // DECLARAMOS ITERADOR PARA RECORRER LA COLECCION PASADA COMO PARAMETRO
	    while(iterador.hasNext()) {				//MIENTRAS HAYA ELEMENTO SIGUIENTE
	        V elem = iterador.next();			// AVANZAMOS
	        
	        if (elem.equals(dato)) {			// SI EL ELEMENTO DE LA LISTA ES IGUAL AL DATO PASADO COMO PARAMETRO
	            nuevaColeccion.add(datoCambiado); //AÑADO EL DATO CAMBIADO (RESULTADO DE LA FUNCION)
	        } else {								//SINO
	            nuevaColeccion.add(elem); 			// AÑADO DEL DATO IGUAL
	        }
	    }
	    
	    coleccion.clear(); 							//BORRO COLECCION PASADA COMO PARAMETRO
	    coleccion.addAll(nuevaColeccion); 			// Y AÑADO LA NUEVA, PARA QUSE VEA EL CAMBIO YA QUE ESTO ES UN VOID
	}

	}
	

