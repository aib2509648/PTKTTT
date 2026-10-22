#include <stdio.h>
typedef struct {
	int key;
	float value;
} record;
void swap(record *a,record *b) {
	record temp = *a;
	*a = *b;
	*b = temp;
}
void heapmax(record a[],int n, int i){
	int max = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;
	
	if (left < n && a[left].key > a[max].key)
		max = left;
	if (left < n && a[right].key > a[max].key)
		max = right;
	if ( max != i){
		swap(&a[i], &a[max]);
	
	heapmax(a, n, max);
	}
}
void heapsort( record a[], int n){
	int i;
	for(i = n/2 - 1; i >= 0; i--){
		heapmax(a, n, i);
	}
	for ( i = n - 1; i > 0; i--){
		swap(&a[0],&a[i]);
		heapmax(a, i, 0);
	}
}
int main() {
	printf("Sap Xep HEAPSORT\n");
	int i;
	FILE *f;
	record a[1000];
	int n = 0;
	f = fopen("data.txt","r");
		if(f == NULL){
			return 1;	
		}
	while( n < 1000 && fscanf(f,"%d %f",&a[n].key,&a[n].value) == 2){
		n++;
	}
		fclose(f);
		printf("du lieu tr khi xep\n");
	for(i = 0; i < n;i++){
		printf(" %d %.02f", a[i].key, a[i].value);
		
	}
	heapsort(a,n);
	printf("\ndu lieu sau khi xep\n");
	for(i = 0; i < n;i++){
		printf(" %d %.02f", a[i].key, a[i].value);
	}
	return 0;
}
