package viaje_toString_equals_clone;
import java.time.LocalDate;

public class Reserva {
	private final String usuario;
	private final int numPlazas;
	private LocalDate fechaRealizaReserva;
	private final String codigoViaje;
	
	public Reserva(String usuario, int numPlazas, String codigoViaje) {
		this.usuario = usuario;
		this.numPlazas = numPlazas;
		this.fechaRealizaReserva = LocalDate.now();
		this.codigoViaje = codigoViaje;
	}
	
	public String getUsuario() {
		return usuario;
	}
	
	public int getNumPlazas() {
		return numPlazas;
	}
	
	public LocalDate getFechaRealizaReserva() {
		return fechaRealizaReserva;
	}
	
	public String getCodigoViaje() {
		return codigoViaje;
	}
	
	@Override
	public String toString() {
		return "Reserva: {Usuario: " + usuario +
				", Numero de plazas: " + numPlazas +
				", Fecha de realizacion de la reserva: " + fechaRealizaReserva +
				", Codigo del viaje: " + codigoViaje + "}";
	}
}
