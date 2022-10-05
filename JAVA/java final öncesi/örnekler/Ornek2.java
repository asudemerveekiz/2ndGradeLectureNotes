package exceptions;

public class Ornek2 {

	public static void main(String[] args) {
		Integer data;
		
		try {
			data = null; // data=0 dene
			System.out.println(data.intValue());
		} catch (NullPointerException e) {
			
			System.out.println(e);
		}finally {
			System.out.println("\nHer zaman çalışır");
			data = 5;
		}
		
		System.out.println(data.intValue());
		
	}

}
