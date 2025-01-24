package examen2;
import java.time.LocalDate;
import java.util.ArrayList;
//import java.util.List;

public class Encuesta {
	
	private static final int PORCENTAJE = 100;	
	
	private final String pregunta;
	private LocalDate fechaLimite;
	private ArrayList<String> listaEncuestados;
	//private boolean activa;
	private ArrayList<Respuesta> listaRespuestas;
	//private double indiceParticipacion;
	
	//activa e indiceParticipacion son propiedades calculables
	
	//String... listaEncuestados -> indica que es un argumento variable, puede recibir 0 o mas valores de ese tipo
	public Encuesta(String pregunta, LocalDate fechaLimite, String... listaEncuestados) {
		this.pregunta = pregunta;
		this.fechaLimite = fechaLimite;
		this.listaEncuestados = new ArrayList<>();
		this.listaRespuestas = new ArrayList<>();
		
		//Para cada encuestado que reciba en el constructor, lo añado uno por uno al arrayList
		for (String encuestado : listaEncuestados) {
			this.listaEncuestados.add(encuestado);
		}	
	}
	
	public Encuesta(String pregunta, String... listaEncuestados) {
		this(pregunta, LocalDate.now().plusDays(7), listaEncuestados);
	}

	//metodo get
	public String getPregunta() {
		return pregunta;
	}
	
	public boolean isActiva() {
		if (LocalDate.now().isBefore(fechaLimite)) {
			return true;
		} else {
			return false;
		}
		
	}
	
	public double getIndiceParticipacion() {
		if (listaEncuestados.isEmpty()) {
			return 0;		//evitamos una posible division por 0
		}
		return listaRespuestas.size() / listaEncuestados.size() * PORCENTAJE;
	}
	
	//Comprueba si persona esta en listaEncuestados (si puede responder) 
	//Además, si lo encuentra, vamos a mirar todas las respuestas de la listaRespuestas para verificar 
	//que no haya respondido antes
	public boolean puedeResponder(String persona) {
		if(listaEncuestados.contains(persona)) {				//si es listaEncuestados esta persona
			for (Respuesta respuesta : listaRespuestas) {
				if (respuesta.getEncuestado().equals(persona)) {	//si en listaRespuestas hay una respuesta de persona
					return false;
				}
			}
			return true;
		} else {
			return false;
		}
	}
	
	public Respuesta responder(String encuestado, String valorRespuesta) {
		if (isActiva() == true && puedeResponder(encuestado) == true) {
			Respuesta respuesta1 = new Respuesta(encuestado, valorRespuesta);
			listaRespuestas.add(respuesta1);
			return respuesta1;
		}
		return null;
	}
	
	public Respuesta responder(String encuestado) {
		return responder(encuestado, "no");
	}
	
	public int recuento(String valorRespuesta) {
		int cont=0;
		for (Respuesta respuesta : listaRespuestas) {
			if (respuesta.getValorRespuesta().equals(valorRespuesta)) {
				cont++;
			}
		}
		return cont;
	}
	

}
