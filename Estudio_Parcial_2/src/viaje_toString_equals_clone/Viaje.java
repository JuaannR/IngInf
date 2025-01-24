package viaje_toString_equals_clone;
import java.time.LocalDate;
import java.util.ArrayList;
import java.util.Objects;
import java.util.UUID;

public class Viaje implements Cloneable{
	protected static final int PLAZAS_OFRECIDAS_POR_DEFECTO = 1;
	private static final int PLAZAS_A_RESERVAR = 1;
	
	private final String codigoViaje;
	private final String propietario;
	private final String coche;
	private final String ruta;
	private LocalDate fechaSalida;
	private final int numPlazasOfrecidas;
	protected ArrayList<Reserva> listaReservas;
	//private int numPlazasReservadas;	-> tamañoArrayList
	//private int numPlazasDisponibles;	-> plazasOfrecidas - plazasReservadas
	
	public Viaje(String propietario, String coche, String ruta, LocalDate fechaSalida, int numPlazasOfrecidas) {
		this.codigoViaje = UUID.randomUUID().toString();
		this.propietario = propietario;
		this.coche = coche;
		this.ruta = ruta;
		this.fechaSalida = fechaSalida;
		this.numPlazasOfrecidas = numPlazasOfrecidas;
		this.listaReservas = new ArrayList<>();
	}
	
	public Viaje(String propietario, String coche, String ruta, LocalDate fechaSalida) {
		this(propietario, coche, ruta, fechaSalida, PLAZAS_OFRECIDAS_POR_DEFECTO);
	}
	
	public String getCodigoViaje() {
		return codigoViaje;
	}
	
	public String getPropietario() {
		return propietario;
	}
	
	public String getCoche() {
		return coche;
	}
	
	public String getRuta() {
		return ruta;
	}
	
	public LocalDate getFechaSalida() {
		return fechaSalida;
	}
	
	public int getNumPlazasOfrecidas() {
		return numPlazasOfrecidas;
	}
	
	public ArrayList<Reserva> getListaReservas() {
		return new ArrayList<Reserva>(listaReservas);
	}
	
	public int getNumPlazasReservadas() {
		int plazas = 0;
		for (Reserva reserva : listaReservas) {
			plazas = plazas + reserva.getNumPlazas();
		}
		return plazas;
	}
	
	public int getNumPlazasDisponibles() {
		return getNumPlazasOfrecidas() - getNumPlazasReservadas();
	}
	
	public Reserva reservar(String usuario, int numPlazas) {
		boolean haReservado = false;		//para comprobar si el usuario ya ha reservado
		for (Reserva reserva : listaReservas) {
			if (reserva.getUsuario().equals(usuario)) {	//Para comparar cadenas, usar .equals en vez de ==
				haReservado = true;
			}
		}
		
		if((haReservado) || (numPlazas > getNumPlazasDisponibles()) || (LocalDate.now().isAfter(getFechaSalida()))) {
			return null;
		} else {
			Reserva reserva = new Reserva(usuario, numPlazas, codigoViaje);	//codigoViaje de la clase Viaje, no Reserva
			listaReservas.add(reserva);
			return reserva;
		}
	}
	
	public Reserva reservar(String usuario) {
		return reservar(usuario, PLAZAS_A_RESERVAR);
	}
	
	public Reserva consultaReserva(String usuario) {
		for (Reserva reserva : listaReservas) {
			if (reserva.getUsuario().equals(usuario)) {
				return reserva;
			}
		}
		return null;
	}
	
	@Override
	public String toString() {
		return "Viaje: {Codigo de viaje: " + codigoViaje + 
				", Propietario: " + propietario + 
				", Coche: " + coche + 
				", Ruta: " + ruta + 
				", Fecha Salida: " + fechaSalida+
				", Plazas ofrecidas: " + numPlazasOfrecidas + 
				", Lista reservas del viaje: " + listaReservas +
				"}";
	}
	
	@Override 
	public boolean equals(Object obj) {
		if (this == obj) return true;	//Misma referencia -> Son iguales //ESTAS DOS LINEAS SIEMPRE SON ASI
		if(obj == null || getClass() != obj.getClass()) return false;	//Objeto es null (no puede serlo) o son de diferente clase 
		
		//Conversion a la clase object
		Viaje other = (Viaje) obj;	//Como cuando el instanceof. Other es un nombre que ponemos nosotros
		
		//ahora hay que comprobar si las caracteristicas de dos objetos son iguales. No hace falta todas, solo las importantes
		return codigoViaje.equals(other.codigoViaje) &&		//Usamos equals() para comparar cadenas
				propietario.equals(other.propietario) &&
				coche.equals(other.coche) &&
				ruta.equals(other.ruta) &&
				fechaSalida.equals(other.fechaSalida) &&
				numPlazasOfrecidas == other.numPlazasOfrecidas;		//Usamos == par comparar enteros
	}
	
	//Para complementar equals(), es necesario la funcion hashCode, 
	//esta es como una funcion de dispersion, para distribuir objetos de forma eficiente
	//Siempre es asi -> Y en el parentesis se meten los atributos que se utilizan en el return de equals().
	
	@Override
	public int hashCode() {
		return Objects.hash(codigoViaje, propietario, coche, ruta, fechaSalida, numPlazasOfrecidas);
	}
	
	//Para la copia, usaremos la copia superficial
	//Primero declaramos el metodo auxiliar, que sera private, pues unicamente lo usara el metodo clone()
	
	private Viaje copiaSuperficial() {
		try {
			Viaje copiaSuperficial = (Viaje) super.clone();
			return copiaSuperficial;
		}
		catch(CloneNotSupportedException e) {
			System.err.println("La clase no es cloneable");
		}
		return null;
	}
	
	//Ahora el metodo clone en si
	@Override
	public Viaje clone() {
		Viaje copia = copiaSuperficial();
		copia.listaReservas = new ArrayList<Reserva>(listaReservas);
		return copia;
	}
	
}
