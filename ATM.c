#include<stdio.h>
#include<string.h>
void swap(int *a,int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}
void swapstring(char a[],char b[]){
	char temp[50];
	strcpy(temp,a);
	strcpy(a,b);
	strcpy(b,temp);
}
void bubblesort(int n,int menhgia[],char tenmenhgia[][50]){
	int j,i;
	for(j = 0;j < n - 1; j++){
		for(i = 0; i < n - 1 - j; i++){
			if(menhgia[i] < menhgia[i + 1]){
				swap(&menhgia[i],&menhgia[i + 1]);
				swapstring(tenmenhgia[i],tenmenhgia[i + 1]);
			}
		}
	}
}
int main(){
	FILE *f;
	char tenmenhgia[100][50];
	int tien,i,soto = 0, n = 0,dem = 0;
	int menhgia[100];
	char dong[50];
	f = fopen("ATM.txt","r");
	
	
	if(f == NULL){
		return 1;
	}
	while( n < 100 && fgets(dong,sizeof(dong), f) != NULL){
		if(sscanf(dong, "%d",&menhgia[n]) == 1){
		
			char *p = dong;
			while(*p ==' ' || *p == '\t'){
				p++;
			}	
			while(*p >= '0' && *p <= '9'){
				p++;
			}
		
			p[strcspn(p,"\r\n")] = '\0';
			strcpy(tenmenhgia[n], p);
			n++;
		}
	}
	fclose(f);
	bubblesort(n,menhgia,tenmenhgia);
	printf("nhap so tien can rut:");
	scanf("%d",&tien);
	int hehe = tien;
	for(i = 0; i < n;i++){
		soto = hehe / menhgia[i];
		hehe = hehe % menhgia[i];
		dem += soto;
	}
	printf(" Tong so to tien:%d\n",dem);
	for(i = 0; i < n;i++){
		soto = tien / menhgia[i];
		tien = tien % menhgia[i];
		if(soto > 0){
			printf("%s: %d to\n",tenmenhgia[i],soto);
		}
		if(tien < 1000){
			return 0;
		}
		
	}
	
	return 0;
}
