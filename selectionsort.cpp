#include <stdio.h>

void swap(int &a, int &b){
	int tmp = a;
	a = b;
	b = tmp;
}
// selection sort
void selectionsort(int a[], int n){
	for(int i = 0; i < n; i++){
		for(int j = i + 1; j < n; j++){
			if(a[i] > a[j])
				swap(a[i],a[j]);
		}
	}
}
int main() {
	int a[100];
	int n;
	printf("Nhap so luong phan tu: ");
	scanf("%d", &n);
	for(int i = 0; i< n; i++) {
		printf("Nhap phan tu thu a[%d]: ", i);
		scanf("%d", &a[i]);
	}
	printf("Day so: "); 
	// Phan nay goi ham in ra Mang xem truoc khi sap xep
	for(int i = 0; i < n; i++)
		printf("%d\t", a[i]);
	printf("\n");
	// Sap xep
	selectionsort(a, n);
	printf("Day so sau khi sap xep: "); 
	// IN mang sau khi sap xep
	for(int i = 0; i < n; i++)
		printf("%d\t", a[i]);
	printf("\n");
	return 0;
}
