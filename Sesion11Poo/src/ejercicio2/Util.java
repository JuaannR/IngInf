package ejercicio2;

import java.util.Iterator;
import java.util.List;
import java.util.function.Consumer;
import java.util.function.Predicate;

public class Util {
	public static void doIf(List<Registro> lista, Consumer<Registro> accion, Predicate<Registro> condicion) {
		Iterator<Registro> iterador = lista.iterator();
		while(iterador.hasNext()) {
			Registro elem = iterador.next();
			if(condicion.test(elem) ) {
				accion.accept(elem);
			}
		}
	}
}



/*   //Generalización
public class Util {
	public static <T> void doIf(List<T> lista, Consumer<T> accion, Predicate<T> condicion) {
		Iterator<T> iterador = lista.iterator();
		while(iterador.hasNext()) {
			T elem = iterador.next();
			if(condicion.test(elem) ) {
				accion.accept(elem);
			}
		}
	}
}
*/