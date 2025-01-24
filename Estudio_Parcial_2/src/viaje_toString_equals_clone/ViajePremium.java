package viaje_toString_equals_clone;

import java.time.LocalDate;

public class ViajePremium extends Viaje {
	
	
	public ViajePremium(String propietario, String coche, String ruta, LocalDate fechaSalida, int numPlazasOfrecidas) {
		super(propietario, coche, ruta, fechaSalida, numPlazasOfrecidas);
	}
	
	public ViajePremium(String propietario, String coche, String ruta, LocalDate fechaSalida) {
		this(propietario, coche, ruta, fechaSalida, PLAZAS_OFRECIDAS_POR_DEFECTO);
	}
	
	public boolean cancelaReserva(String usario) {
		for (Reserva reserva : listaReservas) {
			if ((reserva.getUsuario().equals(usario)) && (reserva.getFechaRealizaReserva().isBefore(getFechaSalida().minusDays(1)))) {
				listaReservas.remove(reserva);
				return true;
			}
		}
		return false;
	}
	
	@Override
	public ViajePremium clone() {
		ViajePremium copia = (ViajePremium) super.clone(); 
		return copia; 
	}
	

}
