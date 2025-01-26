package geometria;

public class Rectangulo {
    private Point verticeII; 
    private int ladoX; 
    private int ladoY; 
   
    public Rectangulo(Point verticeII, int ladoX, int ladoY) {
        this.verticeII = new Point(verticeII); 
        this.ladoX = ladoX;
        this.ladoY = ladoY;
    }

    public Rectangulo(Point verticeII, Point verticeSD) {
        this.verticeII = new Point(verticeII);
        this.ladoX = verticeSD.x() - verticeII.x(); 
        this.ladoY = verticeSD.y() - verticeII.y(); 
    }

    public Point getVerticeSI() {
        return verticeII.desplazar(0, ladoY);
    }

    public Point getVerticeID() {
        return verticeII.desplazar(ladoX, 0);
    }

    public Point getVerticeSD() {
        return verticeII.desplazar(ladoX, ladoY);
    }

    public int getPerimetro() {
        return 2 * (ladoX + ladoY);
    }

    public void desplazar(int incX, int incY) {
        verticeII = verticeII.desplazar(incX, incY);
    }

    public void escalar(double porcentaje) {
        this.ladoX = (int) (ladoX * (porcentaje / 100.0));
        this.ladoY = (int) (ladoY * (porcentaje / 100.0));
    }

    public String toString() {
        return "Rectángulo con vértice inferior izquierda en " + verticeII +
               ", ladoX: " + ladoX + ", ladoY: " + ladoY + ", perímetro: " + getPerimetro();
    }

    public int getLadoX() {
        return ladoX;
    }

    public int getLadoY() {
        return ladoY;
    }

    public Point getVerticeII() {
        return verticeII;
    }
}

