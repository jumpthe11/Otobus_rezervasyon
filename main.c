#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
int Firmagiris(int otobusno, int otobusler[30][2][50], char otobusmodel[10][100],char seferno[30][6],char seferbilgileri[30][8],int sefernosayac,char *sehirbaslangic[30][30],char *sehirbitis[30][30],int saat[30][4],float hasilat[30],int kalkis,int seferbitis,char rezervasyon[50][4],char rezervasyon_no[50][8],char *rezervasyonC[50][2][20],int rezervasyon_sayac);
int Hexadecimaluret(char seferno[30][6],int sayac){

    int r[6]={1,5};
    tekrar:
srand(time(NULL));

for(int i=2;i<6;i++)
    r[i] = rand()%16;

for(int i=0;i<6;i++)
    printf("%x",r[i]);

for(int j=0;j<6;j++)
    seferno[sayac][j]=r[j];
sayac++;
return seferno;


}
/*
if(  (seferno[sayac+1][0]==seferno[sayac][0]) && (seferno[sayac+1][1]==seferno[sayac][1]) && (seferno[sayac+1][2]==seferno[sayac][2]) && (seferno[sayac+1][3]==seferno[sayac][3]) && (seferno[sayac+1][4]==seferno[sayac][4]) && (seferno[sayac+1][5]==seferno[sayac][5]))
{
    goto tekrar;
}
else{
sayac++;




return seferno;
}


*/

char rezervasyon_no_uret(char rezervasyon_no[50][8],int sayac){
    int No[8];
    tekrar:

srand(time(NULL));

for(int i=0;i<8;i++)
    No[i] = rand()%16;

for(int i=0;i<8;i++)
    printf("%x",No[i]);

for(int j=0;j<8;j++)
    rezervasyon_no[sayac][j]=No[j];
sayac++;
printf("\n rezervasyon no sayaci :%d \n",sayac);
return rezervasyon_no;

}

int Anamenu(int otobusno, int otobusler[30][2][50], char otobusmodel[10][100],char seferno[30][6],char seferbilgileri[30][8],int sefernosayac,char *sehirbaslangic[30][30],char *sehirbitis[30][30],int saat[30][4],float hasilat[30],int kalkis,int seferbitis,char rezervasyon[50][4],char rezervasyon_no[50][8],char *rezervasyonC[50][2][20],int rezervasyon_sayac){
    int tus;
    anamenu:
    printf("\n ANA MENU \n 1. FIRMA GIRISIM \n 2. MUSTERI GIRISI \n 3. CIKIS \n");
scanf("%d", &tus);
switch(tus){
    //firma girisi
case 1:
    Firmagiris(otobusno,otobusler,otobusmodel,seferno,seferbilgileri,sefernosayac,sehirbaslangic,sehirbitis,saat,hasilat,kalkis,seferbitis,rezervasyon,rezervasyon_no,rezervasyonC,rezervasyon_sayac);




break;
//firma girisi bitisi
//musteri girisi
case 2:
musterigirisi(otobusno,otobusler,otobusmodel,seferno,seferbilgileri,sefernosayac,sehirbaslangic,sehirbitis,saat,hasilat,kalkis,seferbitis,rezervasyon,rezervasyon_no,rezervasyonC,rezervasyon_sayac);
break;
//musteri girisi bitisi
case 3:
return 0;
default:
    printf("Hatali giris!");
    goto anamenu;





}
}



