package hafta03;

public class Basla {

	public static void main(String[] args) {
		int rafsayisi = 5;
		Kitapl�k kitaplik = new Kitapl�k(rafsayisi);
		Kitap ktp1, ktp2, ktp3;

		ktp1 = new Kitap("Pera Palas'ta Gece Yar�s�", "Charles King", "978-605-105-148-2",1, 1);
		ktp2 = new Kitap("Ali Em�r�'nin �zinde ", "M. Serhan Tay�i","978-975-263-956-0", 1, 0);
		ktp3 = new Kitap("Bir T�rk Ailesinin �yk�s�", "�rfan Orga", "978-975-289-567-6", 2,2);
		
		kitaplik.kitapEkle(ktp1);
		kitaplik.kitapEkle(ktp2);
		kitaplik.kitapEkle(ktp3);
		kitaplik.gosterRaf(0);
		kitaplik.gosterRaf(1);
		kitaplik.kitapSil(ktp1);
		kitaplik.gosterRaf(1);
		kitaplik.gosterRaf(2);
		
	}

}
