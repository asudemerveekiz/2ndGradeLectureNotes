package exceptions;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;

public class Ornek4{  
	   
		public static void main(String[] args) throws SQLException {
			
			/* throws keywordü ile metodun içinde ne tür bir exception olabileceğinin bilgisini veririz.      
			   Veritabanına bağlanmayı sağlayacak aşağıdaki satırı yazdığımızda ya try-catch bloğu oluşturmamız, ya da throws ile method isminden sonra exception ı belirtmemiz istenir. */       
			    
			
			Connection c=DriverManager.getConnection("url...");
			
			
		
		}
		
	    
	}