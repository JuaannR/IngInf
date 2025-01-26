package basicoGenericidad;
import java.util.ArrayList;
import java.util.List;

public class GestorElementos <T> {
	public static final int UNO = 1;
	private List<T> lista;
	
	public GestorElementos() {
		this.lista = new ArrayList<T>();
	}
	
	public void agregarElemento(T elemento) {
		lista.add(elemento);
	}
	
	public int obtenerTamano() {
		return lista.size();
	}
	
	public T obtenerElementoIndice(int indice) {
		return lista.get(indice-1);
	}
	
	public void eliminarElementoIndice(int indice) {
		lista.remove(indice-1);
	}
	
	public void mostrarElementosListaParrafo() {
		for (T elemento : lista) {
			System.out.println(elemento);
		}
	}
	
	public void mostrarElementosListaLinea() {
		for (int i=0; i<lista.size(); i++) {
			System.out.print(lista.get(i));
			if (i<lista.size()-UNO) {
				System.out.print(", ");
			}
		}
		System.out.println();
	}
}
