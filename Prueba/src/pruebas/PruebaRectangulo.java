package pruebas;
import geometria.Point;
import geometria.Rectangulo;

public class PruebaRectangulo {
    public static void main(String[] args) {
       
        Point verticeII = new Point(1, 1);
        Rectangulo rect1 = new Rectangulo(verticeII, 5, 3);

        Point verticeSD = new Point(6, 4);
        Rectangulo rect2 = new Rectangulo(verticeII, verticeSD);
       
        System.out.println(rect1);
        System.out.println(rect2);
        
        rect1.desplazar(2, 3);
        System.out.println("Rectángulo 1 después de desplazar: " + rect1);
      
        rect2.escalar(200);
        System.out.println("Rectángulo 2 después de escalar al 200%: " + rect2);
    }
}
