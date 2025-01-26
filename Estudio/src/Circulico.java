public class Circulico {

	private double radio;
	
	//Constructor para inicializar un circulo con radio r
	public Circulico(double r) {
		radio = r;
	}
	
	//Método para consultar el valor del radio
	public double getRadio() {
		return radio;
	}
		
	//Método para cambiar el valor del radio
	public void setRadio(double newRadio) {
		radio = newRadio;
	}
	
	//Método para incrementar el valor del radio
	public void incrementaRadio(double newRadio) {
		radio = radio + newRadio;
	}
	
	//Método para reducir el valor del radio
	public void reduceRadio(double newRadio) {
		radio = radio - newRadio;
	}
		
	//Método para calcular el perimetro
	public double Perimetro(double radio) {
		double perimetro = 2*Math.PI*radio;
		return perimetro;
		
	}
	
	//Método para calcular el área
	public double Area(double radio) {
		double area = Math.PI * Math.pow(radio,2);
		return area;
	}
	
	//Método para obtener el circulo con mayor radio
	public static double RadioMax(Circulico c1, Circulico c2) {
		if (c1.getRadio() > c2.getRadio()) {
			return c1.getRadio();
		} else {
			return c2.getRadio();
		}
	}
	
	
	public static void main(String[] args) {
		//Primero creamos el circulo 1. Declarar variable + 2. Crear objeto
		
		double r1 = 3.33;
		Circulico c1;
		c1 = new Circulico(r1);
		
		System.out.println("El radio de c1 es: " + c1.getRadio() + " cm");
		
		double p1 = c1.Perimetro(c1.getRadio());
		System.out.printf("El perímetro de c1 es %.2f cm \n", +p1);
		//Se puede usar este formato para redondear numeros, pero no incluye
		//salto de linea, a diferencia de println, por lo que tenemos que agregarlo
		
		c1.incrementaRadio(1.50);
		System.out.println("El nuevo radio de c1 es: " + c1.radio+ " cm^2");
				
		double r2 = 8.78;
		Circulico c2 = new Circulico(r2);
		System.out.println("El radio de c2 es: " +c2.getRadio()+ " cm");
		
		double a2 = c2.Area(c2.getRadio());
		System.out.printf("El área de c2 es: %.2f cm^2 \n", +a2);
		
		c2.reduceRadio(5.30);
		System.out.printf("El nuevo radio de c2 es: %.2f cm^2 \n", +c2.getRadio());
				
		System.out.println("Radio actual de c1= " +c1.getRadio());
		System.out.printf("Radio actual de c2= %.2f \n", +c2.getRadio());
				
		double rmayor = Circulico.RadioMax(c1, c2);
		System.out.println("El radio mayor entre c1 y c2 es: " +rmayor+ " cm");
			
		c2.setRadio(rmayor);
		System.out.println("El radio de c2 actualizado es: " +c2.getRadio());
	}
}
