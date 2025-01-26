package geometria;

public record Point(int x, int y) {

	public Point() {
		this(0,0);
	}
	
	public Point(Point otro) {
		this(otro.x, otro.y);
	}
	
	public Point desplazar(int incX, int incY) {
		int newX = x + incX;
		int newY = y + incY;
		return new Point(newX, newY);
	}
	
	public Point desplazar(Direccion direccion) {
		return switch(direccion) {
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
	}
	
}
