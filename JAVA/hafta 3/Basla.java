package hafta03;

public class Basla {

	public static void main(String[] args) {
		int rafsayisi = 5;
		Kitaplık kitaplik = new Kitaplık(rafsayisi);
		Kitap ktp1, ktp2, ktp3;

		ktp1 = new Kitap("Pera Palas'ta Gece Yarısı", "Charles King", "978-605-105-148-2",1, 1);
		ktp2 = new Kitap("Ali Emîrî'nin İzinde ", "M. Serhan Tayşi","978-975-263-956-0", 1, 0);
		ktp3 = new Kitap("Bir Türk Ailesinin Öyküsü", "İrfan Orga", "978-975-289-567-6", 2,2);
		
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
