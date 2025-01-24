package basico_abstract;

public class Circulo extends Figura {
	private double radio;
	
	public Circulo(double radio) {
		this.radio = radio;
	}
	
	public double getRadio() {
		return radio;
	}
	
	@Override
	protected double calculaArea() {
		return Math.PI * radio * radio;
	}
}
