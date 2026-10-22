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
void bubblesort(record a[], int n){
	int i, j;
	for(i = 0;i < n - 1; i++){
		for(j = 0; j < n - 1 - i; j++){
			if(a[j].key > a[j + 1].key){
				swap(&a[j],&a[j + 1]);
			}
		}
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
	printf("Thuat Toan BubbleSort\n");
	printf("Data truoc khi sap xep\n");
	printdata(a,n);
	bubblesort(a,n);
	printf("\nData sau khi sap xep\n");
	printdata(a,n);
	return 0;
}
