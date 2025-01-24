package examen1;

import java.time.LocalDate;
import java.util.ArrayList;
import java.util.List;
import java.util.UUID;

public class Main {
	
		public static void main(String[] args) {
			
		Autorizacion autorizacion1 = new Autorizacion("juan@um.es", "8778-MLD", LocalDate.now().plusMonths(1));	
		Autorizacion autorizacion2 = new Autorizacion("pepe@um.es", "1221-HHG");
		
		autorizacion1.revocar();
		

		
		autorizacion1.getDesplazamientos();
		
		System.out.println(autorizacion1.isRevocada());	//vemos si esta revocada
		System.out.println(autorizacion1.isCaducada()); //vemos si esta caducada
		
		
		
		autorizacion1.reactivar();
		
		autorizacion1.solicitarDesplazamiento("Transporte");
		autorizacion1.solicitarDesplazamiento("Medico");
		autorizacion1.solicitarDesplazamiento("Pilotar");
		autorizacion1.getDesplazamientos();
		
		//Creamos Array List de autorizaciones e improvisamos funcion para mostrarla por pantalla
		//creando un toString en la clase Autorizacion
		
		ArrayList<Autorizacion> listaAutorizaciones = new ArrayList<>();
		listaAutorizaciones.add(autorizacion1);
		listaAutorizaciones.add(autorizacion2);
		
		for (Autorizacion autorizacion : listaAutorizaciones ) {
			System.out.println(autorizacion);
		}
		
		
		//Recorremos la lista de autorizaciones y solicitamos un desplazamiento para uso comercial
		
		for (Autorizacion autorizacion : listaAutorizaciones) {
			Desplazamiento desplazamiento = autorizacion.solicitarDesplazamiento("comercial");
		
				if (desplazamiento != null) {
					System.out.println("Desplazamiento generado: " + desplazamiento);
				} else {
					System.out.println("Desplazamiento no autorizado");
				}
		
		}

		
		}
		
}
