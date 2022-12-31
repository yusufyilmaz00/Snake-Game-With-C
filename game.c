#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(){
	int M,N,i,j,game,hamle_sayisi,is_eat;
	int yemek_sayisi,yemek_row,yemek_col;
	int yilan_row,yilan_col,row_degis,col_degis;
	char hareket;
	
	// tahta boyutlarý input ( M X N )
	printf("Tahta boyutlarini M x N seklinde giriniz:\n");
	scanf("%d",&M);	
	scanf("%d",&N);
	
	// yemek sayýsý input :
	printf("Yemek sayisini giriniz(Tahta boyutundan fazla olamaz!)\n");
	scanf("%d",&yemek_sayisi);
	
	// tahtaya sýðan yemek sayýsý kontrol edilmeli, gerekirse tekrar alýnmalý
	while(yemek_sayisi >= (M*N) ){
		printf("Daha kucuk bir sayi giriniz !!\n");
		scanf("%d\n",&yemek_sayisi);
	}
	
	// oyun tahtasý oluþtur
	int tablo[100][100];
	
	for(i=0;i<M;i++){
		for(j=0;j<N;j++){
			tablo[i][j]=-1;
		}
	}
	// yýlan koordinatlarý
	int yilan[200][3];
	int max_boyut;
	max_boyut=1;
	
	//yýlan baþlangýc pozisyonu
	yilan_row= rand() % M;
	yilan_col= rand() % N;
	
	tablo[yilan_row][yilan_col]=1;	
	
	yilan[max_boyut-1][0] = max_boyut;
	yilan[max_boyut-1][1] = yilan_row;
	yilan[max_boyut-1][2] = yilan_col;
	
	// olasý bir hata:
			// içinde zaten 0 olan bir hücreye 0 tekrar 0 koyup daha az meyve yerleþtirebilir, diklkat et. if ile içini kontrol ettir.
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

		//güncel tabloyu bastýr
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
		scanf(" %c",&hareket);    // ("%s",&hareket) ----->  (" %c",&hareket) yapýlarak bug çözüldü
		printf("------------\n");

		// yönler U,D,L,R
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
			
			// yýlanýn kafasýnýn yeni koordinatlarý
			yilan_row = yilan[0][1] + row_degis;
			yilan_col = yilan[0][2] + col_degis;
			
			// Yýlanýn kafasý duvara çarptý mý ??
			if(yilan_row<0 || yilan_row>=M || yilan_col<0 || yilan_col >=N){
				game = 0;
				printf("Kaybettiniz....\n\n");
				printf("Toplam Hamle:%d\nYilan Buyuklugu:%d\nKalan Yemek Sayisi:%d\n",hamle_sayisi,max_boyut,yemek_sayisi);
			}
			
			is_eat=0;
			// Yýlanýn meyve yedi mi ?
			if(tablo[yilan_row][yilan_col]== 0){
				is_eat=1;
			}
			
			// yilan kuyruk koordinatlarý güncelle ( kaydýrarak)
			for(i=max_boyut-1;i>0;i--){  // sondan baþa git, soldaki kordinatý saðdakine aktar
 				yilan[i][1] = yilan[i-1][1];
				yilan[i][2] = yilan[i-1][2];
			}
			// kafa koordinatlarý güncelle
			yilan[0][1] += row_degis;
			yilan[0][2] += col_degis;
			
			// haritayý sýfýrlar --meyveler hariç
			for(i=0;i<M;i++){
				for(j=0;j<N;j++){
					if( tablo[i][j] != 0 ){
						tablo[i][j] = -1;
					}
 				}
			}

			// yeni koordinatlarý gir
			for(i=0;i<max_boyut;i++){
				yilan_row = yilan[i][1];
				yilan_col = yilan[i][2];
				tablo[yilan_row][yilan_col] = yilan[i][0];
			}
			// yemek sayýsý azaltma ve kuyruk
			if(is_eat==1){
				yemek_sayisi -= 1;
				max_boyut +=1; 
				// kuyruk ekleyelim
				yilan[max_boyut-1][0]= max_boyut;
				yilan[max_boyut-1][1]= 0; // herhangi bir sayý yazabilirim. 
				yilan[max_boyut-1][2]= 0; // çünkü zaten koordinatlar güncellenirken olmasý gerek koordinatý alacak
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
