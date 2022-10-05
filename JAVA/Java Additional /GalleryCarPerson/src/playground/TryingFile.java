package playground;

public class TryingFile {
	
	private int c,d;
	
	
	public static void main(String[] args) {
		TryingFile tryingFile=new TryingFile();
		tryingFile.deneme1();
		
	}
	
	public void deneme1() {
		 int a=3;
		 int b=5;
		 System.out.println("a:"+a+"b:"+b);
		 vol1(a,b);
		 System.out.println("a:"+a+"b:"+b);
		 c=2;
		 d=4;
		 System.out.println("c:"+c+"d:"+d);
		 vol2();
		 System.out.println("c:"+c+"d:"+d);
		 
	}
	
	public void vol1(int x,int y) {
		int tmp;
		tmp=x;
		x=y;
		y=tmp;
	}
	
	public void vol2() {
		int tmp=c;
		c=d;
		d=tmp;
	}
	
}
