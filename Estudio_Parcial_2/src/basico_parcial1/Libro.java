package basico_parcial1;

public class Libro {
	private final String titulo;
	private final String autor;
	private final String isbn;
	
	public Libro(String titulo, String autor, String isbn) {
		this.titulo = titulo;
		this.autor = autor;
		this.isbn = isbn;
	}
	
	public String getTitulo() {
		return titulo;
	}
	
	public String getAutor() {
		return autor;
	}
	
	public String getIsbn() {
		return isbn;
	}
	
	@Override
	public String toString() {
		return "Libro -> {Titulo:" + titulo + " Autor: " + autor + " ISBN: " + isbn + "}";
	}
}
