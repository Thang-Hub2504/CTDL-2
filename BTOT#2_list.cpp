


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct cannang{
	char name[50];
	int cannang;
}cannang;

typedef struct CNnode{
	cannang data;
	CNnode *pNext;
}CNnode;

CNnode* createNode(int x){
	CNnode *p=(CNnode*)malloc(sizeof(CNnode));
	if(p == NULL){
		printf("Loi cap phat bo nho!!");
		return NULL;
	}
	return p;
}

typedef struct List{
	CNnode*phead;
	CNnode*ptail;
}List;
CNnode*new_ele;
CNnode x;

void AddFirst(List &l, CNnode*new_ele){
	new_ele -> pNext = NULL;
	if(l.phead ==  NULL){
		l.phead = new_ele;
		l.ptail = l.phead;
	}
	else{
		new_ele -> pNext = l.phead;
		l.phead = new_ele;
	}
}
CNnode *preverse(CNnode* phead){
	CNnode *prev = NULL;
	CNnode *curr = phead;
	CNnode *pNext = NULL;
	
	while(curr != NULL){
		pNext = curr -> pNext;
		curr -> pNext = prev;
		prev = curr;
		curr = pNext;
	}
	return prev;
}


int main(){
	int n;
	List l={NULL,NULL};
	printf("Nhap so nguoi: ");
	scanf("%d", &n);
	for(int i=0; i<n; i++){
		CNnode *p = (CNnode*)malloc(sizeof(CNnode));
 		p -> pNext = NULL;
 		getchar();
		printf("\nNhap ten cua nguoi %d: ",i+1);
		fgets(p->data.name,40,stdin);
		p->data.name[strcspn(p->data.name, "\n")] = '\0';
		printf("\nNhap can nang cua nguoi %d: ",i+1);
		scanf("%d", &p -> data.cannang);
		AddFirst(l,p);
	}
	
	printf("\nDanh sach");
	printf("\n| %-3s | %-9s | %-8s |\n", "STT", "Ho va ten", "Can nang");
	CNnode *p = l.phead;
	int i= 0;
	while(p){	
		i++;
		printf("\n| %-3d | %-25s | %-8d |\n",i,p -> data.name, p -> data.cannang);
		p = p -> pNext;
	}
}
