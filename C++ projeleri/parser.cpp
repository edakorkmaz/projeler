#include <stdio.h>
// Eda KORKMAZ No:02200201071 Normal ��retim 
 /*";" kontrol� �devde olmad��� i�in yapmad�m .Txt dosyas�n�n ismi dosya olmal�d�r. Txt dosyas� ile kodun bulundu�u yer ayn� olmal�d�r .
 dosya i�ine ba�a��daki kodu yazd�m. Hata olamd���nda kodun ayn�s�n� yazmaktad�r.
if( AA<B){
	A=A+B
}else if(A=B){
	A=A
}else if(F<10){
F=F+20
}else{
E=B
*/
int acpar(char dizi[],int i,int j){ // (  kontrol� yapar 
	if(dizi[2]=='('|dizi[i]=='('){
			printf("%c",dizi[i]);
			i++;
	}else{
		printf("\n'(' yok. Kod hatali.\n");

	}
	return i;
}

int kapa(char dizi[],int i,int j){ // ) kontrol� yapar 
	if(dizi[i]==')'){
			printf("%c",dizi[i]);
			i++;
	}else{
		printf("\n')' yok. Kod hatali.\n");

	}
	return i;
}
int susa(char dizi[],int i,int j){ // { kontrol� yapar
	if(dizi[i]=='{'){
			printf("%c",dizi[i]);
			i++;
	}else{
		printf("\n'{' yok. Kod hatali.\n");
	}
	return i;
}

int susk(char dizi[],int i,int j){ // } kontrol� yapar
	if(dizi[i]=='}'){
			printf("%c",dizi[i]);
			i++;
	}else{
		printf("\n'}' yok. Kod hatali.\n");

	}
	return i;
}

int id(char dizi[],int i,int j){ // id ve say�  kontrol� yapar
	int k=0;
	int t=0;
	while(dizi[i]=='A'|dizi[i]=='B'|dizi[i]=='C'|dizi[i]=='D'|dizi[i]=='E'|dizi[i]=='F'){
		t++;
		if(t==1){
			printf("%c",dizi[i]);
		}
		i++;
		k++;	
	}
	if(t>1){
		printf("\nid hatali.\n");
	}else{
	while(dizi[i]=='0'|dizi[i]=='1'|dizi[i]=='2'|dizi[i]=='3'|dizi[i]=='4'|dizi[i]=='5'|dizi[i]=='6'|dizi[i]=='7'|dizi[i]=='8'|dizi[i]=='9'){
		printf("%c",dizi[i]);
		i++;
		k++;
	}
	if(k==0){
		printf("\nid hatali.\n");

	}
}
	return i;
}


int ope(char dizi[],int i,int j){ // operat�r kontrol� yapar
	int k=0;
	if(dizi[i]=='<'|dizi[i]=='>'|dizi[i]=='='){
			printf("%c",dizi[i]);
			i++;
			k++;	
	}
	if(dizi[i]=='='){
		printf("%c",dizi[i]);
		i++;
		k++;
	}
	if(k==0){
		printf("\noperator hatali\n");

	}
	return i;
}
int esit(char dizi[],int i,int j){
	if(dizi[i]=='='){
			printf("%c",dizi[i]);
			i++;
	}else{
		printf("\n'=' yok. Kod hatal�.\n");

	}
	return i;
}



