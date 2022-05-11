#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h>
int main()
{
	//Rastgele de�i�ken atamalar� i�in kullan�ld�.
	srand(time(NULL));
	//Program i�in tan�mlanan ya da ilk de�er atanan de�i�kenler.
	int i,j,k,tmp,r1,r2,r3,r4,point=0,prepoint=0,empty=0,boole=0;
	int pre[4][4]={{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}};
	int cur[4][4]={{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}};
	char c[4]={48,48,48,48};
	char button;
	//Rastgele ilk iki matris de�er koordinatlar�n�n birbiri ile �ak��mamas� i�in yap�lan kontrol
	while(boole==0){
		r1 = rand() % 4;
		r2 = rand() % 4;
		r3 = rand() % 4;
		r4 = rand() % 4;
		pre[r1][r2]=2;
		pre[r3][r4]=2;
		if(r1!=r3 || r2!=r4){
			boole=1;
		}
		else{
			pre[r1][r2]=0;
			pre[r3][r4]=0;
		}
	}
	//boole de�i�keninin sonradan da kullan�lmas� i�in tekrar '0' yap�ld�
	boole=0;
	//Program ilk a��ld���nda ekrana yazd�r�lacak yaz�lar
	printf("\n");
	printf("for up move press 'w', for down move press 's'\n");
	printf("for left move press 'a', for right move press 'd'\n");
	printf("for previous state press 'r', for exit press 'e'\n");
	printf("for restart press x\n");
	printf("\n");
	//�nceki durum (previous) matrisini, �imdiki durum (current) matrisine atama i�lemi
	for(i=0;i<4;i++){
			for(j=0;j<4;j++){
				cur[i][j]=pre[i][j];
			}
		}
	//Ekrana yazd�rma (previous state)
	printf(" ______ ______ ______ ______ \n");
	for(i=0;i<4;i++){
		printf("|      |      |      |      |\n");
		printf("|");
		//matristeki de�erin basamak say�s�na g�re ekrana yazd�rma i�lemi
		for(j=0;j<4;j++){
			if(pre[i][j]==0){
				c[0]=' ';
				c[1]=' ';
				c[2]=' ';
				c[3]=' ';
			}
			else if(pre[i][j]>999){
				tmp=pre[i][j]%10;
				c[3]=tmp+48;
				tmp=pre[i][j]/10;
				tmp=tmp%10;
				c[2]=tmp+48;
				tmp=pre[i][j]/100;
				tmp=tmp%10;
				c[1]=tmp+48;
				tmp=pre[i][j]/1000;
				c[0]=tmp+48;
			}
			else if(pre[i][j]>99){
				tmp=pre[i][j]%10;
				c[3]=tmp+48;
				tmp=pre[i][j]/10;
				tmp=tmp%10;
				c[2]=tmp+48;
				tmp=pre[i][j]/100;
				c[1]=tmp+48;
				c[0]=' ';
			}
			else if(pre[i][j]>9){
				c[0]=' ';
				tmp = pre[i][j] / 10;
				c[1]=tmp + 48;
				tmp = pre[i][j] % 10;
				c[2]=tmp + 48;
				c[3]=' ';
			}
			else{
				c[0]=' ';
				c[1]=' ';
				c[2]=pre[i][j]+48;
				c[3]=' ';
			}
			printf(" %c%c%c%c |",c[0],c[1],c[2],c[3]);
		}
		printf("\n");
		printf("|______|______|______|______|\n");
	}
		printf("\n");
	do {
    	button = getch();
    	//'R' butonuna bas�ld���nda yap�lacaklar
    	if((button=='r')||(button=='R')){
    		system("CLS");
			printf("r'ye bastiniz\n");
			for(i=0;i<4;i++){
				for(j=0;j<4;j++){
					cur[i][j]=pre[i][j];
				}
			}
			//Bo� kutucuk kontrol�
			for(i=0;i<4;i++){
				for(j=0;j<4;j++){
					if(cur[i][j]==0){
						empty=empty+1;
					}
				}
			}
			//Random alana de�er atama
			if(empty!=0){
				while(boole==0){
					r1 = rand() % 4;
					r2 = rand() % 4;
					if(cur[r1][r2]==0){
						cur[r1][r2]=2;
						boole=1;
					}
				}
			}
			point=prepoint;
		}
		else{
			system("CLS");
			for(i=0;i<4;i++){
				for(j=0;j<4;j++){
					pre[i][j]=cur[i][j];
				}
			}	
		}
		//'W' butonuna bas�ld���nda yap�lacaklar
    	if((button=='w')||(button=='W')){
    		system("CLS");
    		printf("w'ya bastiniz\n");
    		prepoint=point;
    		//yukar� s�ralama
			for(i=0;i<4;i++){
				for(j=1;j<4;j++){
					if(cur[j][i]!=0){
						for(k=0;k<j;k++){
							if(cur[k][i]==0){
								tmp=cur[j][i];
								cur[j][i]=cur[k][i];
								cur[k][i]=tmp;
							}
						}
					}
				}
			}
			//yukar� i�lemi
			for(i=0;i<4;i++){
				for(j=0;j<3;j++){
					if(cur[j][i]==cur[j+1][i]){
						cur[j][i]=cur[j][i]*2;
						point=point+cur[j][i];
						for(k=j+1;k<3;k++){
							cur[k][i]=cur[k+1][i];
						}
						cur[3][i]=0;
					}
				}
			}
			//Bo� kutucuk kontrol�
			for(i=0;i<4;i++){
				for(j=0;j<4;j++){
					if(cur[i][j]==0){
						empty=empty+1;
					}
				}
			}
			//Random alana de�er atama
			if(empty!=0){
				while(boole==0){
					r1 = rand() % 4;
					r2 = rand() % 4;
					if(cur[r1][r2]==0){
						cur[r1][r2]=2;
						boole=1;
					}
				}
			}
		}
		//'S' butonuna bas�ld���nda yap�lacaklar
		if((button=='s')||(button=='S')){
    		system("CLS");
			printf("s'ye bastiniz\n");
			prepoint=point;
			//a�a�� s�ralama
			for(i=0;i<4;i++){
				for(j=2;j>=0;j--){
					if(cur[j][i]!=0){
						for(k=3;k>j;k--){
							if(cur[k][i]==0){
								tmp=cur[j][i];
								cur[j][i]=cur[k][i];
								cur[k][i]=tmp;
							}
						}
					}
				}
			}
			//a�a�� i�lemi
			for(i=0;i<4;i++){
				for(j=3;j>0;j--){
					if(cur[j][i]==cur[j-1][i]){
						cur[j][i]=cur[j][i]*2;
						point=point+cur[j][i];
						for(k=j-1;k>0;k--){
							cur[k][i]=cur[k-1][i];
						}
						cur[0][i]=0;
					}
				}
			}
			//Bo� kutucuk kontrol�
			for(i=0;i<4;i++){
				for(j=0;j<4;j++){
					if(cur[i][j]==0){
						empty=empty+1;
					}
				}
			}
			//Random alana de�er atama
			if(empty!=0){
				while(boole==0){
					r1 = rand() % 4;
					r2 = rand() % 4;
					if(cur[r1][r2]==0){
						cur[r1][r2]=2;
						boole=1;
					}
				}
			}
		}
		//'A' butonuna bas�ld���nda yap�lacaklar
		if((button=='a')||(button=='A')){
    		system("CLS");
			printf("a'ya bastiniz\n");
			prepoint=point;
			//sola s�ralama
			for(i=0;i<4;i++){
				for(j=1;j<4;j++){
					if(cur[i][j]!=0){
						for(k=0;k<j;k++){
							if(cur[i][k]==0){
								tmp=cur[i][j];
								cur[i][j]=cur[i][k];
								cur[i][k]=tmp;
							}
						}
					}
				}
			}
			//sol i�lemi
			for(i=0;i<4;i++){
				for(j=0;j<3;j++){
					if(cur[i][j]==cur[i][j+1]){
						cur[i][j]=cur[i][j]*2;
						point=point+cur[i][j];
						for(k=j+1;k<3;k++){
							cur[i][k]=cur[i][k+1];
						}
						cur[i][3]=0;
					}
				}
			}
			//Bo� kutucuk kontrol�
			for(i=0;i<4;i++){
				for(j=0;j<4;j++){
					if(cur[i][j]==0){
						empty=empty+1;
					}
				}
			}
			//Random alana de�er atama
			if(empty!=0){
				while(boole==0){
					r1 = rand() % 4;
					r2 = rand() % 4;
					if(cur[r1][r2]==0){
						cur[r1][r2]=2;
						boole=1;
					}
				}
			}
		}
		//'D' butonuna bas�ld���nda yap�lacaklar
		if((button=='d')||(button=='D')){
    		system("CLS");
			printf("d'ye bastiniz\n");
			prepoint=point;
			//sa�a s�ralama
			for(i=0;i<4;i++){
				for(j=2;j>=0;j--){
					if(cur[i][j]!=0){
						for(k=3;k>j;k--){
							if(cur[i][k]==0){
								tmp=cur[i][j];
								cur[i][j]=cur[i][k];
								cur[i][k]=tmp;
							}
						}
					}
				}
			}
			//sa� i�lemi
			for(i=0;i<4;i++){
				for(j=3;j>0;j--){
					if(cur[i][j]==cur[i][j-1]){
						cur[i][j]=cur[i][j]*2;
						point=point+cur[i][j];
						for(k=j-1;k>0;k--){
							cur[i][k]=cur[i][k-1];
						}
						cur[i][0]=0;
					}
				}
			}
			//Bo� kutucuk kontrol�
			for(i=0;i<4;i++){
				for(j=0;j<4;j++){
					if(cur[i][j]==0){
						empty=empty+1;
					}
				}
			}
			//Random alana de�er atama
			if(empty!=0){
				while(boole==0){
					r1 = rand() % 4;
					r2 = rand() % 4;
					if(cur[r1][r2]==0){
						cur[r1][r2]=2;
						boole=1;
					}
				}
			}
		}
		//'X' butonuna bas�ld���nda yap�lacaklar
		if((button=='x')||(button=='X')){
			//De�erleri s�f�rlama
			for(i=0;i<4;i++){
				for(j=0;j<4;j++){
					cur[i][j]=0;
					pre[i][j]=0;
				}
			}
			//Random ilk iki de�er atama
			while(boole==0){
				r1 = rand() % 4;
				r2 = rand() % 4;
				r3 = rand() % 4;
				r4 = rand() % 4;
				pre[r1][r2]=2;
				pre[r3][r4]=2;
				if(r1!=r3 || r2!=r4){
					boole=1;
				}
				else{
					pre[r1][r2]=0;
					pre[r3][r4]=0;
				}
			}
			for(i=0;i<4;i++){
				for(j=0;j<4;j++){
					cur[i][j]=pre[i][j];
				}
			}
			point=0;
			prepoint=0;
		}
		printf("\n");
		boole=0;
		empty=0;
		printf("for up move press 'w', for down move press 's'\n");
		printf("for left move press 'a', for right move press 'd'\n");
		printf("for previous state press 'r', for exit press 'e'\n");
		printf("for restart press x\n");
		printf("\n");
		printf("Previous State: ");
		printf("\n");
		//Ekrana yazd�rma (previous)
		printf(" ______ ______ ______ ______ \n");
		for(i=0;i<4;i++){
			printf("|      |      |      |      |\n");
			printf("|");
			for(j=0;j<4;j++){
				if(pre[i][j]==0){
					c[0]=' ';
					c[1]=' ';
					c[2]=' ';
					c[3]=' ';
				}
				else if(pre[i][j]>999){
					tmp=pre[i][j]%10;
					c[3]=tmp+48;
					tmp=pre[i][j]/10;
					tmp=tmp%10;
					c[2]=tmp+48;
					tmp=pre[i][j]/100;
					tmp=tmp%10;
					c[1]=tmp+48;
					tmp=pre[i][j]/1000;
					c[0]=tmp+48;
				}
				else if(pre[i][j]>99){
					tmp=pre[i][j]%10;
					c[3]=tmp+48;
					tmp=pre[i][j]/10;
					tmp=tmp%10;
					c[2]=tmp+48;
					tmp=pre[i][j]/100;
					c[1]=tmp+48;
					c[0]=' ';
				}
				else if(pre[i][j]>9){
					c[0]=' ';
					tmp = pre[i][j] / 10;
					c[1]=tmp + 48;
					tmp = pre[i][j] % 10;
					c[2]=tmp + 48;
					c[3]=' ';
				}
				else{
					c[0]=' ';
					c[1]=' ';
					c[2]=pre[i][j]+48;
					c[3]=' ';
				}
				printf(" %c%c%c%c |",c[0],c[1],c[2],c[3]);
			}
			printf("\n");
			printf("|______|______|______|______|\n");
		}
		printf("\n");
		printf("Current State: ");
		printf("\n");
		//Ekrana yazd�rma (current)
		printf(" ______ ______ ______ ______ \n");
		for(i=0;i<4;i++){
			printf("|      |      |      |      |\n");
			printf("|");
			for(j=0;j<4;j++){
				if(cur[i][j]==0){
					c[0]=' ';
					c[1]=' ';
					c[2]=' ';
					c[3]=' ';
				}
				else if(cur[i][j]>999){
					tmp=cur[i][j]%10;
					c[3]=tmp+48;
					tmp=cur[i][j]/10;
					tmp=tmp%10;
					c[2]=tmp+48;
					tmp=cur[i][j]/100;
					tmp=tmp%10;
					c[1]=tmp+48;
					tmp=cur[i][j]/1000;
					c[0]=tmp+48;
				}
				else if(cur[i][j]>99){
					tmp=cur[i][j]%10;
					c[3]=tmp+48;
					tmp=cur[i][j]/10;
					tmp=tmp%10;
					c[2]=tmp+48;
					tmp=cur[i][j]/100;
					c[1]=tmp+48;
					c[0]=' ';
				}
					else if(cur[i][j]>9){
					c[0]=' ';
					tmp = cur[i][j] / 10;
					c[1]=tmp + 48;
					tmp = cur[i][j] % 10;
					c[2]=tmp + 48;
					c[3]=' ';
				}
				else{
					c[0]=' ';
					c[1]=' ';
					c[2]=cur[i][j]+48;
					c[3]=' ';
				}
				if(i==r1&&j==r2){
					printf("*%c%c%c%c |",c[0],c[1],c[2],c[3]);
				}
				else{
					printf(" %c%c%c%c |",c[0],c[1],c[2],c[3]);
				}
			}
			printf("\n");
			printf("|______|______|______|______|\n");
		}
		printf("\n");
		//Puan yazd�rma ve ��k��
		printf("Point : %d", point);
	} while ((button != 'e') && (button != 'E'));
	return 0;
}
