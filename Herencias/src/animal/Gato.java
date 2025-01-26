package animal;

public class Gato extends Animal {
	
	private String color;
	
	public Gato(String nombre, int edad, String color) {
		super(nombre, edad);
		this.color = color;
	}
	
	public void muevePata() {
		System.out.println(getNombre() + " mueve la pata");
	}
	
	public String getColor() {
		return color;
	}
	
	@Override
	public void emitirSonido() {
		System.out.println(getNombre() + " maulla");
	}
	
}
