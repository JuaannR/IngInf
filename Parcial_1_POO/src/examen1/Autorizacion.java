package examen1;
import java.time.LocalDate;
import java.util.ArrayList;
import java.util.UUID;

public class Autorizacion {
	
	private final String usuario;
	private LocalDate fechaActivacion;
	private final String codigo;
	private ArrayList<Desplazamiento> listaDesplazamientos;
	private int numDesplazamientos;
	private boolean revocada;
	private final String matricula;
	private final LocalDate fechaCaducidad;
	private boolean caducada;
	
	
	public Autorizacion(String usuario, String matricula, LocalDate fechaCaducidad) {
		this.usuario = usuario;
		this.fechaActivacion = LocalDate.now();
		this.codigo = UUID.randomUUID().toString();
		this.listaDesplazamientos = new ArrayList<>();
		this.numDesplazamientos = 0;
		this.revocada = false;
		this.matricula = matricula;
		this.fechaCaducidad = fechaCaducidad;
		this.caducada = fechaCaducidad.isBefore(fechaActivacion);
	}
	
	//Llamamos al 2º constructor, asignando a fechaCaducidad, la fechaActivacion (.now) + 3 meses
	public Autorizacion(String usuario, String matricula) {
		this(usuario, matricula, LocalDate.now().plusMonths(3));	
	}
	
	//Métodos de consulta
	public String getUsuario() {
		return usuario;
	}
	
	public LocalDate getFechaActivacion() {
		return fechaActivacion;
	}
	
	public String getCodigo() {
		return codigo;
	}
	
	public void getDesplazamientos() {
		for (Desplazamiento desplazamiento : listaDesplazamientos) {
			System.out.println(desplazamiento);
			//System.out.println(desplazamiento.toString());
			//ES LO MISMO, si no pongo el .toString, Java lo hace automaticamente
		}
	}
	
	public int getNumDesplazaminetos() {
		return numDesplazamientos;
	}
	
	public boolean isRevocada() {
		return revocada;
	}
	
	public String getMatricula() {
		return matricula;
	}
	
	public LocalDate getFechaCaducidad() {
		return fechaCaducidad;
	}
	
	public boolean isCaducada() {
		return caducada;
	}
	
	public void revocar() {
		if (revocada == false) {
			revocada = true;
		}
	}
	
	public void reactivar() {
		if (revocada == true) {
			revocada = false;
			fechaActivacion = LocalDate.now();
		}
	}
	/* Se recomienda hacer con this
 
	public void reactivar() {
	    if (this.revocada == true) {
	        this.revocada = false;
	        this.fechaActivacion = LocalDate.now();
	    }
	}
	
	public void revocar() {
    if (!this.revocada) { 
        this.revocada = true;
    }
}	*/
	
	
	public Desplazamiento solicitarDesplazamiento(String uso) {
		if (revocada == false && caducada == false) {
			Desplazamiento desplazamiento1 = new Desplazamiento(codigo, LocalDate.now(), uso);
			listaDesplazamientos.add(desplazamiento1);
			return desplazamiento1;
		}
		return null;
	}
	
	public Desplazamiento solicitarDesplazamiento() {
		return solicitarDesplazamiento("revision");
	}
	
	public void agregaDesplazamiento(Desplazamiento desplazamiento) {
		listaDesplazamientos.add(desplazamiento);
	}
	
	@Override
	public String toString() {
		return "Autorizacion: {" +
		"Usuario: " + usuario +
		", Matricula: " + matricula +
		", Fecha Activacion: " + fechaActivacion +
		", Fecha Caducidad: " +fechaCaducidad +
		", revocada: " +revocada +
		"}";
	}
	
}
