package biblioteca;

public class PruebaBiblioteca {

	public static void main(String[] args) {
		// Creamos libros
		Libro libro1, libro2;
		libro1= new Libro("Cien años de Soledad", "Gabriel Garcia Marquez");
		libro2= new Libro("Don Quijote de la Mancha", "Miguel de Cervantes");
		
		// Creamos usuarios
		Usuario usuario1, usuario2;
		usuario1 = new Usuario("Juan Perez", 123);
		usuario2 = new Usuario("Pedro Porro", 532);
		

	usuario1.prestarLibro(libro1);
	usuario1.prestarLibro(libro2);

	
	System.out.println("Libros prestados a " + usuario1.getNombre() + ":" + usuario1.obtenerLibrosPrestados());
	
	usuario1.devolverLibro(libro1);
	usuario2.prestarLibro(libro1);
	
	System.out.println("Libros prestados a " + usuario1.getNombre() + ":" + usuario1.obtenerLibrosPrestados());
	System.out.println("Libros prestados a " + usuario2.getNombre() + ":" + usuario2.obtenerLibrosPrestados());
	}
	
}
