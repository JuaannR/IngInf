package viaje_toString_equals_clone;
import java.time.LocalDate;

public class Main3 {
	
	public static void main(String[] args) {
	// Probar equals y clone
	System.out.println("\n=== Probando clone y equals ===");

	// Crear un viaje selectivo original
	ViajeSelectivo original = new ViajeSelectivo("María", "Toyota Yaris", "Madrid-Valencia", LocalDate.of(2024, 12, 20), 4);
	original.agregarVetado("Juan");

	// Clonar el viaje
	ViajeSelectivo copia = original.clone();

	// Mostrar original y copia
	System.out.println("Original: " + original);
	System.out.println("Copia: " + copia);

	// Comprobar si son iguales (deberían serlo porque tienen los mismos valores)
	System.out.println("¿Original y copia son iguales? " + original.equals(copia));

	// Modificar la copia (añadir un vetado)
	copia.agregarVetado("Lucía");

	// Mostrar los objetos tras la modificación
	System.out.println("\nTras modificar la copia:");
	System.out.println("Original: " + original);
	System.out.println("Copia: " + copia);

	// Comprobar si son iguales ahora (deberían ser diferentes porque cambiaron los valores)
	System.out.println("¿Original y copia son iguales? " + original.equals(copia));

	// Comprobar si son el mismo objeto (debería ser falso porque son clones)
	System.out.println("¿Original y copia son el mismo objeto? " + (original == copia));
	}
}
