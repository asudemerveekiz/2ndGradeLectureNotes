package exceptions;


public class Example {

	public static void main(String[] args)  {
		
		
		
		try{
			
			int a= 5/0;
		
		}catch(ArithmeticException ae){
			
			System.out.println("aritmetik hata yakalandı.");
			
		}catch(Exception e) {
			
			System.out.println("hata yakalandı.");
			
		}
		
		
		System.out.println("kodun devamı..");
		
		
		
		
		
	
		
		
		
		
	}
}
