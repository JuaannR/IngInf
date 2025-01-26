package subastas;

import java.util.ArrayList;
import java.util.List;

public class Main2 {
    public static void main(String[] args) {
        String juan = "Juan";
        String enrique = "Enrique";

        SubastaLimitada limitada = new SubastaLimitada("Disco duro multimedia", juan, 1);
        SubastaTemporal temporal = new SubastaTemporal("Teclado", juan, 3);
        SubastaMinima minima = new SubastaMinima("Impresora Láser", juan, 100);

        List<Subasta> subastas = new ArrayList<>();
        subastas.add(limitada);
        subastas.add(temporal);
        subastas.add(minima);

        for (Subasta subasta : subastas) {
            System.out.println("Producto en subasta: " + subasta.getNombreProducto());
            
            boolean pujaAceptada = subasta.pujar(enrique, 10);
            System.out.println("Puja de Enrique (10€) aceptada: " + pujaAceptada);
            
            pujaAceptada = subasta.pujar(enrique, 20);
            System.out.println("Puja de Enrique (20€) aceptada: " + pujaAceptada);

            if (subasta instanceof SubastaLimitada) {
                SubastaLimitada subastaLimitada = (SubastaLimitada) subasta;
                System.out.println("Pujas pendientes: " + subastaLimitada.getPujasPendientes());
            }

            if (subasta.isAbierta()) {
                boolean ejecutada = subasta.ejecutar();
                if (!ejecutada) {
                    System.out.println("No se pudo ejecutar la subasta.");
                } else {
                    System.out.println("Subasta ejecutada.");
                }
            }
        }
    }
}
