package basico_parcial1;

import java.time.LocalDate;

public class Main {
	
	public static void main(String[] args) {
	
	Reserva reserva1 = new Reserva("maria@um.es");
	Reserva reserva2 = new Reserva("pedro@um.es", LocalDate.now().plusDays(5));
	
	Libro libro1 = new Libro("El Quijote", "Miguel de Cervantes", "978-3-16-148410-0");
    Libro libro2 = new Libro("1984", "George Orwell", "978-0-452-28423-4");
    Libro libro3 = new Libro("El Principito", "Antoine de Saint-Exupéry", "978-0-15-601219-5");
    
	reserva1.agregarLibro(libro1);
	reserva2.agregarLibro(libro3);
	reserva1.agregarLibro(libro2);
	
	System.out.println(reserva1.toString());
	System.out.println(reserva2.toString());
	
	reserva1.cancelar();
	reserva1.agregarLibro(libro1);
	System.out.println(reserva1.toString());
	}
}
