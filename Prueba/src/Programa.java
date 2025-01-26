
public class Programa {

	public static void main(String[] args) {
		
		//Declarar variable tipo bombilla
		Bombilla b1, b2;
		
		//Creamos el objeto bombilla
		b1 = new Bombilla();
		b2 = new Bombilla();
		
		//Por defecto, valor bool = false.
		System.out.println("Creamos b1 = " + b1.isEncendida());
		
		//paso de mensajes
		//objetoReceptor.metodo(parametro)
		
		//llamamos al método encender
		//ahora encendida = true
		//ya que lo dice el método encender()
		b1.encender();
		
		System.out.println("Encendemos b1 = " + b1.isEncendida());
		
		System.out.println("Creamos b2 = " + b2.isEncendida());
		b2.encender();
		System.out.println("Encendemos b2 = " + b2.isEncendida());
		
		//Ahora disminuimos 3 veces la intensidad a ver si nuestra bombilla se apaga al 
		//tener intensidad a 0
		
		b2.disminuirIntensidad();
		b2.disminuirIntensidad();
		b2.disminuirIntensidad();
		
		System.out.println("Después de disminuir 3 veces la intensidad de b2, ahora esta: " +b2.isEncendida());

		
		b2.aumentarIntensidad();
		System.out.println("Encendemos b2 : " +b2.isEncendida());
		System.out.println("Ademas b2 tiene intensidad: " +b2.getIntensidad());
	
	
	
	
	
	
	}
}
