#include <stdio.h>
#define M 10

struct Node {
	int data;
	struct Node* pLink;
};
// Tao Node
void addNode(Node* node, int val) {
	node->data = val;
	node->pLink = nullptr;
}
struct LinkedList {
	struct Node* pHead;
	struct Node* pTail;
};

struct HashTable {
	int key;
	struct Node* pLink;
};
HashTable hash[M];
void initHash() {
	for(int i = 0; i < M; i++) 
		hash[i].pLink = nullptr;
}
int hashF(int data) {
	return data % M;
}
//
void addLink(int data) {
	Node* node = new Node();
	addNode(node, data);
	int x = hashF(data);
	node->pLink = hash[x].pLink;
	hash[x].key = x;
	hash[x].pLink = node;
}
void printHash() {
	for(int i = 0; i < M; i++) {
		printf("Hash %d: ", i);
		Node* p = hash[i].pLink;
		while(p != nullptr){
			printf("%d\t", p->data);
			p = p->pLink;
		}
		printf("\n");
	}
}
int main() {

	addLink(10);
	addLink(23);
	addLink(45);
	addLink(43);
	addLink(54);
	addLink(13);
	addLink(84);
	printHash();
	return 0;
}
