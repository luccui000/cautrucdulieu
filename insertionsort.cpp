#include <stdio.h>

// insertion sort
void insertionsort(int a[], int n){
	int pos, x;
	for(int i = 1; i < n; i++){
		x = a[i];
		pos = i - 1;
		while(pos >= 0 && a[pos] > x){
			a[pos + 1] = a[pos];
			pos--;
		}
		a[pos+ 1] = x;
	}
}
// Ham nay dung de in ra mang
void printArr(int a[], int n){
	for(int i = 0; i < n; i++)
		printf("%d\t", a[i]);
	printf("\n");
}
int main() {
	// IN ra day chua sap xep
	int a[100];
	int n;

	printf("Nhap so luong phan tu: ");
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		printf("Nhap phan tu thu a[%d]: ", i);
		scanf("%d", &a[i]);
	}
	printf("Day so chua sap xep: ");
	printArr(a, n);
	//  Goi ham sap xep
	insertionsort(a, n);
	// In ra day da sap xep
	printf("Day so sau khi sap xep: ");
	printArr(a, n);
	return 0;
}

