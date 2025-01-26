
public class Bombilla {
	
	//Estructura
	// Propiedades --> atributos
	//ponemos los atributos en private para que no se pueden modificar. 
	//De esta forma, evitamos poder encontrarnos un bombilla apagada con intensidad 3
	//Además, ya no podemos consultar el estado, es por ello que necesitamos crear 
	//dos nuevos metodos de consulta, is Encendida y getIntensidad, para poder consultar
	//el estado de la bombilla en el momento que queramos
	
	
	
	//Al modificar el método isEncendida de modo que devuelve true si intensidad es > 0, podemos
	//prescindir de ""private boolean encendida"".
	//Por ende, también prescindimos de la variable encendida del resto de procedimientos
	
	//private boolean encendida;
	private int intensidad;
	
	//Comportamiento
	//Funcionalidad --> métodos
	public void encender() {
		//encendida = true;
		intensidad = 3;
	}
	
	public void apagar() {
		//encendida = false;
		intensidad = 0;
	}
	
	public void aumentarIntensidad() {
		if (intensidad < 3)
			++intensidad;
	}

	public void disminuirIntensidad() {
		if (intensidad > 0)
			--intensidad;
	}
	
	//el metodo devolverá true si la intensidad es mayor que 0
	public boolean isEncendida() {
		return intensidad > 0;
	}

	public int getIntensidad() {
		return intensidad;
	}
	
	




}
