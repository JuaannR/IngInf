package subastas;

public class Main {
    public static void main(String[] args) {
        
        Subasta subasta = new Subasta("Teléfono Móvil", "Juan");
       
        boolean aceptadaPedro = subasta.pujar("Pedro", 100);
        System.out.println("Puja aceptada de Pedro: " + aceptadaPedro);
        System.out.println("Puja mayor: " + subasta.getPujaMayor());
    
        boolean aceptadaEnrique = subasta.pujar("Enrique", 50);
        System.out.println("Puja aceptada de Enrique: " + aceptadaEnrique);
        System.out.println("Puja mayor: " + subasta.getPujaMayor());

        boolean subastaEjecutada = subasta.ejecutar();
        System.out.println("Subasta ejecutada: " + subastaEjecutada);

        boolean aceptadaEnrique200 = subasta.pujar("Enrique", 200);
        System.out.println("Puja aceptada de Enrique (200 euros): " + aceptadaEnrique200);
    }
}
