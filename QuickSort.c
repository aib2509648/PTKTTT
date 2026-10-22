#include <stdio.h>
typedef struct {
	int key;
	float value;
} record;
void swap(record *a, record *b){
	record temp = *a;
	*a = *b;
	*b = temp;
}
int pivot(record a[],int low, int hight){
	int pivot = a[hight].key;
	int i = low - 1;
	int j;
	for( j = low; j < hight; j++){
		if( a[j].key <= pivot){
			i++;
			swap(&a[i],&a[j]);
		}
	}
	swap(&a[i + 1], &a[hight]);
	return i + 1;
}
void quicksort(record a[],int low, int hight){
	if( low < hight){
		int p = pivot(a,low,hight);
		quicksort(a,low,p - 1);
		quicksort(a,p + 1, hight);
	}
}
void printdata(record a[],int n){
	int i;
	for(i = 0; i < n; i++){
		printf(" %d %.02f",a[i].key, a[i].value);
	}
}
int main(){
	FILE *f;
	record a[1000];
	int n = 0;
	f = fopen("data.txt","r");
	if( f == NULL){
		return 1;
	}
	while ( n < 1000 && fscanf(f, "%d %f",&a[n].key,&a[n].value) == 2){
		n++;
	}
	fclose(f);
	printf("Thuat Toan QuickSort\n");
	printf("Data truoc khi sap xep\n");
	printdata(a,n);
	quicksort(a,0,n - 1);
	printf("\nData sau khi sap xep\n");
	printdata(a,n);
	return 0;
}
