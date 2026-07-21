#include <stdio.h>
#include <math.h>

struct Node
{
    int data;
    Node* pNext;
};

struct List
{
    Node* pHead;
    Node* pTail;
};

struct NodeTree
{
    int data;
    NodeTree *pLeft;
    NodeTree *pRight;
};

typedef NodeTree* TREE;

int InsertNode(TREE &t, int x)
{
    if(t != NULL)
    {
        if(x == t->data)
            return 0;

        if(x < t->data)
            return InsertNode(t->pLeft, x);
        else
            return InsertNode(t->pRight, x);
    }
    else
    {
        t = new NodeTree;

        if(t == NULL)
            return -1;

        t->data = x;
        t->pLeft = NULL;
        t->pRight = NULL;

        return 1;
    }
}

void TaoCay(TREE &t, List L)
{
    t = NULL;

    Node *p = L.pHead;

    while(p != NULL)
    {
        InsertNode(t, p->data);
        p = p->pNext;
    }
}

void NLR(TREE t)
{
    if(t != NULL)
    {
        printf("%d ", t->data);
        NLR(t->pLeft);
        NLR(t->pRight);
    }
}

void InitList(List &L)
{
    L.pHead=NULL;
    L.pTail=NULL;
}

void AddTail(List &L, Node* p)
{
    if(L.pHead == NULL)
        L.pHead = L.pTail = p;
    else
    {
        L.pTail->pNext=p;
        L.pTail = p;
    }
}

void CreateNode(List &L, int x)
{
    Node *p = new Node;
    if(p==NULL)
    {
        printf("Khong du bo nho.");
        return;
    }
    p->data=x;
    p->pNext=NULL;
    AddTail(L, p);
}

void ShowList(List L)
{
    printf("\nDanh sach: ");
    for(Node *p=L.pHead ; p != NULL; p=p->pNext)
        printf("%d ", p->data);
}

void ShowEven(List L)
{
    printf("\nDanh sach chan: ");
    for (Node *p = L.pHead; p!= NULL; p=p->pNext)
    {
        if(p->data %2 == 0)
            printf("%d ", p->data);
    }
}

void ShowOdd(List L)
{
    printf("\nDanh sach le: ");
    for (Node *p = L.pHead; p!= NULL; p=p->pNext)
    {
        if(p->data %2 != 0)
            printf("%d ", p->data);
    }
}

void XoaMin(List &L)
{
    if(L.pHead == NULL) return;
    if(L.pHead->pNext == NULL )
    {
        delete L.pHead;
        L.pHead = L.pTail = NULL;
        return;
    }
    Node *pMin = L.pHead;
    Node *pPreMin = NULL;
    Node *p = L.pHead;
    while (p->pNext != NULL)
    {
        if (pMin->data > p->pNext->data)
        {
            pMin = p->pNext;
            pPreMin = p;
        }
        p=p->pNext;
    }
    if (pMin==L.pHead)
    {
        L.pHead = L.pHead->pNext;
    } else if (pMin == L.pTail)
    {
        L.pTail = pPreMin;
        pPreMin->pNext = NULL;
    } else
    {
        pPreMin->pNext = pMin->pNext;
    }
    delete pMin;
}

void swap (int &i, int &j)
{
    int temp;
    temp = i;
    i = j;
    j = temp;
}

void InterchangeSort(List L)
{
    if (L.pHead == NULL || L.pHead->pNext == NULL) return;

    for (Node *i = L.pHead; i->pNext != NULL; i = i->pNext)
    {
        for (Node *j = i->pNext; j != NULL; j = j->pNext)
        {
            if (i->data > j->data)
            {
                swap(i->data, j->data);
            }
        }
    }
}

void TachDS(List &L, List &L1, List &L2)
{
    InitList(L1); 
    InitList(L2);
    
    Node *p = L.pHead;
    while (p != NULL)
    {
        Node *next = p->pNext;
        p->pNext = NULL;
        if(p->data %2 == 0)
            AddTail(L1, p);
        else
            AddTail(L2, p);
            
        p = next;
    }
    L.pHead = L.pTail = NULL;
}

void NhapThuCong(List &L, int n)
{
    printf("Nhap gia tri cho cac node:\n");
    for(int i = 0; i < n; i++){
        int x;
        printf("> ");
        if(scanf("%d", &x) <= 0) return;
        CreateNode(L, x);
    }
}
TREE Search(TREE t, int x)
{
    if(t == NULL)
        return NULL;

    if(x == t->data)
        return t;

    if(x < t->data)
        return Search(t->pLeft, x);
    else
        return Search(t->pRight, x);
}

int Dem(TREE t)
{
    if(t == NULL)
        return 0;

    int dem = 0;

    if(t->data % 2 == 0) //dieu kien
        dem = 1;

    return dem + Dem(t->pLeft) + Dem(t->pRight);
}

int ChieuCao(TREE t)
{
    if(t == NULL)
        return 0;

    int trai = ChieuCao(t->pLeft);
    int phai = ChieuCao(t->pRight);

    return 1 + (trai > phai ? trai : phai);
}

int main()
{
    List L;
    InitList(L);
    int n;
    printf("1. Tao danh sach gom n node: ");
    if(scanf("%d", &n) <= 0) return 0;
    NhapThuCong(L, n);
    ShowList(L);

    printf("\n\n2. Hien thi danh sach chan / le");
    ShowEven(L);
    ShowOdd(L);

    XoaMin(L);
    printf("\n\n3. Xoa phan tu nho nhat");
    ShowList(L);

    printf("\n\n4. Sap xep tang dan");
    InterchangeSort(L);
    ShowList(L);

    // printf("\n\n5. Tach danh sach");
    // List L1;
    // List L2;
    // TachDS(L, L1, L2);
    // printf("\n- L1:");
    // ShowList(L1);
    // printf("\n- L2 (Con lai):");
    // ShowList(L2);
    printf("\n\n6. Tao BNT");
    TREE t = NULL;
    TaoCay(t, L);
    printf("Duyet NLR: ");
    NLR(t);

    printf("\n\n7. Tìm nhanh");
    int x;
    printf("\nNhap gia tri can tim: ");
    scanf("%d", &x);

    TREE kq = Search(t, x);

    if(kq != NULL)
        printf("Tim thay %d", kq->data);
    else
    printf("Khong tim thay");

    printf("\n\n8. Chieu cao cay");
    printf("Chieu cao cay con trai: %d", ChieuCao(t->pLeft));
    printf("Chieu cao cay con phai: %d", ChieuCao(t->pRight));

    return 0;
}