package votacion;

public class Main_Votacion {
	
	public static void main(String[] args) {
		Eleccion eleccion1 = new Eleccion("Delegado");
		
		eleccion1.emitirVoto("Pedro", "Uriel");
		eleccion1.emitirVoto("Rubén", "Uriel");
		eleccion1.emitirVoto("Ismael", "Juan");
		eleccion1.emitirVoto("Juan", "Rubén");
		eleccion1.emitirVoto("Uriel", "Rubén");
		eleccion1.emitirVoto("Jorge", "Rubén");
		
	System.out.println("El ganador de la votacion " + eleccion1.getNombreEleccion() + " es " + eleccion1.candidatoGanador());
	}
}
