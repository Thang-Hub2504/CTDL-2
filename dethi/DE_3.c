/*
 * DE KIEM TRA DIEM QUA TRINH - MON CTDL & GIAI THUAT
 * De thi so 03
 * =====================================================
 * CAU 1 (4.0 diem): Insertion Sort
 * CAU 2 (3.0 diem): Stack (dung danh sach lien ket don)
 * CAU 3 (3.0 diem): Queue (dung mang tinh)
 */

#include <stdio.h>
#include <stdlib.h>

/* ============================================================
 *  CAU 1 (4.0 DIEM) - INSERTION SORT
 *  - Nhap mang n so nguyen (n <= 100)
 *  - Sap xep tang dan bang Insertion Sort
 *  - In mang sau khi sap xep va so lan dich chuyen (shift)
 * ============================================================ */

void insertionSort(int a[], int n, int *shiftCount) {
    *shiftCount = 0;
    for (int i = 1; i < n; i++) {
        int x = a[i];
        int pos = i - 1;
        /* Tim vi tri chen x va dich chuyen cac phan tu sang phai */
        while (pos >= 0 && a[pos] > x) {
            a[pos + 1] = a[pos]; /* Day phan tu sang phai 1 vi tri */
            (*shiftCount)++;
            pos--;
        }
        a[pos + 1] = x; /* Chen x vao vi tri dung */
    }
}

void cau1() {
    printf("\n===== CAU 1: INSERTION SORT =====\n");

    int n;
    printf("Nhap n (so phan tu, n <= 100): ");
    scanf("%d", &n);

    int a[100];
    printf("Nhap %d phan tu:\n", n);
    for (int i = 0; i < n; i++) {
        printf("  a[%d] = ", i);
        scanf("%d", &a[i]);
    }

    /* In mang truoc khi sap xep */
    printf("\nMang ban dau: ");
    for (int i = 0; i < n; i++) printf("%d ", a[i]);
    printf("\n");

    int shiftCount = 0;
    insertionSort(a, n, &shiftCount);

    /* In mang sau khi sap xep */
    printf("Mang sau khi sap xep tang dan: ");
    for (int i = 0; i < n; i++) printf("%d ", a[i]);
    printf("\n");

    printf("So lan dich chuyen (shift) trong qua trinh sap xep: %d\n", shiftCount);
}

/* ============================================================
 *  CAU 2 (3.0 DIEM) - STACK (dung danh sach lien ket don)
 *  Viet ham: push, pop, isEmpty
 *  Trong main: push(100,200,300), pop hai gia tri, in trang thai
 * ============================================================ */

typedef struct SNode {
    int data;
    struct SNode *pNext;
} SNode;

typedef struct {
    SNode *pHead; /* Dinh stack la pHead cua danh sach */
} Stack;

/* Khoi tao stack rong */
void stackInit(Stack *S) {
    S->pHead = NULL;
}

/* Kiem tra stack co rong khong */
int isEmpty(Stack *S) {
    return (S->pHead == NULL);
}

/* Them phan tu vao dinh stack (chen vao dau danh sach) */
void push(Stack *S, int x) {
    SNode *p = (SNode *)malloc(sizeof(SNode));
    if (p == NULL) {
        printf("Khong du bo nho!\n");
        return;
    }
    p->data = x;
    p->pNext = S->pHead;
    S->pHead = p;
    printf("  Push(%d) -> OK\n", x);
}

/* Lay phan tu ra khoi dinh stack (xoa dau danh sach) */
int pop(Stack *S) {
    if (isEmpty(S)) {
        printf("  Pop() -> Stack rong! Khong the pop.\n");
        return -1; /* Bao loi */
    }
    SNode *p = S->pHead;
    int val = p->data;
    S->pHead = p->pNext;
    free(p);
    printf("  Pop() -> Lay ra gia tri: %d\n", val);
    return val;
}

/* In trang thai stack (tu dinh xuong day) */
void printStack(Stack *S) {
    if (isEmpty(S)) {
        printf("  Stack hien tai: [TRONG]\n");
        return;
    }
    printf("  Stack hien tai (dinh -> day): ");
    SNode *p = S->pHead;
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->pNext;
    }
    printf("\n");
}

