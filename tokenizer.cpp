#include <stdio.h>
   // Eda KORKMAZ 02200201071 
   
   /* cpp uzant�l� dosya ve txt dosyas� masa �st�nde oldu�unda �al���yor . BU �ekilde de �al��mazsa 
   fdosya=fopen("dosya.txt","r") buradaki r yerine w yaz�p �al��t�rd���n�zda dosya adl� bir txt dosyas� a�ar . Bu txt dosyas�na a�a��daki 
   kodu yazarsan�z �al���r .
   
for ( int i=0;i<n;i++){
	y=7+20*xa;
	printf(" hello world <:) ");
	if(y>=20)
		y=0;
}

      */
int main (){
		
	char d1[150];
	char d2[150];
	int i=0;
	int j=0;
	int k=1;
	
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
			k++;	
		}
	}else{
		printf("dosya a�ilmadi.");
	}
	printf("\n");
	
	


	int m=0; //2. dizinin boyutu
	for(int i=0;i<k;i++){ 
	 // T�rnak i�areti aras�ndaki her �eyi ayn� kalacak �ekilde yeni diziye atama i�lemi yapar.
		if(d1[i]=='"'){
			d2[j]=d1[i];
			i++;
			j++;
			m++;
			while(d1[i]!='"'){
				d2[j]=d1[i];
				i++;
				j++;
				m++;
	       	}
		}

		
		// bo�luklar�n yerine virg�l kayma , bo�luktan �nce operat�r gelirse bo�lu�u atlama i�lemi yapar.
		if(d1[i]==' '){
			if( d1[i+1]=='='|d1[i+1]=='<'|d1[i+1]=='>'|d1[i+1]==';'|d1[i+1]=='('|d1[i+1]==')'|d1[i+1]=='%'|d1[i+1]=='*'|d1[i+1]=='{'|d1[i+1]=='}'){
				i++;
  			}else{
  				d2[j]=',';
  				j++;
  				m++;
				i++;
			}
		}
		// operat�rden sonra bo�luk gelirse bo�lu�u atlama i�lemi yapar.
		if( d1[i+1]==' '){
			if(d1[i]=='='|d1[i]=='<'|d1[i]=='>'|d1[i]==';'|d1[i]=='('|d1[i]==')'|d1[i]=='%'|d1[i]=='*'|d1[i]=='{'|d1[i]=='}'){
				d2[j]=d1[i];
  				j++;
  				m++;
				i=i+2;
			}
		}

		// >= , == , != gibi  operat�rlerini   < ,= ,>  operat�rlerden ay�rma i�lemi yapar.
		if(d1[i]=='<'|d1[i]=='>'|d1[i]=='='|d1[i]=='!'){
			if(d1[i+1]=='<'|d1[i+1]=='>'| d1[i+1]=='='){
				d2[j]=',';
				j++;
				d2[j]=d1[i];
			 	j++;
				i++;
				d2[j]=d1[i];
				j++;
				i++;
				d2[j]=',';
				j++;
				m=m+4;
			}else{
			d2[j]=',';
				j++;
				d2[j]=d1[i];
			 	j++;
				i++;
				d2[j]=',';
				j++;
				m=m+3;
			}
			
		}
	
		// yeni dizideki enter ve tab bo�luklar�n� kald�rd�m i�lemi yapar.
	    if((int)d1[i]==10|(int)d1[i]==9){		
		}else{
			d2[j]=d1[i];
			j++;
	        m++;
	        
		}
	
	}	
   
  
	// d2 yi yazd�rma i�lemi :
	for(int i=0;i<m-1;i++){ 
	// t�rnak i�ini oldu�u gibi yazd�r�r.
		if(d2[i]=='"'){
			printf("%c,",d2[i]);
			i++;
			while(d2[i]!='"'){
				printf("%c",d2[i]);
				i++;
	        	}
	        printf(",%c",d2[i]);
			i++;	
		}
	// dizinin son eleman� operat�r oldu�u i�in son eleman�n sonuna virg�l koymama i�lemi :		
		if(i==m-2){
			 printf(",%c",d2[i]);
			 i++;		
		}	
	//topalama i�lemi ile artt�rma i�lemini ay�rd�m.		
	    if(d2[i]=='+'){
	    	if(d2[i+1]=='+'){
	    		i=i+2;
	    		printf(",++");
	    	}else{
	    		i++;
	    		printf(",+,");
			}
		}			
		
	// Operat�r sonuna ve ba��na virg�l koyar ,arka arkaya gelen operat�rlerde fazladan virgil kontrol� yapar.
		if(d2[i]==';'|d2[i]=='('|d2[i]==')'|d2[i]=='%'|d2[i]=='*'|d2[i]=='{'|d2[i]=='}'){
			if(d2[i+1]==';'|d2[i+1]=='('| d2[i+1]==')'|d2[i+1]=='*'|d2[i+1]=='{'|d2[i+1]=='}'){
				printf(",%c",d2[i]);
			}else{
		  		printf(",%c,",d2[i]);
		    }	
		}else{
		// bu kontrol�erin  d���nda olanlar� aynen yazd�r�r.
	        printf("%c",d2[i]);	
        }
	}
	
		return 0; 
}

