package enero24;

import java.time.LocalDate;

public class Video {
	private static final int COSTE_GRATUITO = 0;
	
	private final LocalDate fechaPrimeraEmision;
	private final String nombreSerie;
	private final int temporada;
	private final int capitulo;
	//private String identificador;  // CALCULABLE
	private final int coste;
	private final Clasificacion clasificacion;
	
	//CONSTRUCTORES
	public Video(LocalDate fechaPrimeraEmision, String nombreSerie,
			int temporada, int capitulo, int coste, Clasificacion clasificacion) {
		//CONTROL PRECONDICIONES
		if (temporada < 1) {
			throw new IllegalArgumentException("La temporada no puede ser negativa");
		}
		if (capitulo < 1) {
			throw new IllegalArgumentException("El capitulo no puede ser negativo");
		}
		if (coste < 0) {
			throw new IllegalArgumentException("El coste no puede ser negativo");
		}
		this.fechaPrimeraEmision = fechaPrimeraEmision;
		this.nombreSerie = nombreSerie;
		this.temporada = temporada;
		this.capitulo = capitulo;
		this.coste = coste;
		this.clasificacion = clasificacion;
	}
	
	public Video(String nombreSerie, int temporada, int capitulo) {
		this(LocalDate.now(), nombreSerie, temporada, capitulo, COSTE_GRATUITO, Clasificacion.TODOS_LOS_PUBLICOS);
	}
	
	//GETTERS
	public LocalDate getFechaPrimeraEmision() {
		return fechaPrimeraEmision;
	}
	
	public String getNombreSerie() {
		return nombreSerie;
	}
	
	public int getTemporada() {
		return temporada;
	}
	
	public int getCapitulo() {
		return capitulo;
	}
	
	public int getCoste() {
		return coste;
	}
	
	public Clasificacion getClasificacion() {
		return clasificacion;
	}
	
	public String getIdentificador() {
		return String.format("%s %d.%d", nombreSerie, temporada, capitulo);
	}
	
	// PARA MOSTRAR LA LISTA DE VIDEOS VALIDA DE FORMA LEGIBLE
	@Override
	public String toString() {
		return getIdentificador();
	}
}
