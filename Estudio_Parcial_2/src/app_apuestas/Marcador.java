package app_apuestas;
import java.util.Objects;

public class Marcador {
	private final int tanteoLocal;
	private final int tanteoVisitante;
	
	public Marcador(int tanteoLocal, int tanteoVisitante) {
		this.tanteoLocal = tanteoLocal;
		this.tanteoVisitante = tanteoVisitante;
	}
	
	public int getTanteoLocal() {
		return tanteoLocal;
	}
	
	public int getTanteoVisitante() {
		return tanteoVisitante;
	}
	
	@Override 
	public boolean equals(Object obj) {
		if (this == obj) return true;
		if(obj == null || getClass() != obj.getClass()) return false;
		Marcador other = (Marcador) obj;
		
		return tanteoLocal == other.tanteoLocal &&
				tanteoVisitante == other.tanteoVisitante;
	}
	
	@Override
	public int hashCode() {
		return Objects.hash(tanteoLocal, tanteoVisitante);
	}
}
