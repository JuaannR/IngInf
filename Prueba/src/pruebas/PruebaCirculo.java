package pruebas;

import geometria.Circulo;
import geometria.Punto;

public class PruebaCirculo {
	
	public static void main(String[] args) {
		Punto punto1 = new Punto(2,3);
		Circulo circulo1 = new Circulo(punto1, 3);
		
		System.out.printf("circulo1.centro = (%d,%d) \n",
				circulo1.getCentro().getX(),
				circulo1.getCentro().getY());
		System.out.println("ciruclo1.radio = " + circulo1.getRadio());
		
		Circulo circulo2 = new Circulo();
		System.out.printf("circulo2.centro = (%d,%d) \n",
				circulo2.getCentro().getX(),
				circulo2.getCentro().getY());
		System.out.println("ciruclo2.radio = " + circulo2.getRadio());
		
		System.out.println("Desplazando circulo 1....");
		circulo1.desplazar(3, 2);
		System.out.printf("circulo1.centro = (%d,%d) \n",
				circulo1.getCentro().getX(),
				circulo1.getCentro().getY());
		System.out.println("ciruclo1.radio = " + circulo1.getRadio());
		
		System.out.println("Escalando 150% circulo2...");
		circulo2.escalar(150);
		System.out.printf("circulo.centro = (%d,%d) \n",
				circulo2.getCentro().getX(),
				circulo2.getCentro().getY());
		System.out.println("ciruclo2.radio = " + circulo2.getRadio());
		
		Circulo circulo3 = new Circulo(punto1, 5);
		
		circulo1.desplazar(3, 2);
		
		System.out.printf("circulo1.centro = (%d,%d) \n",
				circulo1.getCentro().getX(),
				circulo1.getCentro().getY());
		
		System.out.printf("circulo3.centro = (%d,%d) \n",
				circulo3.getCentro().getX(),
				circulo3.getCentro().getY());
		
		Punto punto2 = circulo3.getCentro();
		punto2.desplazar(1, 0);
		
		System.out.printf("punto2 = (%d, %d) \n",
				punto2.getX(), punto2.getY());
		
		System.out.printf("circulo3.centro = (%d,%d) \n",
				circulo3.getCentro().getX(),
				circulo3.getCentro().getY());
		
		
		
	}
	
}
