package maquinas;

public class MaquinaExpendedora {
    private String producto;
    private double precioProducto;
    private int stock;
    private Monedero dineroAcumulado;
    private Monedero dineroTransaccion;
    private boolean vacia;

    public MaquinaExpendedora(String producto, double precioProducto, int stock) {
        this.producto = producto;
        this.precioProducto = precioProducto;
        this.stock = stock;
        this.dineroAcumulado = new Monedero();
        this.dineroTransaccion = new Monedero();
        this.vacia = (stock == 0);
    }

    public void insertarMoneda(Moneda moneda) {
        dineroTransaccion.insertar(moneda);
    }

    public double devolverDinero() {
        double dineroDevuelto = dineroTransaccion.obtenerValorTotal();
        dineroTransaccion.vaciar();
        return dineroDevuelto;
    }

    public boolean comprar() {
        if (!vacia && dineroTransaccion.obtenerValorTotal() >= precioProducto) {
            stock--;
            dineroAcumulado.combinar(dineroTransaccion);
            return true;
        } else {
            return false;
        }
    }

    public int getStock() {
        return stock;
    }

    public double getDineroAcumulado() {
        return dineroAcumulado.obtenerValorTotal();
    }

    public double getDineroTransaccion() {
        return dineroTransaccion.obtenerValorTotal();
    }

    public static void main(String[] args) {
        // Prueba básica de funcionalidad
        MaquinaExpendedora maquina = new MaquinaExpendedora("Agua", 0.60, 10);

        // Usuario introduce una moneda de un euro
        maquina.insertarMoneda(Moneda.UN_EURO);

        // Usuario pide la devolución del dinero
        double dineroDevuelto = maquina.devolverDinero();
        System.out.println("Dinero devuelto: " + dineroDevuelto + " euros");

        // Usuario introduce una moneda de 50 céntimos
        maquina.insertarMoneda(Moneda.CINCUENTA_CENTIMOS);

        // Usuario intenta comprar el producto
        boolean compraExitosa = maquina.comprar();
        System.out.println("Compra exitosa: " + compraExitosa); // Se espera false

        // Usuario introduce 20 céntimos
        maquina.insertarMoneda(Moneda.VEINTE_CENTIMOS);

        // Usuario intenta comprar el producto nuevamente
        compraExitosa = maquina.comprar();
        System.out.println("Compra exitosa: " + compraExitosa); // Se espera true

        // Mostrar estado actual de la máquina
        System.out.println("Stock: " + maquina.getStock());
        System.out.println("Dinero acumulado: " + maquina.getDineroAcumulado() + " euros");
        System.out.println("Dinero transacción: " + maquina.getDineroTransaccion() + " euros");
    }
}
