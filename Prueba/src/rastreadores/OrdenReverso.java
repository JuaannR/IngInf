package rastreadores;

import java.util.Comparator;

public class OrdenReverso implements Comparator<Mensaje> {
	
	@Override
	public int compare(Mensaje o1, Mensaje o2) {
		return -o1.compareTo(o2);
	}

}
