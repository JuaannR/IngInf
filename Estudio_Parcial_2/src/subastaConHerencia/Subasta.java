package subastaConHerencia;
import java.util.ArrayList;

public class Subasta {
	private static final double INCREMENTA_PUJA  = 1;
	private final String nombreProducto;
	private final String propietario;
	private boolean abierta;
	private ArrayList<Puja> listaPujas;
	//private double pujaMax;
	
	public Subasta(String nombreProducto, String propietario) {
		this.nombreProducto = nombreProducto;
		this.propietario = propietario;
		this.abierta = true;
		this.listaPujas = new ArrayList<>();
	}
	
	public String getNombreProducto() {
		return nombreProducto;
	}
	
	public String getPropietario() {
		return propietario;
	}
	
	public boolean isAbierta() {
		return abierta;
	}
	
	public ArrayList<Puja> getListaPujas() {
		return new ArrayList<Puja>(listaPujas);
	}
	
	public double getPujaMayor() {
		double max = 0;
		for (Puja puja : listaPujas) {
			if (puja.getCantidad() > max) {
				max = puja.getCantidad();
			}
		}
		return max;
	}
	
	public boolean pujar(String usuario, double cantidad) {
		if ((!abierta) || (usuario == getPropietario()) || (getPujaMayor() > cantidad)) {
			return false;
		} else {
			Puja puja = new Puja(usuario, cantidad);
			listaPujas.add(puja);
			return true;
		}
	}
	
	public boolean pujar(String usuario) {
		double max = getPujaMayor();
		double newCantidad = max + INCREMENTA_PUJA;
		return pujar(usuario, newCantidad);
	}
	
	public boolean ejecutar() {
		if ((listaPujas.size() != 0) && (isAbierta() == true)) {
			abierta = false;
			return true;
		} else {
			return false;
		}
	}
	
	//Metodo auxiliar para poder cerrar una subasta en SubastaMinima
	//Los metodos auxiliares son protected
	protected void cerrar() {
		abierta = false;
	}
	
}
