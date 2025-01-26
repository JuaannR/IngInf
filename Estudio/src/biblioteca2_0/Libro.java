package biblioteca2_0;
import java.time.LocalDate;

public class Libro {

	private String titulo;
	private String autor;
	private LocalDate fechaPublicacion;
	private int numPaginas;
	
	public Libro(String titulo, String autor, LocalDate fechaPublicacion, int numPaginas) {
		this.titulo = titulo;
		this.autor = autor;
		this.fechaPublicacion = fechaPublicacion;
		this.numPaginas = numPaginas;
	}
	
	@Override
	public String toString() {
		return "Libro -> " +
			"Titulo: " + titulo +
			", Autor: " + autor +
			", Fecha publicacion: " + fechaPublicacion +
			", Paginas: " + numPaginas;
		}
			
	public boolean esAntiguo() {
		return fechaPublicacion.isBefore(LocalDate.now().minusYears(20)); 
	}
	
	public String getTitulo() {
		return titulo;
	}
	
	public String getAutor() {
		return autor;
	}

	public LocalDate getFechaPublicacion() {
		return fechaPublicacion;
	}

	public int getNumPaginas() {
		return numPaginas;
	}
}