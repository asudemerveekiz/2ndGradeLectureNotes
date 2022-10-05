package calisma;

public class Employee {
	protected String isim;
	protected String soyisim;
	protected int izinGunu=14;
	protected double maas=2500;
	protected String bolum="Calisan";

	public Employee(String isim, String soyisim) {
		this.isim=isim;
		this.soyisim=soyisim;
	}
	
	public String profil() {
		String profil;
		profil="Isim Soyisim->"+ isim+" "+ soyisim+"\n-> Bölüm: " + bolum + "\n-> İzin Günü: "+ izinGunu +" Gün" + "\n-> Maaş: " + maas +" TL";
		return profil;
	}

	public String getIsim() {
		return isim;
	}

	public void setIsim(String isim) {
		this.isim = isim;
	}

	public String getSoyisim() {
		return soyisim;
	}

	public void setSoyisim(String soyisim) {
		this.soyisim = soyisim;
	}

	public int getIzinGunu() {
		return izinGunu;
	}

	public void setIzinGunu(int izinGunu) {
		this.izinGunu = izinGunu;
	}

	public double getMaas() {
		return maas;
	}

	public void setMaas(double maas) {
		this.maas = maas;
	}

	public String getBolum() {
		return bolum;
	}

	public void setBolum(String bolum) {
		this.bolum = bolum;
	}
	
	
	
	
}
