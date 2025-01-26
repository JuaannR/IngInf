package subastas;

public class SubastaMinima extends Subasta {
    private double cantidadMinima;

    public SubastaMinima(String nombreProducto, String propietario, double cantidadMinima) {
        super(nombreProducto, propietario);
        this.cantidadMinima = cantidadMinima;
    }

    public void setCantidadMinima(double cantidadMinima) {
        this.cantidadMinima = cantidadMinima;
    }

    @Override
    public boolean ejecutar() {
        if (getPujaMayor() >= cantidadMinima) {
            return super.ejecutar();
        }
        return false;
    }
 /*   
    public void cerrar() {
    	super.cerrar();
    }
    */
}

