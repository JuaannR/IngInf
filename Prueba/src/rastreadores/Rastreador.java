package rastreadores;

import java.util.Collections;
import java.util.Comparator;
import java.util.LinkedList;
import java.util.List;
import java.util.Set;
import java.util.TreeMap;

public class Rastreador {
	private LinkedList<Mensaje> mensajes;
	private TreeMap<String, LinkedList<Mensaje>> mensajesXautores;
	private TreeMap<String, LinkedList<Mensaje>> mensajesXtemas;
	
	public Rastreador() {
		mensajes = new LinkedList<Mensaje>();
		mensajesXautores = new TreeMap<String, LinkedList<Mensaje>>();
		mensajesXtemas = new TreeMap<String, LinkedList<Mensaje>>();
	}
	
	public Set<String> getAutores() {
		return Collections.unmodifiableSet(mensajesXtemas.keySet());
	}
	
	public List<Mensaje> getMensajes() {
		return Collections.unmodifiableList(mensajes);
	}
	
	public List<Mensaje> getMensajesAutor(String autor) {
		LinkedList<Mensaje> mensajes = mensajesXautores.getOrDefault(autor, new LinkedList<Mensaje>());
		return Collections.unmodifiableList(mensajes);
	}
	
	public List<Mensaje> getMensajesTema(String tema) {
		LinkedList<Mensaje> mensajes = mensajesXtemas.getOrDefault(tema,  new LinkedList<Mensaje>());
		return Collections.unmodifiableList(mensajes);
	}
	
	public void registrar(Mensaje mensaje) {
		mensajes.add(mensaje);
		
		String autor = mensaje.autor();
		LinkedList<Mensaje> mensajesAutor;
		if (mensajesXautores.containsKey(autor)) {
			mensajesAutor = mensajesXautores.get(autor);
		} else {
			mensajesAutor = new LinkedList<Mensaje>();
			mensajesXautores.put(autor, mensajesAutor);
		}
		mensajesAutor.add(mensaje);
		
		for (String tema : mensaje.getTemas()) {
			LinkedList<Mensaje> mensajesTema;
			if (mensajesXtemas.containsKey(tema)) {
				mensajesTema = mensajesXtemas.get(tema);
			} else {
				mensajesTema = new LinkedList<Mensaje>();
				mensajesXtemas.put(tema, mensajesTema);
			}
			mensajesTema.add(mensaje);
		}
	}
	
	public List<Mensaje> getMensajesOrdenados() {
		List<Mensaje> copia = new LinkedList<Mensaje>(mensajes);
		
		//opcion 1
		Collections.sort(copia);
		
		//opcion 2
		copia.sort(null);
		
		return copia;
	}
	
	
	public List<Mensaje> getMensajesOrdenados(Comparator<Mensaje> criterio) {
		List<Mensaje> copia = new LinkedList<Mensaje>(mensajes);
		
		//opcion 1
		Collections.sort(copia, criterio);
		
		//opcion 2
		copia.sort(criterio);
		
		return copia;
		
	}
}
