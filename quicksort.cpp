#include <stdio.h>

void hoanvi(int &a, int &b) {
	int tam = a;
	a = b;
	b = tam;
}
void quick_sort(int a[], int l, int r) {
	int i = l;
	int j = r;
	int x = a[(l + r) / 2];
	do {
		while(a[i] < x) i++;
		while(a[j] > x) j--;
		if(i <= j) {
			hoanvi(a[i], a[j]);
			i++; j--;
		}
	} while(i < j);
	if(l < j) 
		quick_sort(a, l, j);
	if( i < r)
		quick_sort(a, i, r);
}
int  main() {
	int a[100];
	int n;
	printf("Nhap so luong phan tu: ");
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		printf("Nhap phan tu thu a[%d]: ", i);
		scanf("%d", &a[i]);
	}
	quick_sort(a, 0, n - 1);
	for(int i = 0; i < n; i++) 
		printf("%d\t" , a[i]);
	printf("\n");
	return 0;
}
