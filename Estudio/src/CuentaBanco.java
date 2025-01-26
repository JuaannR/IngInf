public class CuentaBanco {

	private double saldo;
	
	//Método para inicializar una cuenta con saldo -> dinero
	public CuentaBanco(double dinero) {
		saldo = dinero;
	}
	
	//Método para inicializar una cuenta con un saldo por defecto
	public CuentaBanco() {
		saldo = 1000;
	}
	
	public double getSaldo() {
		return saldo;
	}
	
	public void ingresoSaldo(double ingreso) {
		saldo = saldo + ingreso;
	}

	public void retirarSaldo(double retiro) {
		if (retiro > saldo) {
			System.out.println("No hay dinero suficiente en la cuenta.");
		} else {
			saldo = saldo - retiro;
		}
	}
	
	//cb1 hace la transferencia a cb2
	public static void transferirSaldo(CuentaBanco cb1, CuentaBanco cb2, double transferencia) {
		if (transferencia > cb1.saldo) {
			System.out.println("No hay dinero suficiente para realizar la transferencia.");
		} else {
			cb1.saldo = cb1.saldo - transferencia;
			cb2.saldo = cb2.saldo + transferencia;
		}
	}
	
	//Comparar saldos entre cuentas
	public static double compararSaldo(CuentaBanco cb1, CuentaBanco cb2) {
		if(cb1.saldo > cb2.saldo) {
			return cb1.saldo;
		} else {
			return cb2.saldo;
		}
	}
	
	public static void main(String[] args) {
		//Declaramos variables
		CuentaBanco cb1,cb2;
		//Creamos cuentas con x saldo
		cb1 = new CuentaBanco(4000);	//utilizamos 1º constructor
		cb2 = new CuentaBanco();		//utilizamos 2º constructor con saldo por defecto, 1000
		
		//Creamos unos saldos random para no escribir tantos números
		double s1 = 1300;
		double s2 = 4890;
		double s3 = 2222;
		
		System.out.println("El saldo inical de cb2 es: " + cb2.getSaldo());
		cb2.ingresoSaldo(s1);	//Ingreso de 1300
		System.out.println("El saldo de cb2 después del ingreso es: " + cb2.getSaldo());
		
		System.out.println("El saldo inical de cb1 es: " + cb1.getSaldo());
		cb1.retirarSaldo(s3);	//Retiro de 2222
		System.out.println("El saldo de cb1 despuñes del retiro es: " +cb1.getSaldo());
		
		//Vamos a intentar sacar más dinero del que hay en cb1
		cb1.retirarSaldo(s2);
		System.out.println("El saldo de cb1 es: " +cb1.getSaldo());
		//Como no hay dinero suficiente se imprime que no se puede y el saldo de cb1 se queda igual
		
		//Vamos a transferir dinero de una cuenta a otra
		//Saldo de antes de la transeferencia
		System.out.println("Antes de la transferencia: ");
		System.out.println("El saldo de cb1 es: " +cb1.getSaldo());
		System.out.println("El saldo de cb2 es: " +cb2.getSaldo());
		transferirSaldo(cb1, cb2, s1);
		//Después de la transferencia de 1300
		System.out.println("Después de la transferencia de 1300: ");
		System.out.println("El saldo de cb1 es: " +cb1.getSaldo());
		System.out.println("El saldo de cb2 es: " +cb2.getSaldo());
		
		//Ahora comparamos los saldos de las cuentas usando el último método
		
		double saldoMax = compararSaldo(cb1,cb2);
		System.out.println("El saldo máximo de las dos cuentas es: " +saldoMax);

	}

}