void cau2() {
    printf("\n===== CAU 2: STACK (dung danh sach lien ket don) =====\n");

    Stack S;
    stackInit(&S);

    /* Kiem tra isEmpty truoc khi push */
    printf("isEmpty() = %s\n", isEmpty(&S) ? "TRUE (stack rong)" : "FALSE (stack co phan tu)");

    /* Push 3 phan tu: 100, 200, 300 */
    printf("\n-- Push 3 phan tu: 100, 200, 300 --\n");
    push(&S, 100);
    push(&S, 200);
    push(&S, 300);
    printStack(&S);

    /* Pop hai phan tu */
    printf("\n-- Pop 2 phan tu --\n");
    pop(&S);
    pop(&S);
    printStack(&S);

    /* Kiem tra isEmpty sau khi pop */
    printf("\nisEmpty() = %s\n", isEmpty(&S) ? "TRUE (stack rong)" : "FALSE (stack co phan tu)");

    /* Don dep bo nho con lai */
    while (!isEmpty(&S)) pop(&S);
}

/* ============================================================
 *  CAU 3 (3.0 DIEM) - QUEUE (dung mang tinh, kich thuoc toi da 100)
 *  Viet ham: enqueue, dequeue, isFull
 *  Trong main: enqueue(1,2,3,4,5), dequeue hai gia tri,
 *              kiem tra trang thai hang doi (day hay khong)
 * ============================================================ */

#define MAX_QUEUE 100

typedef struct {
    int data[MAX_QUEUE];
    int f; /* Chi so dau hang doi (front) */
    int r; /* Chi so sau cuoi hang doi (rear) */
    int count; /* So phan tu hien co */
} Queue;

/* Khoi tao hang doi rong */
void queueInit(Queue *Q) {
    Q->f = 0;
    Q->r = 0;
    Q->count = 0;
}

/* Kiem tra hang doi co rong khong */
int isEmptyQ(Queue *Q) {
    return (Q->count == 0);
}

/* Kiem tra hang doi co day khong */
int isFull(Queue *Q) {
    return (Q->count == MAX_QUEUE);
}

/* Them phan tu vao cuoi hang doi */
void enqueue(Queue *Q, int x) {
    if (isFull(Q)) {
        printf("  Enqueue(%d) -> THAT BAI: Hang doi day!\n", x);
        return;
    }
    Q->data[Q->r] = x;
    Q->r = (Q->r + 1) % MAX_QUEUE; /* Xoay vong */
    Q->count++;
    printf("  Enqueue(%d) -> OK\n", x);
}

/* Lay phan tu ra khoi dau hang doi */
int dequeue(Queue *Q) {
    if (isEmptyQ(Q)) {
        printf("  Dequeue() -> THAT BAI: Hang doi rong!\n");
        return -1;
    }
    int val = Q->data[Q->f];
    Q->f = (Q->f + 1) % MAX_QUEUE; /* Xoay vong */
    Q->count--;
    printf("  Dequeue() -> Lay ra gia tri: %d\n", val);
    return val;
}

/* In trang thai hang doi */
void printQueue(Queue *Q) {
    printf("  isFull()  = %s\n", isFull(Q)    ? "TRUE (hang doi day)"  : "FALSE (chua day)");
    printf("  isEmptyQ()= %s\n", isEmptyQ(Q)  ? "TRUE (hang doi rong)" : "FALSE (co phan tu)");
    if (!isEmptyQ(Q)) {
        printf("  Noi dung hang doi (dau -> cuoi): ");
        for (int i = 0; i < Q->count; i++) {
            printf("%d ", Q->data[(Q->f + i) % MAX_QUEUE]);
        }
        printf("\n");
    }
}

void cau3() {
    printf("\n===== CAU 3: QUEUE (dung mang tinh, kich thuoc toi da %d) =====\n", MAX_QUEUE);

    Queue Q;
    queueInit(&Q);

    /* Enqueue 5 phan tu: 1, 2, 3, 4, 5 */
    printf("\n-- Enqueue 5 phan tu: 1, 2, 3, 4, 5 --\n");
    enqueue(&Q, 1);
    enqueue(&Q, 2);
    enqueue(&Q, 3);
    enqueue(&Q, 4);
    enqueue(&Q, 5);
    printQueue(&Q);

    /* Dequeue 2 phan tu */
    printf("\n-- Dequeue 2 phan tu --\n");
    dequeue(&Q);
    dequeue(&Q);
    printQueue(&Q);
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
