package biblioteca;

public class Libro {

	private String titulo;
	private String autor;
	private boolean prestado;
	
	public Libro(String titulo, String autor) {
		this.titulo=titulo;
		this.autor=autor;
		this.prestado=false;
	}
	
	
	public void prestar() {
		if (prestado==false) {
			prestado=true;
		}
	}
	
	public void devolver() {
		if (prestado==true) {
			prestado=false;
		}
	}
	
	public boolean isPrestado() {
		return prestado;
	}
	
	public String getTitulo() {
		return titulo;
	}
	
	public String getAutor() {
		return autor;
	}
}
