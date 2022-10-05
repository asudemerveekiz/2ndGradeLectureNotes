package exceptions;

public class Ornek3 {

	public static void main(String[] args) {
		int age = 13;
		
		if(age < 18) { 
			throw new ArithmeticException("Not valid");  
			
		}else{
			System.out.println("Welcome to vote");  
		    System.out.println("Rest of the code");  
		}  
		
		System.out.println("devam.."); 
	}
}
