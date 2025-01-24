package app_apuestas;

public class EventoLibre extends Evento {
	
	public EventoLibre(String nombre, double precioApuesta) {
		super(nombre, precioApuesta);
	}
	
	@Override
	protected boolean marcadorAceptable(Marcador marcadorAnadir) {
		//Para cada elemento en el HashMap, tomame el .value() que hace referencia al Marcador de cada elemento
		for(Marcador marcadorLista : getMapaApuestas().values()) {
			if(marcadorAnadir.equals(marcadorLista)) {	//Si el marcador a añadir ya esta en la lista, no lo añado
				return false;
			}
		}
		return true;
	}
}
