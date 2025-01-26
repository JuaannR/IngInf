package subastas;
import java.util.ArrayList;
import java.util.List;

public class Subasta {
	// private static final int INCREMENTO_PUJA = 1; 	PARA NO HACER UN + 1 ABAJO COMO NÚMERO MÁGICO
    private final String nombreProducto;
    private final String propietario;
    private boolean abierta;
    private final List<Puja> pujas;

    public Subasta(String nombreProducto, String propietario) {
        this.nombreProducto = nombreProducto;
        this.propietario = propietario;
        this.abierta = true;
        this.pujas = new ArrayList<>();
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

    public List<Puja> getPujas() {
        
        return new ArrayList<>(pujas);
    }

    public double getPujaMayor() {
        if (pujas.isEmpty()) {
            return 0;
        }
        return pujas.get(pujas.size() - 1).getCantidad();
    }

    public boolean pujar(String pujador, double cantidad) {
        if (abierta && !pujador.equals(propietario) && cantidad > getPujaMayor()) {
            pujas.add(new Puja(pujador, cantidad));
            return true;
        }
        return false;
    }

    public boolean pujar(String pujador) {
        double nuevaCantidad = getPujaMayor() + 1;
        return pujar(pujador, nuevaCantidad);
    }

    public boolean ejecutar() {
        if (abierta && !pujas.isEmpty()) {
            abierta = false;
            return true;
        }
        return false;
    }
}
