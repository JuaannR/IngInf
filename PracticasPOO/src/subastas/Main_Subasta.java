package subastas;

public class Main_Subasta {
	
	public static void main(String[] args) {
		
		Subasta subasta1 = new Subasta("Teléfono Móvil", "Juan");
		
		subasta1.pujar("Pedro", 100.0);

		System.out.println("La puja mayor actual es: " + subasta1.getPujaMayor());
		
		boolean pujaEnrique = subasta1.pujar("Enrique", 50.0);
	
		
		if (pujaEnrique == false) {
			System.out.println("No se ha aceptado la puja de Enrique");
		} else {
			System.out.println("La puja de Enrique ha sido aceptada");
		}
		
		subasta1.pujar("Pepe", 200);
		System.out.println("La puja mayor actual es: " + subasta1.getPujaMayor());
		
		boolean cierre = subasta1.ejecutar();
		
		if (cierre = true) {
			System.out.println("La puja se ha cerrado");
		} else {
			System.out.println("La puja no se puede cerrar");
		}
	
		//Añadido para mostrar lista de pujas
		subasta1.mostrarPujas();
		
		
	}
	
	
}
