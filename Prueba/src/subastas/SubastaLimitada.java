package subastas;

public class SubastaLimitada extends Subasta {
    private final int maxPujas;

    public SubastaLimitada(String nombreProducto, String propietario, int maxPujas) {
        super(nombreProducto, propietario);
        this.maxPujas = maxPujas;
    }

    @Override
    public boolean pujar(String pujador, double cantidad) {
        if (getPujas().size() < maxPujas) {
            boolean aceptada = super.pujar(pujador, cantidad);
            if (getPujas().size() >= maxPujas) {
                ejecutar(); 
            }
            return aceptada;
        }
        return false;
    }

    public int getPujasPendientes() {
        return maxPujas - getPujas().size();
    }
}
