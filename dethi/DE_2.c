/*
 * DE KIEM TRA DIEM QUA TRINH - MON CTDL & GIAI THUAT
 * De thi so 02
 * =====================================================
 * CAU 1 (4.0 diem): Binary Search
 * CAU 2 (3.0 diem): Cay nhi phan + duyet NLR
 * CAU 3 (3.0 diem): Danh sach lien ket don
 */

#include <stdio.h>
#include <stdlib.h>

/* ============================================================
 *  CAU 1 (4.0 DIEM) - BINARY SEARCH
 *  - Nhap mang n so nguyen da sap xep tang dan (n <= 100)
 *  - Nhap gia tri x can tim
 *  - Tim bang Binary Search, in chi so (neu co) hoac thong bao
 *    khong tim thay, kem so lan so sanh
 * ============================================================ */

int binarySearch(int a[], int n, int x, int *compareCount) {
    *compareCount = 0;
    int left = 0, right = n - 1;

    while (left <= right) {
        int mid = (left + right) / 2;
        (*compareCount)++;

        if (a[mid] == x)
            return mid;          /* Tim thay, tra ve chi so */
        else if (a[mid] < x)
            left = mid + 1;      /* Tim o nua ben phai */
        else
            right = mid - 1;     /* Tim o nua ben trai */
    }
    return -1; /* Khong tim thay */
}

void cau1() {
    printf("\n===== CAU 1: BINARY SEARCH =====\n");

    int n;
    printf("Nhap n (so phan tu, n <= 100): ");
    scanf("%d", &n);

    int a[100];
    printf("Nhap %d phan tu da sap xep tang dan:\n", n);
    for (int i = 0; i < n; i++) {
        printf("  a[%d] = ", i);
        scanf("%d", &a[i]);
    }

    /* In mang vua nhap */
    printf("Mang: ");
    for (int i = 0; i < n; i++) printf("%d ", a[i]);
    printf("\n");

    int x;
    printf("Nhap gia tri x can tim: ");
    scanf("%d", &x);

    int compareCount = 0;
    int idx = binarySearch(a, n, x, &compareCount);

    if (idx != -1)
        printf("Tim thay %d tai chi so %d (a[%d] = %d)\n", x, idx, idx, a[idx]);
    else
        printf("Khong tim thay %d trong mang.\n", x);

    printf("So lan so sanh: %d\n", compareCount);
}

/* ============================================================
 *  CAU 2 (3.0 DIEM) - CAY NHI PHAN + DUYET NLR
 *  Cau truc co dinh:
 *          1
 *         / \
 *        2   3
 *       / \
 *      4   5
 *  NLR: 1 -> 2 -> 4 -> 5 -> 3
 * ============================================================ */

typedef struct TNODE {
    int key;
    struct TNODE *pLeft;
    struct TNODE *pRight;
} TNODE;

/* Tao mot nut moi voi gia tri key */
TNODE* createNode(int key) {
    TNODE *p = (TNODE *)malloc(sizeof(TNODE));
    if (p == NULL) {
        printf("Khong du bo nho!\n");
        exit(1);
    }
    p->key    = key;
    p->pLeft  = NULL;
    p->pRight = NULL;
    return p;
}

/* Duyet cay theo thu tu truoc: Node - Left - Right (NLR) */
void NLR(TNODE *root) {
    if (root != NULL) {
        printf("%d ", root->key);   /* Xu ly nut hien tai (in gia tri) */
        NLR(root->pLeft);           /* Duyet cay con trai */
        NLR(root->pRight);          /* Duyet cay con phai */
    }
}

/* Giai phong toan bo cay (tranh memory leak) */
void freeTree(TNODE *root) {
    if (root != NULL) {
        freeTree(root->pLeft);
        freeTree(root->pRight);
        free(root);
    }
}

void cau2() {
    printf("\n===== CAU 2: CAY NHI PHAN + DUYET NLR =====\n");

    /*
     * Xay dung cay co dinh:
     *        1
     *       / \
     *      2   3
     *     / \
     *    4   5
     */
    TNODE *root = createNode(1);
    root->pLeft           = createNode(2);
    root->pRight          = createNode(3);
    root->pLeft->pLeft    = createNode(4);
    root->pLeft->pRight   = createNode(5);

    printf("Cay nhi phan da tao:\n");
    printf("        1\n");
    printf("       / \\\n");
    printf("      2   3\n");
    printf("     / \\\n");
    printf("    4   5\n\n");

    printf("Duyet NLR (Node-Left-Right): ");
    NLR(root);
    printf("\n");
    /* Ket qua mong doi: 1 2 4 5 3 */

    freeTree(root);
}

/* ============================================================
 *  CAU 3 (3.0 DIEM) - DANH SACH LIEN KET DON
 *  - Viet ham them mot phan tu vao DAU danh sach
 *  - Viet ham xoa phan tu co gia tri x
 *  - Trong main: them 10,20,30,40,50 vao dau; xoa 20; in danh sach
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

/* Them mot phan tu vao DAU danh sach */
void addFirst(List *L, int x) {
    Node *p = (Node *)malloc(sizeof(Node));
    if (p == NULL) {
        printf("Khong du bo nho!\n");
        return;
    }
    p->data  = x;
    p->pNext = L->pHead;
    L->pHead = p;
    if (L->pTail == NULL)   /* Danh sach truoc do rong */
        L->pTail = p;
    printf("  addFirst(%d) -> OK\n", x);
}

/* Xoa phan tu dau tien co gia tri x */
void removeNode(List *L, int x) {
    Node *p = L->pHead;
    Node *q = NULL; /* Nut truoc p */

    /* Tim nut co gia tri x */
    while (p != NULL && p->data != x) {
        q = p;
        p = p->pNext;
    }

    if (p == NULL) {
        printf("  removeNode(%d) -> Khong tim thay %d trong danh sach!\n", x, x);
        return;
    }

    /* Thuc hien xoa nut p */
    if (q == NULL) {
        /* p la nut dau danh sach */
        L->pHead = p->pNext;
        if (L->pHead == NULL)
            L->pTail = NULL; /* Danh sach tro thanh rong */
    } else {
        q->pNext = p->pNext;
        if (p == L->pTail)   /* Xoa nut cuoi */
            L->pTail = q;
    }
    free(p);
    printf("  removeNode(%d) -> Da xoa %d khoi danh sach\n", x, x);
}

void cau3() {
    printf("\n===== CAU 3: DANH SACH LIEN KET DON =====\n");

    List L;
    listInit(&L);

    /* Them 5 so vao DAU: 10, 20, 30, 40, 50
     * Vi them vao dau nen thu tu trong danh sach se la: 50->40->30->20->10 */
    printf("\n-- Them lan luot 10, 20, 30, 40, 50 vao dau danh sach --\n");
    addFirst(&L, 10);
    addFirst(&L, 20);
    addFirst(&L, 30);
    addFirst(&L, 40);
    addFirst(&L, 50);
    printList(&L);

    /* Xoa so 20 */
    printf("\n-- Xoa so 20 --\n");
    removeNode(&L, 20);
    printList(&L);

    /* Don dep bo nho */
    Node *cur = L.pHead;
    while (cur != NULL) {
        Node *tmp = cur;
        cur = cur->pNext;
        free(tmp);
    }
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
