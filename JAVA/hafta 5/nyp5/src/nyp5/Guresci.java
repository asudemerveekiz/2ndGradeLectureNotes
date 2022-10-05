package nyp5;

public class Guresci extends MilliSporcu {
	private String siklet;
	private int toplamSaat;
	private int galibiyet;
	private int beraberlik;
	private int maglubiyet;
	
	
	
	   public Guresci(String siklet, int toplamSaat, String isim, char cinsiyet, String dogumTarihi, int sporcuNo) {
	        super(isim, cinsiyet, dogumTarihi, sporcuNo);
	        this.siklet = siklet;
	        this.toplamSaat = toplamSaat;
	    }
	
	public String SporcuProfili() {
		String profil;
		profil="Merhaba ben "+ super.sporcuNo+" numarali Milli Guresciyim." +this.siklet +"sikletinde guresiyorum.Toplam " +this.galibiyet+ "galibiyetim var.";
		return profil;
	}

	public String getSiklet() {
		return siklet;
	}

	public void setSiklet(String siklet) {
		this.siklet = siklet;
	}

	public int getToplamSaat() {
		return toplamSaat;
	}

	public void setToplamSaat(int toplamSaat) {
		this.toplamSaat = toplamSaat;
	}

	public int getGalibiyet() {
		return galibiyet;
	}

	public void setGalibiyet(int galibiyet) {
		this.galibiyet = galibiyet;
	}

	public int getBeraberlik() {
		return beraberlik;
	}

	public void setBeraberlik(int beraberlik) {
		this.beraberlik = beraberlik;
	}

	public int getMaglubiyet() {
		return maglubiyet;
	}

	public void setMaglubiyet(int maglubiyet) {
		this.maglubiyet = maglubiyet;
	}
	
}
