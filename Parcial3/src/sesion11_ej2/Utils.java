package sesion11_ej2;

import java.util.Iterator;
import java.util.List;
import java.util.function.Consumer;
import java.util.function.Predicate;

public class Utils {
	
	public static void doIf(List<Registro> listaRegistros, Predicate<Registro> condition, Consumer<Registro> action) {
		//ITERADOR EXPLÍCITO
		Iterator<Registro> iterator = listaRegistros.iterator();
		
		//RECORRER LISTA CON ITERATOR
		while (iterator.hasNext()) {
			Registro registro = iterator.next();
			
			//SI EL REGISTRO CUMPLE LA CONDICIÓN, SE LE APLICA LA ACCIÓN
			if (condition.test(registro)) {
				action.accept(registro);
			}
		}
	}
}
