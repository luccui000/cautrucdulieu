#include <stdio.h>


struct Node { 
    int data; 
    struct Node* link; 
}; 
struct Node* top; 
  
void push(int data) { 
    struct Node* temp; 
    temp = new Node();  
    if (!temp) { 
        printf("\nStack Day");
        return;
    }  
    temp->data = data; 
    temp->link = top;  
    top = temp; 
} 
  
int isEmpty()  { 
    return top == NULL; 
} 
int peek()  { 
    if (!isEmpty()) 
        return top->data; 
    else
        return 0;
} 
  
  
void pop()  { 
    struct Node* temp;  
    if (top == NULL) { 
        printf("\nStack Rong\n");
        return;
    }  else { 
        temp = top;  
        top = top->link; 
        temp->link = NULL; 
        delete temp;
    } 
} 
  
void display()   { 
    struct Node* temp; 
    if (top == NULL) { 
        printf("\nStack Rong\n");
        return;
    }  else { 
        temp = top; 
        while (temp != NULL) { 
            printf("%d\t", temp->data);
            temp = temp->link; 
        } 
    } 
} 
  
int main()  { 
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
				push(x);
				break;
			case 2:
				printf("Top: %d\n", peek());
				pop();
				break;
			case 3:
				display();
				break;

		}
	} while(luachon != 0);
	return 0; 
} 
