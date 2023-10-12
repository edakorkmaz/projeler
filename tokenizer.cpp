#include <stdio.h>
   // Eda KORKMAZ 02200201071 
   
   /* cpp uzantýlý dosya ve txt dosyasý masa üstünde olduðunda çalýþýyor . BU þekilde de çalýþmazsa 
   fdosya=fopen("dosya.txt","r") buradaki r yerine w yazýp çalýþtýrdýðýnýzda dosya adlý bir txt dosyasý açar . Bu txt dosyasýna aþaðýdaki 
   kodu yazarsanýz çalýþýr .
   
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
	if(fdosya=fopen("dosya.txt","r")){ //dosyanýn okunup okunmadýðýnýn kontrolünü yaptým.
		karakter=fgetc(fdosya);
		d1[i]= karakter;
		while(karakter!=EOF){ //dosyanýn içindeki karakterleri yazma ve diziye atma iþlemi yapar.
			i++;
			printf("%c",karakter);	
			karakter=fgetc(fdosya);
			d1[i]=karakter;
			k++;	
		}
	}else{
		printf("dosya açilmadi.");
	}
	printf("\n");
	
	


	int m=0; //2. dizinin boyutu
	for(int i=0;i<k;i++){ 
	 // Týrnak iþareti arasýndaki her þeyi ayný kalacak þekilde yeni diziye atama iþlemi yapar.
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

		
		// boþluklarýn yerine virgül kayma , boþluktan önce operatör gelirse boþluðu atlama iþlemi yapar.
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
		// operatörden sonra boþluk gelirse boþluðu atlama iþlemi yapar.
		if( d1[i+1]==' '){
			if(d1[i]=='='|d1[i]=='<'|d1[i]=='>'|d1[i]==';'|d1[i]=='('|d1[i]==')'|d1[i]=='%'|d1[i]=='*'|d1[i]=='{'|d1[i]=='}'){
				d2[j]=d1[i];
  				j++;
  				m++;
				i=i+2;
			}
		}

		// >= , == , != gibi  operatörlerini   < ,= ,>  operatörlerden ayýrma iþlemi yapar.
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
	
		// yeni dizideki enter ve tab boþluklarýný kaldýrdým iþlemi yapar.
	    if((int)d1[i]==10|(int)d1[i]==9){		
		}else{
			d2[j]=d1[i];
			j++;
	        m++;
	        
		}
	
	}	
   
  
	// d2 yi yazdýrma iþlemi :
	for(int i=0;i<m-1;i++){ 
	// týrnak içini olduðu gibi yazdýrýr.
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
	// dizinin son elemaný operatör olduðu için son elemanýn sonuna virgül koymama iþlemi :		
		if(i==m-2){
			 printf(",%c",d2[i]);
			 i++;		
		}	
	//topalama iþlemi ile arttýrma iþlemini ayýrdým.		
	    if(d2[i]=='+'){
	    	if(d2[i+1]=='+'){
	    		i=i+2;
	    		printf(",++");
	    	}else{
	    		i++;
	    		printf(",+,");
			}
		}			
		
	// Operatör sonuna ve baþýna virgül koyar ,arka arkaya gelen operatörlerde fazladan virgil kontrolü yapar.
		if(d2[i]==';'|d2[i]=='('|d2[i]==')'|d2[i]=='%'|d2[i]=='*'|d2[i]=='{'|d2[i]=='}'){
			if(d2[i+1]==';'|d2[i+1]=='('| d2[i+1]==')'|d2[i+1]=='*'|d2[i+1]=='{'|d2[i+1]=='}'){
				printf(",%c",d2[i]);
			}else{
		  		printf(",%c,",d2[i]);
		    }	
		}else{
		// bu kontrolþerin  dýþýnda olanlarý aynen yazdýrýr.
	        printf("%c",d2[i]);	
        }
	}
	
		return 0; 
}

