package subastaConHerencia;

public class Main {
	
	public static void main(String[] args) {
		Subasta subasta = new Subasta("Telefono Movil", "Juan");
		subasta.pujar("Pedro", 100);
		System.out.println("Puja mayor: " + subasta.getPujaMayor());
		
		boolean pujaEnrique = subasta.pujar("Enrique", 50);
		if (pujaEnrique == true) {
			System.out.println("Se acepto la puja de Enrique");
		} else {
			System.out.println("No se acepto la puja de Enrique");
		}
		
		System.out.println("Puja mayor: " + subasta.getPujaMayor());
		
		subasta.ejecutar();

		subasta.pujar("Enrique", 200);
		System.out.println("Puja mayor: " + subasta.getPujaMayor());
	}
}


