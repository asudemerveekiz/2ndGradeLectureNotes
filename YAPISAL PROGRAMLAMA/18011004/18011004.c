#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <stdlib.h>

typedef struct{
	int id;
	char unvan[15];
	char ad[20];
	char soyad[20];
}hoca;

typedef struct{
	int ogrNo;
	char ad[20];
	char soyad[20];
	int dersSay;
	int topKredi;
}ogr;

typedef struct{
	char dersKod[10];
	char dersAd[50];
	int kredi;
	int kontenjan;
	int hocaID;
}ders;

typedef struct{
	char dersID[10];
	int ogrID;
	char durum[10]; //aktif ya da b�rakt�
	char tarih[10]; //g�n.ay.y�l//�al��m�yor
}kayitlar;

void ogrKayit(){  
	FILE *fileP;
	ogr yenikayit;
	fileP=fopen("��renciler.txt","a");
	if(fileP==NULL){
		printf("dosya acilamadi");
	}
	printf("Ogrenci Numarasi:");
	scanf("%d",&yenikayit.ogrNo);
	printf("Ogrenci isim:");
	scanf("%s",yenikayit.ad);
	printf("Ogrenci soyisim:");
	scanf("%s",yenikayit.soyad);
	
	fprintf(fileP,"%d %s %s %d %d \n",yenikayit.ogrNo,yenikayit.ad,yenikayit.soyad,0,0);
	fclose(fileP);
}

void ogrSil(int num_to_del){  
	FILE *fileP;
	ogr *dizi;
	int cnt=0,i;
	char tmp;
	
	fileP=fopen("��renciler.txt","r");
	if(fileP==NULL){
		printf("dosya acilamadi");
	}
	for (tmp = getc(fileP); tmp != EOF; tmp = getc(fileP)){
		if (tmp == '\n'){
        	cnt++;
		}          
	} 
	rewind(fileP);
	dizi=(ogr*)malloc(cnt*sizeof(ogr));
    for(i=0;i<cnt;i++){
    	fscanf(fileP,"%d %s %s %d %d",&dizi[i].ogrNo,dizi[i].ad,dizi[i].soyad,&dizi[i].dersSay,&dizi[i].topKredi);
	}
	fclose(fileP);
	fileP=fopen("��renciler.txt","w");
	for(i=0;i<cnt;i++){
		if(dizi[i].ogrNo!=num_to_del){
			fprintf(fileP,"%d %s %s %d %d\n",dizi[i].ogrNo,dizi[i].ad,dizi[i].soyad,dizi[i].dersSay,dizi[i].topKredi);	
		}    	
	}
	free(dizi);
	fclose(fileP);
}


void ogrGuncelle(int num_to_update){  
	FILE *fileP;
	ogr *dizi;
	int cnt=0,i;
	char tmp;
	
	fileP=fopen("��renciler.txt","r");
	if(fileP==NULL){
		printf("dosya acilamadi");
	}
	for(tmp = getc(fileP); tmp != EOF; tmp = getc(fileP)){ //eleman say�c�
		if (tmp == '\n'){
        	cnt++;
		}          
	} 
	rewind(fileP);
	dizi=(ogr*)malloc(cnt*sizeof(ogr));
    for(i=0;i<cnt;i++){
    	fscanf(fileP,"%d %s %s %d %d",&dizi[i].ogrNo,dizi[i].ad,dizi[i].soyad,&dizi[i].dersSay,&dizi[i].topKredi);
	}
	fclose(fileP);
	fileP=fopen("��renciler.txt","w");
	for(i=0;i<cnt;i++){
		if(dizi[i].ogrNo!=num_to_update){
			fprintf(fileP,"%d %s %s %d %d\n",dizi[i].ogrNo,dizi[i].ad,dizi[i].soyad,dizi[i].dersSay,dizi[i].topKredi);	
		}else{
			printf("Yeni isim:");
			scanf("%s",dizi[i].ad);
			printf("Yeni soyisim:");
			scanf("%s",dizi[i].soyad);
			fprintf(fileP,"%d %s %s %d %d\n",dizi[i].ogrNo,dizi[i].ad,dizi[i].soyad,dizi[i].dersSay,dizi[i].topKredi);
		}	
	}
	free(dizi);
	fclose(fileP);
}

