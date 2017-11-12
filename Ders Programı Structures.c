/**
@file
Programlama Dilleri spring2017 assignment 2.
Bu program bir ogrenci ders programini simule etmektedir.
ogrenci ders tanimlama,programina ders ekleme,cikarma vb. seyler yapabilmektedir.
bir dersi programda 2 farkli gune de ekleyebilmektedir.
@author
Name: Muhammet Ceneli
Student no: 15011025
Date: 30.10.2017
E-Mail: muhammetceneli@gmail.com
Compiler used: GCC 9
IDE: Dev-C++ 5.11
Operating System Windows 7 64-bit
CPU: Intel i7 4720hq
RAM: 8 GB DDR3
*/ 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
//Student ve courses adinda 2 structure tanimladim.
struct Student {
   char* Name;
   int   Id;
   int   Clas;
};

typedef struct{
   char* Name;
   char* Id;
   int   Clas;
   int   Day;
   int   StartTime;
   int   EndTime;
   int	 Day2;
   int	 StartTime2;
   int	 EndTime2;
   int   Enroll;
}COURSE;
//COURSE STRUCTUR'i icin yer actim.
COURSE* courses = malloc(20 * sizeof(*courses));
/* @param menu = menude kullanicinin secim yapmasi icin.
   @param loop = menude islem yaptiktan sonra programin sonlanmamasi icin loopa sokuyor.
   @param ekle = ders ekleyip cikartirken indis gorevi goruyor
   @param i    = courses structure'inda islem yaparken indis gorevi goruyor.
   @param sayac= ders ekleme sirasinda haftalik programda cakisan ders olup olmadigini kontrol ediyor.
   @param tf   = bir dersin iki farkli gunde olup olmadigini kullanicidan aliyor.
*/
char str[50];
int menu,i,j,k,loop=1,ekle,sayac=0,tf=0;
struct Student Student1;//Student structure'ini ilklendirmek icin.

char *plan[8][6]; //haftalik ders programindaki sabit yazilar.
plan[0][0]="      ";
plan[1][0]="9 -10 ";
plan[2][0]="10-11 ";
plan[3][0]="11-12 ";
plan[4][0]="12-13 ";
plan[5][0]="13-14 ";
plan[6][0]="14-15 ";
plan[0][1]="pazrtsi ";
plan[0][2]="sali    ";
plan[0][3]="carsmba ";
plan[0][4]="persmbe ";
plan[0][5]="cuma    ";
//haftalik ders programinin icini sifirladim.
	for(i=1; i<8; i++)
	{
		for( j=1; j<6; j++){
			plan[i][j]="       ";
		}
	}
