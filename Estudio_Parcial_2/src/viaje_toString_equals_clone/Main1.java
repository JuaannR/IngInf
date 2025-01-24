package viaje_toString_equals_clone;

import java.time.LocalDate;

public class Main1 {
	
	public static void main(String[] args) {
		
		Viaje viaje = new Viaje("Jose Antonio", "Seat León", "Murcia-Cartagena", LocalDate.of(2024, 12, 9));
		ViajeSelectivo selectivo = new ViajeSelectivo("Jose Antonio", "Seat León", "Murcia-Campus", LocalDate.of(2024, 12, 11), 4);
		selectivo.agregarVetado("Beatriz");
		ViajePremium premium = new ViajePremium("Jose Antonio", "Seat León", "Murcia-Barcelona", LocalDate.of(2024, 12, 15), 6);
		
		System.out.println("Reserva de Alberto: " + viaje.reservar("Alberto", 2));
		
		System.out.println("Reserva de Enrique: " + selectivo.reservar("Enrique", 3));
		
		System.out.println("Reserva de Beatriz " + selectivo.reservar("Beatriz", 1));
		
		System.out.println("Reserva de Ana: " + premium.reservar("Ana", 2));
		
		System.out.println("Canelación de reserva de Ana: " + premium.cancelaReserva("Ana"));
		
		
	}
	
	
}
