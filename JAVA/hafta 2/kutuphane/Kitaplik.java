package kutuphane;

public class Kitaplik {
	Raf raf[];
	public Kitaplik(int rafSayisi) {
		raf =new Raf[rafSayisi];
		for (int i = 0; i < rafSayisi; i++) {
			raf[i] = new Raf();
		}
	}
	public void kitapEkle(Kitap ktp) {
		raf[ktp.getRafNo()].kitapEkle(ktp);
	}
	public Kitap kitapSil(Kitap ktp) {
		return raf[ktp.getRafNo()].kitapSil(raf[ktp.getRafNo()].kitaplar.lastIndexOf(ktp));
		//return raf[ktp.getRafNo()].kitapSil(ktp)
	}
	public Kitap kitapAra(String kitapIsmı) {
		for (int i = 0; i < raf.length; i++) {
			for (Kitap kitap : raf[i].kitaplar) {
				if(kitap.getKitapAd().compareTo(kitapIsmı)==0) {
					return kitap;
				}
			}
		}
		
		
		return null;
		
	}
	public boolean rafKontrol(int rafNo) {
		if(raf[rafNo]==null) {
			return false;
		}
		else {
			return true;
		}
	
	}
	
	public void gosterRaf(int rafNo) {
		System.out.println(rafNo + " Raftaki Kitaplar \n kitap Adı \t Yazar \t ISBN : ");
		for (int i = 0; i < raf[rafNo].kitaplar.size(); i++) {
			System.out.println(raf[rafNo],kitaplar.get(i).getK));
		}
		
	
	}
	
	
	
}
