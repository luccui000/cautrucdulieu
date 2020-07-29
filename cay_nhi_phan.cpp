#include"stdio.h"
#include"string.h"
#include <stdlib.h>

#define MAX 50

typedef struct sv
{
	char hoten[MAX];
	int tuoi;
}sv;
typedef struct node
{
	sv data;
	node *left;
	node *right;
}node;

typedef struct node *TREE;
TREE root;

void init(){
	root = NULL;
}
void CreateTree(TREE &root)
{	
	sv s;
	fflush(stdin);
	printf("Nhap ho ten: ");
	gets(s.hoten);
	if(strcmp(s.hoten, "n") != 0) {
		printf("Nhap tuoi: ");
		scanf("%d",&s.tuoi);
		root=(node*)malloc(sizeof(node));
		root->data = s;
		printf("\nCon trai cua %s (ENTER NULL)\n", s.hoten);
		CreateTree(root->left);
		printf("\nCon phai cua %s (ENTER NULL)\n", s.hoten);
		CreateTree(root->right);
	} else 
		root=NULL;
}

void NLR(TREE root)
{
	if (root != NULL)
	{
		printf("\t|__>Ten: %s\t Tuoi: %d\n", root->data.hoten, root->data.tuoi);
		NLR(root->left);
		NLR(root->right);
	}
}
void LNR(TREE root)
{
	if (root != NULL)
	{
			LNR(root->left);
			printf("\t|__>Ten: %s\t Tuoi: %d\n", root->data.hoten,root->data.tuoi);
			LNR(root->right);
	}
}
void LRN(TREE root)
{
	if (root != NULL)
	{
		LRN(root->left);
		LRN(root->right);
		printf("\t|__>Ten: %s\t Tuoi: %d\n", root->data.hoten, root->data.tuoi);
	}
}

int max(int a,int b)
{
	if(a>b)
		return a;
	else
		return b;
}
int Hightree(TREE root)
{
	if(root==NULL)
		return 0;
	else
		return max(Hightree(root->left),Hightree(root->right))+1;
}
void InsertNode(TREE &root, sv x)
{
	if(root!=NULL)
	{
		if(strcmp(root->data.hoten,x.hoten)==0) return ;
			if(root->data.tuoi>x.tuoi)
				InsertNode(root->left,x);
			else
				InsertNode(root->right,x);
	}
	else
	{
		root=new(node);
		root->data=x;
		root->left=root->right=NULL;
	}
}
void init(TREE &t) {
	t = NULL;
}
void CreateTree1(TREE &root)
{
	int n;
	sv x;
	printf("\nNhap so sv:");
	scanf("%d",&n);
	printf("\nNhap thong tin cho sv:");
	for(int i=1;i<=n;i++)
	{
		printf("\nNhap ho ten:");
		fflush(stdin);
		gets(x.hoten);
		printf("\nNhap tuoi:");
		scanf("%d",&x.tuoi);
		InsertNode(root,x);
	}
}
void Findreplace(TREE &p,TREE &q)
{
	if(q->right!=NULL)
		Findreplace(p,q->right);
	else
	{
		p->data=q->data;
	 	p=q;
	 	if(q->left!=NULL)
	 		q=q->left;
	 	else
	 		q=q->right;
	}
}
void Findreplace2(TREE &p,TREE &q)
{
	if(q->right!=NULL)
		Findreplace2(p,q->left);
	else
	{
		p->data=q->data;
	 	p=q;
	 	if(q->right!=NULL)
	 		q=q->right;
	 	else
	 		q=q->left;
	}
}
bool c = false;
void Deletenode(TREE &root,sv x)
{
	if(root==NULL)
		return;
	if(root->data.tuoi>x.tuoi)
		Deletenode(root->left,x);
	if(root->data.tuoi<x.tuoi)
		Deletenode(root->right,x);
	if(root->data.tuoi==x.tuoi) {
		node *p = root;
		if(root->right==NULL)
			root = root->left;
		else
			if(root->left==NULL)
				root=root->right;
			else
				Findreplace2(p,root->right);
		delete(p);
		c = true;
	}
}
void Deletetree(TREE &root)
{
	if(root!=NULL)
	{
		Deletetree(root->left);
		Deletetree(root->right);
		Deletenode(root,root->data);
	}
}
node* Search(TREE root, sv x) {
	if(root!=NULL) {
		if(root->data.tuoi == x.tuoi)
			return root;
		if(root->data.tuoi>x.tuoi)
			return Search(root->left,x);
		else
			return Search(root->right,x);
	} else
		return NULL;
}
void menu() {
	int choose;
	TREE t;
	do {
		printf("\n+++++ MENU +++++\n");
		printf("\n1. Nhap TREE");
		printf("\n2. Duyet TREE");
		printf("\n3. Tim Node theo tuoi");
		printf("\n4. Nhap TREE theo so luong");
		printf("\n5. Xoa Tat Ca Cay");
		printf("\n6. Chieu cao cua Cay");
		printf("\n7. Xoa Sinh Vien theo tuoi");
		printf("\n0. Thoat");
		printf("\nNhap lua chon cua ban: ");
		scanf("%d",&choose);
		init();
		switch(choose) {
		case 0:
			break;
		case 1:
			CreateTree(t);
			break;
		case 2:
			printf("\n+++++ DUYET CAY +++++\n");
			printf("=== Duyet NLR ===\n");
				NLR(t);
			printf("\n=== Duyet LRN ===\n");
				LRN(t);
			printf("\n=== Duyet LNR ===\n");
				LNR(t);
			break;
		case 3:
			sv z;
			printf("Nhap tuoi: ");
			scanf("%d", &z.tuoi);
			node *n;
			n = Search(t, z);
			if(n != NULL)
				printf("Tim thay\n");
			else 
				printf("Khong co SV nao co tuoi nhu vay\n");
			break;
		case 4:
			init(t);
			CreateTree1(t);
			break;
		case 5:
			Deletetree(t);
			break;
		case 6:
			printf("Chieu cao cua cay la: %d\n", Hightree(t));
			break;
		case 7:
			printf("Nhap Tuoi Sinh Vien muon xoa: ");
			sv x;
			scanf("%d", &x.tuoi);
			Deletenode(t, x);
			if(c)
				printf("Da xoa SV co tuoi %d \n", x.tuoi);
			else
				printf("Khong tim thay ma so can xoa\n");
			break;
		default:
			break;
	}
	} while(choose != 0);
	
}
int main()
{
	menu();
	return 0;
}
