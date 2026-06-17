#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct Node{
	int infor;
	struct Node *pNext;
}Node;

typedef struct Stack{
	Node *pHead;
}Stack;

void initStack(Stack *S){
	S -> pHead = NULL;
}

char IsEmpty(Stack *S){
	if(S -> pHead == NULL)	return 1;
	else	return 0;
}

void push(Stack *S, int x){
	Node *pNew = (Node*)malloc(sizeof(Node));
	pNew -> infor = x;
	pNew -> pNext = S->pHead;
    S->pHead = pNew;
}

int Pop(Stack *S){
	if(IsEmpty(S))	return -1;
	Node *pTemp = S -> pHead;
	int x = pTemp -> infor;
	S -> pHead = pTemp -> pNext;
	free(pTemp);
	return x;
}

int top(Stack *S){
	if(IsEmpty(S))	return -1;
	return S -> pHead -> infor;
}

int main(){
	
}
