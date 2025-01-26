package ejercicio2;

import java.time.LocalDate;
import java.util.Collections;
import java.util.Comparator;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.Set;
import java.util.stream.Collectors;

public class Programa {

	public static void main(String[] args) {
		
		LocalDate cuatroNov = LocalDate.of(2024, 11, 4);
		LocalDate onceNov = LocalDate.of(2024, 11, 11);
		LocalDate doceNov = LocalDate.of(2024, 11, 12);
		
		Registro r1 = new Registro("Pedro", onceNov);
		Registro r2 = new Registro("Juan", cuatroNov);
		Registro r3 = new Registro("Martina", doceNov);
		Registro r4 = new Registro("Andrea", cuatroNov);
		Registro r5 = new Registro("Pedro", doceNov);
		
		LinkedList<Registro> registros = new LinkedList<Registro>();
		Collections.addAll(registros, r1, r2, r3, r4, r5);
		
		//Obtener un conjunto con todos los usuarios que han realizado algún acceso desde
		//10/11/2024, no incluido.
	
		//Opcion 1
		HashSet<String> usuarios1 = new HashSet<String>();
		registros.stream().filter(r -> r.fecha().isAfter(LocalDate.of(2024, 11, 10))).map(r -> r.usuario()).forEach(u -> usuarios1.add(u));
		System.out.println(usuarios1);
		
		// registros.stream().filter(r -> r.fecha().isAfter(LocalDate.of(2024, 11, 10))).map(Registro::usuario()).forEach(usuarios1::add);
		
		
		
		//Opcion 2
		Set<String> usuarios2 = registros.stream().filter(r -> r.fecha().isAfter(LocalDate.of(2024, 11, 10))).map(r -> r.usuario()).collect(Collectors.toSet());
		
				System.out.println(usuarios2);
	
		// Set<String> usuarios2 = registros.stream().filter(r -> r.fecha().isAfter(LocalDate.of(2024, 11, 10))).map(Registro::usuario()).collect(Collectors.toSet());
		
		
		//Mostrar el nombre de los usuarios que han accedido el día 12/11/2024 en orden
		//alfabético inverso
		registros.stream().filter(r -> r.fecha().equals(doceNov)).map(r -> r.usuario()).sorted(Comparator.reverseOrder()).forEach(u -> System.out.println(u));
																		//.sorted((u1, u2) -> -u1.compareTo(u2))
		
		//registros.stream().filter(r -> r.fecha().equals(doceNov)).map(Resgistro::usuario()).sorted(Comparator.reverseOrder()).forEach(System.out::println);
		
		
		
		
		//Contar el número de accesos desde el 4/11/2024 y hasta 12/11/2024, ambos
		//incluidos. Mostrar el resultado en la consola.
	
		long numAccesos = registros.stream().filter(r -> !r.fecha().isBefore(cuatroNov) && !r.fecha().isAfter(doceNov)).count();
		System.out.print("Accesos entre el 4 y 12 de noviembre = " + numAccesos);
	
	//Mostrar en la consola los registros comprendidos desde el 4/11/2024 y hasta
		//12/11/2024, ambos incluidos, ordenados por fecha y, a igualdad de fecha, ordenado
		//alfabéticamente por el nombre de los usuarios
	
		registros.stream().filter(r -> !r.fecha().isBefore(cuatroNov) && !r.fecha().isAfter(doceNov)).sorted(Comparator.comparing(Registro::fecha).thenComparing(r -> r.usuario())).forEach(r -> System.out.println(r));

	// Consultar si algún usuario ha realizado un registro el día 4/11/2024. Mostrar el
	//resultado en la consola
	boolean existe = registros.stream().anyMatch(r -> r.fecha().equals(cuatroNov));
	System.out.println("¿Hay registros el 4 de noviembre?" + existe);
	
	
	
	Util.doIf(registros, r -> System.out.println(r), r -> r.fecha().equals(doceNov));
	//Util.doIf(registros, System.out::println, r -> r.fecha().equals(doceNov));
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	}

}
