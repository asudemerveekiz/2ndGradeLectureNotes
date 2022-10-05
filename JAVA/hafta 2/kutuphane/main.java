package kutuphane;

import java.util.Scanner;

public class main {
	public static void main(String[] args) {
		int rafSayisi=5;
		Kitaplik kitaplik=new Kitaplik(rafSayisi);
		Kitap ktp1,ktp2,ktp3;
		
		ktp1 =new Kitap("Serenad","livaneli","123",1,1);
		ktp2 =new Kitap("kitap2","livaneli","124",1,0);
		ktp3 =new Kitap("DEnme","livaneli","125",2,2);

		
		kitaplik.kitapEkle(ktp1);
		kitaplik.gosterRaf(0);
		
		Scanner giris = new Scanner (System.in);
		int no;
		
		do {
			System.out.println(raf numarasını gir);
			no=giris.nextInt();
		}while(!kitaplik.rafKontrol(no));
	}

}
