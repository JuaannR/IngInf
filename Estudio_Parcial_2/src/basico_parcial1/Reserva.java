package basico_parcial1;
import java.time.LocalDate;
import java.util.UUID;
import java.util.ArrayList;



public class Reserva {
	
	private final String usuario;
	private final String codigoReserva;
	private final LocalDate fechaCreacion;
	private LocalDate fechaLimite;
	private boolean activa;
	private ArrayList<Libro> listaLibros;
	
	public Reserva(String usuario, LocalDate fechaLimite) {
		this.usuario = usuario;
		this.codigoReserva = UUID.randomUUID().toString();
		this.fechaCreacion = LocalDate.now();
		this.fechaLimite = fechaLimite;
		this.activa = true;
		this.listaLibros = new ArrayList<>();
	}
	
	public Reserva(String usuario) {
		this(usuario, LocalDate.now().plusWeeks(2));
	}
	
	public String getUsuario() {
		return usuario;
	}
	
	public String getCodigoReserva() {
		return codigoReserva;
	}
	
	public LocalDate getFechaCreacion() {
		return fechaCreacion;
	}
	
	public LocalDate getFechaLimite() {
		return fechaLimite;
	}
	
	//Copia defensiva del array list
	public ArrayList<Libro> getListaLibrosCopia() {
		return new ArrayList<Libro>(listaLibros);
	}
	
	//Utilizando el toString() seria con void. Se puede omitir el toString() en el print
	public void getListaLibrosString() {
		for (Libro libro : listaLibros) {
			System.out.println(libro.toString());
		}
	}
	
	public boolean isActiva() {
		return activa;
	}
	
	public void agregarLibro(Libro libro) {
		if (isActiva() == true && fechaCreacion.isBefore(fechaLimite)) {
			listaLibros.add(libro);
		}
	}
	
	public void cancelar() {
		if (isActiva()) {
			activa = false;
			listaLibros.clear();
		}
	}
	
	public String toString() {
		return "Reserva: {Usuario: " + usuario + 
				" Codigo reserva: " + codigoReserva + 
				" Fecha Creacion: " + fechaCreacion + 
				" Fecha Limite: " + fechaLimite + 
				" Activa: " + activa + 
				" Lista Libros: " + listaLibros +
				"}";
	}
}
