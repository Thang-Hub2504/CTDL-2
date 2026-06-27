/*
 * DE KIEM TRA DIEM QUA TRINH - MON CTDL & GIAI THUAT
 * De thi so 01
 * =====================================================
 * CAU 1 (4.0 diem): Bubble Sort + dem so lan hoan doi
 * CAU 2 (3.0 diem): Danh sach lien ket don (them cuoi, in, dem)
 * CAU 3 (3.0 diem): Stack dung mang tinh (kich thuoc toi da 100)
 */

#include <stdio.h>
#include <stdlib.h>

/* ============================================================
 *  CAU 1 (4.0 DIEM) - BUBBLE SORT
 *  - Nhap mang n so nguyen (n <= 100)
 *  - Sap xep tang dan bang Bubble Sort
 *  - In mang sau khi sap xep va so lan hoan doi (swap)
 * ============================================================ */

/* Ham hoan vi hai so nguyen */
void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void bubbleSort(int a[], int n, int *swapCount) {
    *swapCount = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = n - 1; j > i; j--) {
            /* Neu cap ke nhau sai vi tri thi doi cho */
            if (a[j] < a[j - 1]) {
                swap(&a[j], &a[j - 1]);
                (*swapCount)++;
            }
        }
    }
}

void cau1() {
    printf("\n===== CAU 1: BUBBLE SORT =====\n");

    int n;
    printf("Nhap n (so phan tu, n <= 100): ");
    scanf("%d", &n);

    int a[100];
    printf("Nhap %d phan tu:\n", n);
    for (int i = 0; i < n; i++) {
        printf("  a[%d] = ", i);
        scanf("%d", &a[i]);
    }

    printf("Mang ban dau:              ");
    for (int i = 0; i < n; i++) printf("%d ", a[i]);
    printf("\n");

    int swapCount = 0;
    bubbleSort(a, n, &swapCount);

    printf("Mang sau khi sap xep:      ");
    for (int i = 0; i < n; i++) printf("%d ", a[i]);
    printf("\n");

    printf("So lan hoan doi (swap):    %d\n", swapCount);
}

/* ============================================================
 *  CAU 2 (3.0 DIEM) - DANH SACH LIEN KET DON
 *  - addTail : them mot phan tu vao CUOI danh sach
 *  - printList: in toan bo danh sach
 *  - countList: dem so luong phan tu
 *  Trong main: them 1,2,3,4,5 -> in -> in so luong
 * ============================================================ */

typedef struct Node {
    int data;
    struct Node *pNext;
} Node;

typedef struct {
    Node *pHead;
    Node *pTail;
} List;

/* Khoi tao danh sach rong */
void listInit(List *L) {
    L->pHead = NULL;
    L->pTail = NULL;
}

/* Them mot phan tu vao CUOI danh sach */
void addTail(List *L, int x) {
    Node *p = (Node *)malloc(sizeof(Node));
    if (p == NULL) {
        printf("Khong du bo nho!\n");
        return;
    }
    p->data  = x;
    p->pNext = NULL;

    if (L->pHead == NULL) {
        /* Danh sach dang rong */
        L->pHead = p;
        L->pTail = p;
    } else {
        L->pTail->pNext = p;
        L->pTail = p;
    }
    printf("  addTail(%d) -> OK\n", x);
}

/* In toan bo danh sach */
void printList(List *L) {
    if (L->pHead == NULL) {
        printf("  Danh sach: [RONG]\n");
        return;
    }
    printf("  Danh sach: ");
    Node *p = L->pHead;
    while (p != NULL) {
        printf("%d", p->data);
        if (p->pNext != NULL) printf(" -> ");
        p = p->pNext;
    }
    printf(" -> NULL\n");
}

/* Dem so luong phan tu trong danh sach */
int countList(List *L) {
    int count = 0;
    Node *p = L->pHead;
    while (p != NULL) {
        count++;
        p = p->pNext;
    }
    return count;
}

