package examen2;

public class Main {
	
	public static void main(String[] args) {
		String p1 = "Juan Martinez";
		String p2 = "Pedro Lopez";
		String p3 = "Ana Abenza";
		String p4 = "Maria Gomez";
		String p5 = "Sergio Perez";
		String p6 = "Alejandro Perez";
	
	Encuesta encuesta1 = new Encuesta("¿Cambio de parcial al 13 de noviembre?", p1, p2, p3, p4, p5);
	
	encuesta1.responder(p1,"si");
	encuesta1.responder(p2,"quizas");
	encuesta1.responder(p3,"si");
	encuesta1.responder(p4,"no");
	encuesta1.responder(p6,"si");
	
	System.out.println(encuesta1.getPregunta());
	System.out.println(encuesta1.getIndiceParticipacion());
	
	System.out.println("si: " + encuesta1.recuento("si"));
	System.out.println("no: " + encuesta1.recuento("no"));
	System.out.println("quizas: " + encuesta1.recuento("quizas"));
	
	}
	
}
