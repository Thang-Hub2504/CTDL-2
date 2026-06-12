#include <stdio.h>
#include <stdbool.h>

typedef struct Node {
    int songuyen[100];
    int top;
}NODE;

void KhoiTao(NODE* n){
    n -> top = -1;
}

bool isEmpty(NODE* n){
    if (n -> top == -1) return true;
    else return false;
}

void push(NODE* n, int x){
    if (n-> top < 99){
        n-> top++;
        n-> songuyen[n->top] = x;
    }
	else{
        printf("\n stack da day!");
        return;
    }
}

int pop(NODE* n){
    int val;
    if (isEmpty(n) == true) return -1;
    else {
        val = n->songuyen[n->top];
        n->top--;
    }
    return val;
}

void KiemTraStack(NODE* n, int a){
    if (isEmpty(n)){
        printf("\n Stack hien tai dang rong");
    }
	else{
        printf("\n cac phan tu con lai trong mang la:");
        for(int i=0; i<= n->top; i++){
            printf("\n%d\t", n->songuyen[i]);
        }
    }
}

int main(){
    NODE stack;
    KhoiTao(&stack);
    int n, x, popcheck, check;
    printf("\n nhap so phan tu muon push:");
        scanf("%d", &n);

    for(int i=0; i<n; i++){
        printf("\n nhap so nguyen thu %d:", i);    
        scanf("%d", &x);
        push(&stack, x);
    }

    while(true){
        printf("\n ban muon pop phan tu khong? 0 or 1: ");
        scanf("%d", &check);

        if(check == 1){
            printf("\n ban muon pop bao nhieu phan tu:");
            scanf("%d", &n);
            
            for(int i=0; i<n; i++){
                popcheck = pop(&stack);
                if (popcheck == -1){
                    printf("\n da pop het phan tu trong mang");
                    break;
                }else {
                    printf("\n pop phan tu thu %d:%d", i, popcheck);
                }
            }
        }
        else break;
    }

    KiemTraStack(&stack, n);
	return 0;
}