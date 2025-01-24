package parcial2_ej1;
import java.time.LocalDate;

public record Tarea(String descripcion, LocalDate plazo) {

    // Constructor sobrecargado que inicializa 'plazo' como null
    public Tarea(String descripcion) {
        this(descripcion, null); // Llama al constructor principal con 'null' para el plazo
    }
	
	public boolean tienePlazo() {
		if (plazo == null) {
			return false;
		} else {
			return true;
		}
	}
	
	public boolean isVencida() {
		if (tienePlazo() == false) {
			return false;	//No plazo -> no vence
		} 
			//tienePlazo() = true
		if (plazo.isBefore(LocalDate.now())) {
			return true;	//Vencido
		} else {			
			return false;	//No vencido
		}
	}
}
