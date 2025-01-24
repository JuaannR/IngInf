package parcial2_ej1;
import java.time.LocalDate;
import java.util.Collections;
import java.util.Comparator;
import java.util.LinkedList;
import java.util.List;
import java.util.Set;
import java.util.HashMap;
import java.util.HashSet;

public abstract class Agenda implements Cloneable {
	private LinkedList<Tarea> todas;
	private LinkedList<Tarea> completas;
	
	//relaciona una fecha con las tareas que tienen ese plazo de venciminto
	private HashMap<LocalDate, HashSet<Tarea>> fechasXtareas;
	
	//Constructor
	public Agenda() {
		this.todas = new LinkedList<>();
		this.completas = new LinkedList<>();
	}
	
	/*
	public List<Tarea> getCompletas(){
		return new LinkedList<Tarea>(completas);
	}
	
	public List<Tarea> getTodas() {
		return new LinkedList<Tarea>(todas);
	}
	*/
	
	//Metodos consulta -> Devolemos listas inmutables
	public List<Tarea> getCompletas() {
		return Collections.unmodifiableList(completas);
	}
	
	//Metodos consulta -> Devolemos listas inmutables
	public List<Tarea> getTodas() {
		return Collections.unmodifiableList(todas);
	}

	//Programar hacia la interfaz  ------OJO-----
	//Declaramos como List, en vez de un tipo concreto
	//como ArrayList o LinkedList
	public List<Tarea> getPendientes() {
		LinkedList<Tarea> pendientes = new LinkedList<Tarea>();
		for (Tarea tarea : todas) {
			if (!completas.contains(tarea) && tarea.isVencida() == false) {
				pendientes.add(tarea);
			}
		}
		return pendientes;
	}
	
	//Metodo sobrecargado ordenando la lista con comparator ----OJOO-----
	//Criterio de ordenacion en clase a parte
	public List<Tarea> getPendientes(Comparator<Tarea> criterio) {
		LinkedList<Tarea> pendientes = (LinkedList<Tarea>) getPendientes();
		pendientes.sort(criterio);
		return pendientes;
	}

	//Almacenar en un HashSet todos los plazos de todas las tareas SIN REPETIR (HashSet)
	public Set<LocalDate> getPlazos() {
		HashSet<LocalDate> plazos = new HashSet<LocalDate>();
		for (Tarea tarea : getPendientes()) {
			plazos.add(tarea.plazo());	//getPlazo()
		}								//pero esta en base al record -> plazo()
		return plazos;
	}
	
	//eliminar tarea de la lisra de todas las tareas
	protected boolean eliminarTarea(Tarea tarea) {
		if (todas.contains(tarea)) {
			todas.remove(tarea);
			return true;
		}
		return false;
	}
	
	//Añadir tarea a la lista de todas las tareas
	public boolean addTarea(Tarea tarea) {
		if (todas.contains(tarea) ) {
			return false;
		} else {
			todas.add(tarea);
			return true;
		}
	}
	
	//Añade varias tareas a la lista de todas las tareas
	//Y retorno una lista con las tareas añadidas (tareasAnadidas)
	public List<Tarea> addTareas(Tarea ...tareas) {
		LinkedList<Tarea> tareasAnadidas = new LinkedList<Tarea>();
			for (Tarea tarea : tareas) {		//Recorro todas las tareas pasadas como parametro
				if (!todas.contains(tarea)) {
					todas.add(tarea);			//Añado en todas y en tareasAnadidas
					tareasAnadidas.add(tarea);
				}
			}
			return tareasAnadidas;
	}
	
	public Set<Tarea> getTareasXFecha(LocalDate fecha) {
		if (fechasXtareas.containsKey(fecha)) {	//comparamos fecha de parametro con la fecha del HashMao, que actua de clave
												//si fuera valor, seria con .value()
			HashSet<Tarea> tareaFecha = fechasXtareas.get(fecha);	//como fecha es la clave del HashMap, al hacer get(fecha)
																	//obtengo todos los valores asociados a esa fecha, es decir 
																	//las tareas
			return new HashSet<Tarea>(tareaFecha);
		} else {
			return null;
		}
	}

	//Clase debe ser abstracta para implementar método abstracto
	public abstract boolean isDestacada(Tarea tarea);
	
	public void mostrarDestacadas() {
		for (Tarea tarea : getPendientes()) {
			if (isDestacada(tarea)) {
				System.out.println(tarea);
			}
		}
	}
	
	//Metodo auxiliar para aplicar el clone()
	private Agenda copiaSuperficial() {
		try {
			Agenda copiaSuperficial = (Agenda) super.clone();
			return copiaSuperficial;
		}
		catch(CloneNotSupportedException e) {
			System.err.println("La clase no es cloneable");
		}
		return null;
	}
	//Ahora el metodo clone en si
	@Override
	public Agenda clone() {
		Agenda copia = copiaSuperficial();
		copia.todas = new LinkedList<Tarea>(todas);
		copia.completas = new LinkedList<Tarea>(completas);
		copia.fechasXtareas = new HashMap<LocalDate, HashSet<Tarea>>(fechasXtareas);
		//Hacemos una copia de todos los atributos de la clase y retornamos la copia
		return copia;
	}

	@Override
	public String toString() {
		return "Todas: " + todas + ", Completadas: " + completas;
	}
}
