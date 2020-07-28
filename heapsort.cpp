#include <stdio.h>

void hoanvi(int &a, int &b){
	int tmp = a;
	a = b;
	b = tmp;
}
void xuat_mang(int a[], int n){
	for(int i = 0; i < n; i++)
		printf("%d\t", a[i]);
	printf("\n");
}
// Heap Sort
void Shift(int a[], int l, int r){
	int i = l;
	int j = 2 * i;
	int x = a[i];
	while(j <= r){
		if(j < r)
			++j;
		if(a[j] < x)
			break;
		else {
			a[i] = a[j];
			i = j;
			j = 2 * i;
			a[i] = x;
		}
	}
}
void createHeap(int a[], int n ) {
	int l = n/2;
	while(l >= 0){
		Shift(a, l, n - 1);
		l--;
	}
}
void heapsort(int a[], int n) {
	createHeap(a, n);
	int r = n;
	while(r >= 0){
		hoanvi(a[0], a[r]);
		r--;
		Shift(a, 0, r);
	}
}
int main() {
	int a[100], n;
	printf("nhap so luong phan tu: ");
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		printf("nhap phan tu thu a[%d]: ", i);
		scanf("%d", &a[i]);
	}
	printf("Day so da nhap: "); 
	xuat_mang(a, n);
	heapsort(a, n - 1);
	printf("Day so sau khi sap xep: "); 
	xuat_mang(a, n);
	return 0;
}

