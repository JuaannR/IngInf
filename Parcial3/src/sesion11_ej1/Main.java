package sesion11_ej1;

import java.util.HashMap;
import java.util.LinkedList;
import java.util.Random;

public class Main {
	
	public static void main(String[] args) {
		
	LinkedList<Integer> numeros = new LinkedList<>();
	
	Random random = new Random();
	
	for(int i = 0; i<15; i++) {
		numeros.add(random.nextInt(100));
	}
	
	// MOSTAR LISTA DE ENTEROS EN PANTALLA
	System.out.println("Lista de números aleatorios:");
	numeros.stream().forEach(n -> System.out.println(n));
		
	// PASAR LISTA A HEXADECIMAL
	System.out.println("Lista de números en hexadecimal:");
	numeros.stream().map(n -> Integer.toHexString(n)).forEach(n -> System.out.println(n));
	
	// ORDENADO ALFABÉTICAMENTE
	System.out.println("Lista números hexadecimal ordenados alfabéticamente");
	numeros.stream().map(n -> Integer.toHexString(n)).sorted().forEach(n -> System.out.println(n));
	
	// CONTAR PARES
	System.out.println("Conteo números pares");
	long numPares = numeros.stream().filter(n -> n%2 == 0).count();
	System.out.println("Hay " + numPares + " números pares en la lista");
	
	//MAPA CON PAR <NUMERO ENTERO, CADENA VALOR HEXADECIMAL>
	HashMap<Integer, String> mapa = new HashMap<>();
	numeros.stream().forEach(n->mapa.put(n, Integer.toHexString(n)));
	System.out.println("El mapa creado es: ");
	System.out.println(mapa);
	
	// ENTEROS ENTRE 55 Y 60
	System.out.println("Números entre 55 y 60: ");
	numeros.stream().filter(n -> n >= 55 && n <= 60).forEach(n -> System.out.println(n));
	
	boolean existe = numeros.stream().anyMatch(n -> n >= 55 && n <= 60);
	System.out.println("Exiten números entre [55-60] ?: " + existe);
	}
	
}
