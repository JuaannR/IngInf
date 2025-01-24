package viaje_toString_equals_clone;
import java.time.LocalDate;
import java.util.ArrayList;
import java.util.Collections;

public class Main2 {
	
	public static void main(String[] args) {
		
		Viaje viaje = new Viaje("Jose Antonio", "Seat León", "Murcia-Cartagena", LocalDate.of(2024, 12, 9));
		ViajeSelectivo selectivo = new ViajeSelectivo("Jose Antonio", "Seat León", "Murcia-Campus", LocalDate.of(2024, 12, 11), 4);
		selectivo.agregarVetado("Beatriz");
		selectivo.agregarVetado("Laura");
		ViajePremium premium = new ViajePremium("Jose Antonio", "Seat León", "Murcia-Barcelona", LocalDate.of(2024, 12, 15), 6);
		
		viaje.reservar("Pepe");
		System.out.println(viaje.toString());
		
		// Se declara array list para meter los 3 tipos de viaje
		ArrayList<Viaje> listaViajes = new ArrayList<>();
		
		//Añadimos los 3 viajes del tiron a la lista
		Collections.addAll(listaViajes, viaje, selectivo, premium);
		
		for (Viaje v : listaViajes) {
			if (v instanceof ViajeSelectivo) {
				ViajeSelectivo viajeSelectivo = (ViajeSelectivo) v;	//Transforma a ViajeSelectivo
				viajeSelectivo.eliminarVetado("Beatriz");			//Aplica metodo especifico de la clase ViajeSelectivo
			}
			System.out.println(v);		//No hace falta poner v.toString();
		}
		
		//forma abreviada de escribir if ... else -> Si se cumple -> true ;  si no se cumple -> false
		boolean estaContenido = listaViajes.contains(premium) ? true : false;	
		System.out.println("Viaje premium esta en la lista?: " + estaContenido);	
	}
}
