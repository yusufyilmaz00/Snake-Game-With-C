// y�lan[tahta boyutu][1][1] = uzunluk,x kor., y kor

// son yeme�i yedi�inde boyutu 1 artt�r�p ya da o halini ekrana yazd�rabilirsin.

// boyut 10 olsun. son yeme�i yedi�inde 11 de bast�rabilirsin 10 da

// yaz�lar� renklendirmek i�in kutuphane kullanabilrisin

// kendin fonk. yaz

// kuyruk b�y�yecek ( b�y�me bir sonraki hamlede ger�ekle�ecek)

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
	int M,N,i,j,game,hamle_sayisi;
	int yemek_sayisi,yemek_row,yemek_col;
	int yilan_row,yilan_col,row_degis,col_degis;
	char hareket;
	
	printf("Tahta boyutlarini M x N seklinde giriniz:\n");
	scanf("%d",&M);	
	scanf("%d",&N);
	
	// yemek say�s� input :
	printf("Yemek sayisini giriniz (Tahta boyutundan fazla olamaz!\n)");
	scanf("%d",&yemek_sayisi);
	
	// tahtaya s��an yemek say�s� kontrol edilmeli, gerekirse tekrar al�nmal�
	while(yemek_sayisi >= (M*N) ){
		printf("Daha kucuk bir sayi giriniz !!\n");
		scanf("%d",&yemek_sayisi);
	}
	
	// oyun tahtas� olu�tur
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
		yemek_row= rand() % M;
		yemek_col= rand() % N;
		
		if(tablo[yemek_row][yemek_col] =='_'){
			tablo[yemek_row][yemek_col]='0';	
			i -= 1;
		}
	}
	
	// y�lan koordinatlar�
	int yilan[M*N][3];
	int max_boyut;
	max_boyut=1;
	
	// y�lan ba�lang�� pozisyonu
	srand(time(NULL));
	j=1;
	while(j != 0){
		yilan_row= rand() % M;
		yilan_col= rand() % N;
		
		if(tablo[yilan_row][yilan_col] =='_' ){
			tablo[yilan_row][yilan_col]='1';	
			yilan[max_boyut-1][0] = max_boyut;
			yilan[max_boyut-1][1] = yilan_row;
			yilan[max_boyut-1][2] = yilan_col;
			j -= 1;
		}
	}

	game = 1;
	hamle_sayisi=0;
	while(game == 1 && yemek_sayisi>0){
		
		//g�ncel tabloyu bast�r
		for(i=0;i<M;i++){
			for(j=0;j<N;j++){
				printf("%c ",tablo[i][j]);
			}
			printf("\n");
		}
		printf("------------\nToplam Hamle Sayisi: %d\n------------\n",hamle_sayisi);
		
		//process	
		printf("Hareket yonunu gir: ");
		scanf("%s",&hareket);
		printf("------------\n");

		// y�nler U,D,L,R
		if(hareket=='u' || hareket=='d' || hareket=='l' || hareket=='r'){
			if(hareket=='u'){
				row_degis = -1;	
				col_degis = 0;
				hamle_sayisi +=1;
			}
			else if(hareket=='d'){
				row_degis = 1;
				col_degis = 0;
				hamle_sayisi +=1;
			}
			else if(hareket=='l'){
				row_degis = 0;
				col_degis = -1;
				hamle_sayisi +=1;
			}
			else if(hareket=='r'){
				row_degis = 0;
				col_degis = 1;
				hamle_sayisi +=1;
			}
			
			// yilan koordinatlar� g�ncelle
			for(i=0;i<max_boyut;i++){
				yilan[i][1] += row_degis;
				yilan[i][2] += col_degis;
			}
			
			// Y�lan�n kafas� duvara �arpt� m� ??
			yilan_row = yilan[0][1];
			yilan_col = yilan[0][2];

			if(yilan_row<0 || yilan_row>=M || yilan_col<0 || yilan_col >=N){
				game = 0;
				printf("Kaybettiniz....\n\n");
				printf("Toplam Hamle:%d\nYilan Buyuklugu:%d\nKalan Yemek Sayisi:%d\n",hamle_sayisi,max_boyut,yemek_sayisi);
			}
			
			// haritay� s�f�rlar --meyveler hari�
			for(i=0;i<M;i++){
				for(j=0;j<N;j++){
					if( tablo[i][j] !='0' ){
						tablo[i][j] = '_';
					}
 				}
			}

			// yeni koordinatlar� gir
			int kuyruk_no;
			for(i=0;i<max_boyut;i++){
				kuyruk_no = yilan[i][0];
				
				yilan_row = yilan[i][1];
				yilan_col = yilan[i][2];
				tablo[yilan_row][yilan_col] = kuyruk_no ;
			}
		//if bitiyor	
		}
		else{
			printf("Hatali tus basimi,Yeni ");
		}
	}
	return 0;
}                   
