package junio24;

import java.time.LocalDate;
import java.time.Period;

public class Vino {
	private static final int DOS  = 2;
	
	private final LocalDate fechaProduccion;
	private final String nombre;
	private final Color color;
	private final Maduracion maduracion;
	private final double coste;
	
	public Vino(LocalDate fechaProduccion, String nombre, Color color, Maduracion maduracion, double coste) {
		
		if(fechaProduccion == null || nombre == null || color == null || maduracion == null || coste <= 0) {
			throw new IllegalArgumentException("Alguno de los parámetros no es válido");
		}
		this.fechaProduccion = fechaProduccion;
		this.nombre = nombre;
		this.color = color;
		this.maduracion = maduracion;
		this.coste = coste;
	}
	
	public Vino(LocalDate fechaProduccion, String nombre) {
		this(fechaProduccion, nombre, Color.BLANCO, Maduracion.JOVEN, DOS);
	}
	
	public LocalDate getFechaProduccion() {
		return fechaProduccion;
	}
	
	public String getNombre() {
		return nombre;
	}
	
	public Color getColor() {
		return color;
	}
	
	public Maduracion getMaduracion() {
		return maduracion;
	}
	
	public double getCoste() {
		return coste;
	}
	
	//CONTROL DE PRECONDICIONES
	public void validaVino(Vino vino) {
		long mesesMaduracion = Period.between(fechaProduccion, LocalDate.now()).toTotalMonths();
		
		/*
		SI FUERAN DIAS ENTRE DOS FECHAS:  
		 long totalDays = ChronoUnit.DAYS.between(startDate, endDate);
		*/
		
		Maduracion maduracionEsperada;
		
		if (mesesMaduracion >= 0 && mesesMaduracion <= 5) {
			maduracionEsperada = Maduracion.JOVEN;
		} else if (mesesMaduracion >= 6 && mesesMaduracion <=11) {
			maduracionEsperada = Maduracion.CRIANZA;
		} else if (mesesMaduracion >= 12 && mesesMaduracion <=35) {
			maduracionEsperada = Maduracion.RESERVA;
		} else if (mesesMaduracion >= 36) {
			maduracionEsperada = Maduracion.GRAN_RESERVA;
		} else {
			throw new IllegalArgumentException("Fecha producción no válida");
		}
		
		if (vino.getMaduracion() != maduracionEsperada) {
			throw new IllegalArgumentException("La maduracion de " + vino.getNombre() + " no es la esperada");
		}
		
	}
	
	@Override
	public String toString() {
		return "[Fecha: " + fechaProduccion + ", " + 
			   "Nombre: " + nombre + ", " + 
			   "Color: " + color + ", " + 
			   "Maduración: " + maduracion + ", " + 
			   "Coste: " + coste + "]";
	}
}
