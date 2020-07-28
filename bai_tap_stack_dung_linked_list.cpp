#include <bits/stdc++.h>

struct Node {
	int data;
	struct Node* next;
};
struct Linked_list {
	struct Node* pHead;
	struct Node* pTail;
};
void init(Linked_list& l) {
	l.pHead = l.pTail = NULL;
}
Node* addNode( int val) {
	Node *node = new Node;
	node->data = val;
	node->next = NULL;
	printf("Da them Node moi\n");
	return node;
}
	
void addHead(Linked_list& l, Node* node) {
	l.pHead = node;
	l.pTail = l.pHead;
}
void addLinked(Linked_list& l, Node* node) {
	if(l.pHead == NULL)
		addHead(l, node);
	else {
		l.pTail->next = node;
		l.pTail = node;
	}
	printf("Da them Linked\n");
}
void insertLinked(Linked_list& l, Node* src, Node* node) {
	if(l.pHead == NULL)
		addHead(l, node);
	else {
		Node* p = l.pHead;
		while(p != src) p = p->next;
		if(src == l.pTail) {
			src->next = node;
			l.pTail = node;
		}
		src->next = node;
		node->next = src->next;
		delete src->next;	
	}
}

struct stack {
	Linked_list list;
	Node *top;
};
void printNode(Node *node) {
	printf("Gia tri cua Node: %d\n", node->data);
}
void printLinked(Linked_list& l) {
	printf("\n+++++ IN LINKED LIST +++++\n");
	Node *p = l.pHead;
	while(p != NULL) {
		printf("%d\t", p->data);
		p = p->next;
	}
	printf("\n");
}

int main() {
	Node *node = new Node;
	Linked_list list;
	// init Linked List
	init(list);
	// Add First Node
	node = addNode(10); 
	printNode(node);
	// Add Node to Link
	addLinked(list, node);
	// 
	node = addNode(30); 
	printNode(node);
	addLinked(list, node);
	//
	node = addNode(23); 
	printNode(node);
	addLinked(list, node);
	//
	node = addNode(30); 
	printNode(node);
	addLinked(list, node);
	// 
	printLinked(list);
	return 0;
}