int Firmagiris(int otobusno, int otobusler[30][2][50], char otobusmodel[10][100],char seferno[30][6],char seferbilgileri[30][8],int sefernosayac,char *sehirbaslangic[30][30],char *sehirbitis[30][30],int saat[30][4],float hasilat[30],int kalkis,int seferbitis,char rezervasyon[50][4],char rezervasyon_no[50][8],char *rezervasyonC[50][2][20],int rezervasyon_sayac)
{
int secilenotobus;
int tus=0;
sefernosayac=0;
    anamenubaslangic:


firmagirisustu:
printf("\n FIRMA GIRISI \n 1-Otobus ekle \n 2-Sefer bilgisi ekle \n 3-Sefer\\Koltuk bilgisi \n 4-Bir ust menuye don \n");
scanf("%d",&tus);
switch(tus){
// OTOBUS EKLEME YERI
case 1:
    for(int j=0;j<50;j++)
    otobusler[otobusno][1][j]=0;
printf("Otobus kapasite ekle= ");
scanf("%d",&otobusler[otobusno][0][0]);
printf("\nOtobus modeli nedir?= ");
scanf("%s",&otobusmodel[otobusno]);
//puts(otobusmodel[otobusno]);
//printf("\n MODEL BU MU? %s",otobusmodel[otobusno]);
personelsayiustu:
printf("\nPersonel sayisi kac?= ");
scanf("%d",&otobusler[otobusno][0][1]);
if(!(otobusler[otobusno][0][1]==2 || otobusler[otobusno][0][1]==3)){
printf("\nPersonel sayisi 2 veya 3 olmalidir");
goto personelsayiustu;
}
//printf("\n Personel sayisi bu mu? %d",otobusler[otobusno][0][1]);
otobusno++;
//printf("otobusno: %d",otobusno);
goto firmagirisustu;
break;

//OTOBUS EKLE BITISI
case 2:
printf("---Sefer bilgisi ekle \n");


Hexadecimaluret(seferno,sefernosayac);
for(int k=0;k<otobusno;k++){
printf("\n%d Nolu otobusun Otobus kapasitesi= %d /// Otobus modeli= %s /// Personel sayisi = %d",k+1,otobusler[k][0][0],otobusmodel[k],otobusler[k][0][1]);
}

printf("\n");

// TÜM SEFER SEYSILERI BURADA ----------------------------------------
printf("\nHangi otobus numarasini istersiniz? \n");
scanf("%d",&secilenotobus);
--secilenotobus;
seferbilgileri[sefernosayac][0]=secilenotobus;
//printf("\n SEFER BILGISI= %d",seferbilgileri[sefernosayac][0]);
olmamis:
printf("\n Hangi saatte baslayacak? = ");

scanf("%d",&kalkis);
if(kalkis>24){
printf("\n saat 24'den fazla olamaz tekrar girin: \n");
goto olmamis;
}
//kalkissaati(kalkis,saat,sefernosayac);
saat[sefernosayac][0]=kalkis * 100 + 15;
//printf("\n kalkis saati= %d",saat[sefernosayac][0]);
printf("\n Varis Saati? = ");
scanf("%d",&seferbitis);
if(seferbitis>24){
printf("\n saat 24'den fazla olamaz tekrar girin: \n");
goto olmamis;
}
saat[sefernosayac][1]=seferbitis * 100 + 15; //VARIS - KALKIS / 6-23=-17 22-23=-1
//printf("%d %d",kalkis,seferbitis);
int yolculuksuresi=seferbitis-kalkis;//-19 18                -25 -26
if((yolculuksuresi>=4 || (yolculuksuresi>=-20 && yolculuksuresi<=0)) && !(otobusler[secilenotobus][0][0]>30 && otobusler[secilenotobus][0][1]>=3)){
    printf("\nOTOBUS KUCUK\n");
    goto olmamis;
}


printf("\nHangi sehirden basliyacak? = ");
scanf("%s",&sehirbaslangic[sefernosayac]);
//printf("\n Dogrumu %s \n",sehirbaslangic[sefernosayac]);
printf("\nHangi sehirde bitecek? = ");
scanf("%s",&sehirbitis[sefernosayac]);
//printf("\n Dogrumu %s \n",sehirbitis[sefernosayac]);
printf("\nCebe kac para gecicek? = ");
scanf("%f",&hasilat[sefernosayac]);
//printf("\n dogru mu= %d",hasilat[sefernosayac]);
printf("\nKisi basi gelir= %f \n",hasilat[sefernosayac]/otobusler[secilenotobus][0][0]);

//printf("\n \n Kalkis saati= %d \n Bitis saati= %d \n",saat[sefernosayac][0],saat[sefernosayac][1]);
sefernosayac++;
goto firmagirisustu;
break;
case 3:
printf("----Sefer ve koltuk bilgileri \n");
for(int i=0;i<sefernosayac;i++){
printf("%d. Sefer numarali sefer=",i+1);
for(int j=0;j<6;j++)
printf("%X",seferno[i][j]);
printf("\n");
}
printf("\n");
//for(int i=0;i<sefernosayac;i++)
printf("Hangi noyu secmek istersiniz?");
scanf("%d",&tus);
tus--;
printf("Otobus no = %d \n Baslangic sehri = %s \n Bitis sehri = %s \n Kalkis saati = %d \n Bitis saati = %d \n Kisi basi gerir = %0.2f \n Toplam hasilat = %f \n\n\n",seferbilgileri[tus][0]+1,sehirbaslangic[tus],sehirbitis[tus],saat[tus][0],saat[tus][1],hasilat[tus]/otobusler[tus][0][0],hasilat[tus]);
//printf("Otobus no = %d \n Baslangic sehri = %s \n Bitis sehri = %s \n Kalkis saati = %d \n Bitis saati = %d \n Kisi basi gerir = %d \n Toplam hasilat = %d \n\n\n",seferbilgileri[tus][0]+1,sehirbaslangic[tus],sehirbitis[tus],saat[tus][0],saat[tus][1],hasilat[tus]/otobusler[tus][0][0],hasilat[tus]);
  for(int i=0;i<otobusler[seferbilgileri[tus][0]][0][0];i++){
            if(otobusler[seferbilgileri[tus][0]][1][i]!=0){
                printf("%d.[x]  ",i+1);
            }


            else{
                  printf("%d.[]  ",i+1);
            }


  }



goto firmagirisustu;
break;
case 4:
Anamenu(otobusno,otobusler,otobusmodel,seferno,seferbilgileri,sefernosayac,sehirbaslangic,sehirbitis,saat,hasilat,kalkis,seferbitis,rezervasyon,rezervasyon_no,rezervasyonC,rezervasyon_sayac);
break;
default:
printf("hata");
goto anamenubaslangic;
}
}



