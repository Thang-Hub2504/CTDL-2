 #include<stdio.h>
 #include<conio.h>
 #include<string.h>
 #include<stdlib.h>
 
 typedef struct Balo{
 	char mahang[30];
 	char tenhang[30];
 	int sl;
 	int dg;
 	int tt;
 }Balo;
 
 typedef struct BLnode{
 	Balo data;
 	BLnode *pNext;
 }BLnode;
 
 typedef struct List{
 	BLnode *phead;
 	BLnode *ptail;
 }list;
 BLnode *new_ele;
 BLnode x;
 
 void AddTail(list &l, BLnode *new_ele){
 	new_ele -> pNext = NULL;
 	if(l.phead == NULL){
 		l.phead = new_ele;
 		l.ptail = l.phead;
	 }
	 else{
	 	l.ptail -> pNext = new_ele;
	 	l.ptail = new_ele;
	 }
 }
 
 BLnode* createNode(int x){
 	BLnode *p = (BLnode*)malloc(sizeof(BLnode));
 	if(p == NULL){
 		printf("Loi cap phat bo nho: ");
 		return NULL;
	 }
	 return p;
 }
 
 void nhap(List &danhsach, int &n){
 	printf("Nhap so luong do vat ban mang: ");
 	scanf("%d", &n);
 	for(int i = 1; i<=n; i++){
 		BLnode *p = (BLnode*)malloc(sizeof(BLnode));
 		p -> pNext = NULL;
 		printf("\nNhap ma do vat [%d]: ", i);
 		scanf("%s", p -> data.mahang);
 		printf("\nNhap ten do vat [%d]: ", i);
 		scanf("%s", p -> data.tenhang);
 		printf("\nNhap so luong do vat [%d]: ", i);
 		scanf("%d", &p -> data.sl);
 		printf("\nNhap gia do vat [%d]: ", i);
 		scanf("%d", &p -> data.dg);
 		p -> data.tt = p -> data.dg * p -> data.sl;
 		printf("\nTong tien do vat [%d]: %d\n", i, p -> data.tt);
		AddTail(danhsach,p);
	 }
 }
 
 void xuat(List &l){
 	printf("\nDanh sach do vat trong balo la!!!");
 	printf("\n| %-7s | %-8s | %-8s | %-7s | %-10s |","Ma hang","Ten hang","So luong","Don gia","Thanh tien");
 	BLnode *p = l.phead;
 	while(p){
 		printf("\n| %-7s | %-8s | %-8d | %-7d | %-10d |", p -> data.mahang, p -> data.tenhang, p -> data.sl, p -> data.dg, p -> data.tt);
 		p = p -> pNext;
	 }
 }
 
 int main(){
 	List danhsach = {NULL,NULL};
 	int n;
 	nhap(danhsach, n);
 	xuat(danhsach);
 	return 0;
 }