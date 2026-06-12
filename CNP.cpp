#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
	int key;
	struct Node *left, *right;
}Node;

Node* createNode(int x){
	Node* p = (Node*)malloc(sizeof(Node));
	p -> key = x;
	p -> left = p -> right = NULL;
	return p;
}
typedef Node*tree;

Node* insert(Node* root, int x){
	if(root == NULL) return createNode(x);
	if(x < root -> key)
		root -> left = insert(root -> left, x);
	else
		root -> right  = insert(root -> right, x);
	return root;
}

void NLR(tree root){
	if(root != NULL){
		printf("%d\t",root -> key);
		NLR(root -> left);
		NLR(root -> right);
	}
}

void LNR(tree root){
	if(root != NULL){
		LNR(root ->left);
		printf("%d\t", root -> key);
		LNR(root -> right);
	}
}

void LRN(tree root){
	if(root != NULL){
		LRN(root -> left);
		LRN(root -> right);
		printf("%d\t", root -> key);
	}
}

int main(){
	int n,x;
	printf("Nhap so phan tu cua cay: ");
	scanf("%d",&n);
	tree root = NULL;
	for(int i=0; i<n; i++ ){
		printf("Nhap phan tu so %d: ", i);
		scanf("%d",&x);
		root = insert(root,x);
	}
	printf("\nDuyet NLR: ");
	NLR(root);
	
	printf("\nDuyet LNR: ");
	LNR(root);
	
	printf("\nDuyet LRN: ");
	LRN(root);
	
	return 0;
}