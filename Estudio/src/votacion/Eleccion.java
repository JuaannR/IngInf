package votacion;
import java.util.ArrayList;

public class Eleccion {

	private String nombreEleccion;
	private ArrayList<Voto> listaVotos;
	private static final int MIN_VOTOS_GANADOR = 3;
	
	public Eleccion(String nombreEleccion) {
		this.nombreEleccion = nombreEleccion;
		this.listaVotos = new ArrayList<>();
	}
	
	public String getNombreEleccion() {
		return nombreEleccion;
	}
	
	public boolean emitirVoto(String votante, String candidato) {
		if (votante == candidato) {
			return false;
		} else {
		Voto voto1 = new Voto(votante, candidato);
		listaVotos.add(voto1);
		return true;
		}
	}
	
	//Cuenta el total de votos del Array List
	public int totalVotos() {
		return listaVotos.size();
	}
	
	//Cuenta los votos de un candidato especifico
	public int contarVotos(String candidato) {
		int cont = 0;
		for (Voto voto : listaVotos) {
			if (voto.getCandidato() == candidato) {
				cont++;
			}
		}
		return cont;
	}
	
	//Obtiene el candidato con más votos	
	public String candidatoGanador() {
		String ganador = "No hay ganador";
		int maxVotos = 0;
		
		for (Voto voto : listaVotos) {
			int votosCandidato = contarVotos(voto.getCandidato());
			if (votosCandidato > maxVotos && votosCandidato >= MIN_VOTOS_GANADOR) {
				maxVotos = votosCandidato;
				ganador = voto.getCandidato();
			}
		}
		return ganador;
	}
	
}
