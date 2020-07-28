
#include <stdio.h>
#include <string.h>
#define M 10

struct HashTable {

};
typedef int Hash;

int hashF1(int data) {
	return data % M;
}
int hashF2(int n, int data) {
	return n - (data % n);
}
Hash hash[M];
void init() {
	memset(hash, -1, sizeof(hash));
}
void addHash(int data) {
	int x = hashF1(data);
	int y = hashF2(7, data);
	if(hash[x] == -1)
		hash[x] = data;
	else {
		while(hash[x] != -1) {
			x = (x + y) % M;
		}
		hash[x] = data;
	}
}
void addHash2(int data) {
	int x = hashF1(data);
	if(hash[x] == -1)
		hash[x] = data;
	else {
		while(hash[x] != -1) {
			x = (x + 1) % M;
		}
		hash[x] = data;
	}
}
void printHash() {
	for(int i = 0; i < M; i++) {
			printf("%d\t", hash[i]);
	}
	printf("\n");
}

int main() {
	init();
	addHash2(23);
	addHash2(12);
	addHash2(53);
	addHash2(64);
	addHash2(62);
	addHash2(73);
	addHash2(84);
	addHash2(62);
	printHash();
	return 0;
}
