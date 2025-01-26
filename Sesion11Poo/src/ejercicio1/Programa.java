package ejercicio1;

import java.util.HashMap;
import java.util.LinkedList;
import java.util.Random;

public class Programa {
	public static void main(String[] args) {
		
		//Ejercicio 1
		Random random = new Random();
		
		LinkedList<Integer> numeros = new LinkedList<Integer>();
		
		for(int i = 0; i<20; i++) {
			numeros.add(random.nextInt(100));
		}
		
		//Muestra por la consola la representación en hexadecimal de los números de la lista.
		numeros.stream().map(n -> Integer.toHexString(n)).forEach(h -> System.out.println(h));
		//numeros.stream().map(Integer::toHexString).forEach(System.out::println);		// ej3
		
		
		
		//Igual que el anterior, pero mostrando las cadenas hexadecimales ordenadas
		//alfabéticamente.
		
		numeros.stream().map(n -> Integer.toHexString(n)).sorted().forEach(h -> System.out.print(h));
		//numeros.stream().map(Integer::toHexString).sorted().forEach(System.out::println);  //ej 3
		
		
		
		// Muestra por la consola la cantidad de números que son pares.
		
		long numPares = numeros.stream().filter(n -> n%2 == 0).count();
		System.out.println("\nNúmeros pares = " + numPares);
		
		//Construye un mapa que asocie cada número de la lista con su representación
		//hexadecimal.
		
		HashMap<Integer, String> mapa = new HashMap<Integer, String>();
		numeros.stream().forEach(n -> mapa.put(n,  Integer.toHexString(n)));
		System.out.println(mapa);
		
		//Consulta si hay algún número en el rango de valores 55 – 60. Muestra el resultado
		//por la consola
		
		boolean existe = numeros.stream().anyMatch(n -> n >= 55 && n <= 60);
		System.out.println("Existe un número entre [55, 60]? " + existe);
	}
}
