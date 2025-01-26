package animal;

public class Perro extends Animal{
	//Atributos especificos subclase
	private String raza;
	
	//Constructor
	public Perro(String nombre, int edad, String raza) {
		super(nombre, edad);	// Llamada al constructor de la clase animal
		this.raza = raza;		// El resto de argumentos de la subclase se trata igual que siempre
	}
	
	//Metodos que serán específicos de la subclase
	public void moverCola() {
		System.out.println(getNombre() + " mueve la cola");
	}
	
	public String getRaza() {
		return raza;
	}
	
	//Podemos sobreescribir los métodos de la clase padre
	//Ahora, el perro, en vez de "emitir sonido singular", ladrará
	
	@Override
	public void emitirSonido() {
		System.out.println(getNombre() + " ladra");
	}
	//Podemos usar los métodos de la clase padre como si estuvieran en esta
}
