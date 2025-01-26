package apuesta;

import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

public class Main {
    public static void main(String[] args) {
        // Crear evento libre
        EventoLibre eventoLibre = new EventoLibre("Real Madrid - F.C. Barcelona", 1.0);
        eventoLibre.apostar("juan", new Marcador(5, 0));
        eventoLibre.apostar("pepe", new Marcador(1, 3));

        // Crear opciones para evento restringido
        Set<Marcador> opciones = new HashSet<>();
        opciones.add(new Marcador(2, 0));
        opciones.add(new Marcador(2, 1));
        opciones.add(new Marcador(0, 2));
        opciones.add(new Marcador(1, 2));

        // Crear evento restringido
        EventoRestringido eventoRestringido = new EventoRestringido("Alcaraz vs Djokovic", 3.0, opciones);
        eventoRestringido.apostar("juan", new Marcador(2, 0));
        eventoRestringido.apostar("pedro", new Marcador(2, 1));
        eventoRestringido.apostar("pepe", new Marcador(2, 0));

        // Crear lista de eventos
        List<Evento> eventos = new ArrayList<>();
        eventos.add(eventoLibre);
        eventos.add(eventoRestringido);

        // Recorrer eventos y realizar operaciones
        for (Evento evento : eventos) {
            evento.apostar("enrique", new Marcador(5, 0));
            System.out.println(evento);
            if (evento instanceof EventoRestringido) {
                EventoRestringido restr = (EventoRestringido) evento;
                System.out.println("Apuestas para marcador (2, 0): " + restr.getNumeroApuestasPorMarcador(new Marcador(2, 0)));
            }
        }
    }
}
