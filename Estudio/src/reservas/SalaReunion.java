package reservas;
import java.time.LocalDate;
import java.util.ArrayList;
import java.util.UUID;

public class SalaReunion {
	
	private final String nombre;
	private String identificador;
	private int capacidad;
	private ArrayList<Reserva> listaReservas;
	//private int numReservas -> CALCULABLE
	
	public SalaReunion(String nombre, int capacidad) {
		this.nombre = nombre;
		this.identificador = UUID.randomUUID().toString();
		this.capacidad = capacidad;
		this.listaReservas = new ArrayList<>();
	}
	
	public SalaReunion(String nombre) {
		this(nombre, 30);
	}

	public String getNombre() {
		return nombre;
	}
	
	public String getIdentificador() {
		return identificador;
	}
	
	public int getCapacidad() {
		return capacidad;
	}
	
	public void getListaReservas() {
		for (Reserva reserva : listaReservas) {
			System.out.println(reserva);
		}
	}
	
	public int getNumReservas() {
		return listaReservas.size();
	}
	
	public boolean reservar(LocalDate fecha, String tipo) {
		for (Reserva reserva : listaReservas) {					//Si en la lista de reservas
			if  (reserva.getFechaReserva().equals(fecha)) {		//Ya esta la fecha recibida por parametro
				return false;									//No se puede reservar
			}
		}														//Si no esta
			Reserva reserva1 = new Reserva(LocalDate.now(), nombre, tipo);	//creo la reserva
			listaReservas.add(reserva1);										//y la añado a lista
			return true;
	}
	
	public boolean reservar(LocalDate fecha) {
		return reservar(fecha, "conferencias");
	}
	
	public boolean cancelar(LocalDate fecha) {
		for (Reserva reserva : listaReservas) {
			if (reserva.getFechaReserva().equals(fecha)) {
				listaReservas.remove(reserva);
				return true;
			}
		}
		return false;
	}
	
	  @Override
	    public String toString() {
	        return "SalaReunion{" +
	                "Nombre Sala: " + nombre + 
	                ", identificadorSala: " + identificador + 
	                ", capacidad: " + capacidad +
	                "}";
	    }
}
