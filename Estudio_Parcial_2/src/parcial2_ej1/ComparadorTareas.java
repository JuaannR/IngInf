package parcial2_ej1;
import java.util.Comparator;

public class ComparadorTareas implements Comparator<Tarea> {
	//ordenamos por fecha
	@Override
	public int compare(Tarea t1, Tarea t2) {
		if (!t1.tienePlazo() && !t2.tienePlazo()) {
			return 0; //son iguales en cuanto a plazo -> no tienen
		}
		
		if (!t1.tienePlazo()) { //t1 no plazo y t2 si plazo
			return 1; //t1 > t2 en la comparacion. Tarea sin plazo es posterior a una con plazo
		}
		
		if (!t2.tienePlazo()) {  //t1 plazo y t2 no plazo
			return -1; //t1 < t2 en la comparacion. Tarea sin plazo es posterior a una con plazo
		}
		
		return t1.plazo().compareTo(t2.plazo());
	}
	//Si t1 es mayor que t2 -> return 1 -> t1 va despues de t2 en la lista
	//Si t1 es menor que t2 -> return -1 -> t1 va delante de t2 en la lista
}

/*
t1: Tiene un plazo del 1 de enero de 2024.
t2: Tiene un plazo del 5 de enero de 2024.
compare(t1, t2)
como t1 < t2, devuelve -1. Esto indica que t1 va antes que t2 en la lista
*/