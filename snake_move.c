#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(){
	int M,N,i,j,yilan_x,yilan_y;
	
	/*
	printf("Tahta boyutlarini M x N seklinde giriniz:\n");
	scanf("%d",&M);	
	scanf("%d",&N);
	*/
	M=7;
	N=7;
	
	// tablo oluþtur
	char tablo[M][N];
	
	for(i=0;i<M;i++){
		for(j=0;j<N;j++){
			tablo[i][j]='_';
		}
	}
	
	// yýlan koordinatlarý
	int yilan[M*N][3];
	int max_boyut;
	max_boyut=1;
	
	// yýlaný rastgele canlandýr
	srand(time(NULL));
	j=1;
	while(j != 0){
		yilan_x= rand() % M;
		yilan_y= rand() % N;
		
		if(tablo[yilan_x][yilan_y] =='_' ){
			//tablo[yilan_x][yilan_y]='1';
				
			yilan[max_boyut-1][0] = max_boyut;
			yilan[max_boyut-1][1] = yilan_x;
			yilan[max_boyut-1][2] = yilan_y;
			j -= 1;
		}
	}
	printf("rastgele\n");
	char game='T';
	char hareket;
	int x_degis,y_degis;
	
	
	while(game=='T'){
		printf(" test 0 :%c\n ",game);
		// tabloyu güncelle;
		for(i=0;i<max_boyut;i++){
			for(j=0;j<3;j++){
				if( yilan[i][0]>0){	
					yilan_x= yilan[i][1];
					yilan_y= yilan[i][2];
					tablo[yilan_x][yilan_y] = (char) yilan[i][0];
				}
			}
		}
		printf(" test 1 :%c\n ",game);
		printf("tabloyu bas\n");
		
		for(i=0;i<M;i++){
			for(j=0;j<N;j++){
				printf("%c ",tablo[i][j]);
			}
			printf("\n");
		}
		printf(" test 2 :%c\n ",game);
		//process
		printf("Hareket yonunu gir: ");
		scanf("%s",&hareket);
		
		if(hareket=='u' || hareket=='d' || hareket=='l' || hareket=='r'){
			//oyun devam
			if(hareket=='u'){
				x_degis = 0;
				y_degis = 1;
				game = 'T';
				printf(" test up :%c\n ",game);
				printf("yukari\n");
			}
			else if(hareket=='d'){
				x_degis = 0;
				y_degis = -1;
				printf(" test down :%c\n ",game);
				printf("asagi\n");
			}
			else if(hareket=='l'){
				x_degis = -1;
				y_degis = 0;
				printf(" test left :%c\n ",game);
				printf("sol\n");
			}
			else if(hareket=='r'){
				x_degis = 1;
				y_degis = 0;
				printf(" test right :%c\n ",game);
				printf("sag\n");
			}
			
			// yýlanýn koordinatlarýný güncelle
			for(i=0;i<max_boyut;i++){
					yilan[i][1] += x_degis;
					yilan[i][2] += y_degis;
				}
			printf("yilan da guncel\n");	
			// if bitiren poarantez	
			}
		else{
			printf("Hatali tus basimi,Yeni ");
		}
		printf("%d test son : ",game);
		//oyun bitiren parantez
	}
	
	
	
	return 0;
}