void ogrDersEkle(int ogrID){ 
	char dersID[10];
	FILE *fileP;
	ders secim;
	ogr *dizi;
	char IDtmp[10];
	char tmp;
	int cnt=0,i;
	
	printf("Eklemek istedi�iniz Dersin Kodunu Girin: ");
	scanf("%s",dersID);
	fileP=fopen("Dersler.txt","r");
	
	for (tmp = getc(fileP); tmp != EOF; tmp = getc(fileP)){
		if (tmp == '\n'){
        	cnt++;
		}          
	} 
	rewind(fileP);
	fscanf(fileP,"%s %s %d %d %d",secim.dersKod,secim.dersAd,&secim.kredi,&secim.kontenjan,&secim.hocaID);
	i=1;
	while(i<cnt && strcmp(dersID,secim.dersKod)!=0){
		fscanf(fileP,"%s %s %d %d %d",secim.dersKod,secim.dersAd,&secim.kredi,&secim.kontenjan,&secim.hocaID);
		i++;
	}
	if(strcmp(dersID,secim.dersKod)!=0){
		printf("B�yle bir ders bulunmamaktad�r.");
	}else{
		fclose(fileP);
		fileP=fopen("DersKay�tlar.txt","a");
		fprintf(fileP,"%d %s %s\n",ogrID,dersID,"kay�tl�");
	}
	fclose(fileP);
	cnt=0;
	fileP=fopen("��renciler.txt","r");
	for(tmp = getc(fileP); tmp != EOF; tmp = getc(fileP)){ //eleman say�c�
		if (tmp == '\n'){
        	cnt++;
		}          
	} 
	rewind(fileP);
	dizi=(ogr*)malloc(cnt*sizeof(ogr));
    for(i=0;i<cnt;i++){
    	fscanf(fileP,"%d %s %s %d %d",&dizi[i].ogrNo,dizi[i].ad,dizi[i].soyad,&dizi[i].dersSay,&dizi[i].topKredi);
	}
	fclose(fileP);
	fileP=fopen("��renciler.txt","w");
	for(i=0;i<cnt;i++){
		if(dizi[i].ogrNo==ogrID){
			dizi[i].topKredi+=secim.kredi;
			dizi[i].dersSay++;
		}
		fprintf(fileP,"%d %s %s %d %d\n",dizi[i].ogrNo,dizi[i].ad,dizi[i].soyad,dizi[i].dersSay,dizi[i].topKredi);
	}
	fclose(fileP);
	free(dizi);			
}



