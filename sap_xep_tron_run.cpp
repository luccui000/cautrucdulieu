#include <stdio.h>

int p, n;

void tao_file() {
	//Tao file co n phan tu
	int i,x;
	FILE *fp;
	fp=fopen("Bang.txt","wb");
	printf("Cho biet so phan tu : ");
	scanf("%d", &n);
	for(i=0;i<n;i++) {
		printf("Nhap so thu %d : ",i+1);
		scanf("%d", &x);
		fprintf(fp,"%3d",x);
	}
	fclose(fp);
}
void xuat_file() {
	int x;
	FILE *fp;
	fp = fopen("Bang.txt","rb");
	int i=0;
	while(i<n) {
		fscanf(fp,"%d",&x);
		printf("%3d",x);
		i++;
	}
	fclose(fp);
}
void chia(FILE *a, FILE *b, FILE *c, int p) {
	int dem, x;
	a=fopen("Bang.txt","rb");
	b=fopen("Bang1.txt","wb");
	c=fopen("Bang2.txt","wb");
	while(!feof(a)) {
		dem=0;
		while((dem<p) && (!feof(a))) {
			fscanf(a,"%3d",&x);
			fprintf(b,"%3d",x);
			dem++;
		}
		//Chia p phan tu cho c
		dem=0;
		while((dem<p) && (!feof(a))) {
			fscanf(a,"%3d",&x);
			fprintf(c,"%3d",x);
			dem++;
		}
	}
	fclose(a);
	fclose(b);
	fclose(c);
}
void tron(FILE *b, FILE *c, FILE *a, int p) {
	int stop, x, y, l, r;
	a = fopen("Bang.txt","wb");
	b = fopen("Bang1.txt","rb");
	c = fopen("Bang2.txt","rb");
	while((!feof(b)) && (!feof(c))) {
			l=0; //so phan tu cua b da ghi het len a
			r=0; //so phan tu cua c da ghi het len a
			fscanf(b,"%3d",&x);
			fscanf(c,"%3d",&y);
			stop=0;
			while((l!=p) && (r!=p) && (!stop)) {
				if(x<y) {
					fprintf(a,"%3d",x);
					l++;
					if((l<p) && (!feof(b)))
						fscanf(b,"%3d",&x); //chua du p phan tu va chua
					else {
						fprintf(a,"%3d",y);
						r++;
						if((feof(b)))
							stop=1;
					}
				} else {
					fprintf(a,"%3d",y);
					r++;
					if((r<p) && (!feof(c)))
						fscanf(c,"%3d",&y); //chua du p phan tu va chua
					else {
						fprintf(a,"%3d",x);
						l++;
						if((feof(c)))
							stop=1;
					}
				}
		}
		//chep phan tu con lai cua p phan tu tren b len a
		while((!feof(b)) && (l<p)) {
			fscanf(b,"%3d",&x);
			fprintf(a,"%3d",x);
			l++;
		}
		//chep phan tu con lai cua p phan tu tren c len a
		while((!feof(c)) && (r<p)) {
			fscanf(c,"%3d",&y);
			fprintf(a,"%3d",y);
			r++;
		}
	}
	if(!feof(b)) {
	//chep phan tu con lai cua b len a
		while(!feof(b)) {
			fscanf(b,"%3d",&x);
			fprintf(a,"%3d",x);
		}
	}
	if(!feof(c)) {
		//chep phan tu con lai cua c len a
		while(!feof(c)) {
			fscanf(c,"%3d",&x);
			fprintf(a,"%3d",x);
		}
	}
	fclose(a);
	fclose(b);
	fclose(c);
}
int main()
{
FILE *a, *b, *c;
tao_file();
xuat_file();
p=1;
while(p<n)
{
chia(a,b,c,p);
tron(b,c,a,p);
p=2*p;
}
printf("\n");
xuat_file();
return 0;
}
