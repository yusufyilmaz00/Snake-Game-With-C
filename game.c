// yýlan[tahta boyutu][1][1] = uzunluk,x kor., y kor

// son yemeði yediðinde boyutu 1 arttýrýp ya da o halini ekrana yazdýrabilirsin.

// boyut 10 olsun. son yemeði yediðinde 11 de bastýrabilirsin 10 da

// yazýlarý renklendirmek için kutuphane kullanabilrisin

// kendin fonk. yaz

// kuyruk büyüyecek ( büyüme bir sonraki hamlede gerçekleþecek)

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
	int M,N,i,j,game,hamle_sayisi;
	int yemek_sayisi,yemek_row,yemek_col;
	int yilan_row,yilan_col,row_degis,col_degis;
	char hareket;
	
	printf("Tahta boyutlarini M x N seklinde giriniz:\n");
	scanf("%d",&M);	
	scanf("%d",&N);
	
	// yemek sayýsý input :
	printf("Yemek sayisini giriniz (Tahta boyutundan fazla olamaz!\n)");
	scanf("%d",&yemek_sayisi);
	
	// tahtaya sýðan yemek sayýsý kontrol edilmeli, gerekirse tekrar alýnmalý
	while(yemek_sayisi >= (M*N) ){
		printf("Daha kucuk bir sayi giriniz !!\n");
		scanf("%d",&yemek_sayisi);
	}
	
	// oyun tahtasý oluþtur
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
		yemek_row= rand() % M;
		yemek_col= rand() % N;
		
		if(tablo[yemek_row][yemek_col] =='_'){
			tablo[yemek_row][yemek_col]='0';	
			i -= 1;
		}
	}
	
	// yýlan koordinatlarý
	int yilan[M*N][3];
	int max_boyut;
	max_boyut=1;
	
	// yýlan baþlangýç pozisyonu
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
		
		//güncel tabloyu bastýr
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

		// yönler U,D,L,R
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
			
			// yilan koordinatlarý güncelle
			for(i=0;i<max_boyut;i++){
				yilan[i][1] += row_degis;
				yilan[i][2] += col_degis;
			}
			
			// Yýlanýn kafasý duvara çarptý mý ??
			yilan_row = yilan[0][1];
			yilan_col = yilan[0][2];

			if(yilan_row<0 || yilan_row>=M || yilan_col<0 || yilan_col >=N){
				game = 0;
				printf("Kaybettiniz....\n\n");
				printf("Toplam Hamle:%d\nYilan Buyuklugu:%d\nKalan Yemek Sayisi:%d\n",hamle_sayisi,max_boyut,yemek_sayisi);
			}
			
			// haritayý sýfýrlar --meyveler hariç
			for(i=0;i<M;i++){
				for(j=0;j<N;j++){
					if( tablo[i][j] !='0' ){
						tablo[i][j] = '_';
					}
 				}
			}

			// yeni koordinatlarý gir
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
