package parcial2_ej1;
import java.time.LocalDate;
import java.util.LinkedList;

public class Main {
	public static void main(String[] args) {
	
	LinkedList<Agenda> agendas = new LinkedList<Agenda>();
	
	AgendaPersonal agenda1 = new AgendaPersonal();
	agenda1.addTarea(new Tarea("Tarea 1", LocalDate.now()));
    agenda1.addTarea(new Tarea("Tarea 2", LocalDate.now().plusDays(1)));
    agenda1.setUrgente(new Tarea("Tarea 1", LocalDate.now()));
	
    
    AgendaPersonal agenda2 = new AgendaPersonal();
    agenda2.addTarea(new Tarea("Tarea 3", LocalDate.now()));

    agendas.add(agenda1);
    agendas.add(agenda2);
    
    for (Agenda agenda : agendas) {
    	if (agenda instanceof AgendaPersonal) {
    		AgendaPersonal agendapersonal = (AgendaPersonal) agenda;
    		System.out.println("Tareas urgentes de las Agendas Personales: " + agendapersonal.getUrgente());
    	}
    }
    
    
    
	}

}
