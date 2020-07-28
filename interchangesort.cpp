#include <stdio.h>

void swap(int &a, int &b){
	int tmp = a;
	a = b;
	b = tmp;
}
void xuat_mang(int a[], int n){
	for(int i = 0; i < n; i++)
		printf("%d\t", a[i]);
	printf("\n");
}
void interchangesort(int a[], int n){
	for(int i = 0; i < n - 1; i++){
		for(int j = i + 1; j < n; j++){
			if(a[j] < a[i])
				swap(a[i], a[j]);
		}
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

	interchangesort(a, n);

	printf("Day so sau khi sap xep: "); 
	xuat_mang(a, n);
	return 0;
}
