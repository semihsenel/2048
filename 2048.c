#include<stdio.h>
#include<windows.h>
#include<time.h>
int renklendir(int sayi){
if (sayi==2){
    return 14;
    }
else if(sayi ==4){
    return 6;
}
else if(sayi == 8){                        // Hangi sayinin hangi renk olacaginin kodu
    return 12;
}
else if(sayi == 16){ 
    return 4;
}
else if(sayi == 32){
    return 5;
}
else if(sayi == 64){
    return 10;
}
else if(sayi == 128){
    return 2;
}
else if(sayi == 256){
    return 9;
}
else if(sayi == 512){
    return 1;
}
else if(sayi==1024){
    return 11;
}
else if(sayi == 2048){
    return 3;
}
}
int main(){
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
	WORD saved_attributes;                              // RENK ICIN GEREKLI KODLAR
    GetConsoleScreenBufferInfo(hConsole,&consoleInfo);
	saved_attributes = consoleInfo.wAttributes;
    srand(time(NULL));
	int main[4][4],ihtimal[10]={2,2,2,2,2,2,2,2,2,4},i,j,k,random1,random2,swap=1,a,end=0;
	int previousscore,highscore=0,score=0,randomat=1,dolu=0,rmatris[4][4];
SetConsoleTextAttribute(hConsole,4);
	printf("****************************************************WELCOME TO 2048****************************************************\n\nPress 'w' to go up\nPress 's' to go down\n");
	printf("Press 'd' to go right\nPress 'a' to go left\nPress 'r' to take your move back\nPress 'x' to restart\nPress 'e' to exit the game\n\n");
SetConsoleTextAttribute(hConsole,saved_attributes);
	for(i=0;i<4;i++){
		for(j=0;j<4;j++){
			main[i][j]=0;
		}
	}

    main[rand()%4][rand()%4]=ihtimal[rand()%10];
	do{
    random1=rand()%4; random2=rand()%4;
	}
	while(main[random1][random2]!=0);           // RANDOM KODU VE ILK MATRÝSÝN YAZDIRILMASI
	main[random1][random2]=ihtimal[rand()%10];
    
	printf("\n");
    printf("_____________________");
    printf("\n");
	for(i=0;i<4;i++){
		printf("|");
        for(j=0;j<4;j++){
			if(main[i][j]==0)
			printf("%4c|",' ');
			else{
            if(main[i][j]==2){
            SetConsoleTextAttribute(hConsole,14);
            printf("%4d",main[i][j]);
            SetConsoleTextAttribute(hConsole,saved_attributes);
            }
            else if(main[i][j]==4){
            SetConsoleTextAttribute(hConsole,6);
            printf("%4d",main[i][j]);
            SetConsoleTextAttribute(hConsole,saved_attributes);
            }
            printf("|");
		}

	}
	printf("\n");
	printf("_____________________");
	printf("\n");
}
	printf("\n\n\n");
	char tus;
	int sayi1,sayi2,sayi3,sayi4,t,yer,start=1;
	while(start==1){
	tus = getch();
	randomat=0;
		if(tus=='a'||tus=='d'||tus=='A'||tus=='D'){
                randomat=1;
                for(i=0;i<4;i++){
				for(j=0;j<4;j++){
					a = main[i][j];
					rmatris[i][j]=a;    // HAMLEYI GERI ALMAK ICIN HER HAMLEDEN ONCE MATRISI BASKA BIR MATRISE ATIYORUM
					main[i][j]=a;
				}
		}
                if(tus=='a'||tus=='A'){                    // D TUÞU ICIN YAZILAN KOD
                   for(i=0;i<4;i++){                       // EGER KULLANICI A'YA BASARSA MATRÝS TERS CEVRILIYOR VE TEKRAR D TUÞUNUN KODLARI CALISIYOR
                        for(j=0;j<2;j++){
                            t=main[i][j];
                            main[i][j]=main[i][3-j];
                            main[i][3-j]=t;
                        }
                    }
                }
			previousscore=score;    // HAMLEYI GERI ALDIGINDA SKORUN ESKIYE DONMESI
			 for(j=0;j<4;j++){
				sayi1=sayi2=sayi3=sayi4=5;
				k=3;
				swap=1;
				while(k>=0&&main[j][k]==0)
				k--;                        // SON SUTUNDAN BASLAYARAK GERIYE DOGRU SAYI VAR MI DIYE KONTROL EDIYORUM
				if(k>=0)
				sayi1=k;

				if(sayi1==0){
					t=main[j][3];
					main[j][3]=main[j][0];  // SADECE ILK SUTUNDA SAYI VARSA DIREKT YER DEGISTIRME YAPIYORUM
					main[j][0]=t;
					}
				k--;
				while(k>=0&&main[j][k]==0)
				k--;
				if(k>=0){
				sayi2=k;
				k--;
				}
				else if(k>=0&&sayi1<3){
					main[j][3]=t;
					main[j][3]=main[j][sayi1];  // SADECE BIR SAYI VARSA SAYIYI SON SUTUNA ALIYORUM
					main[j][sayi1]=t;
				}
				while(k>=0&&main[j][k]==0){
					k--;
				}
				if(k>=0){
					sayi3=k;
				}
				k--;
				while(k>=0&&main[j][k]==0){
					k--;
				}
				if(k==0)
				sayi4=k;
				if(sayi1!=5&&sayi2!=5){
				if(main[j][sayi1]==main[j][sayi2]){
					main[j][sayi1]=main[j][sayi1]+main[j][sayi2];   // UST USTE GELECEK SAYILAN ESIT OLMASI HALINDE TOPLANIP YAZILMASI
					main[j][sayi2]=0;
					score+=(main[j][sayi1]);
				}
			}
			if(sayi3!=5){
				if(main[j][sayi2]==main[j][sayi3]){
					main[j][sayi2]=main[j][sayi2]+main[j][sayi3];
					main[j][sayi3]=0;
					score+=(main[j][sayi2]);
				}
			}
				if(sayi4!=5){
				if(main[j][sayi3]==main[j][sayi4]){
					main[j][sayi3]=main[j][sayi3]+main[j][sayi4];
					main[j][sayi4]=0;
					score+=(main[j][sayi3]);
				}
			}
                if(sayi1==5)
				swap=0;
				if(sayi1==3&&sayi2==5)
				swap=0;
				if(swap==1){
				for(i=3;i>=0;i--){
					yer=i;
					while(yer>=0&&main[j][yer]==0)  //BUTUN SAYILARIN KAYDIRILMASI ISLEMÝ
					yer--;
					if(yer>=0&&yer!=i){
						t=main[j][yer];
						main[j][yer]=main[j][i];
						main[j][i]=t;
				}
			}
		}
	}
	if(tus=='a'||tus=='A'){
                    for(i=0;i<4;i++){
                        for(j=0;j<2;j++){
                            t=main[i][j];
                            main[i][j]=main[i][3-j];
                            main[i][3-j]=t;
                        }
                    }
                }
}
    else if(tus=='w'||tus=='s'||tus=='W'||tus=='S'){
                        randomat=1;
            previousscore=score;
            for(i=0;i<4;i++){
				for(j=0;j<4;j++){
					a = main[i][j];
					main[i][j]=a;
					rmatris[i][j]=a;
				}
		}

            if(tus=='w'||tus=='W'){
                for(i=0;i<4;i++){
        for(j=0;j<2;j++){
            t=main[j][i];
            main[j][i]=main[3-j][i];
            main[3-j][i]=t;
        }
    }
            }
             for(j=0;j<4;j++){
				sayi1=sayi2=sayi3=sayi4=5;
				k=3;
				swap=1;
				while(k>=0&&main[k][j]==0)
				k--;
				if(k>=0)
				sayi1=k;
                if(k==0){
					t=main[3][j];
					main[3][j]=main[0][j];
					main[0][j]=t;

				}
				k--;
				while(k>=0&&main[k][j]==0)
				k--;
				if(k>=0){
				sayi2=k;
				k--;
				}
				else if(sayi1!=5&&k>=0&&sayi1!=0){
					main[k][j]=t;
					main[3][j]=main[sayi1][j];
					main[sayi1][j]=t;
				}
				while(k>=0&&main[k][j]==0){
					k--;
				}
				if(k>=0){
					sayi3=k;
				}
				k--;
				while(k>=0&&main[k][j]==0){
					k--;
				}
				if(k==0)
				sayi4=k;
				if(sayi1!=5&&sayi2!=5){
				if(main[sayi1][j]==main[sayi2][j]){
					main[sayi1][j]=main[sayi1][j]+main[sayi2][j];
					main[sayi2][j]=0;
					score+=(main[sayi1][j]);
				}
			}	if(sayi3!=5){
				if(main[sayi2][j]==main[sayi3][j]){
					main[sayi2][j]=main[sayi2][j]+main[sayi3][j];
					main[sayi3][j]=0;
					score+=(main[sayi2][j]);
				}
			}   if(sayi4!=5){
				if(main[sayi3][j]==main[sayi4][j]){
					main[sayi3][j]=main[sayi3][j]+main[sayi4][j];
					main[sayi4][j]=0;
					score+=(main[sayi3][j]);
				}
			}   if(sayi1==5)
				swap=0;
				if(sayi1==3&&sayi2==5)
				swap=0;
				if(swap==1){
				for(i=3;i>=0;i--){
					yer=i;
					while(yer>=0&&main[yer][j]==0)
					yer--;
					if(yer>=0&&yer!=i){
						t=main[yer][j];
						main[yer][j]=main[i][j];
						main[i][j]=t;
				}
			}
		}
    }
        if(tus=='w'||tus=='W'){
            for(i=0;i<4;i++){
        for(j=0;j<2;j++){
            t=main[j][i];
            main[j][i]=main[3-j][i];
            main[3-j][i]=t;
        }
    }
        }
	}
		else if(tus == 'r'||tus=='R'){  //HAMLEYI GERI ALMAK ICIN DÝGER MATRISI ANA MATRISE ATAMA ISLEMI
			for(i=0;i<4;i++){
				for(j=0;j<4;j++){
					main[i][j]=rmatris[i][j];

				}
			}
			score=previousscore;
		}
		if(tus=='x'||tus=='X'){        //RESETLEME ISLEMÝ MATRISI 0'LAYIP YENI 2 RANDOM ATYIORUM
			for(i=0;i<4;i++){
				for(j=0;j<4;j++){
					main[i][j]=0;
				}
			}
			main[rand()%4][rand()%4]=ihtimal[rand()%10];
            score=0;
            do{
				random1=rand()%4;random2=rand()%4;

			}
        while(main[random1][random2]!=0);
        main[random1][random2]=ihtimal[rand()%10];
        random1=5;
		}
		else if(tus=='e'||tus=='E'){    //OYUNDAN CIKMA
            start=3;
		}
	if(score>highscore)
			highscore=score; // YUKSEK SKOR, SKOR YUKSEK SKORU GECERSE SKORU YUKSEK SKORA ATYIOR
	end=0;
		dolu=0;
		for(i=0;i<4;i++){
			for(j=0;j<4;j++){
				if(main[i][j]!=0)
				dolu++;         //MATRISIN DOLU OLUP OLMADIGININ KONTROLU
			}
	}   if(dolu==16){
            for(i=0;i<4;i++){
                for(j=0;j<3;j++){
                    if(main[i][j]!=main[i][j+1]) //MATRIS DOLUYSA YAPILABILECEK HAMLE OLUP OLMADIGININ KONTROLU
                    end++;
			}
			for(j=0;j<3;j++){
				if(main[j][i]!=main[j+1][i])
				end++;
			}
			}
			randomat=0;
}
		if(end==24){
		start=0;
		printf("\n");       //OYNANABILECEK HAMLE KALMAMASI
		printf("                                                             GAMER OVER!!!!!!!!\n");
		printf("SCORE = %d\nHIGHSCORE = %d\n",score,highscore);
		score=0;
}
        if(dolu==16)
        randomat=0;
        if(randomat==1){
        do{
				random1=rand()%4;random2=rand()%4;

			}
        while(main[random1][random2]!=0);           //RANDOMUN DOLU BIR YERE GELMEMESÝ ICIN KOD
        main[random1][random2]=ihtimal[rand()%10];
}
			if(start!=0){
            printf("                                                         Score = %d\n                                                         Highscore = %d\n",score,highscore);
			}
			printf("_____________________");
			printf("\n");
			for(i=0;i<4;i++){
		printf("|");
		for(j=0;j<4;j++){
            if(main[i][j]==2048){
                start=2;
            }
			if(main[i][j]==0)
            printf("%4c|",' ');

            else if(tus!='r'&&i==random1&&j==random2){
			SetConsoleTextAttribute(hConsole,renklendir(main[i][j]));
			printf("%3d*",main[i][j]);
			SetConsoleTextAttribute(hConsole,saved_attributes);
			printf("|");
		}
			else{
            SetConsoleTextAttribute(hConsole,renklendir(main[i][j]));
			printf("%4d",main[i][j]);
			SetConsoleTextAttribute(hConsole,saved_attributes);
			printf("|");
		}
	}
		printf("\n");
		printf("_____________________");
		printf("\n");
		}
		printf("\n\n");
}
	if(start==3){
        printf("                               GAME OVER!!!!\n");
        printf("SCORE = %d\nHIGHSCORE = %d\n",score,highscore);     //E'YE BASARSA
	}
	if(start==2){
        printf("                           YOU WONN!!!!\n");
        printf("SCORE = %d\nHIGHSCORE = %d\n",score,highscore); //2048 YAPARSA
	}
	printf("\n");
	printf("PRESS 'X' TWICE TO EXIT");
	do{
		tus=getch();
	}                           //DIREKT OYUNDAN ATMAMASI ICIN BEKLETME
	while(tus!='x');


	return 0;
}

