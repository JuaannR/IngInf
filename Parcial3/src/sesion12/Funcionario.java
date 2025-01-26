package sesion12;

import java.time.LocalDate;
import java.time.Period;

public class Funcionario {
	private static final int SMI = 1000;
	
	private final String nombre;
	private final LocalDate fechaNacimiento;
	private final LocalDate fechaContrato;
	private TipoCategoria categoriaProfesional;
	private double salario;
	//private int edad // CALCULABLE
	// private int anosServicio // CALCULABLE

	
	//Constructor
	public Funcionario(String nombre, LocalDate fechaNacimiento, LocalDate fechaContrato,
			TipoCategoria categoriaProfesional, double salario) {
		this.nombre = nombre;
		this.fechaNacimiento = fechaNacimiento;
		this.fechaContrato = fechaContrato;
		this.categoriaProfesional = categoriaProfesional;
		this.salario = salario;
	}
	
	//getters y setters
	
	public String getNombre() {
		return nombre;
	}
	
	public LocalDate getFechaNacimiento() {
		return fechaNacimiento;
	}
	
	public LocalDate getFechaContrato() {
		return fechaContrato;
	}
	
	public TipoCategoria getCategoriaProfesional() {
		return categoriaProfesional;
	}
	
	public double getSalario() {
		return salario;
	}
	
	public int getSMI() {
		return SMI;
	}
	
	public int getEdad() {
		return Period.between(fechaNacimiento,LocalDate.now()).getYears();
	}
	
	public int getAnyosServicio() {
		return Period.between(fechaContrato, LocalDate.now()).getYears();
	}
	
	public void setSalario(double aumento) {
		salario = salario * aumento ;
	}
	
	// NECESARIO SOBREESCRBIR TOSTRING PARA QUE APAREZCA
	// EL NOMBRE DEL FUNCIONARIO CORRECTO. PARA QUE SEA 
	// LIEGIBLE BASTA CON PONER EL NOMBRE SOLO

	@Override
    public String toString() {
        return nombre;
               
    }
}