/* Giai phong toan bo danh sach */
void freeList(List *L) {
    Node *p = L->pHead;
    while (p != NULL) {
        Node *tmp = p;
        p = p->pNext;
        free(tmp);
    }
    L->pHead = NULL;
    L->pTail = NULL;
}

void cau2() {
    printf("\n===== CAU 2: DANH SACH LIEN KET DON =====\n");

    List L;
    listInit(&L);

    /* Them 5 so vao CUOI: 1, 2, 3, 4, 5 */
    printf("\n-- Them lan luot 1, 2, 3, 4, 5 vao cuoi danh sach --\n");
    addTail(&L, 1);
    addTail(&L, 2);
    addTail(&L, 3);
    addTail(&L, 4);
    addTail(&L, 5);

    /* In danh sach */
    printf("\n-- In danh sach --\n");
    printList(&L);

    /* In so luong phan tu */
    printf("\n-- Dem so luong phan tu --\n");
    printf("  So luong phan tu: %d\n", countList(&L));

    freeList(&L);
}

/* ============================================================
 *  CAU 3 (3.0 DIEM) - STACK DUNG MANG TINH (toi da 100)
 *  - push  : them phan tu vao dinh stack
 *  - pop   : lay phan tu ra khoi dinh stack, in gia tri
 *  - isEmpty: kiem tra stack co rong khong
 *  Trong main: push(10,20,30) -> pop 1 lan -> in trang thai
 * ============================================================ */

#define MAX_STACK 100

typedef struct {
    int data[MAX_STACK];
    int top; /* Chi so dinh stack, -1 khi rong */
} Stack;

/* Khoi tao stack rong */
void stackInit(Stack *S) {
    S->top = -1;
}

/* Kiem tra stack co rong khong */
int isEmpty(Stack *S) {
    return (S->top == -1);
}

/* Kiem tra stack co day khong */
int isFull(Stack *S) {
    return (S->top == MAX_STACK - 1);
}

/* Them phan tu x vao dinh stack */
void push(Stack *S, int x) {
    if (isFull(S)) {
        printf("  push(%d) -> THAT BAI: Stack day!\n", x);
        return;
    }
    S->top++;
    S->data[S->top] = x;
    printf("  push(%d) -> OK  | dinh stack (top=%d)\n", x, S->top);
}

/* Lay phan tu ra khoi dinh stack, tra ve gia tri */
int pop(Stack *S) {
    if (isEmpty(S)) {
        printf("  pop() -> THAT BAI: Stack rong!\n");
        return -1;
    }
    int val = S->data[S->top];
    S->top--;
    printf("  pop() -> Lay ra gia tri: %d\n", val);
    return val;
}

/* In trang thai stack */
void printStackStatus(Stack *S) {
    if (isEmpty(S)) {
        printf("  Trang thai stack: RONG (isEmpty = TRUE)\n");
    } else {
        printf("  Trang thai stack: CO PHAN TU (isEmpty = FALSE)\n");
        printf("  Noi dung (dinh -> day): ");
        for (int i = S->top; i >= 0; i--) {
            printf("%d ", S->data[i]);
        }
        printf("\n");
    }
}

void cau3() {
    printf("\n===== CAU 3: STACK DUNG MANG TINH =====\n");

    Stack S;
    stackInit(&S);

    /* Kiem tra trang thai ban dau */
    printf("\n-- Trang thai ban dau --\n");
    printf("  isEmpty() = %s\n", isEmpty(&S) ? "TRUE (stack rong)" : "FALSE");

    /* Push 3 phan tu: 10, 20, 30 */
    printf("\n-- Push 3 phan tu: 10, 20, 30 --\n");
    push(&S, 10);
    push(&S, 20);
    push(&S, 30);

    /* Pop 1 phan tu */
    printf("\n-- Pop 1 phan tu --\n");
    pop(&S);

    /* Kiem tra va in trang thai stack */
    printf("\n-- Kiem tra trang thai stack --\n");
    printStackStatus(&S);
}

/* ============================================================
 *  MAIN
 * ============================================================ */
int main() {
    cau1();
    cau2();
    cau3();
    return 0;
}
