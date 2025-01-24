package subastaConHerencia;
import java.time.LocalDateTime;
import java.time.temporal.ChronoUnit;

public class SubastaTemporal extends SubastaLimitada{
	private static final int DOS = 2;
	
	private LocalDateTime creacion;
	private LocalDateTime vencimiento;
	//private int duracionPuja;   -> es un "atributo" de la clase aunque no este definido como tal
	// se proporcionara al crear un objeto del tipo SubastaTemporal. A partir de él se calcula maxPujas
	
	public SubastaTemporal(String nombreProducto, String propietario, int duracionPuja) {
		super(nombreProducto, propietario, duracionPuja * DOS);	//duracionPuja * DOS será el maxPujas permitidas
		this.creacion = LocalDateTime.now();
		this.vencimiento = creacion.plusHours(duracionPuja);
	}
	
	public long getHorasRestantes() {
		return ChronoUnit.HOURS.between(creacion, vencimiento);
		// return (int)ChronoUnit.HOURS.between(creacion, vencimiento);
		//si la funcion fuera int
	}
	
	public LocalDateTime getCreacion() {
		return creacion;
	}
	
	public LocalDateTime getVencimiento() {
		return vencimiento;
	}
	
	@Override
	public boolean pujar(String usuario, double cantidad) {
		if (getHorasRestantes() > 0) {
			return super.pujar(usuario, cantidad);
		}
		return false;
	}
	
	@Override
	public boolean ejecutar() {
		if (getHorasRestantes() <= 0) {
			return super.ejecutar();
		}
		return false;
	}
	
}
