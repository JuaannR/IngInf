package enero24;

import java.time.LocalDate;
import java.util.ArrayList;
import java.util.List;
import java.util.Map;
import java.util.Scanner;
import java.util.Collections;
import java.util.LinkedList;

public class Programa {
	private final static int TRES = 3;
	
	public static void main(String[] args) {
	
	Video video1 = new Video(LocalDate.of(2017, 1, 7), "ST:Disco", 1, 1, 5, Clasificacion.ADULTOS);
	Video video2 = new Video(LocalDate.of(2024, 1, 1), "ST:Disco", 2, 2, 1, Clasificacion.DESDE_12_ANYOS);
	Video video3 = new Video(LocalDate.of(2024, 1, 5), "ST:Disco", 2, 1, 2, Clasificacion.DESDE_7_ANYOS);
	Video video4 = new Video("ST:Gen", 1, 1);
	Video video5 = new Video("ST:Gen", 1, 2);
	
	List<Video> listaVideos = new ArrayList<Video>();
	Collections.addAll(listaVideos, video1, video2, video3, video4, video5);
	

	
	// STREAMS
	long contador =listaVideos.stream()
	.filter(v -> v.getNombreSerie().equals("ST:Disco"))
	.count();
	
	System.out.println("Hay " + contador + " videos de ST:Disco");
	
	
	List<String> listaSeriesMasDeUnaTemporada = new LinkedList<String>();
	
	System.out.println("Series con +2 temporadas: ");
	listaVideos.stream()
	.filter(v -> v.getTemporada() >= 2)
	.map(v -> v.getNombreSerie())
	.sorted()
	.distinct()	//ELIMINA REPETIDOS
	.forEach(v -> listaSeriesMasDeUnaTemporada.add(v));
	
	System.out.println(listaSeriesMasDeUnaTemporada);
	
	
	System.out.println("Ahora creando la lista con el stream: ");
	List<String> series = listaVideos.stream()
						.filter(v -> v.getTemporada() >= 2)
						.map(v -> v.getNombreSerie())
						.sorted()
						.distinct()
						.toList();
	System.out.println(series);
	
	// EJ 5
	Scanner scanner = new Scanner(System.in);
	int intentos = 0;
	int anyo = 0;
	boolean anyoValido = false;
	
	while (intentos < TRES && !anyoValido) {
		System.out.print("Introduce el año: ");
		String entrada = scanner.nextLine();
	
	try {
		anyo = Integer.parseInt(entrada);
		anyoValido = true;
	} catch (NumberFormatException e) {
		System.out.println("El dato introducido no es un año válido. Por favor, introduce un número entero.");
        intentos++;
	}
}
	//FILTRADO VIDEOS DE ESE AÑO
	if (anyoValido) {
		final int anyoFinal = anyo;	// HACEMOS LA VARIABLE FINAL PARA QUE NO DE ERROR
		listaVideos.stream()
		.filter(v -> v.getFechaPrimeraEmision().getYear() == anyoFinal)
		.forEach(v -> System.out.println(v));
		} else {
			System.out.println("No se ha introducido un año válido después de 3 intentos.");
		}
	scanner.close();

	// EJ 6 : UTIL EJEMPLO COLECCION VIDEO CLASIFICADOS POR EDAD	
	System.out.println("Clasificación vídeos por edad: ");
	Map<Clasificacion, List<Video>> clasificadosPorEdad = Util.clasificar(listaVideos, Video::getClasificacion);
	
	clasificadosPorEdad.forEach((clasificacion, lista) -> {
		System.out.println("Clasificacion: " + clasificacion);
		lista.forEach(video -> System.out.println(" - " + video.getIdentificador()));
	});
	 
	}
}
