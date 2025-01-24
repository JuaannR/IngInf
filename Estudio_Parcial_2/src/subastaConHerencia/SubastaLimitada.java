package subastaConHerencia;

public class SubastaLimitada extends Subasta {
	private final int maxPujas;
	
	public SubastaLimitada(String nombreProducto, String propietario, int maxPujas) {
		super(nombreProducto, propietario);
		this.maxPujas = maxPujas;
	}
	
	public int getMaxPujas() {
		return maxPujas;
	}
	
	public int getPujasPendientes() {
		return getMaxPujas() - getListaPujas().size();
	}
	
	
	@Override
	public boolean pujar(String usuario, double cantidad) {
		if (getPujasPendientes() > 0) {
			boolean pujado = super.pujar(usuario, cantidad);
			
			if (pujado && getPujasPendientes() == 0) {
				ejecutar();
			}
			return pujado;
		} 
		return false;
	}
	
	public void cerrar() {
		if (isAbierta()) {
			 super.cerrar();
		}
	}
}
