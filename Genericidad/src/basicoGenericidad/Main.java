package basicoGenericidad;

public class Main {
	
	public static void main(String[] args) {
		
		GestorElementos<Integer> enteros = new GestorElementos<>();
		
		System.out.println("El tamaño de la lista de 'enteros' es: " + enteros.obtenerTamano());
		
		enteros.agregarElemento(10);
		enteros.agregarElemento(32);
		enteros.agregarElemento(54);
		enteros.agregarElemento(25);
		
		System.out.println("El nuevo tamaño de la lista de 'enteros' es: " + enteros.obtenerTamano());
		
		System.out.println("Lista entera");
		enteros.mostrarElementosListaLinea();
		
		enteros.eliminarElementoIndice(1);
		
		System.out.println("Lista tras eliminar el 1º elemento");
		enteros.mostrarElementosListaParrafo();
		
		System.out.println("El 2º elemento de la lista 'enteros' es: " + enteros.obtenerElementoIndice(2));
		
		/////////////////////////////////LO MISMO CON STRING//////////////////////////////////////////
		
		GestorElementos<String> cadenas = new GestorElementos<>();
		
		System.out.println("El tamaño de la cadena de 'cadenas' es: " + cadenas.obtenerTamano());
		
		cadenas.agregarElemento("hola");
		cadenas.agregarElemento("casa");
		cadenas.agregarElemento("Pepe");
		cadenas.agregarElemento("gato");
		
		System.out.println("El nuevo tamaño de la lista de 'cadena' es: " + cadenas.obtenerTamano());
		
		System.out.println("Lista cadenas");
		cadenas.mostrarElementosListaLinea();
		
		cadenas.eliminarElementoIndice(1);
		
		System.out.println("Lista tras eliminar el 1º elemento");
		cadenas.mostrarElementosListaParrafo();
		
		System.out.println("El 2º elemento de la lista 'cadenas' es: " + cadenas.obtenerElementoIndice(2));
		
	}

}