int musterigirisi(int otobusno, int otobusler[30][2][50], char otobusmodel[10][100],char seferno[30][6],char seferbilgileri[30][8],int sefernosayac,char *sehirbaslangic[30][30],char *sehirbitis[30][30],int saat[30][4],float hasilat[30],int kalkis,int seferbitis,char rezervasyon[50][4],char rezervasyon_no[50][8],char *rezervasyonC[50][2][20],int rezervasyon_sayac){
    int tus;
    int boskoltuk=0;
    char Ad[20];
    char Soyad[20];

    int koltuk_no;
    char secim;

    ustmenu:
    boskoltuk=0;
printf("\n 1. Seferleri Listele \n2. Sefer Rezervasyon Yap \n3. Bir Ust Menuye Don \n4. Rezervasyon Goster \n");
scanf("%d",&tus);
switch(tus){
case 1:
    for(int i=0;i<sefernosayac;i++){
printf("%d. Sefer numarali sefer=",i+1);
for(int j=0;j<6;j++)
printf("%X",seferno[i][j]);
printf("\n");
}
printf("Hangi noyu secmek istersiniz?");
scanf("%d",&tus);
tus--;
//seferbilgileri[tus][0]
  for(int i=0;i<otobusler[seferbilgileri[tus][0]][0][0];i++){
            if(otobusler[seferbilgileri[tus][0]][1][i]!=0){
                //printf("%d.[x]  ",i+1);
            }


            else{
                  //printf("%d.[]  ",i+1);
                  boskoltuk++;
            }
  }

printf("\n Baslangic sehri = %s \n Bitis sehri = %s \n Kalkis saati = %d \n Bitis saati = %d \n Kisi basi ucret = %d \n Bos koltuk sayisi = %d \n\n",sehirbaslangic[tus],sehirbitis[tus],saat[tus][0],saat[tus][1],hasilat[tus]/otobusler[tus][0][0],boskoltuk);
printf("\n \n Devam etmek icin bir tusa basiniz\n");
getch(); //Bir tusa basinca ilerletir.

goto ustmenu;
    break;

case 2:
    for(int i=0;i<sefernosayac;i++){
printf("%d Sefer numarali sefer=",i+1);
for(int j=0;j<6;j++)
printf("%X",seferno[i][j]);
printf("\n");
}
printf("\n Hangi noyu secmek istersiniz?");
scanf("%d",&tus);
tus--;

  for(int i=0;i<otobusler[seferbilgileri[tus][0]][0][0];i++){
            if(otobusler[seferbilgileri[tus][0]][1][i]!=0){
                printf("%d.[x]  ",i+1);
            }


            else{
                  printf("%d.[]  ",i+1);
                  boskoltuk++;
            }
  }
printf("\n Baslangic sehri = %s \n Bitis sehri = %s \n Kalkis saati = %d \n Bitis saati = %d \n Kisi basi ucret = %d \n Bos koltuk sayisi = %d \n\n",sehirbaslangic[tus],sehirbitis[tus],saat[tus][0],saat[tus][1],hasilat[tus]/otobusler[tus][0][0],boskoltuk);
printf("\n \nIsim soyisim?");
scanf("%s %s",&Ad,&Soyad);
rezervasyonC[rezervasyon_sayac][0][0]=Ad;
rezervasyonC[rezervasyon_sayac][1][0]=Soyad;
rezervasyon[rezervasyon_sayac][2]=tus;
// printf("%c %c",rezervasyonC[rezervasyon_sayac][0][0],rezervasyonC[rezervasyon_sayac][1][0]);
printf("Hangi koltuk numarasini almak istersiniz?");
scanf("%d",&koltuk_no);
koltuk_no--;
otobusler[seferbilgileri[tus][0]][1][koltuk_no]=4;
rezervasyon[rezervasyon_sayac][3]=koltuk_no;
  for(int i=0;i<otobusler[seferbilgileri[tus][0]][0][0];i++){
            if(otobusler[seferbilgileri[tus][0]][1][i]!=0){
                printf("%d.[x]  ",i+1);
            }


            else{
                  printf("%d.[]  ",i+1);
                  boskoltuk++;
            }
  }
  secimustu:
printf("\n Secili yeri onayliyor musunuz? E/H \n");
scanf("%s",&secim);
tolower(secim);
if(secim=='e'){
    printf("\n Kaydiniz alinmistir");
    rezervasyon_no_uret(rezervasyon_no,rezervasyon_sayac);
    rezervasyon_sayac++;
    goto ustmenu;
}
else if(secim=='h'){
    printf("\n Kaydiniz iptal edilmistir");
    otobusler[seferbilgileri[tus][0]][1][koltuk_no]=0;
    rezervasyonC[rezervasyon_sayac][0][0]=NULL;
rezervasyonC[rezervasyon_sayac][1][0]=NULL;
rezervasyon[rezervasyon_sayac][2]=NULL;
otobusler[seferbilgileri[tus][0]][1][koltuk_no]=0;
rezervasyon[rezervasyon_sayac][3]=0;
goto ustmenu;
}
else{
    printf("hata");
    goto secimustu;
}
printf("\n \n Devam etmek icin bir tusa basiniz\n");
getch(); //Bir tusa basinca ilerletir.
goto ustmenu;
    break;
case 3:
    Anamenu(otobusno,otobusler,otobusmodel,seferno,seferbilgileri,sefernosayac,sehirbaslangic,sehirbitis,saat,hasilat,kalkis,seferbitis,rezervasyon,rezervasyon_no,rezervasyonC,rezervasyon_sayac);
    break;
case 4:
    printf("\n \n \nRezervasyonlar \n Rezervasyon numarasini giriniz\n");

    for(int i=0;i<rezervasyon_sayac;i++){
            printf("%d. Rezervasyon no =",i+1);
        for(int j=0;j<8;j++){
        printf("%X",rezervasyon_no[i][j]);
        }
        printf("\n");
    }
    scanf("%d",&tus);
    tus--;
 printf(" Ad:%s \n Soyad:%s \n Sefer no:%d \n Koltuk no:%d \n",rezervasyonC[tus][0][0],rezervasyonC[tus][1][0],rezervasyon[tus][2]+1,rezervasyon[tus][3]+1);
printf("\n Baslangic sehri = %s \n Bitis sehri = %s \n Kalkis saati = %d \n Bitis saati = %d \n Ucret = %f \n\n",sehirbaslangic[tus],sehirbitis[tus],saat[tus][0],saat[tus][1],hasilat[tus]/otobusler[tus][0][0]);
printf("\n \n Devam etmek icin bir tusa basiniz\n");
getch();
goto ustmenu;
    break;

default:
goto ustmenu;

}
return 4;
}
int main()
{
    int tus;
    int sefernosayac=0;
    char seferbilgileri[30][7];// 0:otobusno 1:sefer baþlangýç saati 2:Varýþ saati 3:Sefer baþlangýç þehri 4:Sefer varýþ þehri 5:Ýstenen toplam hasiyat 6:Müþteri baþý ücret
    char seferno[30][6]; // 0-6: sefer no
    int otobusno=0;
    int otobusler[30][2][50]={NULL}; //ILK DIZI: OTOBUSNO IKINCI DIZI 0: KAPASITE 1:PERsON SAY
    char otobusmodel[10][100];
        int saat[30][4];
    char *sehirbaslangic[30][30];
    char *sehirbitis[30][30];
    float hasilat[30];
    int seferbitis;
    char rezervasyon[50][4];//0: AD 1: SOYAD 2: sefer no 3: koltuk no
    char rezervasyon_no[50][8];
    char *rezervasyonC[50][2][20];
    int rezervasyon_sayac=0;
    int kalkis;

    Anamenu(otobusno,otobusler,otobusmodel,seferno,seferbilgileri,sefernosayac,sehirbaslangic,sehirbitis,saat,hasilat,kalkis,seferbitis,rezervasyon,rezervasyon_no,rezervasyonC,rezervasyon_sayac);
return 0;
}
