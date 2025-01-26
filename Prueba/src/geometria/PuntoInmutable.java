package geometria;

public class PuntoInmutable {
	//Propiedades --> atributos --> 
	private int x;
	private int y;
	
	public PuntoInmutable(int iniX, int iniY) {
		x = iniX;
		y = iniY;
	}
	
	/*
	 public Punto(int x, int y) {
		this.x = x;
		this.y = y;
	}
	 */
	
	public PuntoInmutable() {
		this(0,0);
	}
	
	public PuntoInmutable(PuntoInmutable otro) {
		this(otro.x, otro.y);
	}
	
	// Métodos de consulta de las propiedades
	public int getX() {
		return x;
	}
	
	public int getY() {
		return y;
	}
	
	// Metodos aplicables sobre los objetos
	public PuntoInmutable desplazar(int incX, int incY) {
		int newX = x +incX;
		int newY = y +incY;
		return new PuntoInmutable(newX, newY);
	}
	
	public PuntoInmutable desplazar(Direccion direccion) {
		PuntoInmutable destino = switch(direccion) {
		case ARRIBA -> {
			yield desplazar(0,1);
		}
		case ABAJO -> {
			yield desplazar(0,-1);
		}
		case DERECHA -> {
			yield desplazar(1,0);
		}
		case IZQUIERDA -> {
			yield desplazar(-1,0);
		}
	};
		return destino;
		
	}
}
