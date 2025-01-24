package parcial2_ej1;
import java.time.LocalDate;
import java.util.Collections;
import java.util.LinkedList;
import java.util.List;

public class AgendaPersonal extends Agenda{
	//nuevos atributos
	private LinkedList<Tarea> urgentes;
	
	//Constructor
	public AgendaPersonal() {
		super();
		this.urgentes = new LinkedList<Tarea>();
	}
	
	//Metodo get
	public List<Tarea> getUrgente() {
		return Collections.unmodifiableList(urgentes);
	}
	
	//Añadir una tarea a urgentes si no esta 
	public boolean setUrgente(Tarea tarea) {
		if (urgentes.contains(tarea)) {
			return false;
		} else {
			urgentes.add(tarea);
			return true;
		}
	}
	
	//eliminar una tarea de urgentes si esta
	public boolean unsetUrgente(Tarea tarea) {
		if (urgentes.contains(tarea)) {
			urgentes.remove(tarea);
			return true;
		} else {
			return false;
		}
	}
	
	//consultar si una tarea esta en la lista de urgentes
	public boolean isUrgente(Tarea tarea) {
		if (urgentes.contains(tarea)) {
			return true;
		} else {
			return false;
		}
	}
	
	//Redefinicion de métodos de Agenda
	@Override
	public boolean addTarea(Tarea tarea) {
		if (super.addTarea(tarea)) {
			if (tarea.tienePlazo()) {
				urgentes.add(tarea);
				return true;
			}
			return false;
		}
		return false;
	}
	
	
	@Override
	public boolean isDestacada(Tarea tarea) {
		if (isUrgente(tarea) && tarea.plazo().equals(LocalDate.now())) {
			return true;
		} else {
			return false;
		}
	}
	
	//Sobreescribimos el metodo toSring para añadir urgentes
	@Override
	public String toString() {
		return super.toString() + "Tareas pendientes: " + urgentes;
	}
	
	//Sobreescribimos el metodo clone para añadir urgentes
	@Override
	public AgendaPersonal clone() {
		AgendaPersonal copia = (AgendaPersonal) super.clone();
		copia.urgentes = new LinkedList<Tarea>(urgentes);
		return copia;
	}
}
