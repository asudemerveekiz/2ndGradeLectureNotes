package kutuphane;

public class Kitap {
	
	private String yazar;
	private String ISBN;
	private int rafNo;
	private int sira;
	private String  kitapAd;
	public Kitap(String kitapAd, String yazar, String iSBN, int rafNo, int sira) {
		super();
		this.kitapAd = kitapAd;
		this.yazar = yazar;
		ISBN = iSBN;
		this.rafNo = rafNo;
		this.sira = sira;
	}
	public String getKitapAd() {
		return kitapAd;
	}
		
	public void setKitapAd(String isim) {
		kitapAd=isim;
	}
	public String getYazar() {
		return yazar;
	}
	public void setYazar(String yazar) {
		this.yazar = yazar;
	}
	public String getISBN() {
		return ISBN;
	}
	public void setISBN(String iSBN) {
		ISBN = iSBN;
	}
	public int getRafNo() {
		return rafNo;
	}
	public void setRafNo(int rafNo) {
		this.rafNo = rafNo;
	}
	public int getSira() {
		return sira;
	}
	public void setSira(int sira) {
		this.sira = sira;
	}
	
	
	
	
	
	
	
	
	}
	
}
