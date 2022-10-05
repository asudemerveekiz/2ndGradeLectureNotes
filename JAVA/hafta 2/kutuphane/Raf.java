package kutuphane;

import java.util.ArrayList;

public class Raf {
	ArrayList<Kitap> kitaplar; //ARRAYLÝST OTOMATÝK KAYDIRMA VS YAPAR

	public Raf() {
		this.kitaplar=new ArrayList<>();
		
	}
	public void kitapEkle(Kitap ktp1) {
		this.kitaplar.add(ktp1);
	}
	public Kitap kitapSil(int index){
		Kitap=ktp2;
		ktp2=this.kitaplar.remove(index);
		return ktp2;
	}
		
	


}
