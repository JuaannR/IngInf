package pruebas;

import geometria.Punto;

public class PruebaPunto {

	public static void main(String[] args) {
		//Punto punto1;
		//punto1 = new punto;
		Punto punto1 = new Punto(1,3);
		
		System.out.println("punto1.x = " + punto1.getX());
		System.out.println("punto1.y = " + punto1.getY());
		
		Punto punto2 = new Punto();
		System.out.printf("punto2 = (%d, %d) \n", punto2.getX(), punto2.getY());
		
		Punto punto3 = new Punto(punto1);
		System.out.printf("punto3 = (%d, %d) \n", punto3.getX(), punto3.getY());
		
		Punto punto4 = punto2;
		System.out.printf("punto4 = (%d, %d) \n", punto4.getX(), punto4.getY());
	
		punto2.desplazar(1,2);
		System.out.printf("punto2 = (%d, %d) \n", punto2.getX(), punto2.getY());
		System.out.printf("punto4 = (%d, %d) \n", punto4.getX(), punto4.getY());
		// Tenemos un caso de aliasing, al desplazar el punto2, también se desplaza el punto4
	}
}
