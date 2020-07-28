#include <stdio.h>
#include <string.h>
#define INP "SinhVien.dat"

struct SinhVien {
	char ma[10];
	char hoten[20];
};
void writeFile(char* fName) {
	FILE* f;
	int n, i; SinhVien sv;
	f = fopen(fName, "ab");
	printf("Nhap so luong sinh vien: "); scanf("%d", &n);
	fflush(stdin);
	for(int i = 0; i < n; i++){
		printf("Sinh vien thu %d\n", i);
		printf("MSSV: "); gets(sv.ma);
		printf("Ho ten: "); gets(sv.hoten);
		fwrite(&sv, sizeof(sv), 1, f);
		fflush(stdin);
	}
	fclose(f);
	printf("An phim bat ki de tiep tuc !!!\n");
}
void readFile(char* fName) {
	FILE* f;
	SinhVien sv;
	f= fopen(fName, "rb");
	printf("MSSV	| Ho va ten\n");
	fread(&sv, sizeof(sv), 1, f);
	while(!feof(f)) {
		printf("%s\t%s\n", sv.ma, sv.hoten);
		fread(&sv, sizeof(sv), 1, f);
	}
	printf("An phim bat ki de tiep tuc !!!\n");
}
void Search(char* fName) {
	char mssv[10];
	FILE *f;
	int found =0;
	SinhVien sv;
	fflush(stdin);
	printf("Nhap MSSV sinh vien can tim: "); gets(mssv);
	f = fopen(fName, "rb");
	while(!feof(f) && found == 0){
		fread(&sv, sizeof(sv), 1, f);
		if(strcmp(sv.ma, mssv) == 0) 
			found = 1;
	}
	
	fclose(f);
	if(found == 1)
		printf("Tim thay SV co ma %s Ho va ten la: %s\n", sv.ma, sv.hoten);
	else
	printf("Khong tim thay sinh vien co ma %s\n", mssv);
	printf("An phim bat ki de tiep tuc !!!\n");
}
void menu() {
	printf("1. Nhap DSSV\n");
	printf("2. In DSSV\n");
	printf("3. Tim Kiem\n");
	printf("4. Xoa du lieu\n");
	printf("0. Thoat\n");
}
int main() {
	int c;
	while(1) {
		menu();
		printf("Ban chon 0, 1, 2, 3: "); scanf("%d", &c);
		if(c == 1)
			writeFile((char*)INP);
		else if(c == 2)
			readFile((char*)INP);
		else if(c == 3)
			Search((char*)INP);
		else 
			break;
	}
	return 0;
}
