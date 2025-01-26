package enero24;

import java.util.Collection;
import java.util.List;
import java.util.Map;
import java.util.function.Function;
import java.util.stream.Collectors;

public class Util {
	// T: TIPO OBJETO COLECCION, VIDEO POR EJEMPLO
	// K: TIPO DE LA CLAVE EN EL MAPA, STRING POR EJEMPLO
	
	public static<T, K> Map<K, List<T>> clasificar(Collection<T> coleccion, Function<T, K> clasificador) {
		return coleccion.stream()
				.collect(Collectors.groupingBy(clasificador));
	}
	
}
