package maquinas;

public class Monedero {
    private int[] cantidades;
    private double valorTotal;

    public Monedero() {
        this.cantidades = new int[Moneda.values().length];
        this.valorTotal = 0.0;
    }

    public Monedero(Moneda moneda, int cantidad) {
        this();
        insertar(moneda, cantidad);
    }

    public Monedero(Moneda moneda) {
        this(moneda, 1);
    }

    public void insertar(Moneda moneda, int cantidad) {
        int index = moneda.ordinal();
        cantidades[index] += cantidad;
        valorTotal += cantidad * obtenerValorMoneda(moneda);
    }

    public void insertar(Moneda moneda) {
        insertar(moneda, 1);
    }

    public void vaciar() {
        cantidades = new int[Moneda.values().length];
        valorTotal = 0.0;
    }

    public void combinar(Monedero otroMonedero) {
        for (Moneda moneda : Moneda.values()) {
            int cantidad = otroMonedero.cantidades[moneda.ordinal()];
            insertar(moneda, cantidad);
            otroMonedero.cantidades[moneda.ordinal()] = 0;
        }
        otroMonedero.valorTotal = 0.0;
    }

    public double obtenerValorTotal() {
        return valorTotal;
    }

    private double obtenerValorMoneda(Moneda moneda) {
        switch (moneda) {
            case UN_CENTIMO:
                return 0.01;
            case DOS_CENTIMOS:
                return 0.02;
            case CINCO_CENTIMOS:
                return 0.05;
            case DIEZ_CENTIMOS:
                return 0.10;
            case VEINTE_CENTIMOS:
                return 0.20;
            case CINCUENTA_CENTIMOS:
                return 0.50;
            case UN_EURO:
                return 1.00;
            case DOS_EUROS:
                return 2.00;
            default:
                return 0.0;
        }
    }
}
