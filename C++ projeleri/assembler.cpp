#include <stdio.h>
// Eda KORKMAZ No:02200201071 Normal öðretim 
 /*Txt dosyasýnýn ismi dosya olmalýdýr. Txt dosyasý ile kodun bulunduðu yer ayný olmalýdýr .
*/
int h (char d[],int i){  //dosyadan alýnan sayýlarýn hesaplanmasý  
	int x;
	if((int)d[i+1]==10){
		x=(int)d[i]-48;
	}else if((int)d[i+2]==10){
		x=((int)d[i]-48)*10+(int)d[i+1]-48;
	}else{
		x=((int)d[i]-48)*100+((int)d[i+1]-48)*10+(int)d[i+2]-48;
			
	}
	return x;		
}

int p(char d[],int i){ // [ ] arasýndaki sayýyý veren fonksiyon
	int y;
	if((int)d[i+2]==']'){
		y=(int)d[i+1]-48;
	}else if((int)d[i+3]==']'){
		y=((int)d[i+1]-48)*10+(int)d[i+2]-48;
	}else{
		y=((int)d[i+1]-48)*100+((int)d[i+2]-48)*10+(int)d[i+3]-48;		
	}
	return y;
}



 int main (){	
	char d1[150];
	int i=0;
	int m=1;

	char karakter;
	FILE *fdosya;	
	if(fdosya=fopen("dosya.txt","r")){ //dosyanýn okunup okunmadýðýnýn kontrolünü yaptým.
		karakter=fgetc(fdosya);
		d1[i]= karakter;
		while(karakter!=EOF){ 	//dosyanýn içindeki karakterleri yazma ve diziye atma iþlemi yapar.
			i++;
			karakter=fgetc(fdosya);
			d1[i]=karakter;
			m++;	
		}
	}else{
		printf("dosya açilmadi.");
	}

	int a;			
	int ram[256];
	short ax,bx,cx,dx=0;
	for(int i=0;i<m;i++){
		if(d1[i]=='H'){   // HKR iþlemini kontrol eder.
			if(d1[i+4]=='A'){ 
				i=i+7;
				if(d1[i]=='B'){
					ax=bx;
				}else if(d1[i]=='A'){
					ax=ax;	
				}else if(d1[i]=='C'){
					ax=cx;	
				}else if(d1[i]=='D'){
					ax=dx;
				}else if(d1[i]=='['){
					a=p(d1,i);
					ram[a]=20;
					ax=ram[a];
				}else{
					ax=h(d1,i);
				}	
			}else if(d1[i+4]=='B'){
				i=i+7;
				if(d1[i]=='A'){
					bx=ax;
				}else if(d1[i]=='B'){
					bx=bx;
				}else if(d1[i]=='C'){
					bx=cx;	
				}else if(d1[i]=='D'){
					bx=dx;
				}else if(d1[i]=='['){
					a=p(d1,i);
					ram[a]=30;
					bx=ram[a];
				}else{
					bx=h(d1,i);
				}
			}else if(d1[i+4]=='C'){
				i=i+7;
				if(d1[i]=='A'){
					cx=ax;	
				}else if(d1[i]=='B'){
					cx=bx;	
				}else if(d1[i]=='C'){
					cx=cx;	
				}else if(d1[i]=='D'){
					cx=dx;
				}else if(d1[i]=='['){
					a=p(d1,i);
					ram[a]=33;
					cx=ram[a];
				}else{
					cx=h(d1,i);
				}
			}else if(d1[i+4]=='D'){
				i=i+7;
				if(d1[i]=='A'){
					dx=ax;	
				}else if(d1[i]=='B'){
					dx=bx;	
				}else if(d1[i]=='C'){
					dx=cx;
				}else if(d1[i]=='D'){
					dx=dx;
				}else if(d1[i]=='['){
					a=p(d1,i);
					ram[a]=26;
					dx=ram[a];
				}else{
					dx=h(d1,i);
				}
			}
		}else if(d1[i]=='T'){ // TOP iþlemini kontrol eder.
			if(d1[i+4]=='A'){ 
				i=i+7;
				if(d1[i]=='B'){
					ax=ax+bx;
				}else if(d1[i]=='A'){
					ax=ax+ax;
				}else if(d1[i]=='C'){
					ax=ax+cx;	
				}else if(d1[i]=='D'){
					ax=ax+dx;
				}else if(d1[i]=='['){
					a=p(d1,i);
					ram[a]=25;
					ax=ax+ram[a];
				}else{
					ax=ax+h(d1,i);
				}	
			}else if(d1[i+4]=='B'){
				i=i+7;
				if(d1[i]=='A'){
					bx=bx+ax;
				}else if(d1[i]=='B'){
					bx=bx+bx;
				}else if(d1[i]=='C'){
					bx=bx+cx;	
				}else if(d1[i]=='D'){
					bx=bx+dx;
				}else if(d1[i]=='['){
					a=p(d1,i);
					ram[a]=15;
					bx=bx+ram[a];
				}else{
					bx=bx+h(d1,i);
				}
			}else if(d1[i+4]=='C'){
				i=i+7;
				if(d1[i]=='A'){
					cx=cx+ax;	
				}else if(d1[i]=='B'){
					cx=cx+bx;
				}else if(d1[i]=='C'){
					cx=cx+cx;
				}else if(d1[i]=='D'){
					cx=cx+dx;
				}else if(d1[i]=='['){
					a=p(d1,i);
					ram[a]=17;
					cx=cx+ram[a];	
				}else{
					cx=cx+h(d1,i);
				}
			}else if(d1[i+4]=='D'){
				i=i+7;
				if(d1[i]=='A'){
					dx=dx+ax;	
				}else if(d1[i]=='B'){
					dx=dx+bx;	
				}else if(d1[i]=='C'){
					dx=dx+cx;
				}else if(d1[i]=='D'){
					dx=dx+dx;	
				}else if(d1[i]=='['){
					a=p(d1,i);
					ram[a]=32;
					dx=dx+ram[a];
				}else{
					dx=dx+h(d1,i);
				}
			
		}
	
		}else if(d1[i]=='C'&&d1[i+1]=='I'){   // CIK iþlemini kontrol eder .
			if(d1[i+4]=='A'){ 
				i=i+7;
				if(d1[i]=='B'){
					ax=ax-bx;
				}else if(d1[i]=='A'){
					ax=ax-ax;
				}else if(d1[i]=='C'){
					ax=ax-cx;	
				}else if(d1[i]=='D'){
					ax=ax-dx;
					}else if(d1[i]=='['){
					a=p(d1,i);
					ram[a]=31;
					ax=ax-ram[a];
				}else{
					ax=ax-h(d1,i);
				}	
			}else if(d1[i+4]=='B'){
				i=i+7;
				if(d1[i]=='A'){
					bx=bx-ax;
				}else if(d1[i]=='B'){
					bx=bx-bx;
				}else if(d1[i]=='C'){
					bx=bx-cx;	
				}else if(d1[i]=='D'){
					bx=bx-dx;
				}else if(d1[i]=='['){
					a=p(d1,i);
					ram[a]=25;
					bx=bx-ram[a];
				}else{
					bx=bx-h(d1,i);
				}
			}else if(d1[i+4]=='C'){
				i=i+7;
				if(d1[i]=='A'){
					cx=cx-ax;	
				}else if(d1[i]=='B'){
					cx=cx-bx;
				}else if(d1[i]=='C'){
					cx=cx-cx;
				}else if(d1[i]=='D'){
					cx=cx-dx;
				}else if(d1[i]=='['){
					a=p(d1,i);
					ram[a]=25;
					cx=cx-ram[a];
				}else{
					cx=cx-h(d1,i);
				}
			}else if(d1[i+4]=='D'){
				i=i+7;
				if(d1[i]=='A'){
					dx=dx-ax;	
				}else if(d1[i]=='B'){
					dx=dx-bx;	
				}else if(d1[i]=='C'){
					dx=dx-cx;
				}else if(d1[i]=='D'){
					dx=dx-dx;
				}else if(d1[i]=='['){
					a=p(d1,i);
					ram[a]=25;
					dx=dx-ram[a];	
				}else{
					dx=dx-h(d1,i);
				}
			}
		}else if(d1[i]=='C'&&d1[i+1]=='R'){   // CRP iþlemini kontrol eder .
			if(d1[i+4]=='A'){ 
				i=i+7;
				if(d1[i]=='B'){
					ax=ax*bx;
				}else if(d1[i]=='A'){
					ax=ax*ax;
				}else if(d1[i]=='C'){
					ax=ax*cx;	
				}else if(d1[i]=='D'){
					ax=ax*dx;
				}else if(d1[i]=='['){
					a=p(d1,i);
					ram[a]=34;
					ax=ax*ram[a];	
				}else{
					ax=ax*h(d1,i);
				}	
			}else if(d1[i+4]=='B'){
				i=i+7;
				if(d1[i]=='A'){
					bx=bx*ax;
				}else if(d1[i]=='B'){
					bx=bx*bx;	
				}else if(d1[i]=='C'){
					bx=bx*cx;	
				}else if(d1[i]=='D'){
					bx=bx*dx;
				}else if(d1[i]=='['){
					a=p(d1,i);
					ram[a]=16;
					bx=bx*ram[a];
				}else{
					bx=bx*h(d1,i);
				}
			}else if(d1[i+4]=='C'){
				i=i+7;
				if(d1[i]=='A'){
					cx=cx*ax;	
				}else if(d1[i]=='B'){
					cx=cx*bx;	
				}else if(d1[i]=='C'){
					cx=cx*cx;	
				}else if(d1[i]=='D'){
					cx=cx*dx;
				}else if(d1[i]=='['){
					a=p(d1,i);
					ram[a]=45;
					cx=cx+ram[a];	
				}else{
					cx=cx+h(d1,i);
				}
			}else if(d1[i+4]=='D'){
				i=i+7;
				if(d1[i]=='A'){
					dx=dx*ax;	
				}else if(d1[i]=='B'){
					dx=dx*bx;	
				}else if(d1[i]=='C'){
					dx=dx*cx;
				}else if(d1[i]=='D'){
					dx=dx*dx;
				}else if(d1[i]=='['){
					a=p(d1,i);
					ram[a]=13;
					dx=dx*ram[a];	
				}else{
					dx=dx*h(d1,i);
				}
			}
		}else if(d1[i]=='B'&&d1[i+1]=='B'){ // BOL iþlemini kontrol eder .
			if(d1[i+4]=='A'){ 
				i=i+7;
				if(d1[i]=='B'){
					dx=ax%bx;
					ax=ax/bx;	
				}else if(d1[i]=='A'){
					dx=ax%ax;
					ax=ax/ax;	
				}else if(d1[i]=='C'){
					dx=ax%cx;
					ax=ax/cx;		
				}else if(d1[i]=='D'){
					dx=ax%dx;
					ax=ax/dx;	
				}else if(d1[i]=='['){
					a=p(d1,i);
					ram[a]=25;
					dx=ax%ram[a];
					ax=ax/ram[a];	
				}else{
					dx=ax%h(d1,i);	
					ax=ax/h(d1,i);		
				}	
			}else if(d1[i+4]=='B'){
				i=i+7;
				if(d1[i]=='A'){
					dx=bx%ax;
					bx=bx/ax;
				}else if(d1[i]=='B'){
					dx=bx%bx;
					bx=bx/bx;		
				}else if(d1[i]=='C'){
					dx=bx%cx;
					bx=bx/cx;		
				}else if(d1[i]=='D'){
					dx=bx%dx;
					bx=bx/dx;
				}else if(d1[i]=='['){
					a=p(d1,i);
					ram[a]=17;
					dx=bx%ram[a];
					bx=bx/ram[a];				
				}else{
					dx=bx%h(d1,i);
					bx=bx/h(d1,i);	
				}
			}else if(d1[i+4]=='C'){
				i=i+7;
				if(d1[i]=='A'){
					dx=cx%ax;
					cx=cx/ax;			
				}else if(d1[i]=='B'){
					dx=cx%bx;
					cx=cx/bx;
				}else if(d1[i]=='C'){
					dx=cx%cx;
					cx=cx/cx;
				}else if(d1[i]=='D'){
					dx=cx%dx;
					cx=cx/dx;
				}else if(d1[i]=='['){
					a=p(d1,i);
					ram[a]=25;
					dx=cx%ram[a];
					cx=cx/ram[a];			
				}else{
					dx=cx%h(d1,i);
					cx=cx/h(d1,i);	
				}
			}else if(d1[i+4]=='D'){
				i=i+7;
				if(d1[i]=='A'){
					dx=dx%ax;
					dx=dx/ax;		
				}else if(d1[i]=='B'){
					dx=dx%bx;
					dx=dx/bx;	
				}else if(d1[i]=='C'){
					dx=dx%cx;
					dx=dx/cx;
				}else if(d1[i]=='D'){
					dx=dx%dx;
					dx=dx/dx;
				}else if(d1[i]=='['){
					a=p(d1,i);
					ram[a]=25;
					dx=dx%ram[a];
					dx=dx/ram[a];	
				}else{
					dx=dx%h(d1,i);
					dx=dx/h(d1,i);	
				}
			}
		}else if(d1[i]=='V'&&d1[i+1]=='E'&&d1[i+2]=='Y'){  // VEYA iþlemini kontrol eder .
			if(d1[i+5]=='A'){ 
				i=i+8;
				if(d1[i]=='B'){
					ax=ax|bx;
				}else if(d1[i]=='A'){
					ax=ax|ax;		
				}else if(d1[i]=='C'){
					ax=ax|cx;	
				}else if(d1[i]=='D'){
					ax=ax|dx;
				}else if(d1[i]=='['){
					a=p(d1,i);
					ram[a]=3;
					ax=ax|ram[a];	
				}else{
					ax=ax|h(d1,i);
				}	
			}else if(d1[i+5]=='B'){
				i=i+8;
				if(d1[i]=='A'){
					bx=bx|ax;
				}if(d1[i]=='B'){
					bx=bx|bx;
				}else if(d1[i]=='C'){
					bx=bx|cx;	
				}else if(d1[i]=='D'){
					bx=bx|dx;
				}else if(d1[i]=='['){
					a=p(d1,i);
					ram[a]=4;
					bx=bx|ram[a];	
				}else{
					bx=bx|h(d1,i);
				}
			}else if(d1[i+5]=='C'){
				i=i+8;
				if(d1[i]=='A'){
					cx=cx|ax;	
				}else if(d1[i]=='B'){
					cx=cx|bx;
				}else if(d1[i]=='C'){
					cx=cx|cx;
				}else if(d1[i]=='D'){
					cx=cx|dx;
				}else if(d1[i]=='['){
					a=p(d1,i);
					ram[a]=10;
					cx=cx|ram[a];	
				}else{
					cx=cx|h(d1,i);
				}
			}else if(d1[i+5]=='D'){
				i=i+8;
				if(d1[i]=='A'){
					dx=dx|ax;	
				}else if(d1[i]=='B'){
					dx=dx|bx;	
				}else if(d1[i]=='C'){
					dx=dx|cx;
				}else if(d1[i]=='D'){
					dx=dx|dx;
				}else if(d1[i]=='['){
					a=p(d1,i);
					ram[a]=5;
					dx=dx|ram[a];
				}else{
					dx=dx|h(d1,i);
				}
			}
		}else if(d1[i]=='V'&&d1[i+1]=='E'){  // VE iþemini kontrol eder .
			if(d1[i+3]=='A'){ 
				i=i+6;
				if(d1[i]=='B'){
					ax=ax & bx;	
				}else if(d1[i]=='A'){
					ax=ax & ax;	
				}else if(d1[i]=='C'){
					ax=ax & cx;	
				}else if(d1[i]=='D'){
					ax=ax & dx;
				}else if(d1[i]=='['){
					a=p(d1,i);
					ram[a]=24;
					ax=ax&ram[a];
				}else{
					ax=ax & h(d1,i);
				}	
			}else if(d1[i+3]=='B'){
				i=i+6;
				if(d1[i]=='A'){
					bx=bx&ax;
				}else if(d1[i]=='B'){
					bx=bx&bx;	
				}else if(d1[i]=='C'){
					bx=bx&cx;	
				}else if(d1[i]=='D'){
					bx=bx&dx;
				}else if(d1[i]=='['){
					a=p(d1,i);
					ram[a]=42;
					bx=bx&ram[a];
				}else{
					bx=bx&h(d1,i);
				}
			}else if(d1[i+3]=='C'){
				i=i+6;
				if(d1[i]=='A'){
					cx=cx&ax;	
				}else if(d1[i]=='B'){
					cx=cx&bx;
				}else if(d1[i]=='C'){
					cx=cx&cx;
				}else if(d1[i]=='D'){
					cx=cx&dx;
				}else if(d1[i]=='['){
					a=p(d1,i);
					ram[a]=44;
					cx=cx&ram[a];
				}else{
					cx=cx&h(d1,i);
				}
			}else if(d1[i+3]=='D'){
				i=i+6;
				if(d1[i]=='A'){
					dx=dx&ax;	
				}else if(d1[i]=='B'){
					dx=dx&bx;	
				}else if(d1[i]=='C'){
					dx=dx&cx;
				}else if(d1[i]=='D'){
					dx=dx&dx;
				}else if(d1[i]=='['){
					a=p(d1,i);
					ram[a]=23;
					dx=dx&ram[a];
				}else{
					dx=dx&h(d1,i);
				}
			}
		}else if(d1[i]=='D'&&d1[i+1]=='E'){  // DEG iþlemini kontrol eder .
			if(d1[i+4]=='A'){ 
				ax=~ax;
			}else if(d1[i+4]=='B'){
				bx=~bx;
			}else if(d1[i+4]=='C'){
				cx=~cx;
				
			}else if(d1[i+4]=='D'){
				dx=~dx;
			}else if(d1[i+4]=='['){
				a=p(d1,i);
				ram[a]=30;
				dx=~ram[a];
			}
		}
	}

	printf("AX= %d\n",ax);
	printf("BX= %d\n",bx);
	printf("CX= %d\n",cx);
	printf("DX= %d\n",dx);
	
		return 0; 
}
