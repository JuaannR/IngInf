package sesion11_ej2;
import java.time.LocalDate;
import java.util.Collections;
import java.util.Comparator;
import java.util.HashSet;
import java.util.LinkedList;

public class Main {
	
	public static void main(String[] args) {
		
		Registro r1 = new Registro("Pedro", LocalDate.of(2024, 11, 11));
		Registro r2 = new Registro("Juan", LocalDate.of(2024, 11, 4));
		Registro r3 = new Registro("Martina", LocalDate.of(2024, 11, 12));
		Registro r4 = new Registro("Andrea", LocalDate.of(2024, 11, 4));
		Registro r5 = new Registro("Pedro", LocalDate.of(2024, 11, 12));
		
		LinkedList<Registro> listaRegistros = new LinkedList<Registro>();
		Collections.addAll(listaRegistros, r1,  r2, r3, r4, r5);
		
		//COLECCIÓN DE USUARIOS CON ACCESO DESDE 10/11/24 HASTA FECHA ACTUAL
		System.out.println("Colección usuarios con acceso a partir de 10/11/24:");
		HashSet<String> listaUsuarios = new HashSet<String>();
		listaRegistros.stream().filter(r -> r.entrada().isAfter(LocalDate.of(2024, 11, 10))).forEach(r -> listaUsuarios.add(r.usuario()));
		System.out.println(listaUsuarios);
		
		//NOMBRE USUARIOS CON ACCESO 12/11/24 ORDEN ALFABETICO INVERSO (REVERSED())
		System.out.println("Usuarios con acceso el día 12/11/24 en orden alfabeticmente inverso. Opción 1:");
		listaRegistros.stream().filter(r -> r.entrada().equals(LocalDate.of(2024, 11, 12)))
		.sorted(Comparator.comparing(Registro::usuario).reversed())
		.forEach(r -> System.out.println(r));
		
		//PODEMOS HACER USO DE MAP PARA TRABAJAR CON LOS NOMBRES DIRECTAMENTE Y NO CON LOS REGISTROS ENTEROS:
		System.out.println("Usuarios con acceso el día 12/11/24 en orden alfabeticmente inverso. Opción 2:");
		listaRegistros.stream().filter(r -> r.entrada().equals(LocalDate.of(2024, 11, 12)))
		.map(r -> r.usuario())
		.sorted(Comparator.reverseOrder())  // NO PUEDO USAR R.USUARIO() PORQUE DEPUÉS DE MAP SE TRABAJA CON STRINGS, NO REGISTROS
		.forEach(u -> System.out.println(u));
		
		// CONTEO DE ACCESOS ENTRE 4/11/24 Y 11/11/24
		System.out.println("Conteo accesos entre 4/11/24 y 11/11/24");
		long numAccesos = listaRegistros.stream()
				.filter(r->!r.entrada().isAfter(LocalDate.of(2024, 11, 11)) &&
						   !r.entrada().isBefore(LocalDate.of(2024, 11, 4)))
				.count();
		System.out.println("Hay " + numAccesos + " accesos entre el 4 y el 11 de noviembre");
		
		//MOSTAR REGISTROS ENTRE 4/11/24 Y 11/11/24 ORDENADOS POR FECHA Y SI HAY EMPATE, ORDENADO ALFABAETICAMENTE POR NOMBRE DE USUARIO
		System.out.println("Registros entre 4/11 y 11/11 ordenados por fecha y nombre de usuario en caso de empate");
		listaRegistros.stream()
		.filter(r->!r.entrada().isAfter(LocalDate.of(2024, 11, 11)) &&
				   !r.entrada().isBefore(LocalDate.of(2024, 11, 4)))
		.sorted(Comparator.comparing(Registro::entrada)
		.thenComparing(Registro::usuario))			//  --------- THENCOMPARING VA DENTRO DEL PARÉNTESIS DEL SORTED --------------
		.forEach(r -> System.out.println(r));
				
		//COMPROBAR SI HAY REGISTROS EL 4/11
		boolean existe = listaRegistros.stream()
		.anyMatch(r -> r.entrada().equals(LocalDate.of(2024, 11, 4)));   //AnyMatch // LO MISMO QUE UN FILTER PERO PARA 
		System.out.println("Existen accesos el 4/11 ?: " + existe);					// UNA VARAIBLE BOOLEANA
		

	}
	
	
}
