package animal;

public class Animal {
	
	private String nombre;
	private int edad;
	
	public Animal(String nombre, int edad) {
		this.nombre = nombre;
		this.edad = edad;
	}
	
	public String getNombre() {
		return nombre;
	}
	
	public int getEdad() {
		return edad;
	}
	
	public void setNombre(String nombre) {
		this.nombre = nombre;
	}
	
	public void setEdad(int edad) {
		this.edad =edad;
	}
	
	public void mostrarInfo() {
		System.out.println("Animal. Nombre: " + nombre + ", Edad: " +edad);
	}
	
	public void emitirSonido() {
		System.out.println("Animal emite sonido singular");
	}
	

}
