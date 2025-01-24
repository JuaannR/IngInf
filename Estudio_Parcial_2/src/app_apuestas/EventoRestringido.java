package app_apuestas;
import java.util.Collections;
import java.util.HashSet;

public class EventoRestringido extends Evento {
	private HashSet<Marcador> opciones;	//es como una lista desodenada de elementos
								//desordenado xq se guarda en una Tabla Hash
								//no permite elementos repetidos, guarda 1 solo elemento
	
public EventoRestringido(String nombre, double precioApuesta, Marcador ... marcador) {
	super(nombre, precioApuesta);
	this.opciones = new HashSet<Marcador>();
	Collections.addAll(opciones, marcador);
	}

public HashSet<Marcador> getOpciones() {
	return opciones;
}

@Override
protected boolean marcadorAceptable(Marcador marcador) {
	if (opciones.contains(marcador)) {
		return true;
	}
	return false;
}
	
public int getNumApuestas(Marcador marcador) {
	int cont = 0;
	for (Marcador marcadorActual : getMapaApuestas().values()) {
		if (marcador.equals(marcadorActual)) {
			cont++;
		}
	}
	return cont;
}

}
