#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(){
	int M,N,i,j,game,hamle_sayisi,is_eat;
	int yemek_sayisi,yemek_row,yemek_col;
	int yilan_row,yilan_col,row_degis,col_degis;
	char hareket;
	
	// tahta boyutlar� input ( M X N )
	printf("Tahta boyutlarini M x N seklinde giriniz:\n");
	scanf("%d",&M);	
	scanf("%d",&N);
	
	// yemek say�s� input :
	printf("Yemek sayisini giriniz(Tahta boyutundan fazla olamaz!)\n");
	scanf("%d",&yemek_sayisi);
	
	// tahtaya s��an yemek say�s� kontrol edilmeli, gerekirse tekrar al�nmal�
	while(yemek_sayisi >= (M*N) ){
		printf("Daha kucuk bir sayi giriniz !!\n");
		scanf("%d\n",&yemek_sayisi);
	}
	
	// oyun tahtas� olu�tur
	int tablo[100][100];
	
	for(i=0;i<M;i++){
		for(j=0;j<N;j++){
			tablo[i][j]=-1;
		}
	}
	// y�lan koordinatlar�
	int yilan[200][3];
	int max_boyut;
	max_boyut=1;
	
	//y�lan ba�lang�c pozisyonu
	yilan_row= rand() % M;
	yilan_col= rand() % N;
	
	tablo[yilan_row][yilan_col]=1;	
	
	yilan[max_boyut-1][0] = max_boyut;
	yilan[max_boyut-1][1] = yilan_row;
	yilan[max_boyut-1][2] = yilan_col;
	
	// olas� bir hata:
			// i�inde zaten 0 olan bir h�creye 0 tekrar 0 koyup daha az meyve yerle�tirebilir, diklkat et. if ile i�ini kontrol ettir.
	// yemek pozisyonu
	i= yemek_sayisi;
	srand(time(NULL));
	while( i>0 ){
		yemek_row= rand() % M;
		yemek_col= rand() % N;
		
		if(tablo[yemek_row][yemek_col] ==-1){
			tablo[yemek_row][yemek_col]=0;	
			i -= 1;
		}
	}
	
	game = 1;
	hamle_sayisi=0;
	while(game == 1 && yemek_sayisi>0){

		//g�ncel tabloyu bast�r
		for(i=0;i<M;i++){
			for(j=0;j<N;j++){
				if(tablo[i][j] == -1){
					printf("  |");
				}
				else if(tablo[i][j] <=9 ){
					printf("%d |",tablo[i][j]);
				}
				else if(tablo[i][j] >9 ){
					printf("%d|",tablo[i][j]);
				}
			}
			printf("\n");
		}
		printf("------------\nToplam Hamle Sayisi: %d\n------------\n",hamle_sayisi);
		
		//process	
		printf("Hareket yonunu gir: ");
		scanf(" %c",&hareket);    // ("%s",&hareket) ----->  (" %c",&hareket) yap�larak bug ��z�ld�
		printf("------------\n");

		// y�nler U,D,L,R
		if(hareket=='u' || hareket=='d' || hareket=='l' || hareket=='r'){
			if(hareket=='u'){
				row_degis = -1;	
				col_degis = 0;
			}
			else if(hareket=='d'){
				row_degis = 1;
				col_degis = 0;
			}
			else if(hareket=='l'){
				row_degis = 0;
				col_degis = -1;
			}
			else if(hareket=='r'){
				row_degis = 0;
				col_degis = 1;
			}
	
			hamle_sayisi +=1;
			
			// y�lan�n kafas�n�n yeni koordinatlar�
			yilan_row = yilan[0][1] + row_degis;
			yilan_col = yilan[0][2] + col_degis;
			
			// Y�lan�n kafas� duvara �arpt� m� ??
			if(yilan_row<0 || yilan_row>=M || yilan_col<0 || yilan_col >=N){
				game = 0;
				printf("Kaybettiniz....\n\n");
				printf("Toplam Hamle:%d\nYilan Buyuklugu:%d\nKalan Yemek Sayisi:%d\n",hamle_sayisi,max_boyut,yemek_sayisi);
			}
			
			is_eat=0;
			// Y�lan�n meyve yedi mi ?
			if(tablo[yilan_row][yilan_col]== 0){
				is_eat=1;
			}
			
			// yilan kuyruk koordinatlar� g�ncelle ( kayd�rarak)
			for(i=max_boyut-1;i>0;i--){  // sondan ba�a git, soldaki kordinat� sa�dakine aktar
 				yilan[i][1] = yilan[i-1][1];
				yilan[i][2] = yilan[i-1][2];
			}
			// kafa koordinatlar� g�ncelle
			yilan[0][1] += row_degis;
			yilan[0][2] += col_degis;
			
			// haritay� s�f�rlar --meyveler hari�
			for(i=0;i<M;i++){
				for(j=0;j<N;j++){
					if( tablo[i][j] != 0 ){
						tablo[i][j] = -1;
					}
 				}
			}

			// yeni koordinatlar� gir
			for(i=0;i<max_boyut;i++){
				yilan_row = yilan[i][1];
				yilan_col = yilan[i][2];
				tablo[yilan_row][yilan_col] = yilan[i][0];
			}
			// yemek say�s� azaltma ve kuyruk
			if(is_eat==1){
				yemek_sayisi -= 1;
				max_boyut +=1; 
				// kuyruk ekleyelim
				yilan[max_boyut-1][0]= max_boyut;
				yilan[max_boyut-1][1]= 0; // herhangi bir say� yazabilirim. 
				yilan[max_boyut-1][2]= 0; // ��nk� zaten koordinatlar g�ncellenirken olmas� gerek koordinat� alacak
			}
		//if bitiyor	
		}
		else{
			printf("Hatali tus basimi,tekrar yon belirtin\n------------\n");
		}
	}
	if(yemek_sayisi==0){
		printf("\nTebriklerr !\n\nTum meyveleri yediniz\n\nYaptiginiz toplam hamle sayisi:%d\nMax Yilan Boyutu:%d",hamle_sayisi,max_boyut);
	}
	return 0;
}                   
