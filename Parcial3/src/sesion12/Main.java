package sesion12;

import java.time.LocalDate;
import java.util.Collections;
import java.util.Comparator;
import java.util.LinkedList;
import java.util.List;

public class Main {
	public static final double AUMENTO_CINCO_POR_CIENTO = 1.05;
	public static final int VEINTICINCO_ANYOS = 25;
	public static final int SESENTA_Y_CINCO_ANYOS = 65;
	
	public static void main(String[] args) {
		
	
		// CREAMOS VARIOS FUNCIONARIOS
		
		Funcionario f1 = new Funcionario("Evita", LocalDate.of(1990, 1, 2), LocalDate.of(2005, 5, 29), TipoCategoria.A1, 1300);
		Funcionario f2 = new Funcionario("Pedro", LocalDate.of(1987, 1, 2), LocalDate.of(1999, 6, 22), TipoCategoria.A2, 870);
		Funcionario f3 = new Funcionario("Uriel", LocalDate.of(1953, 8, 22), LocalDate.of(1970, 12, 12), TipoCategoria.A2, 3200);
		Funcionario f4 = new Funcionario("Rubén", LocalDate.of(2000, 9, 2), LocalDate.of(2020, 2, 2), TipoCategoria.B, 1600);
		Funcionario f5 = new Funcionario("Paula", LocalDate.of(1998, 11, 9), LocalDate.of(2010, 5, 15), TipoCategoria.C2, 2500);
		Funcionario f6 = new Funcionario("Laura", LocalDate.of(1960, 6, 19), LocalDate.of(1990, 8, 19), TipoCategoria.C2, 3000);
		
		//CREAMOS LISTA FUNCIONARIOS Y AÑADIMOS TODOS
		List<Funcionario> listaFuncionarios = new LinkedList<Funcionario>();
		Collections.addAll(listaFuncionarios, f1, f2, f3, f4, f5, f6);
		
		// 1.FELICITAR FUNCIONARIOS CUYO CUMPLEAÑOS SEA HOY, ORDENADOS POR ORDEN ALFABETICO
		
		listaFuncionarios.stream()
		//PARA CADA FUNCIONARIO, OBTENEMOS DIA Y MES DE NACIMIENTO Y COMPROBAMOS SI COINCIDE CON DIA Y MES ACTUAL
		.filter(f -> f.getFechaNacimiento().getMonth() == LocalDate.now().getMonth() && f.getFechaNacimiento().getDayOfMonth() == LocalDate.now().getDayOfMonth())
		//ORDENAMOS POR NOMBRE
		.sorted(Comparator.comparing(Funcionario::getNombre))	// (f-> f.getNombre()) ES LO MISMO
		.forEach(f -> System.out.println("Felicidades " + f.getNombre())); //MOSTRAR FELICITACION PARA CADA USUARIO 
		
		
		// 2. SUBIR 5% EL SUELDO A FUNCIONARIOS CON +25 AÑOS TRABAJANDO
		
		//SUELDOS ANTES DEL AUMENTO
		System.out.println("Antes del aumento: ");
		listaFuncionarios.stream().forEach(f -> System.out.println("Salario de " + f + ": " + f.getSalario()));
		
		listaFuncionarios.stream()
		.filter(f -> f.getAnyosServicio() >= VEINTICINCO_ANYOS)  //FILTRADO FUNCIONARIOS CON +25 AÑOS TRABAJANDO
		.forEach(f ->  f.setSalario(AUMENTO_CINCO_POR_CIENTO));	 //AUMENTO DE SUELDO PARA ESTOS
		
		//SUELDOS DESPUES DEL AUMENTO
		System.out.println("Después del aumento: ");
		listaFuncionarios.stream().forEach(f -> System.out.println("Salario de " + f + ": " + f.getSalario()));
		
		// 3. COMPROBAR QUE NINGÚN FUNCIONARIO COBRE MENOS DEL SMI
		
		System.out.println("Funcionarios con salario menor al SMI: ");
		boolean existe = listaFuncionarios.stream()
		.anyMatch(f -> f.getSalario() < f.getSMI());		// COMPRUEBA SI EXISTEN FUNCIONARIOS QUE COBREN MENOS DEL SMI
		System.out.println("Existen funcionarios que cobren menos del SMI?: " + existe);
		
		// 4. FUNCIONARIOS QUE COBRAN + DEL SMI ORDENADOS POR CATEGORIA
		
		System.out.println("Funcionarios con salario mayor al SMI ordenados por categoria: ");
		listaFuncionarios.stream()
		.filter(f -> f.getSalario() > f.getSMI())		// FILTRADO SALARIO MAYOR AL SMI
		.sorted(Comparator.comparing(Funcionario::getCategoriaProfesional)
			.thenComparing(Funcionario::getAnyosServicio))
			.forEach(f -> System.out.println(f));
		
		// 5. CUANTOS FUNCIONARIOS HAY EN EDAD DE JUBILARSE
		
		System.out.println("Usuarios en edad de jubilarse: ");
		long num  = listaFuncionarios.stream()
		.filter(f -> f.getEdad() >= SESENTA_Y_CINCO_ANYOS )		// FILTRADO FUNCIONARIOS +65 AÑOS
		.count();
		System.out.println("Hay " + num + " usuarios en edad de jubilarse");
		
	}
}
