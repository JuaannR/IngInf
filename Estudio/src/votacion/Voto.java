package votacion;

public class Voto {

	private final String votante;
	private final String candidato;
	
	public Voto(String votante, String candidato) {
		this.votante = votante;
		this.candidato = candidato;
	}
	
	public String getVotante() {
		return votante;
	}
	
	public String getCandidato() {
		return candidato;
	}
	
	
}
