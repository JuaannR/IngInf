package examen2;

public class Respuesta {
	private final String encuestado;
	private final String valorRespuesta;
	
	public Respuesta(String encuestado, String valorRespuesta) {
		this.encuestado = encuestado;
		this.valorRespuesta = valorRespuesta;
	}
	
	public String getEncuestado() {
		return encuestado;
	}
	
	public String getValorRespuesta() {
		return valorRespuesta;
	}
	
}
