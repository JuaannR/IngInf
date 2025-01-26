package rastreadores;

import java.util.Comparator;

public class OrdenLongitudMensaje implements Comparator<Mensaje> {

	@Override
	public int compare(Mensaje o1, Mensaje o2) {
		return o1.texto().length() - o2.texto().length();
	}
}
