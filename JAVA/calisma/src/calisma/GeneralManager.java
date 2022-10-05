package calisma;

public class GeneralManager extends Employee{
	
	private int yas;
	
	public int getYas() {
		return yas;
	}
	public void setYas(int yas) {
		this.yas = yas;
	}
	public GeneralManager(String isim, String soyisim,int yas) {
		super(isim,soyisim);
		this.yas=yas;
	
	}
	public String profil() {
		String profil="Isim Soyisim->"+ isim+" "+ soyisim+"\n-> Bölüm: " + bolum + "\n-> İzin Günü: "+ izinGunu +" Gün" + "\n-> Maaş: " + maas +" TL"+"\n-> Yaş: "+yas ;
		return profil;
	}
	
		
}
