package viaje_toString_equals_clone;
import java.time.LocalDate;
import java.util.ArrayList;
import java.util.Objects;

public class ViajeSelectivo extends Viaje {
	private ArrayList<String> listaVetados;
	
	public ViajeSelectivo(String propietario, String coche, String ruta, LocalDate fechaSalida, int numPlazasOfrecidas) {
		super(propietario, coche, ruta, fechaSalida, numPlazasOfrecidas);
		this.listaVetados = new ArrayList<>();
	}
	
	public ViajeSelectivo(String propietario, String coche, String ruta, LocalDate fechaSalida) {
		this(propietario, coche, ruta, fechaSalida, PLAZAS_OFRECIDAS_POR_DEFECTO);
	}
	
	public void agregarVetado(String usuario) {
		if(!listaVetados.contains(usuario)) {
		listaVetados.add(usuario);
		}
	}
	
	public void eliminarVetado(String usuario) {
		listaVetados.remove(usuario);
	}

@Override 
public Reserva reservar(String usuario, int numPlazas) {
	if (listaVetados.contains(usuario)) {
		return null;
	}
	return super.reservar(usuario, numPlazas);
}

//Sobreescribimos el toString de Viaje para añadir la lista de Vetados
@Override
public String toString() {
    return super.toString() + ", Vetados: " + listaVetados;
}

//Como tenemos atributos nuevos, hay que sobreescribir los metodos

@Override
public boolean equals(Object obj) {
    if (this == obj) return true;  
    if (obj == null || getClass() != obj.getClass()) return false;  

    if (!super.equals(obj)) return false;

    ViajeSelectivo other = (ViajeSelectivo) obj;
    return listaVetados.equals(other.listaVetados);  
}

@Override
public int hashCode() {
    return Objects.hash(super.hashCode(), listaVetados);
}


//Al sobreescribir clone tenemos que añadir atributos de esta subclase
@Override
public ViajeSelectivo clone() {
	ViajeSelectivo copia = (ViajeSelectivo) super.clone(); 
	copia.listaVetados = new ArrayList<String> (listaVetados);
	
	return copia; 
	}
}
