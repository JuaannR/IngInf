package jerarquiaViajes;

import java.time.LocalDate;
import java.util.ArrayList;
import java.util.List;

public class Main {

    public static void main(String[] args) {

        // Crear viajes
        Viaje viaje1 = new Viaje("José Antonio", "Seat León", "Murcia-Cartagena", LocalDate.of(2024, 12, 9));
        ViajeSelectivo viajeSelectivo = new ViajeSelectivo("José Antonio", "Seat León", "Murcia-Campus", LocalDate.of(2024, 12, 11), 4);
        ViajePremium viajePremium = new ViajePremium("José Antonio", "Seat León", "Murcia-Barcelona", LocalDate.of(2024, 12, 15), 6);

        // Gestionar reservas y vetos
        viajeSelectivo.vetarUsuario("Beatriz");
        viaje1.realizarReserva("Alberto", 2);
        viajeSelectivo.realizarReserva("Enrique", 3);
        viajePremium.realizarReserva("Ana", 2);

        // Crear lista original de viajes
        List<Viaje> listaViajes = List.of(viaje1, viajeSelectivo, viajePremium);

        // Quitar veto y mostrar información de los viajes
        for (Viaje viaje : listaViajes) {
            if (viaje instanceof ViajeSelectivo selectivo) {
                selectivo.quitarVetoUsuario("Beatriz");
            }
            System.out.println(viaje);
        }

        // Comprobar si el viaje premium está en la lista
        System.out.println("El viaje premium está en la lista: " + listaViajes.contains(viajePremium));

        // Crear lista de copias
        List<Viaje> listaCopias = new ArrayList<>();
        for (Viaje viaje : listaViajes) {
            Viaje copia = viaje.clone();
            if (copia instanceof ViajePremium premium) {
                premium.listaReservas.clear(); // Cancelar reservas en la copia premium
            }
            listaCopias.add(copia);
        }

        // Mostrar lista de copias
        System.out.println("Lista de copias:");
        for (Viaje copia : listaCopias) {
            System.out.println(copia);
        }

        // Comparar listas
        System.out.println("¿La lista original es igual a la lista de copias? " + listaViajes.equals(listaCopias));
    }
}
