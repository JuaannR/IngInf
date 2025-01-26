package junio24;

import java.time.LocalDate;
import java.util.ArrayList;
import java.util.Collection;
import java.util.Collections;
import java.util.Comparator;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.List;
import java.util.Set;
import java.util.function.Function;


public class Programa {
	
	public static void main(String[] args) {
	
	// VINOS EXIGIDOS POR EL EXAMEN (DATOS CAMBIDOS PARA QUE SEAN VALIDOS)
	Vino vino1 = new Vino(LocalDate.of(2020,6, 1), "Marqués", Color.ROSADO, Maduracion.GRAN_RESERVA, 15);
	Vino vino2 = new Vino(LocalDate.of(2015,10, 1), "Constantino", Color.TINTO, Maduracion.GRAN_RESERVA, 30);
	Vino vino3 = new Vino(LocalDate.of(2022,9, 1), "El Purísimo", Color.ROSADO, Maduracion.RESERVA, 5);
	Vino vino4 = new Vino(LocalDate.of(2024,10, 1), "Don Pimpón");
	Vino vino5 = new Vino(LocalDate.of(2024,11, 1), "Gil y Gil");
	
	//EJEMPLO VINOS EXTRA 
	Vino vino6 = new Vino(LocalDate.of(2020,6, 1), "Don Quijote", Color.ROSADO, Maduracion.CRIANZA, 15);
	Vino vino7 = new Vino(LocalDate.of(2020,12, 1), "Nuevo", Color.ROSADO, Maduracion.JOVEN, 30);
	
	Set<Vino> listaVinos = new HashSet<Vino>();
	Collections.addAll(listaVinos, vino1, vino2, vino3, vino4, vino5, vino6, vino7);
	
	Set<Vino> listaVinosValidos = new HashSet<Vino>();
	
	for (Vino vino : listaVinos) {
		try {
			vino.validaVino(vino);
			listaVinosValidos.add(vino);
		} catch (IllegalArgumentException e) {
			System.out.println("Error en el vino: " + vino.getNombre());
			System.out.println(e.getMessage());
		}
	}
	
	System.out.println("Colección de vinos validos: ");
	System.out.println(listaVinosValidos);
	
	//STREAMS
	System.out.println("Vinos validos rosados: ");
	listaVinosValidos.stream()
	.filter(v -> v.getColor() == Color.ROSADO)
	.map(v -> v.getNombre())
	.forEach(n -> System.out.println(n));
	
	
	long cuenta = listaVinosValidos.stream()
	.filter(v -> v.getFechaProduccion().isBefore(LocalDate.of(2021, 1, 1)))
	.count();
	System.out.println("Cuenta de vinos validos producidos antes de 2021: " + cuenta);
	
	System.out.println("Lista de vinos con un coste mayor a 5€ ordenados alfabeticamente: ");
	List<Vino> listaMasCinco = new ArrayList<Vino>();
	listaVinosValidos.stream()
	.filter(v -> v.getCoste() > 5)
	.sorted(Comparator.comparing(Vino::getNombre))
	.forEach(v -> listaMasCinco.add(v));
	System.out.println(listaMasCinco);
	
	
	//REGISTRAR POR TECLADO
	Collection<Vino> listaRegistrar = Util.registrarVino();
	listaRegistrar.stream()
	.forEach(v -> System.out.println(v.toString()));
	
	//GENÉRICO
	Function<Integer, Integer> cuadradoNumero = n -> n*n;	//FUNCION A USAR (CUADRADO)
	List<Integer> numeros= new LinkedList<Integer>();		//LISTA DE ENTEROS
	Collections.addAll(numeros, 4, 5, 7, 9, 4, 4);			//SE AÑADE EL EJEMPLO DEL EXAMEN
	
	Util.buscarReemplazar(numeros, 4, cuadradoNumero);		//SE APLICA EL METODO DE LA CLASE UTIL 
	System.out.println(numeros);							//SE IMPRIME LA LISTA
	
	
	}
}
