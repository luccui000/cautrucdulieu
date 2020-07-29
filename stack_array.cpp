#include <stdio.h>
#define M 10
 
int top = -1;
 
bool isFull(){
    if(top >= M - 1)
        return true;
    else
        return false;
    
}
 
bool IsEmpty(){
    if(top == -1){
        return true;
    }else{
        return false;
    }
}
 
void Push(int stack[], int val){
    if(isFull() == true){
        printf("\nStack day\n");
    }else{
        ++top;
        stack[top] = val;
    }
}
 
void Pop(){
    if(IsEmpty() == true)
        printf("\nStack rong");
    else
        --top;
    
}
 
 
int Top(int stack[]){
    return stack[top];
}
 
int Size(){
    return top + 1;
}
void display(int stack[]) {
	for(int i = 0; i < Size(); i++)
		printf("%d\t", stack[i]);
}
int main(){
	int top = -1; 
	int stack[M];
    
	int luachon, x;
	do {
		printf("\n1. Them phan tu vao Stack ");
		printf("\n2. Xoa phan tu cuoi cung ra khoi Stack ");
		printf("\n3. In Stack ");
		printf("\n0. Thoat ");
		printf("\nNhap lua chon cua ban: ");
		scanf("%d", &luachon);
		switch(luachon) {
			case 1:
				printf("Nhap gia tri: ");
				scanf("%d", &x);
				Push(stack, x);
				break;
			case 2:
				printf("Top: %d\n", Top(stack));
				Pop();
				break;
			case 3:
				display(stack);
				break;

		}
	} while(luachon != 0);
	return 0;
}
