#include <stdio.h>

struct Node
{
	int data;
	Node* next;
};
Node* createNode(int val) {
	Node *node = new Node();
	node->data = val;
	node->next = NULL;
	return node;
}
struct List
{ 
    Node* head;
    Node* tail;    
};
List l;
void initList() {
	l.head = l.tail = NULL;
}
void insertToHead(Node* node) {
    node->next = l.head;
    l.head = node;
}
void insertToTail(Node* node) {
    if (l.tail != NULL)
        l.tail->next = node;
    else {
        l.head = node;
        l.tail = node;
    }
}
void insertAfter(Node* node, Node* q) {
    if (q != l.tail) {
        node->next = q->next;
        q->next = node;
    }
    else {
        insertToTail(node);
    }
}

void removeAtHead() {
    if (l.head == nullptr)
        return;
    Node* temp = l.head;
    l.head = l.head->next;
    delete temp;
}
void removeAfter(Node* q) {
    Node* temp = q->next;
    q->next = temp->next;
    delete temp;
}
void printList() {
	Node* p;

	p = l.head;
	while (p != NULL) {
		printf("%d\t", p->data);	
		p = p->next;
	}
	printf("\n");
}
Node *searchNode(int value){
	Node *p = l.head;
	while(p->data != value && p != NULL) p = p->next;
	return p;
}
void menu() {	
	Node* node = NULL;
	int x;
	while(true) {
		printf("\n +++++ DANH SACH LIEN KET +++++ ");
		printf("\n1. Them gia tri vao dau DSLK ");
		printf("\n2. Them gia tri vao cuoi DSLK ");
		printf("\n3. Them gia tri vao sau Node");
		printf("\n4. Xoa dau DSLK");
		printf("\n5. Xoa phia sau Node");
		printf("\n6. In danh sach lien ket");
		printf("\n7. Them gia tri");
		printf("\nNhap vao lua chon cua ban: " );
		int choose;
		scanf("%d", &choose);
		switch(choose) {
			case 1:
				printf("Nhap gia tri can chen: ");
				scanf("%d", &x);
				node = createNode(x);
				insertToHead(node);
				break;
			case 2:
				printf("Nhap gia tri can chen: ");
				scanf("%d", &x);
				node = createNode(x);
				insertToTail(node);
				break;
			case 3:
				printf("Nhap gia tri cua Node can chen phia sau: ");
				scanf("%d", &x);
				node = searchNode(x);
				if(node == l.tail) {
					Node *p = new Node();
					int val;
					printf("Nhap vao gia tri can chen: ");
					scanf("%d", &val);
					p = createNode(val);
					node->next = p;
					l.tail = p;
				} else {	
					if(node != NULL) {
						Node *p = new Node();
						int val;
						printf("Nhap vao gia tri can chen: ");
						scanf("%d", &val);
						p = createNode(val);
						p->next = node->next;
						node->next = p;
					} else 
						printf("Khong tim thay Node phia truoc can chen nhu vay !!!!\n");
				}
				break;
			case 4:
				removeAtHead();
				break;
			case 5:
				printf("Nhap gia tri tai Node can XOA: ");
				scanf("%d", &x);
				node = searchNode(x);
				removeAfter(node);
				break;
			case 6:
				printf("+++++ IN DSLK +++++\n");
				printList();
				break;
			case 7:
				printf("Nhap vao gia tri can chen: ");
				scanf("%d", &x);
				node = createNode(x);
				if(l.head == NULL) 
					insertToHead(node);
				else {
					Node* p = l.head;
					while(p->next != NULL) 
						p = p->next;
					p->next = node;
					l.tail = node;
				}
				break;
		}
	}	
}
int main() {
	menu();
	return 0;
}










