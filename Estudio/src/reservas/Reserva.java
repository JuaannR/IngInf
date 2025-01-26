package reservas;
import java.time.LocalDate;
import java.util.UUID;

public class Reserva {
	private String codigoReserva;
	private LocalDate fechaReserva;
	private String sala;
	private String tipoReserva;
	
	public Reserva(LocalDate fechaReserva, String sala, String tipoReserva) {
		this.codigoReserva = UUID.randomUUID().toString();
		this.fechaReserva = fechaReserva;
		this.sala = sala;
		this.tipoReserva = tipoReserva;
	}
	
	public String getCodigoReserva() {
		return codigoReserva;
	}
	public LocalDate getFechaReserva() {
		return fechaReserva;
	}
	public String getSala() {
		return sala;
	}
	
	public String getTipoReserva() {
		return tipoReserva;
	}
	@Override
	public String toString() {
		return "Reserva: {" +
		"Codigo: " + codigoReserva +
		", Fecha: " + fechaReserva +
		", Sala: " + sala +
		", Tipo: " + tipoReserva +
		"}";
	}
}
