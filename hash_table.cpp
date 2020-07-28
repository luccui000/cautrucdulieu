#include <stdio.h>
#include <string.h>

#define MAX 50
#define M 26
#define INP "data.txt"

struct Tudien {
	char tu[MAX];
	char nghia[MAX];
};
struct Node {
	Tudien tudien;
	struct Node* pLink;
};
struct HashTable {
	int key;
	struct Node* pLink;
};
HashTable hash[M];
int convertChar(char c) {
	if(c >= 'a' && c <= 'z')
		return c - 97;
	if(c >= 'A' && c <= 'Z')
		return c - 65;
	return 0;
}
void remove_newline_ch(char *line) {
	int new_line = strlen(line) -1;
	if (line[new_line] == '\n')
		line[new_line] = '\0';
}
void init() {
	for(int i = 0; i < M; i++) {
		hash[i].pLink = nullptr;	
	}
}

Tudien addTu() {
	Tudien tudien;
	printf("Nhap tu Tieng Anh: ");
	fgets(tudien.tu, sizeof(tudien.tu), stdin);
	remove_newline_ch(tudien.tu);
	printf("Nhap nghia Tieng Viet: ");
	fgets(tudien.nghia, sizeof(tudien.nghia), stdin);
	remove_newline_ch(tudien.nghia);
	return tudien;
}
Node* addNode() {
	Node* node = new Node;
	Tudien tudien = addTu();
	node->tudien = tudien;
	node->pLink = nullptr;
	return node;
}
void addHash() {
	Node* node = addNode();
	int x = convertChar(node->tudien.tu[0]);
	node->pLink = hash[x].pLink;
	hash[x].pLink = node;
}
void addHash(char *tu, char *nghia){
	Tudien tudien;
	strcpy(tudien.tu, tu);
	strcpy(tudien.nghia, nghia);
	// 
	Node* node = new Node();
	node->tudien = tudien;
	int x = convertChar(node->tudien.tu[0]);
	node->pLink = hash[x].pLink;
	hash[x].pLink = node;
}
void printHash() {
	for(int i = 0; i < M; i++) {
		printf("Hash %c: ", i + 65);
		Node* p = hash[i].pLink;
		while(p != nullptr) {
			printf("[%s]: %s\t", p->tudien.tu, p->tudien.nghia);
			p = p->pLink;
		}
		printf("\n");
	}
}
void traTu() {
	char tu[MAX];
	printf("Nhap tu Tieng Anh can tra: ");
	fgets(tu, sizeof(tu), stdin);
	remove_newline_ch(tu);
	int x = convertChar(tu[0]);
	Node *p = hash[x].pLink;
	bool ok = false;
	while(p != nullptr) {
		if(strcmp(p->tudien.tu, tu) == 0) {
			printf("[%s]: %s\n", p->tudien.tu, p->tudien.nghia);
			ok = true;
			break;
		}
		p = p->pLink;
	}
	if(!ok)
		printf("Khong tim thay tu: %s\n", tu);
}
void loadFile(const char* name) {
	char tu[MAX];
	char nghia[MAX];
	FILE* fp = fopen(name, "rt");
	if(fp == NULL) {
		printf("File Loi !!!");
		return;
	} else { 
		while(!feof(fp)) {
			fgets(tu, 255, (FILE*)fp);
			fgets(nghia, 255, (FILE*)fp);
			addHash(tu, nghia);	
		}
	}
}
int main() {
	addHash((char*)"Apple", (char*)"Tao");
	printf("\n++++ TU DIEN ++++\n");
	printHash();
	traTu();
	return 0;
}
