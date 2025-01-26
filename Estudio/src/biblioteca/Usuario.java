package biblioteca;
import java.util.ArrayList; //se debe importar para utilizar ArrayList

public class Usuario {

	private String nombre;
	private int idUsuario;
	private ArrayList<Libro> librosPrestados;	//creamos un array list vacio
	//Un ArrayList es como un array normal pero con la diferencia de que no tiene un tamaño predefinido, sino
	//que puede incrementarse si añades un objeto de tipo libro y puede reducirse si eliminas un objeto tipo libro
	//DEBE IMPORTARSE
	
	public Usuario(String nombre, int idUsuario ) {
		this.nombre=nombre;
		this.idUsuario=idUsuario;
		this.librosPrestados=new ArrayList<>();
	}
	
	public void prestarLibro(Libro libro) {
		if (libro.isPrestado()==false) {
			librosPrestados.add(libro);
			libro.prestar();
		}
	}
	
	public void devolverLibro(Libro libro) {
		if (libro.isPrestado()==true) {
			librosPrestados.remove(libro);
			libro.devolver();
		}
	}
	
	public ArrayList<String> obtenerLibrosPrestados() {
		ArrayList<String> titulos = new ArrayList<>();
		for (Libro libro : librosPrestados) {
			titulos.add(libro.getTitulo());
			}
		return titulos;
	}
	
	public String getNombre() {
		return nombre;
	}
	
	public int getIdUsuario() {
		return idUsuario;
	}
}
