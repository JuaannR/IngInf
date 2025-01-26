package geometria;

public class Circulo {

	public static final int RADIO_POR_DEFECTO = 5;
	public static final Punto ORIGEN_COORDENADAS = new Punto();
	// (0,0)
	
	private Punto centro;
	private int radio;
	
	public Circulo(Punto centro, int radio) {
		//this.centro = centro;
		this.centro = new Punto(centro);
		this.radio = radio;
	}
	
	public Circulo() {
		this(ORIGEN_COORDENADAS, RADIO_POR_DEFECTO);
	}
	public Punto getCentro() {
		return new Punto(centro);
	}
	
	public int getRadio() {
		return radio;
	}
		
	public double getPerimetro() {
		return 2 * Math.PI * radio;
	}
		
	public void desplazar(int incX, int incY) {
		centro.desplazar(incX,  incY);
	}
		
	public void escalar(double porcentaje) {
		radio = (int) (radio * porcentaje / 100);
	}
	
}
