package geometria;

public class Circulo2 {
	
	public static final int RADIO_POR_DEFECTO = 5;  //Declaración de constante
	public static final PuntoInmutable ORIGEN_COORDENADAS = new PuntoInmutable();
	//(0,0)
	
	private PuntoInmutable centro;
	private int radio;
	
	public Circulo2(PuntoInmutable centro, int radio) {
		this.centro = centro;
		//this.centro = new PuntoInmutable(centro);
		this.radio = radio;
	}
	
	public Circulo2() {
		this(ORIGEN_COORDENADAS, RADIO_POR_DEFECTO);
	}
	
	public PuntoInmutable getCentro() {
		return new PuntoInmutable(centro);
	}
	
	public int getRadio() {
		return radio;
	}
	
	public double getPerimetro() {
		return 2 * Math.PI * radio;
	}
	
	public void desplazar(int incX, int incY) {
		centro.desplazar(incX, incY);
	}
	
	public void escalar(double porcentaje) {
		radio = (int) (radio * porcentaje / 100);
	}
	
	
}