void ogrDersSil(int ogrID){  
	char dersID[10];
	FILE *fileP;
	ders secim;
	ogr *dizi2;
	kayitlar *dizi;
	char IDtmp[10];
	char tmp;
	int cnt=0,i,hold;
	
	printf("Silmek istedi�iniz Dersin Kodunu Girin: ");
	scanf("%s",dersID);
	
	fileP=fopen("Dersler.txt","r");
	for (tmp = getc(fileP); tmp != EOF; tmp = getc(fileP)){
		if (tmp == '\n'){
        	cnt++;
		}          
	} 
	for(i=0;i<cnt;i++){
		fscanf(fileP,"%s %s %d %d %d",secim.dersKod,secim.dersAd,&secim.kredi,&secim.kontenjan,&secim.hocaID);
		if(strcmp(dersID,secim.dersKod)==0){
			printf("%d",secim.kredi);
			hold=secim.kredi;  
			printf("%d",hold);
		}
	}
	fclose(fileP);
	fileP=fopen("DersKay�tlar.txt","r");
	cnt=0;
	for (tmp = getc(fileP); tmp != EOF; tmp = getc(fileP)){
		if (tmp == '\n'){
        	cnt++;
		}          
	} 
	rewind(fileP);
	dizi=(kayitlar*)malloc(cnt*sizeof(kayitlar));
	for(i=0;i<cnt;i++){
		fscanf(fileP,"%d %s %s",&dizi[i].ogrID,dizi[i].dersID,dizi[i].durum);
	}
	fclose(fileP);
	fileP=fopen("DersKay�tlar.txt","w");
	for(i=0;i<cnt;i++){
		if(dizi[i].ogrID==ogrID && strcmp(dizi[i].dersID,dersID)==0){
			fprintf(fileP,"%d %s %s\n",dizi[i].ogrID,dizi[i].dersID,"b�rakt�");
		}else{
			fprintf(fileP,"%d %s %s\n",dizi[i].ogrID,dizi[i].dersID,dizi[i].durum);
		}
	}
	fclose(fileP);
	cnt=0;
	fileP=fopen("��renciler.txt","r");
	for(tmp = getc(fileP); tmp != EOF; tmp = getc(fileP)){ //eleman say�c�
		if (tmp == '\n'){
        	cnt++;
		}          
	} 
	rewind(fileP);
	dizi2=(ogr*)malloc(cnt*sizeof(ogr));
    for(i=0;i<cnt;i++){
    	fscanf(fileP,"%d %s %s %d %d",&dizi2[i].ogrNo,dizi2[i].ad,dizi2[i].soyad,&dizi2[i].dersSay,&dizi2[i].topKredi);
	}
	fclose(fileP);
	fileP=fopen("��renciler.txt","w");
	for(i=0;i<cnt;i++){
		if(dizi2[i].ogrNo==ogrID){
			dizi2[i].dersSay--;
		}
		fprintf(fileP,"%d %s %s %d %d\n",dizi2[i].ogrNo,dizi2[i].ad,dizi2[i].soyad,dizi2[i].dersSay,dizi2[i].topKredi);
	}
	fclose(fileP);
	free(dizi);
	free(dizi2);
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void hocaKayit(){ 
	FILE *fileP;
	hoca yenikayit;
	fileP=fopen("Akademisyenler.txt","a");
	if(fileP==NULL){
		printf("dosya acilamadi");
	}
	printf("Hoca ID: ");
	scanf("%d",&yenikayit.id);
	printf("Hoca �nvan: ");
	scanf("%s",yenikayit.unvan);
	printf("Hoca �sim: ");
	scanf("%s",yenikayit.ad);
	printf("Hoca Soyisim: ");
	scanf("%s",yenikayit.soyad);
	
	fprintf(fileP,"%d %s %s %s \n",yenikayit.id,yenikayit.unvan,yenikayit.ad,yenikayit.soyad);
	fclose(fileP);	
}

void hocaSil(int hocaID){ 
	FILE *fileP;
	hoca *dizi;
	int cnt=0,i;
	char tmp;
	
	fileP=fopen("Akademisyenler.txt","r");
	if(fileP==NULL){
		printf("dosya acilamadi");
	}
	for (tmp = getc(fileP); tmp != EOF; tmp = getc(fileP)){
		if (tmp == '\n'){
        	cnt++;
		}          
	} 
	rewind(fileP);
	dizi=(hoca*)malloc(cnt*sizeof(hoca));
    for(i=0;i<cnt;i++){
    	fscanf(fileP,"%d %s %s %s",&dizi[i].id,dizi[i].unvan,dizi[i].ad,dizi[i].soyad);
	}
	fclose(fileP);
	fileP=fopen("Akademisyenler.txt","w");
	for(i=0;i<cnt;i++){
		if(dizi[i].id!=hocaID){
			fprintf(fileP,"%d %s %s %s\n",dizi[i].id,dizi[i].unvan,dizi[i].ad,dizi[i].soyad);	
		}    	
	}
	free(dizi);
	fclose(fileP);
}

void hocaGuncelle(int hocaID){   
	FILE *fileP;
	hoca *dizi;
	int cnt=0,i;
	char tmp;
	
	fileP=fopen("Akademisyenler.txt","r");
	if(fileP==NULL){
		printf("dosya acilamadi");
	}
	for(tmp = getc(fileP); tmp != EOF; tmp = getc(fileP)){ //eleman say�c�
		if (tmp == '\n'){
        	cnt++;
		}          
	} 
	rewind(fileP);
	dizi=(hoca*)malloc(cnt*sizeof(hoca));
    for(i=0;i<cnt;i++){
    	fscanf(fileP,"%d %s %s %s",&dizi[i].id,dizi[i].unvan,dizi[i].ad,dizi[i].soyad);
	}
	fclose(fileP);
	fileP=fopen("Akademisyenler.txt","w");
	for(i=0;i<cnt;i++){
		if(dizi[i].id!=hocaID){
			fprintf(fileP,"%d %s %s %s\n",dizi[i].id,dizi[i].unvan,dizi[i].ad,dizi[i].soyad);	
		}else{
			printf("Yeni �nvan: ");
			scanf("%s",dizi[i].unvan);
			printf("Yeni isim:");
			scanf("%s",dizi[i].ad);
			printf("Yeni soyisim:");
			scanf("%s",dizi[i].soyad);
			fprintf(fileP,"%d %s %s %s\n",dizi[i].id,dizi[i].unvan,dizi[i].ad,dizi[i].soyad);
		}    	
	}
	free(dizi);
	fclose(fileP);
}



void dersEkle(){ 
	FILE *fileP;
	ders ekleDers;
	fileP=fopen("Dersler.txt","a");
	if(fileP==NULL){
		printf("dosya acilamadi");
	}
	printf("Ders Kodu: ");
	scanf("%s",ekleDers.dersKod);
	printf("Ders Ad�: ");
	scanf("%s",ekleDers.dersAd);
	printf("Ders Kredi: ");
	scanf("%d",&ekleDers.kredi);
	printf("Ders Kontenjan�: ");
	scanf("%d",&ekleDers.kontenjan);
	printf("Dersi Veren ��retim �yesi ID: ");
	scanf("%d",&ekleDers.hocaID);
	
	fprintf(fileP,"%s %s %d %d %d\n",ekleDers.dersKod,ekleDers.dersAd,ekleDers.kredi,ekleDers.kontenjan,ekleDers.hocaID);
	fclose(fileP);
}

void hocaDersSil(int hocaID){   
	FILE *fileP,*fp;
	ders *dizi;
	ogr *dizi2;
	char tmp;
	char ID_to_del[10];
	int i,cnt=0,cnt2=0,dersKredi;
	
	printf("Silmek istedi�iniz dersin kodunu girin: ");
	scanf("%s",ID_to_del);
	
	fileP=fopen("Dersler.txt","r");	
	if(fileP==NULL){
		printf("dosya acilamadi");
	}
	
	for (tmp = getc(fileP); tmp != EOF; tmp = getc(fileP)){
		if (tmp == '\n'){
        	cnt++;
		}          
	} 
	rewind(fileP);
	dizi=(ders*)malloc(cnt*sizeof(ders));
    for(i=0;i<cnt;i++){
    	fscanf(fileP,"%s %s %d %d %d",dizi[i].dersKod,dizi[i].dersAd,&dizi[i].kredi,&dizi[i].kontenjan,&dizi[i].hocaID);
	}
	fclose(fileP);
	fileP=fopen("Dersler.txt","w");
	for(i=0;i<cnt;i++){
		if(strcmp(dizi[i].dersKod,ID_to_del)!=0){
			fprintf(fileP,"%s %s %d %d %d\n",dizi[i].dersKod,dizi[i].dersAd,dizi[i].kredi,dizi[i].kontenjan,dizi[i].hocaID);
		}else{
			if(hocaID != dizi[i].hocaID){
				printf("B�yle bir ders vermiyorsunuz.L�tfen girdi�iniz ders kodunu kontrol edin.\n");
				fprintf(fileP,"%s %s %d %d %d\n",dizi[i].dersKod,dizi[i].dersAd,&dizi[i].kredi,dizi[i].kontenjan,dizi[i].hocaID);
			}
		}	
	}
	fclose(fileP);
	free(dizi);
}

void dersGuncelle(){   
	FILE *fileP;
	ders *dizi;
	int cnt=0,i;
	char tmp;
	char ID_to_update[10];
	
	printf("G�ncellemek istedi�iniz dersin kodunu giriniz: ");
	scanf("%s",ID_to_update);
	fileP=fopen("Dersler.txt","r");
	if(fileP==NULL){
		printf("dosya acilamadi");
	}
	for(tmp = getc(fileP); tmp != EOF; tmp = getc(fileP)){ //eleman say�c�
		if (tmp == '\n'){
        	cnt++;
		}          
	} 
	rewind(fileP);
	dizi=(ders*)malloc(cnt*sizeof(ders));
    for(i=0;i<cnt;i++){
    	fscanf(fileP,"%s %s %d %d %d",dizi[i].dersKod,dizi[i].dersAd,&dizi[i].kredi,&dizi[i].kontenjan,&dizi[i].hocaID);
	}
	fclose(fileP);
	fileP=fopen("Dersler.txt","w");
	for(i=0;i<cnt;i++){
		if(strcmp(ID_to_update,dizi[i].dersKod) != 0){
			fprintf(fileP,"%s %s %d %d %d\n",dizi[i].dersKod,dizi[i].dersAd,dizi[i].kredi,dizi[i].kontenjan,dizi[i].hocaID);	
		}else{
			printf("Yeni Ders Kodu: ");
			scanf("%s",dizi[i].dersKod);
			printf("Yeni Ders Ad�: ");
			scanf("%s",dizi[i].dersAd);
			printf("Yeni Ders Kredi: ");
			scanf("%d",&dizi[i].kredi);
			printf("Yeni Ders Kontenjan: ");
			scanf("%d",&dizi[i].kontenjan);
			printf("Yeni Dersi Veren HocaID: ");
			scanf("%d",&dizi[i].hocaID);
			fprintf(fileP,"%s %s %d %d %d\n",dizi[i].dersKod,dizi[i].dersAd,dizi[i].kredi,dizi[i].kontenjan,dizi[i].hocaID);
		}
	}
	fclose(fileP);
	free(dizi);
}

void sinifList(int hocaID){
	FILE *fileP,*fp,*fp2;
	ders *dizi;
	ogr *sinif;
	ders list;
	kayitlar check;
	int cnt=0,cnt2=0,i,j,control=0;
	char tmp;
	char dersKod[25];
	
	printf("Listelemek istedi�iniz dersin Kodunu girin: ");
	scanf("%s",dersKod);
	
	fp2=fopen("Dersler.txt","r");
	if(fileP==NULL){
		printf("dosya acilamadi");
	}

	for (tmp = getc(fp2); tmp != EOF; tmp = getc(fp2)){
		if (tmp == '\n'){
        	cnt++;
		}          
	}
	rewind(fp2);
	dizi=(ders*)malloc(cnt*sizeof(ders));
	for(i=0;i<cnt;i++){
		fscanf(fp2,"%s %s %d %d %d",dizi[i].dersKod,dizi[i].dersAd,&dizi[i].kredi,&dizi[i].kontenjan,&dizi[i].hocaID);
		if(dizi[i].hocaID==hocaID && strcmp(dizi[i].dersKod,dersKod)==0){
			control++;
			strcpy(list.dersKod,dizi[i].dersKod);
		}
	}
	
	
	if(control==0){
		printf("�zerinize kay�tl� b�yle bir ders bulunmamakta.\n");
		fclose(fp2);
		free(dizi);
		return;
	}
	
	fclose(fp2);
	free(dizi);	
	
	fileP=fopen("��renciler.txt","r");
	if(fileP==NULL){
		printf("dosya acilamadi");
	}
	for(tmp = getc(fileP); tmp != EOF; tmp = getc(fileP)){ //eleman say�c�
		if (tmp == '\n'){
        	cnt2++;
		}          
	} 
	rewind(fileP);
	sinif=(ogr*)malloc(cnt2*sizeof(ogr));
    for(i=0;i<cnt2;i++){
    	fscanf(fileP,"%d %s %s %d %d",&sinif[i].ogrNo,sinif[i].ad,sinif[i].soyad,&sinif[i].dersSay,&sinif[i].topKredi);
	}
	fclose(fileP);
	strcat(dersKod,"_s�n�flistesi.txt");
	
	cnt=0;
	fp=fopen("DersKay�tlar.txt","r");
	for(tmp = getc(fileP); tmp != EOF; tmp = getc(fileP)){ //eleman say�c�
		if (tmp == '\n'){
        	cnt++;
		}          
	}
	rewind(fp);
	fileP=fopen(dersKod,"w");
	if(fileP==NULL){
		printf("dosya a��lamad�");
	}
	for(i=0;i<cnt;i++){
		fscanf(fp,"%d %s %s",&check.ogrID,check.dersID,check.durum);
		if(strcmp(check.dersID,list.dersKod)==0){
			for(j=0;j<cnt2;j++){
				if(check.ogrID==sinif[j].ogrNo){
					fprintf(fileP,"%d %s %s\n",sinif[j].ogrNo,sinif[j].ad,sinif[j].soyad);
				}
			}
		}
	}
	fclose(fileP);
	fclose(fp);
	free(sinif);

	
}

int main(){
	setlocale(LC_ALL,"Turkish");
	printf("Yap�sal Programlama Proje �devi\nUmut G�zel-18011004\n\n");
	printf("////////////////////////////HO�GELD�N�Z//////////////////////////////////\n");
	int secenek=-1,ID;
	while(secenek!=0){
		printf("===================L�tfen ��lem Se�iniz=====================\n");
		printf("1)��renci i�lemleri\n");
		printf("2)Akademisyen i�lemleri\n");
		printf("3)Ders i�lemleri\n");
		printf("0)��k��\n\n");
		printf("Se�iminiz: ");
		scanf("%d",&secenek);
		if(secenek==1){
			printf("\n\n===================��renci ��lemleri=====================\n");
			printf("1)Yeni ��renci Kay�t\n");
			printf("2)��renci Bilgisi G�ncelleme\n");
			printf("3)��renci Sil\n");
			printf("4)Ders Ekle\n");
			printf("5)Ders Sil\n\n");
			printf("Se�iminiz:");
			scanf("%d",&secenek);
			printf("\n");
			switch(secenek){
				case 1:
					ogrKayit();
					break;
				case 2:
					printf("L�tfen ��renci Numaran�z� Girin: ");
					scanf("%d",&ID);
					ogrGuncelle(ID);
					break;
				case 3:
					printf("L�tfen ��renci Numaran�z� Girin: ");
					scanf("%d",&ID);
					ogrSil(ID);
					break;
				case 4:
					printf("L�tfen ��renci Numaran�z� Girin: ");
					scanf("%d",&ID);
					ogrDersEkle(ID);
					break;
				case 5:
					printf("L�tfen ��renci Numaran�z� Girin: ");
					scanf("%d",&ID);
					ogrDersSil(ID);
					break;
				default:
					printf("Ge�erli bir se�enek se�mediniz. Ana men�ye d�n�l�yor...\n");
			}
		}else if(secenek==2){
			printf("\n\n===================Akademisyen ��lemleri=====================\n");
			printf("1)Akademisyen Kay�t\n");
			printf("2)Akademisyen Bilgisi G�ncelleme\n");
			printf("3)Akademisyen Sil\n\n");

			printf("Se�iminiz:");
			scanf("%d",&secenek);
			printf("\n");
			switch(secenek){
				case 1:
					hocaKayit();
					break;
				case 2:
					printf("L�tfen ID Numaran�z� Girin: ");
					scanf("%d",&ID);
					hocaGuncelle(ID);
					break;
				case 3:
					printf("L�tfen ID Numaran�z� Girin: ");
					scanf("%d",&ID);
					hocaSil(ID);
					break;
				default:
					printf("Ge�erli bir se�enek se�mediniz. Ana men�ye d�n�l�yor...\n");
			}
		}else if(secenek==3){
			printf("\n\n===================Ders ��lemleri=====================\n");
			printf("1)Ders Olu�tur\n");
			printf("2)Ders Bilgilerini G�ncelle\n");
			printf("3)Dersi Sil\n");
			printf("4)S�n�f Listesi Olu�tur\n\n");

			printf("Se�iminiz:");
			scanf("%d",&secenek);
			printf("\n");
			switch(secenek){
				case 1:
					dersEkle();
					break;
				case 2:
					dersGuncelle();
					break;
				case 3:
					printf("L�tfen Akademisyen ID Numaran�z� Girin: ");
					scanf("%d",&ID);
					hocaDersSil(ID);
					break;
				case 4:
					printf("L�tfen ID Numaran�z� Girin: ");
					scanf("%d",&ID);
					sinifList(ID);
					break;
				default:
					printf("Ge�erli bir se�enek se�mediniz. Ana men�ye d�n�l�yor...\n");		
			}
		}
		printf("_____________________________________________________________________\n                      ANA MEN�YE D�N�L�YOR...                        \n_____________________________________________________________\n\n");
	}
	
	return 0;
}
