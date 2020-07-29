#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define M 26
typedef struct tudien {
	char tu[10];
	char nghia[100];
}tudien;
typedef struct Node {
	tudien data;
	Node *link;
}Node;
Node butket[M];
void khoitao(Node b[]) {
	for(int i=0; i<M; i++) 
		b[i].link=NULL;
}
int hambam(char tu[]) {
	char ch;
	ch = toupper(tu[0]);
	return (ch-65)%M;
}
//ham doi thanh chu In hoa
//65 l
void themtu(Node b[], tudien x) {
	int i;
	Node *p;
	i = hambam(x.tu);
	p = new(Node);
	p->data = x;
	p->link = b[i].link;
	b[i].link = p;
}
Node *tratu(Node b[], char tu[]) {
	int i;
	int tim=0;
	Node *p;
	i = hambam(tu);
	p = b[i].link;
	while(p!=NULL && !tim) {
		if(strcmp(p->data.tu,tu)==0)
			tim = 1;
		else
			p = p->link;
	}
	if(tim==1)
		return p;
	else
		return NULL;
}
int kiemtra(Node b[], char tu[]) {
	int i;
	int tim=0;
	Node *p;
	i = hambam(tu);
	p = b[i].link;
	while(p!=NULL && !tim) {
		if(strcmp(p->data.tu,tu)==0)
			tim = 1;
		else
			p = p->link;
	}
	if(tim==1)
		return 1;
	else
		return 0;
}
void intudien(Node b[]) {
	int i;
	Node *p;
	for(i=0;i<M;i++) {
		p = b[i].link;
		printf("\nDanh muc tu %c : ",i+65);
		while(p!=NULL) {
			printf("\nTu : %s, Nghia : %s",p->data.tu, p->data.nghia);
			p = p->link;
		}
	}
}
void xoatu(Node b[],char tu[]) {
	int i;
	Node *p, *q;
	i = hambam(tu);
	p = b[i].link;
	while(p!=NULL && strcmp(p->data.tu,tu)!=0) {
		q = p;
		p=p->link;
	}
	if(p==NULL)
		printf("\nTu nay khong co trong tu dien!!");
	else {
		if(p==b[i].link) {
			b[i].link = p->link;
			delete(p);
		} else {
			q->link = p->link;
			delete(p);
		}
		printf("\nXoa thanh cong!!");
	}
}
void ghifile(Node b[], char *filename) {
	FILE *f;
	int i;
	Node *p;
	f = fopen(filename,"wb");
	for(i=0;i<M;i++) {
		p = b[i].link;
		while(p!=NULL) {
			fwrite(&p->data,sizeof(tudien),1,f);
			p = p->link;
		}
	}
	printf("Write File Suscessfull");
	fclose(f);
}
void docfile(Node b[], char *filename) {
	FILE *f;
	tudien tam;
	f = fopen(filename,"rb");
	while(!feof(f)) {
		fread(&tam,sizeof(tudien),1,f);
		if(kiemtra(b,tam.tu)==0)
			themtu(b,tam);
	}
	printf("Open File Suscessfull");
	fclose(f);
}
int main() {
	int n, chon;
	tudien x;
	char ch[10];
	Node *p;
	do {
		printf("\t\nChuong trinh tu dien\n");
		printf("\t1.Nhap tu moi\n");
		printf("\t2.Tra tu\n");
		printf("\t3.In tu dien\n");
		printf("\t4.Xoa 1 tu\n");
		printf("\t5.Ghi File\n");
		printf("\t6.Doc File\n");
		printf("\t7.Thoat");
		printf("\nNhap lua chon cua ban : ");
		scanf("%d", &chon);
		switch(chon) {
			case 1:
				printf("\nBan nhap bao nhieu tu : ");
				scanf("%d", &n);
				fflush(stdin);
				for(int i = 0 ; i< n; i++) {
					printf("Nhap tu moi : ");
					fgets(x.tu, sizeof(x.tu), stdin);
					if(kiemtra(butket, x.tu) == 1)
						printf("\nTu nay da co trong tu dien!!\n");
					else {
						printf("Nhap nghia cua tu : ");
						fflush(stdin);
						fgets(x.nghia, sizeof(x.nghia), stdin);
						themtu(butket,x);
					}
				}
				break;
			case 2:
			
				printf("\nNhap tu can tra : ");
				fflush(stdin);
				fgets(ch, 10, stdin);
				p = tratu(butket,ch);
				if(p==NULL)
					printf("Tu nay khong co trong tu dien!");
				else
					printf("\nTu : %s co nghia la : %s",p->data.tu, p->data.nghia);
				printf("\nNhap phim bat ki de tiep tuc!!");
				break;
			case 3:
				intudien(butket);
				break;
			case 4:
				printf("\nNhap tu can xoa : ");
				fflush(stdin);
				fgets(ch, 10, stdin);
				xoatu(butket,ch);
				printf("\nNhan phim bat ki de tiep tuc!!");
				break;
			case 5:
				ghifile(butket,(char*)"Bangbam.txt");
				break;
			case 6:
				docfile(butket,(char*)"Bangbam.txt");
				break;
			case 7:
				printf("\nNhap phim bat ki de thoat !!\n");
				break;
		}
	}while(chon!=7);
}

