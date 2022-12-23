// yýlan[tahta boyutu][1][1] = uzunluk,x kor., y kor

// son yemeði yediðinde boyutu 1 arttýrýp ya da o halini ekrana yazdýrabilirsin.

// boyut 10 olsun. son yemeði yediðinde 11 de bastýrabilirsin 10 da

// yazýlarý renklendirmek için kutuphane kullanabilrisin

// kendin fonk. yaz


// yýlan (1-n) , yemekler 0, diðerleri boþluk

// kuyruk büyüyecek ( büyüme bir sonraki hamlede gerçekleþecek)




	

	
// her adýmda tahta güncellenmeli ve hamle sayýsý gösterilmeli ( + puan da olabilir)

// yönler U,D,L,R

// oyun tamamlanýnca kaç hamlede tüm meyveleri yedi, yazdýr

// duvara çarpýnca oyun sonlanmalý , kaybettiniz mesajý:
	
	// hamle sayýsý, yýlan büyüklüðü ve geriye kalan yemek sayýsý yazdýr.
	
// yýlan yemek yediði kareye gelince deðil, hareket edince büyümeli

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// rand() % 6 + 1; ( %6 bitiþ deðeri, +x = kaydýrma deðeri)[1,6]

int main(){
	// tahta boyutlarý input ( M X N )
	int M,N,i,j,game;
	int yemek_sayisi,yemek_x,yemek_y;
	int yilan_x,yilan_y;
	char hareket;
	
	printf("Tahta boyutlarini M x N seklinde giriniz:\n");
	scanf("%d",&M);	
	scanf("%d",&N);
	
	// yemek sayýsý input :
	printf("Yemek sayisini giriniz (Tahta boyutundan fazla olamaz!\n)");
	scanf("%d",&yemek_sayisi);
	
	// tahtaya sýðan yemek sayýsý kontrol edilmeli, gerekirse tekrar alýnmalý
	while(yemek_sayisi >= (M*N) ){
		if(yemek_sayisi >= (M*N)){
		printf("Daha kucuk bir sayi giriniz !!\n");
		scanf("%d",&yemek_sayisi);
		}
	}
	
	// oyun tahtasý oluþturalým
	char tablo[M][N];
	
	for(i=0;i<M;i++){
		for(j=0;j<N;j++){
			tablo[i][j]='_';
		}
	}
	
	// olasý bir hata:
			// içinde zaten 0 olan bir hücreye 0 tekrar 0 koyup daha az meyve yerleþtirebilir, diklkat et. if ile içini kontrol ettir.
	// yemek pozisyonu
	i= yemek_sayisi;
	while( i>0 ){
		yemek_x= rand() % M;
		yemek_y= rand() % N;
		
		if(tablo[yemek_x][yemek_y] =='_'){
			tablo[yemek_x][yemek_y]='0';	
			i -= 1;
		}
	}
	// yýlan baþlangýç pozisyonu
	srand(time(NULL));
	j=1;
	while(j != 0){
		yilan_x= rand() % M;
		yilan_y= rand() % N;
		
		if(tablo[yilan_x][yilan_y] =='_' ){
			tablo[yilan_x][yilan_y]='1';	
			j -= 1;
		}
	}
	
	// tabloyu bastýralým
	for(i=0;i<M;i++){
		for(j=0;j<N;j++){
			printf("%c ",tablo[i][j]);
		}
		printf("\n");
	}

	game = 1;
	while(game == 1){
		//process
		printf("Hareket yonunu gir: ");
		scanf("%s",&hareket);
		
		if(hareket=='u' || hareket=='d' || hareket=='l' || hareket=='r'){
			if(hareket=='u'){
				printf("up\n");
			}
			else if(hareket=='d'){
				printf("down\n");
			}
			else if(hareket=='l'){
				printf("left\n");
			}
			else if(hareket=='r'){
				printf("right\n");
			}
		}
		else{
			printf("Hatali tus basimi,Yeni ");
		}
	}
	
	
	return 0;
	
}                   

