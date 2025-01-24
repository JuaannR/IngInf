package parcial2_g2;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Iterator;
import java.util.LinkedHashSet;
import java.util.List;
import java.util.Set;

public class Comunidad extends Grupo {
	
	private static final int NUEVO_MIEMBRO = 1;
	private static final int CUPO_POR_DEFECTO = 100;
	private TipoComunidad tipo;
	private Set<String> vetados;	//Importa orden insercion
	private List<Mensaje> mensajes;
	private int cupo;	//max miembros
	
	//atributo calculable -> boolean lleno
	public boolean isLLeno() {
		if (getMiembros().size() == cupo) {
			return true;
		} else {
			return false;
		}
	}
	//Constructores
	public Comunidad(String nombre, String admin, TipoComunidad tipo, int cupo) {
		super(nombre, admin);
		this.tipo = tipo;
		this.cupo = cupo;
		this.vetados = new LinkedHashSet<String>();
		this.mensajes = new ArrayList<Mensaje>();
	}
	
	public Comunidad(String nombre, String admin) {
		this(nombre, admin, TipoComunidad.OFICIAL, CUPO_POR_DEFECTO);
	}
	
	//getters
	public TipoComunidad getTipo() {
		return tipo;
	}
	public Set<String> getVetados(){
		return Collections.unmodifiableSet(vetados);
	}
	
	public List<Mensaje> getMensajes() {
		return Collections.unmodifiableList(mensajes);
	}
	
	public Mensaje pubicaMensaje(String emisor, String contenido) {
		if (getMiembros().contains(emisor)) {
			Mensaje mensaje = new Mensaje(emisor, contenido);
			mensajes.add(mensaje);
			return mensaje;
		} else {
			return null;
		}
	}
	
	public boolean vetarUsuario(String usuario) {
		//Comprobamos si el miembro es admin.
		boolean isEliminado = eliminarMiembro(usuario);
		
		//Si lo es, return false, no se puede eliminar, si si podemos:
		if(isEliminado) {
			//Creamos el iterador sobre la lista de mensajes
			Iterator<Mensaje> iterador = mensajes.iterator();
			
			while(iterador.hasNext()) {	//Mientras haya algo en la lista
				Mensaje actual = iterador.next();  //Elemento tipo mensaje actual de la lista
				if(actual.emisor().equals(usuario)) {	//Si el emisor del mensaje actual, es igual al usuario a vetar:
					iterador.remove();					//borro el mensaje
				}
			}
			vetados.add(usuario);			//añado usuario a la lista de vetados
			return true;
			
		}
		return false;
	}

	@Override
	protected boolean isAceptado(String miembro) {
		if (((getMiembros().size() + NUEVO_MIEMBRO) < cupo) && (!vetados.contains(miembro))) {  //esta el metodo isLleno()
			return true;
		} else {
			return false;
		}
	}
	
	
	
	
}
