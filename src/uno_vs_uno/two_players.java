package uno_vs_uno;

import java.util.Scanner;

public class two_players {
	
	private static void printBoard(char[][] board) {
	System.out.println(board[0][0] + "|" + board[0][1] + "|" + board[0][2]);
	System.out.println("-+-+-");
	System.out.println(board[1][0] + "|" + board[1][1] + "|" + board[1][2]);
	System.out.println("-+-+-");
	System.out.println(board[2][0] + "|" + board[2][1] + "|" + board[2][2]);
	}
	
	private static void player1Turn(char[][] board, Scanner scanner) {
		System.out.println("Turno del jugador 1: ");
		boolean casillaValida = false;
		
		while(!casillaValida) {
			String userInput = scanner.nextLine();
			
			try {
			
		if (isValido(board, Integer.parseInt(userInput))) {
			casillaValida = true;
			
		switch(userInput) {
			case "1":
				board[0][0] = 'X';
				break;
			case "2":
				board[0][1] = 'X';
				break;
			case "3":
				board[0][2] = 'X';
				break;
			case "4":
				board[1][0] = 'X';
				break;
			case "5":
				board[1][1] = 'X';
				break;
			case "6":
				board[1][2] = 'X';
				break;
			case "7":
				board[2][0] = 'X';
				break;
			case "8":
				board[2][1] = 'X';
				break;
			case "9":
				board[2][2] = 'X';
				break;
			default:
				System.out.println("No es posible marcar la casilla " + userInput);
		}
		
		printBoard(board);
		} else {
			System.out.println("La casilla  " + userInput + " ya está marcada. Pruebe otra vez: ");
		}
		} catch(NumberFormatException e)	{
			System.out.println("Entrada no valida, por favor ingrese un número del 1 al 9");
		
		}
	}
}		
	
	private static void player2Turn(char[][] board, Scanner scanner) {
		System.out.println("Turno del jugador 2: ");
		boolean casillaValida = false;
		
		while (!casillaValida) {
			String userInput = scanner.nextLine();
		
		try {	
			
		if (isValido(board, Integer.parseInt(userInput))) {
			casillaValida = true;
		switch(userInput) {
			case "1":
				board[0][0] = 'O';
				break;
			case "2":
				board[0][1] = 'O';
				break;
			case "3":
				board[0][2] = 'O';
				break;
			case "4":
				board[1][0] = 'O';
				break;
			case "5":
				board[1][1] = 'O';
				break;
			case "6":
				board[1][2] = 'O';
				break;
			case "7":
				board[2][0] = 'O';
				break;
			case "8":
				board[2][1] = 'O';
				break;
			case "9":
				board[2][2] = 'O';
				break;
			default:
				System.out.println("No es posible marcar la casilla " + userInput);
		}
		
		printBoard(board);
	} else {
		System.out.println("La casilla  " + userInput + " ya está marcada. Pruebe otra vez: ");
		}
		
		} catch (NumberFormatException e) {
			System.out.println("Entrada no valida, por favor ingrese un número del 1 al 9");
		}
	}
}

	private static boolean isValido(char[][] board, int position) {
		switch(position) {
			case 1:
				return board[0][0] == ' ';
			case 2:
				return board[0][1] == ' ';
			case 3:
				return board[0][2] == ' ';
			case 4:
				return board[1][0] == ' ';
			case 5:
				return board[1][1] == ' ';
			case 6:
				return board[1][2] == ' ';
			case 7:
				return board[2][0] == ' ';
			case 8:
				return board[2][1] == ' ';
			case 9:
				return board[2][2] == ' ';
			default:
				return false;
		}
	}
	
	private static boolean isAcabado(char[][] board) {
		if ((board[0][0] == 'X' && board[0][1] == 'X' && board[0][2] == 'X') ||
			(board[1][0] == 'X' && board[1][1] == 'X' && board[1][2] == 'X') ||
			(board[2][0] == 'X' && board[2][1] == 'X' && board[2][2] == 'X') ||
			
			(board[0][0] == 'X' && board[1][0] == 'X' && board[2][0] == 'X') ||
			(board[0][1] == 'X' && board[1][1] == 'X' && board[2][1] == 'X') ||
			(board[0][2] == 'X' && board[1][2] == 'X' && board[2][2] == 'X') ||
			
			(board[0][0] == 'X' && board[1][1] == 'X' && board[2][2] == 'X') ||
			(board[0][2] == 'X' && board[1][1] == 'X' && board[2][0] == 'X'))	{
			System.out.println("Jugador 1 gana");
			return true;
		}
		
		if ((board[0][0] == 'O' && board[0][1] == 'O' && board[0][2] == 'O') ||
				(board[1][0] == 'O' && board[1][1] == 'O' && board[1][2] == 'O') ||
				(board[2][0] == 'O' && board[2][1] == 'O' && board[2][2] == 'O') ||
				
				(board[0][0] == 'O' && board[1][0] == 'O' && board[2][0] == 'O') ||
				(board[0][1] == 'O' && board[1][1] == 'O' && board[2][1] == 'O') ||
				(board[0][2] == 'O' && board[1][2] == 'O' && board[2][2] == 'O') ||
				
				(board[0][0] == 'O' && board[1][1] == 'O' && board[2][2] == 'O') ||
				(board[0][2] == 'O' && board[1][1] == 'O' && board[2][0] == 'O'))	{
				System.out.println("Jugador 2 gana");
				return true;
			}
		
		
		for (int i = 0; i < board.length; i++) {
			for (int j  = 0; j < board[i].length; j++) {
				if (board[i][j] == ' ') {
					return false;
				}
			}
		}
		printBoard(board);
		System.out.println("Empate!");
		return true;
	}
	
	public static void main(String[] args) {
		
		char[][] board = {	{' ', ' ', ' '},
							{' ', ' ', ' '},
							{' ', ' ', ' '}};
		
		Scanner scanner = new Scanner(System.in);
		printBoard(board);
		while (true) {
		
		player1Turn(board, scanner);
		
		if (isAcabado(board)) {
			break;
		}
		
		player2Turn(board, scanner);
		if (isAcabado(board)) {
			break;
		}
		
		}
		scanner.close();
	}

}
