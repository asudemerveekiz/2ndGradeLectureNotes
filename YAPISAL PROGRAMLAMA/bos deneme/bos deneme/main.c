#include <stdio.h>
#include <stdlib.h>
// polinom= a1*x^(n)+a2*x^(n-1)+a3*x^(n-2)+......+an*x^(0)
typedef struct polinom{
    int derece;
    double katsayi;
   
}POLINOM;// boyle yaparsak hem struct diyerek hem de demeksizin tanımlama yapabiliriz.
  
int main(){
    int N;
    int i;
    printf("Polinomunuz kac elemanli olacak?:\n");
    scanf(" %d", &N);
    POLINOM *pol=(POLINOM *)malloc(N*sizeof(POLINOM));
    //dot operatoruyle deger alimi
    for (i=0; i<N; i++) {
        printf("Pol[%d] nin katsayisi: \n", i+1);
        scanf(" %lf", &(pol[i].katsayi));
        printf("Pol[%d] nin derecesi: \n", i+1);
        scanf(" %d", &(pol[i].derece));
    }
    
    
    //N-1 e kadar yazdirim (+ bozmasın diye) (dot operatoru ile)
    for (i=0; i<N-1; i++) {
        printf("%2.2lf X ^", pol[i].katsayi);
        printf(" %d + ", pol[i].derece);
    }
    //son eleman yazdiriliyor (dot operatoru ile)
    printf("%2.2lf X ^", pol[N-1].katsayi);
    printf("%d", pol[N-1].derece);
    
    //arrow ile deger alimi
    printf("\n");
    for (i=0; i<N; i++) {
        printf("Pol[%d] nin katsayisi: \n", i+1);
        scanf("%lf", &((pol+i)->katsayi));
        printf("Pol[%d] nin derecesi: \n", i+1);
        scanf(" %d", &((pol+i)->derece));
    }
    //+ isareti bozmasin diye son elemana kadar olan kısım yazdırılıyor (arrow operetru ile)
    for (i=0; i<N-1; i++) {
        printf("%2.2lf X ^", (pol+i)->katsayi);
        printf(" %d +", (pol+i)->derece);
    }
    //son eleman yazdırılıyor (arrow operatoru ile)
    printf("%2.2lf X ^", (pol+N-1)->katsayi);
    printf("%d", (pol+N-1)->derece);
    
    
 
   
    

    
    return 0;
}
// dot ve arrow operatörleri
//dot:
//yapı_turunden_nesne.yapı_turunden_eleman
//arrow:
//yapı_turunde_pointer_nesne->yapı_turunden_eleman


/* POLINOM p1;
POLINOM *p2;
POLINOM **p3;
POLINOM p4[10];
POLINOM *p5[10];
POLINOM p6[4][7];

p1.katsayi=3.6;
p1.derece=2;

p2=&p1;
p3=&p2;

//dot operatoruyle erisim
printf("Derece: %d, Katsayi:%2.2lf\n",p1.derece,p1.katsayi);
printf("Struct adres: %p, derece adres:%p, katsayi adres: %p \n",&p1,&p1.derece,&p1.katsayi);
printf("Struct adres: %p, derece adres:%p, katsayi adres: %p \n",&p1,&p2->derece,&p2->katsayi);
printf("Struct adres: %p, derece:%d, katsayi: %2.2lf \n",&p1,(*p2).derece,(*p2).katsayi);
//decimal bi seyi %p ile yazdirmaya calisirsan hexadecimal yazıyor burda ornegi yok da soylemek istedim
printf("Struct adres: %p, derece adres:%p, katsayi adres: %p \n",&p1,&(*p2).derece,&(*p2).katsayi);
printf("\nDerece giriniz: ");
scanf(" %d",&p1.derece);
printf("Katsayi giriniz: ");
scanf(" %lf",&p1.katsayi);
printf("Derece: %d Katsayi:%2.2lf\n",p1.derece,p1.katsayi);
(*p2).derece=60;
p2->katsayi=44;
printf("Derece: %d Katsayi:%2.2lf\n",p1.derece,p1.katsayi);

//arrow operatoruyle erisim
printf("\nDerece giriniz: ");
scanf(" %d",&p2->derece); //& koymamız gerekiyor çünkü p2 bir adres ama p2->derece diyince bir deger oldu ve scanfte deger degil adres koymalısın virgulden sonra
printf("Katsayi giriniz: ");
scanf(" %lf",&p2->katsayi);
printf("Derece: %d Katsayi:%2.2lf\n",p2->derece,p2->katsayi);
 
 
*/