i=0;j=0;
//kullanici bilgilerini aldim.
printf("Adin Soyadin ne? \n");
scanf("%[^\n]s",&Student1.Name);
printf("Okul numaran kac? \n");
while(scanf("%d",&Student1.Id) != 1){
 printf("Okul numaran sadece rakamlardan olusmalidir \n");
 while(getchar() != '\n');
}
printf("Kacinci siniftasin? \n");	
while(Student1.Clas<1 || Student1.Clas>4){
	printf("Sinifiniz 1. ve 4. siniflar arasinda olmalidir\n");
while(scanf("%d",&Student1.Clas) != 1){
 printf("Sinifin sadece rakamlardan olusabilir \n");
 while(getchar() != '\n');
}
}
//programin surekliligi icin loopta tutar.
while(loop){

system("cls");
printf("1.Yeni Ders Tanimla\n2.Ders Ekle\n3.Ders Cikar\n4.Haftalik Plani Goruntule\n5.Kayitli Derslerin Ayrintili Bilgisini Goruntule\n0.Cikis\n");
scanf("%d",&menu);	
if(menu==1){
	//ders tanimlama.
		system("cls");
		i++;
		
		courses[i].Name=(char*)malloc(50*sizeof(char*));
        printf("Dersin adini giriniz\n");
		fgets(courses[i].Name,50,stdin);
		fgets(courses[i].Name,50,stdin);
        courses[i].Id=(char*)malloc(7*sizeof(char*));
		printf("Dersin idsini giriniz\n");
		scanf("%[^\n]s",courses[i].Id);
		printf("Kacinci sinif dersi oldugunu giriniz\n");
        //integer istedigimde harf girilmesi durumunda hata almamak icin kontrol bir kac yerde daha geciyor.
		while(courses[i].Clas<1 || courses[i].Clas>4){
	printf("Sinif 1. ve 4. siniflar arasinda olmalidir\n");
while(scanf("%d",&courses[i].Clas) != 1){
 printf("Sinif sadece rakamlardan olusabilir \n");
 while(getchar() != '\n');
}
}
        printf("Ders haftanin kacinci gunu? \n");
		while(courses[i].Day<1 || courses[i].Day>5){
	printf("Ders gunu hafta icerisinde olmalidir\n");
while(scanf("%d",&courses[i].Day) != 1){
 printf("Haftanin kacinci gunu oldugunu giriniz \n");
 while(getchar() != '\n');
}
}
		printf("Dersin baslangic saatini giriniz\n");
        while(courses[i].StartTime<9 || courses[i].StartTime>14){
	printf("Baslangic saati 9-14 araliginda olmalidir\n");
while(scanf("%d",&courses[i].StartTime) != 1){
 printf("Saat sadece rakamlardan olusabilir \n");
 while(getchar() != '\n');
}
}
        printf("Dersin bitis saatini giriniz\n");
        while(courses[i].EndTime<10 || courses[i].EndTime>15){
	printf("Bitis saati 10-15 araliginda olmalidir\n");
while(scanf("%d",&courses[i].EndTime) != 1){
 printf("Saat sadece rakamlardan olusabilir \n");
 while(getchar() != '\n');
}
}   
		printf("Dersin ayri saatleri var mi? (1=evet,2=hayir) \n");
		while(tf<1 || tf>2){
while(scanf("%d",&tf) != 1){
 printf("1 ya da 2 \n");
 while(getchar() != '\n');
}
}
		if(tf==1){
			printf("Haftanin kacinci gunu? \n");
		while(courses[i].Day2<1 || courses[i].Day2>5){
	printf("Ders gunu hafta icerisinde olmalidir\n");
while(scanf("%d",&courses[i].Day2) != 1){
 printf("Haftanin kacinci gunu oldugunu giriniz \n");
 while(getchar() != '\n');
}
}
		printf("Baslangic saatini giriniz\n");
        while(courses[i].StartTime2<9 || courses[i].StartTime2>14){
	printf("Baslangic saati 9-14 araliginda olmalidir\n");
while(scanf("%d",&courses[i].StartTime2) != 1){
 printf("Saat sadece rakamlardan olusabilir \n");
 while(getchar() != '\n');
}
}
        printf("Bitis saatini giriniz\n");
        while(courses[i].EndTime2<10 || courses[i].EndTime2>15){
	printf("Bitis saati 10-15 araliginda olmalidir\n");
while(scanf("%d",&courses[i].EndTime2) != 1){
 printf("Saat sadece rakamlardan olusabilir \n");
 while(getchar() != '\n');
}
}			
} tf=0;
		courses[i].Enroll=0; //enroll dersin alinip alinmadigini belirtiyor. ilk tanimlandiginda alinmamis olarak ilklendirdim.
		printf("Kurs tanimlandi\n");
		getchar();
}else if(menu==2){
	//programa ders ekleme.
system("cls");
	for(j=1;j<i+1;j++){
		printf("%d. %s\n",j,courses[j].Name);
	}
printf("Eklemek istediginiz dersin numarasini giriniz\n");
	scanf("%d",&ekle);
		if(ekle<=20){
			if(courses[ekle].Id!= NULL){
		for(j=courses[ekle].StartTime-8;j<=courses[ekle].EndTime-9;j++){
			if(plan[j][courses[ekle].Day]!="       "){
				sayac++;
			}
		}
		for(j=courses[ekle].StartTime2-8;j<=courses[ekle].EndTime2-9;j++){
			if(plan[j][courses[ekle].Day2]!="       "){
				sayac++;
			}
		}
//programin bos olup olmadigini kontrol edip bos ise dersi ekledim.
		if(sayac==0 && Student1.Clas>=courses[ekle].Clas){
			for(j=courses[ekle].StartTime-8;j<=courses[ekle].EndTime-9;j++){
			plan[j][courses[ekle].Day]=courses[ekle].Id;
			}
	
		for(j=courses[ekle].StartTime2-8;j<=courses[ekle].EndTime2-9;j++){
			if(plan[j][courses[ekle].Day2]!="       "){
				sayac++;
			}
		}

		if(sayac==0 && Student1.Clas>=courses[ekle].Clas){
			for(j=courses[ekle].StartTime2-8;j<=courses[ekle].EndTime2-9;j++){
			plan[j][courses[ekle].Day2]=courses[ekle].Id;
			}
		}
				courses[ekle].Enroll=1;
				printf("Ders planiniza eklendi.\n");
		}else{
			if(sayac!=0){
				printf("Baska dersle cakisiyor veya zaten alinmis.\n");
			}else{
				printf("Ust sinif dersi oldugundan eklenemedi.\n");
			}
		}
		sayac=0;
		getchar();
	}else{
		printf("Ders bulunamadi\n");
		getchar();
	}
}
		
}else if(menu==3){
	//programdan ders silme.
	system("cls");
	for(j=1;j<i+1;j++){
		printf("%d. %s\n",j,courses[j].Name);
	}
printf("Cikarmak istediginiz dersin numarasini giriniz\n");
	scanf("%d",&ekle);
		if(ekle<=20){
			//ders eklimi diye kontrol etme.
			if(courses[ekle].Id!= NULL){
		if(plan[courses[ekle].StartTime-8][courses[ekle].Day]==courses[ekle].Id){
			for(j=courses[ekle].StartTime-8;j<=courses[ekle].EndTime-9;j++){
			plan[j][courses[ekle].Day]="       ";
			}
			
			if(courses[ekle].Day2!= NULL){
				for(j=courses[ekle].StartTime2-8;j<=courses[ekle].EndTime2-9;j++){
					plan[j][courses[ekle].Day2]="       ";
				}
			}
			
			courses[ekle].Enroll=0;
			printf("Ders planinizdan cikartildi.\n");
		}else{
			printf("Ders zaten ekli degil.\n");
		}
}else{
	printf("Ders bulunamadi\n");
	getchar();
}
}
	getchar();
	
}else if(menu==4){
	//ders programini ekrana yazdirma.
		system("cls");
		for(k=0; k<7; k++)
	{
		for( j=0; j<6; j++){
			printf("%.7s ",plan[k][j]);
		}
		printf("\n");
	}
	getchar();
}else if(menu==5){
	//aldigin derslerin ayrintili bilgisini goruntuleme.
	system("cls");
	printf("Alinmis Dersler:\n\n");
	for(k=1;k<i+1;k++){
		if(courses[k].Enroll==1){
			printf("Kurs Adi: %sKurs idsi:%s\nSinif:    %d\nGun:      %d\nSaat:     %d-%d\n",courses[k].Name,courses[k].Id,courses[k].Clas,courses[k].Day,courses[k].StartTime,courses[k].EndTime);
			if(courses[k].Day2!=NULL){
				printf("Diger gun:%d\nSaat:     %d-%d\n\n",courses[k].Day2,courses[k].StartTime2,courses[k].EndTime2);
			}else{
				printf("\n");
			}
		}	
	}
	getchar();
	
}else if(menu==0){
	loop=0;
}

getchar();
}

	return 0;
}

