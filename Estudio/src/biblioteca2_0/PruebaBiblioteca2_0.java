package biblioteca2_0;

import java.time.LocalDate;

public class PruebaBiblioteca2_0 {

	public static void main(String[] args) {
		
		Libro l1 = new Libro("El Sótano", "Natasha Prestón", LocalDate.of(2020, 5, 22), 570);
		Libro l2 = new Libro("La Noche de Halloween", "Stephen King", LocalDate.of(1987, 10, 31), 1250);
		Libro l3 = new Libro("El Grinch", "Amador Robles", LocalDate.of(2022, 8, 12), 298);
	
		Biblioteca biblioteca1 = new Biblioteca();
		
		biblioteca1.agregarLibro(l1);
		biblioteca1.agregarLibro(l2);
		biblioteca1.agregarLibro(l3);
		
		biblioteca1.mostrarLibros();
	
		System.out.println("Hay " + biblioteca1.contarLibrosAntiguos() + " libros con más de 20 años de antigüedad" );
	
		System.out.println("Entre los libros de la lista, hay " + biblioteca1.cuentaPaginas() + " páginas");
	}
}
