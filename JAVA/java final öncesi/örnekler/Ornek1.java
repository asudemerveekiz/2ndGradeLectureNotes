package exceptions;

public class Ornek1 {

	public static void main(String[] args) {
		int a = 1;
		int b[] = new int[5];
		
		try {
			//a = a / 0;
			b[10] = a;
		}catch (ArrayIndexOutOfBoundsException aiobe) {
			aiobe.printStackTrace();
			System.out.println("dizi sınırı aşıldı");
			b[b.length-1] = 3;
			
		}catch (ArithmeticException ae) {
			//ae.printStackTrace();
			System.out.println("sıfıra bölmeye çalışıldı");
			a = 2;
			
		}catch (Exception e) {
			e.printStackTrace();
		}
		
		a = a * 5;
		System.out.println("a'nin son degeri: " + a);
		System.out.println("b dizisi son elemanın değeri: " + b[b.length-1]);
		
	
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
	}

}
