package animal;

public class Main {
	
	public static void main (String[] args) {
		
		Animal animal1 = new Animal("Name", 50);
		animal1.mostrarInfo();		
		animal1.emitirSonido();
		
		Perro perro1 = new Perro("Koko", 5, "Bichón Maltés");
		System.out.println("El animal " + perro1.getNombre() + " tiene " + perro1.getEdad() + " años y es de la raza " + perro1.getRaza());
		perro1.emitirSonido();
		perro1.moverCola();
		
		Gato gato1 = new Gato("Michi", 3, "negro");
		gato1.emitirSonido();
		gato1.muevePata();
		System.out.println("El animal " + gato1.getNombre() + " tiene " + gato1.getEdad() + " años y es de color " + gato1.getColor());
		
		
	}
	
	
}
