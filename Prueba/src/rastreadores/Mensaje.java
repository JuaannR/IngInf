package rastreadores;

import java.util.HashSet;
import java.util.Set;

public record Mensaje(String autor, String texto) implements Comparable<Mensaje>{
	public Set<String> getTemas() {
		HashSet<String> temas = new HashSet<String>();
		String[] palabras = texto.split("\\s+");
		
		for(String palabra : palabras) {
			if (palabra.startsWith("#")) {
				temas.add(palabra);
			}
		}
		return temas;
	}
	
	@Override
	public int compareTo(Mensaje o) {
		int criterio1 = autor.compareTo(o.autor);
		int criterio2 = texto.compareTo(o.texto);
		
		if (criterio1 == 0) {
			return criterio2;
		} else {
			return criterio1;
		}
	}
	
}
