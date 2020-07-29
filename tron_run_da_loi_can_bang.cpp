#include"stdio.h"
#include"stdlib.h"
#include"string.h"
#define n 4

int Copy_run(FILE **f,FILE **fx,int ele_start,int &ele_new_run) {
	int cur=ele_start,old,Eof;
	do {
		fwrite(&cur,sizeof(cur),1,*fx);
		old=cur;
		Eof=fread(&cur,sizeof(cur),1,*f);
		if(Eof<=0) {
			ele_new_run = 0;
			return -1;// het file
		}
	} while(old<=cur);
	ele_new_run=cur;
	return 0;
}
void Distribute_Run(char *fa,char *fax[],int &q) {
	int current,old,Eof,new_run=0,tx;
	int i=0;
	FILE *f,*fx[15];
	f=fopen(fa,"w+");
	for(i=0;i<n;i++)
		fx[i]=fopen(fax[i],"w+");
	Eof=fread(&current,sizeof(current),1,f);
	if(Eof<=0) 
		return;
	do {
		Eof = Copy_run(&f,&fx[i],current,new_run);
		current = new_run;
		i = i%n+1;
		q++;
	} while(Eof>0);
}
void Distribute(char *fa,char *fax[],int &q) {
	FILE *f,*fx[7];
	f=fopen(fa,"w+");
	int j;
	for(int i=0;i<n;i++) {
		remove(fax[i]);
		fx[i]=fopen(fax[i],"w+");
	}
	j = n;
	q = 0;
	int current,old;
	do {
		if(j<n-1) j++;
		else j=0;
		q++;
		fread(&current,sizeof(current),1,f);
		do {
			old  = current;
			fwrite(&current,sizeof(current), 1, fx[j]);
			fread(&current,sizeof(current),1,f);
		} while(!feof(f)&&old<current);
	} while(!feof(f));
}
/**/
void Merge(char *fa[],int &q) {
	FILE *f[20];
	int i,j,k1,k2,min,mx,Eof,x,tx;
	int t[20],ta[20];
	int current[100],cur;
	for(i=0;i<2*n;i++) {
		t[i]=i;
		f[i]=fopen(fa[i],"w+");
	}
	do {
		if(q<n) k1=q;
		else k1=n;
		for(i=0;i<k1;i++) {
			fread(&current[i],sizeof(current[i]), 1, f[t[i]]);
			ta[i]=t[i];
		}
		q = 0;
		j = n;
		do {
			k2 = k1;
			q++;
			do {
				i=0;mx=0;
				min=current[i];
				while(i<k2-1) {
					i++;
					x = current[i];
					if(x<min) {
						min=x;
						mx=i;
					}
				}
				fwrite(&min,sizeof(min),1,f[t[j]]);
				Eof=fread(&cur, sizeof(cur), 1, f[ta[mx]]);
				if(Eof<=0) {
					remove(fa[ta[mx]]);
					ta[mx]=ta[k2];
					ta[k2]=ta[k1];
					k1=k1-1;
					k2--;
				} else {
					if(min>cur){
						tx=ta[mx];
						ta[mx]=ta[k2];
						ta[k2]=tx;
						k2--;
					}
				}
			} while(k2!=0);
			if(j<n*2-1)
				j++;
			else j=n;
		}while(k1!=0);
		for(i=0;i<n;i++) {
			tx=t[i];
			t[i]=ta[n+i];
			t[n+i]=tx;
		}
	} while(q!=1);
	fcloseall();
}
/**/
void Copy(char *fa,char *ga) {
	int current;
	FILE *f,*g;
	f = fopen(fa,"w+");
	g = fopen(ga,"w+");
	while(!feof(f)) {
		fread(&current,sizeof(current),1,f);
		fwrite(&current,sizeof(current),1,g);
	}
	fcloseall();
	}
	/**/
void Taofile(char *filename,int k) {
	int t;
	FILE *f;
	f = fopen(filename,"w+");
	for(int i=0;i<k;i++) {
		t = rand() % 1000;
		fwrite(&t,sizeof(t),1,f);
	}
	fcloseall();
}
void xuat(char *filename) {
	int cur;
	FILE *f;
	f = fopen(filename,"rb");
	while(fread(&cur,sizeof(cur),1,f)>0)
		printf("%5d",cur);
	fcloseall();
}
/**/
int main() {
	char *filename[]= {(char*)"f1.txt", (char*)"f2.txt", (char*)"f3.txt",(char*)"f4.txt", (char*)"f4.txt", (char*)"f5.txt", (char*)"f6.txt", (char*)"f7.txt", (char*)"f8.txt", (char*)"f9.txt"};
	char* f = (char*)"trung.txt";
	Taofile(f,20);
	int q;
	xuat(f);
	printf("\nfile f sau khi xap xep\n");
	for(int i=0;i<n;i++)
		Distribute(f,filename,q);
	Merge(filename,q);
	Copy(f,filename[0]);
	xuat(f);
	return 0;
}
