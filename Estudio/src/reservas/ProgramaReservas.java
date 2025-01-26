package reservas;
import java.time.LocalDate;

public class ProgramaReservas {
	
	public static void main(String[] args) {
	
	SalaReunion sala1 = new SalaReunion("Sala 101", 10);
	SalaReunion sala2 = new SalaReunion("Sala 102");
	
	LocalDate manana = LocalDate.now().plusDays(1);
	LocalDate mes = LocalDate.now().plusMonths(1);
	
	
	sala1.reservar(manana, "videollamada");
	sala1.reservar(mes, "negocios");
	
	sala2.reservar(manana, "conferencia");
	sala2.reservar(manana, "videollamada");
	
	sala1.getListaReservas();
	sala2.getListaReservas();
	
	sala1.cancelar(manana);
	sala1.getListaReservas();
	}
}
