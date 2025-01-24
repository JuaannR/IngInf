package parcial2_g2;
import java.util.Collections;
import java.util.HashMap;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.Map;
import java.util.Set;

public class ComunidadActiva extends Comunidad {
	private Set<Mensaje> mensajesDestacados;
	private Map<Mensaje, LinkedList<String>> likes;
	
	
	//Constructor
	public ComunidadActiva(String nombre, String admin, TipoComunidad tipo, int cupo) {
		super(nombre, admin, tipo, cupo);
		this.mensajesDestacados = new HashSet<Mensaje>();
		this.likes = new HashMap<Mensaje, LinkedList<String>>();
	}
	
	public Set<Mensaje> getMensajesDestacados() {
		return Collections.unmodifiableSet(mensajesDestacados);
	}
	
	public Map<Mensaje, LinkedList<String>> getLikes() {
		return Collections.unmodifiableMap(likes);
	}
	
	public boolean darLike(String miembro, Mensaje mensaje) {
		LinkedList<String> miembros;
		
		if(getMiembros().contains(miembro)) {	//Comprobamos si miembro esta en la comunidad
			if(likes.containsKey(mensaje)) {	//Verifica si el mensaje tiene una lista de miembros que han dado like
				miembros = likes.get(mensaje);	// Si -> recuperamos lista y se asigna a miembros
			} else {							
				miembros = new LinkedList<String>();  //no -> creamos lista vacia
				likes.put(mensaje, miembros);			//ascociamos mensaje y miembro
			}
			miembros.add(miembro);		//añadir miembro a la lista de likes
			return true;
		}
		return false;
	}
	
	public int getLikes(Mensaje mensaje) {
		if(likes.containsKey(mensaje)) {
			return likes.get(mensaje).size();
		}
		return 0;
	}
	
	@Override
	public Mensaje pubicaMensaje(String emisor, String contenido) {
		Mensaje publicado = super.pubicaMensaje(emisor, contenido);
		
		if (publicado == null) {
			return null;
		}
		
		mensajesDestacados.add(publicado);
		return publicado;
	}
	

}
