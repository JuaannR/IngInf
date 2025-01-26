package geometria;
import static java.lang.Math.sqrt;
import static java.lang.Math.pow;

public class Punto {

	//Propiedades --> Atributitos
	private int x;
	private int y;
	
	public Punto(int iniX, int iniY) {
		x = iniX;
		y = iniY;
	}
	
	/*
	 public Punto(int x, int y) {
		this.x = x;
		this.y = y;
	}
	 */
	
	public Punto() {
		this(0,0);
	}
	
	public Punto(Punto otro) {
		this(otro.x, otro.y);
	}
	
	public void desplazar(int incX, int incY) {
		x = x + incX;
		y = y + incY;
	}
	
	
	// Métodos de consulta de las propiedades
	public int getX() {
		return x;
	}
	
	public int getY() {
		return y;
	}
	
	//Ejercicio 2 Sesion 3
	public double distancia(Punto punto) {
		int difX = x-punto.x;
		int difY = y-punto.y;		
		//return Math.sqrt(Math.pow(difX, 2) + Math.pow(difY, 2));
		//Para no poner el Math todo el rato, importamos el static.java.Math. sqrt / pow
		
		return sqrt(pow(difX, 2) + pow(difY, 2));	
	}
	
	public void desplazar(Direccion direccion) {
		switch(direccion) {
		case ARRIBA:
			desplazar(0,1);
			break;
		case ABAJO:
			desplazar(0,-1);
			break;
		case DERECHA:
			desplazar(1,0);
			break;
		case IZQUIERDA:
			desplazar(-1,0);
			break;
		}
	}
	
	
	public static Punto mayorDistancia(Punto...puntos) {
		Punto masLejano = null;
		double mayorDistancia = 0;
		
		Punto origen = new Punto(); //(0,0) origen
		
		for(Punto punto: puntos) {
			double distanciaActual = origen.distancia(punto);
			
			if(distanciaActual > mayorDistancia) {
				masLejano = punto;
				mayorDistancia = distanciaActual;				
			}
		}
		return masLejano;
	}
		
	
}
