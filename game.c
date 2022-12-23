// y�lan[tahta boyutu][1][1] = uzunluk,x kor., y kor

// son yeme�i yedi�inde boyutu 1 artt�r�p ya da o halini ekrana yazd�rabilirsin.

// boyut 10 olsun. son yeme�i yedi�inde 11 de bast�rabilirsin 10 da

// yaz�lar� renklendirmek i�in kutuphane kullanabilrisin

// kendin fonk. yaz


// y�lan (1-n) , yemekler 0, di�erleri bo�luk

// kuyruk b�y�yecek ( b�y�me bir sonraki hamlede ger�ekle�ecek)




	

	
// her ad�mda tahta g�ncellenmeli ve hamle say�s� g�sterilmeli ( + puan da olabilir)

// y�nler U,D,L,R

// oyun tamamlan�nca ka� hamlede t�m meyveleri yedi, yazd�r

// duvara �arp�nca oyun sonlanmal� , kaybettiniz mesaj�:
	
	// hamle say�s�, y�lan b�y�kl��� ve geriye kalan yemek say�s� yazd�r.
	
// y�lan yemek yedi�i kareye gelince de�il, hareket edince b�y�meli

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// rand() % 6 + 1; ( %6 biti� de�eri, +x = kayd�rma de�eri)[1,6]

int main(){
	// tahta boyutlar� input ( M X N )
	int M,N,i,j,game;
	int yemek_sayisi,yemek_x,yemek_y;
	int yilan_x,yilan_y;
	char hareket;
	
	printf("Tahta boyutlarini M x N seklinde giriniz:\n");
	scanf("%d",&M);	
	scanf("%d",&N);
	
	// yemek say�s� input :
	printf("Yemek sayisini giriniz (Tahta boyutundan fazla olamaz!\n)");
	scanf("%d",&yemek_sayisi);
	
	// tahtaya s��an yemek say�s� kontrol edilmeli, gerekirse tekrar al�nmal�
	while(yemek_sayisi >= (M*N) ){
		if(yemek_sayisi >= (M*N)){
		printf("Daha kucuk bir sayi giriniz !!\n");
		scanf("%d",&yemek_sayisi);
		}
	}
	
	// oyun tahtas� olu�tural�m
	char tablo[M][N];
	
	for(i=0;i<M;i++){
		for(j=0;j<N;j++){
			tablo[i][j]='_';
		}
	}
	
	// olas� bir hata:
			// i�inde zaten 0 olan bir h�creye 0 tekrar 0 koyup daha az meyve yerle�tirebilir, diklkat et. if ile i�ini kontrol ettir.
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
	// y�lan ba�lang�� pozisyonu
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
	
	// tabloyu bast�ral�m
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

