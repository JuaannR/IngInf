package examen1;
import java.time.LocalDate;

public class Desplazamiento {
	
	private final String codigoAutorizacion;
	private final LocalDate fecha;
	private final String uso;
	
	public Desplazamiento(String codigoAutorizacion, LocalDate fecha, String uso) {
		this.codigoAutorizacion = codigoAutorizacion;
		this.fecha = fecha;
		this.uso = uso;
	}
	
	public String getCodigoAutorizacion() {
		return codigoAutorizacion;
	}
	
	public LocalDate getFecha() {
		return fecha;
	}
	
	public String getUso() {
		return uso;
	}
	
	@Override
	public String toString() {
		return "Desplazamiento: {" +
	"Codigo Autorizacion: " + codigoAutorizacion +
	", fecha: " + fecha +
	", uso: " + uso + "}";
	}
}
