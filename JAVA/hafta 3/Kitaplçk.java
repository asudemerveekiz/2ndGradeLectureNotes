package hafta03;

import java.util.ArrayList;

public class Kitaplık {
	ArrayList<Raf> raf;
	
	public Kitaplık(int rafsayi) {
		raf = new ArrayList<Raf>();
		for (int i = 0; i < rafsayi; i++) {
			raf.add(i,new Raf());
		}
	}
	public void kitapEkle(Kitap ktp) {
		raf.get(ktp.getRafNo()).KitapEkle(ktp);
	}
	public Kitap kitapSil(Kitap kitap){
		return raf.get(kitap.getRafNo()).kitapSil(raf.get(kitap.getRafNo()).kitaplar.indexOf(kitap));
	}
	
	public void gosterRaf(int rafno) {
		System.out.println(rafno + ". Raftaki Kitaplar...\nKitap Adı\t\t\tYazar\t\tISBN");
		for(int i = 0; i < raf.get(rafno).kitaplar.size(); i++){
			System.out.println(raf.get(rafno).kitaplar.get(i).getKitapAd()+"\t"+raf.get(rafno).kitaplar.get(i).getYazar()+"\t"+raf.get(rafno).kitaplar.get(i).getISBN());
		}
		System.out.println("\n\n");
	}
}
