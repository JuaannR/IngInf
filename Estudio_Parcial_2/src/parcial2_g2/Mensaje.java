package parcial2_g2;
import java.time.LocalDateTime;
import java.util.Objects;

public record Mensaje(String emisor, String contenido, LocalDateTime creacion) {
	
	public Mensaje(String emisor, String contenido) {
		this(emisor, contenido, LocalDateTime.now());
	}
	
	@Override
	public boolean equals(Object obj) {
		if (this == obj) return true;
		if (obj == null || getClass() != obj.getClass()) return false;
		
		Mensaje other = (Mensaje) obj;
		return emisor.equals(other.emisor) &&
			   contenido.equals(other.contenido) &&
			   creacion.equals(other.creacion);
	}
	
	@Override
	public int hashCode() {
		return Objects.hash(emisor, contenido, creacion);
	}
	
}
