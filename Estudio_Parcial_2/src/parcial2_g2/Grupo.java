package parcial2_g2;
import java.util.Collections;
import java.util.HashSet;
import java.util.Set;
import java.util.TreeSet;

public abstract class Grupo {
	private String nombre;
	private final String admin;
	private Set<String> miembros; //Ordena por orden alfabetico
	
	//Constructor
	public Grupo(String nombre, String admin) {
		this.nombre = nombre;
		this.admin = admin;
		this.miembros = new TreeSet<String>();
		//Inicialmente solo el admin esta en la lista de miembros
		miembros.add(admin);
	}
	
	//Getters
	public String getNombre() {
		return nombre;
	}
	
	public String getAdmin() {
		return admin;
	}
	
	public Set<String> getMiembros() {
		return Collections.unmodifiableSet(miembros);
	}
	
	//Metodos
	protected boolean eliminarMiembro(String miembro) {
		if (miembro.equals(admin)) {
			return false;
		} 
		if (miembros.contains(miembro)) {
				miembros.remove(miembro);
				return true;
			} else {
				return false;
			}
	}
	
	protected abstract boolean isAceptado(String miembro);
	
	public Set<String> agrearMiembros(String ...miembrosAnadir) {
		HashSet<String> noAceptados = new HashSet<String>();
		
		for (String miembroActual : miembrosAnadir) {
			if(isAceptado(miembroActual)) {
				miembros.add(miembroActual);  //Recuerdo que miembros es la lista de miembros
			} else {
				noAceptados.add(miembroActual);
			}
		}
		return noAceptados;
	}
}