int isaret(char dizi[],int i){ 
	if(dizi[i]=='+'|dizi[i]=='-'|dizi[i]=='*'|dizi[i]=='/'){
		printf("%c",dizi[i]);
		i++;
	}else{
		printf("\n'(' yok. Kod hatali.\n");
	}
	return i;
}




 main (){	
	char d1[150];
	char d2[150];
	int i=0;
	int j=0;
	int m=1;
	
	char karakter;
	FILE *fdosya;	
	if(fdosya=fopen("dosya.txt","r")){ //dosyan�n okunup okunmad���n�n kontrol�n� yapt�m.
		karakter=fgetc(fdosya);
		d1[i]= karakter;
		while(karakter!=EOF){ //dosyan�n i�indeki karakterleri yazma ve diziye atma i�lemi yapar.
			i++;
			printf("%c",karakter);	
			karakter=fgetc(fdosya);
			d1[i]=karakter;
			m++;	
		}
	}else{
		printf("dosya a�ilmadi.");
	}
	printf("\n");
	
	int k=0;
	for(int i=0;i<m;i++){	
		if((int)d1[i]==10|(int)d1[i]==9|d1[i]==' '){		
		}else{
			d2[j]=d1[i];
			j++;
	        k++;
		}
	}
	
	int z=0; // else ifadesinin 1 defa kullan�ld���n� komtrol� i�in kullan .
	for(int i=0;i<k;i++){	
		if(d2[0]=='i'&&d2[1]=='f'){ // if yap�s�n� �art ve cumle k�sm�n� kontrol eder.
			printf("%c",d2[i]);
			printf("%c",d2[i+1]);
			i=i+2;
			i=acpar(d2,i,k);
			i=id(d2,i,k);		    		
			i=ope(d2,i,k);  
			i=id(d2,i,k);
			i=kapa(d2,i,k);
			i=susa(d2,i,k);
			i=id(d2,i,k);
			i=esit(d2,i,k);
			i=id(d2,i,k);
			if(d2[i]=='+'|d2[i]=='-'|d2[i]=='*'|d2[i]=='/'){
				printf("%c",d2[i]);
				i++;
				i=id(d2,i,k);
			}
			i=susk(d2,i,k);
		}else{
			printf("'if'ifadesi hatali");
			i=k;	
		}		
		
		while(d2[i]=='e'&&d2[i+1]=='l'&&d2[i+2]=='s'&&d2[i+3]=='e'&&d2[i+4]=='i'&&d2[i+5]=='f'){ //else is yap�s�n� �art ve cumle k�sm�n� kontrol eder.
			printf("%c",d2[i]);
			printf("%c",d2[i+1]);
			printf("%c",d2[i+2]);
			printf("%c",d2[i+3]);
			i=i+4;			
			printf("%c",d2[i]);
			printf("%c",d2[i+1]);
			i=i+2;
			i=acpar(d2,i,k);
			i=id(d2,i,k);		     		
			i=ope(d2,i,k);  
			i=id(d2,i,k);
			i=kapa(d2,i,k);
			i=susa(d2,i,k);
			i=id(d2,i,k);
			i=esit(d2,i,k);
			i=id(d2,i,k);
			if(d2[i]=='+'|d2[i]=='-'|d2[i]=='*'|d2[i]=='/'){
				printf("%c",d2[i]);
				i++;
				i=id(d2,i,k);
			}
			i=susk(d2,i,k);
		}
	
		
		if(d2[i]=='e'&&d2[i+1]=='l'&&d2[i+2]=='s'&&d2[i+3]=='e'){ // else yap�s�n� �art ve cumle k�sm�n� kontrol eder.
			printf("%c",d2[i]);
			printf("%c",d2[i+1]);
			printf("%c",d2[i+2]);
			printf("%c",d2[i+3]);
			i=i+4;			
			z++; 
			if(z==1){ //else yap�s�n�n bir kez kullan�lmas�n� kontrol eder.
				i=susa(d2,i,k);
				i=id(d2,i,k);
				i=esit(d2,i,k);
				i=id(d2,i,k);
				if(d2[i]=='+'|d2[i]=='-'|d2[i]=='*'|d2[i]=='/'){
					printf("%c",d2[i]);
					i++;
					i=id(d2,i,k);
				}
				i=susk(d2,i,k);
			}else{
				printf("if yap�s�n�n tek else yap�s� olabilir. Kod hatal�");
				i=k;
			}
		}
	}
		return 0; 
}
