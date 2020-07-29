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

void bublesort(int a[], int n){
	for(int i = 0; i < n - 1; i++){
		for(int j = n - 1; j > i; j--){
			if(a[j] < a[j-1])
				swap(a[j], a[j- 1]);
		}
	}
}
int main() {
	int a[100];
	int n;
	printf("Phan so luong phan tu: ");
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		printf("Nhap phan tu thu a[%d]: ", i);
		scanf("%d", &a[i]);
	}
	printf("\nTRUOC KHI SAP SEP\n");
	xuat_mang(a, n);
	bublesort(a, n);
	printf("\n+++++ BUBBLE SORT +++++\n");
	xuat_mang(a, n);
}
