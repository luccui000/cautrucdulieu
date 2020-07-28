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
	int a[] = { 2, 54, 23, 66, 33, 85, 4, 56, 23, 6, 44, 99, 10, 9, 48, 38 };
	int n = sizeof(a)/ sizeof(a[0]);
	// IN ra day chua sap xep
	printf("Day so chua sap xep: ");
	printArr(a, n);
	//  Goi ham sap xep
	insertionsort(a, n);
	// In ra day da sap xep
	printf("Day so sau khi sap xep: ");
	printArr(a, n);
	return 0;
}

