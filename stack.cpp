#include <stdio.h>

#define MAX 100
struct stack {
	int data[MAX];
	int top = -1;
};

bool isEmpty(stack& s){
	return s.top == -1;
}
bool isFull(stack& s) {
	return s.top == MAX;
}
void push(stack& s, int data){
	if(isFull(s))
		printf("Stack Day\n");
	else
		s.data[++s.top] = data;
}

void pop(stack &s) {
	if(isEmpty(s))
		printf("Stack Rong\n");
	else 
		--s.top;
}
	
void printArr(stack& s){
	while(s.top >= 0){
		printf("Gia tri tai %d: %d\n", s.top, s.data[s.top]);
		pop(s);
	}
}
int main() {
	stack s;
	// Them phan tu cao stack 
	push(s, 11);
	push(s, 23);
	push(s, 12);
	push(s, 4);
	push(s, 43);
	
	
	printArr(s);
	return 0;
}
