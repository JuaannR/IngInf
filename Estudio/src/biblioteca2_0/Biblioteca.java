package biblioteca2_0;
import java.util.ArrayList;

public class Biblioteca {
	
	private ArrayList<Libro> coleccionLibros;
	
	public Biblioteca() {
		this.coleccionLibros = new ArrayList<>();
	}
	
	public void agregarLibro(Libro libro) {
		coleccionLibros.add(libro);
	}
	
	public void mostrarLibros() {
		for (Libro libro : coleccionLibros) {
			System.out.println(libro.toString());
		}	
	}
	
	public int contarLibrosAntiguos() {
		int total=0;
		for (Libro libro : coleccionLibros) {
			if (libro.esAntiguo() == true) {
				total++;
			}
		}
		return total;
	}
	
	public int cuentaPaginas() {
		int pags=0;
		for (Libro libro : coleccionLibros) {
			pags += libro.getNumPaginas();
		}
		return pags;
	}
	
}
