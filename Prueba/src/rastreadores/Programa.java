package rastreadores;

public class Programa {
	
	public static void main(String[] args) {
		
		Rastreador rastreador = new Rastreador();
		
		Mensaje m1 = new Mensaje("Ernesto", "Los rivales también juegan, no sólo el #Barça");
		Mensaje m2 = new Mensaje("Manolete", "El #Barça es poco competitivo esta temporada");
		Mensaje m3 = new Mensaje("Manolete", "#Barça y #RealMadrid han roto el mercado de fichajes");
		
		rastreador.registrar(m1);
		rastreador.registrar(m2);
		rastreador.registrar(m3);
		
		System.out.println("Mensajes registrados: ");
		System.out.println(rastreador.getMensajes());
		
		System.out.println("\nMensajes del #Barsa: ");
		System.out.println(rastreador.getMensajesTema("#Barsa"));
		
		System.out.println("\nMensajes de Manolete: ");
		System.out.println(rastreador.getMensajesAutor("Manolete"));
		
		System.out.println("\nMensajes ordenados (orden natural)");
		System.out.println(rastreador.getMensajesOrdenados());
		
		System.out.println("\nMensajes ordenados (orden inverso al natural): ");
		System.out.println(rastreador.getMensajesOrdenados(new OrdenReverso()));
		
		System.out.println("\nMensajes ordenados (orden longitud texto): ");
		System.out.println(rastreador.getMensajesOrdenados(new OrdenLongitudMensaje()));
		
		
		System.out.println("\nMensajes ordenados (orden inverso al natural expresion lambda): ");
		System.out.println(rastreador.getMensajesOrdenados((me1, me2) -> -me1.compareTo(me2)));
		
		System.out.println("\nMensajes ordenados (orden longitud texto): ");
		System.out.println(rastreador.getMensajesOrdenados((me1, me2) -> -me1.texto().length() - me1.texto().length()));

	}

}
