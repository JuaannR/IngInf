package app_apuestas;

import java.util.Collections;
import java.util.ArrayList;

public class Main {

	public static void main(String[] args) {
		EventoLibre futbol = new EventoLibre("Real Madrid - F.C. Barcelona", 1);
		System.out.println("APOSTANDO...");
		System.out.println("Juan (5, 0): " + futbol.apostar("Juan", new Marcador(5, 0)));
		System.out.println("Pepe (1, 3): " + futbol.apostar("Pepe", new Marcador(1, 3)));
		
		
		EventoRestringido tenis = new EventoRestringido("Alcaraz vs Djokovic", 3, new Marcador(2, 0), new Marcador(2, 1), new Marcador(0, 2), new Marcador(1, 2));
		System.out.println();
		System.out.println("APOSTANDO...");
		System.out.println("Juan (2, 0): " + tenis.apostar("Juan", new Marcador(2, 0)));
		System.out.println("Pedro (2, 1): " + tenis.apostar("Pedro", new Marcador(2, 1)));
		System.out.println("Pepe (2, 0): " + tenis.apostar("Pepe", new Marcador(2, 0)));
		
		ArrayList<Evento> eventos = new ArrayList<Evento>(); 
		Collections.addAll(eventos, futbol, tenis);
		
		System.out.println();
		
		for(Evento evento : eventos) {
			
			System.out.println("Enrique (5, 0): " + evento.apostar("Juan", new Marcador(5, 0)));
			
			System.out.println(evento.toString());
			
			if(evento instanceof EventoRestringido) {
				EventoRestringido eventoRestringido = (EventoRestringido) evento;
				System.out.println("Número de eventos para el marcador (2, 0): " + eventoRestringido.getNumApuestas(new Marcador(2, 0)));
			}
		}
	}

}
