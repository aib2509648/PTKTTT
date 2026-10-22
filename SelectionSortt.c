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
void selection(record a[],int n){
	int i,j;
	for(i = 0 ; i < n - 1;i++){
		int min = i;
		for(j = i + 1;j < n;j++){
			if(a[j].key < a[min].key){
				min = j;
			}
		}
		if(min != i){
			swap(&a[i],&a[min]);
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
	printf("Thuat Toan SelectionSort\n");
	printf("Data truoc khi sap xep\n");
	printdata(a,n);
	quicksort(a,0,n - 1);
	printf("\nData sau khi sap xep\n");
	printdata(a,n);
	return 0;
}
