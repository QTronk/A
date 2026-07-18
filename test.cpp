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

void AddHead(List &L, Node* p)
{
    if (L.pHead == NULL)
        L.pHead = L.pTail = p;
    else
    {
        p->pNext = L.pHead;
        L.pHead = p;
    }
}

void AddAfterHead(List &L, Node* p)
{
    if (L.pHead == NULL)
        L.pHead = L.pTail = p;
    else
    {
        p->pNext = L.pHead->pNext;
        L.pHead->pNext = p;
        if (L.pTail == L.pHead)
            L.pTail = p;
    }
}

void RemoveHead(List &L)
{
    Node *p = L.pHead;
    L.pHead = L.pHead->pNext;

    if (L.pHead == NULL)
    {
        L.pTail = NULL;
    }
    delete p;
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

bool laSoChinhPhuong(int n) {
    if (n < 0) return false; 
    
    int canBacHai = (int)sqrt(n); 
    
    return (canBacHai * canBacHai == n); 
}

bool laSoNguyenTo(int n) {
    if (n < 2) {
        return false;
    }
    
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            return false; 
        }
    }
    
    return true; 
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

void SelectionSort(List L)
{
    if (L.pHead == NULL || L.pHead->pNext == NULL) return;

    for (Node *i = L.pHead; i->pNext != NULL; i = i->pNext)
    {
        Node *pMin = i;
        for (Node *j = i->pNext; j != NULL; j = j->pNext)
        {
            if (pMin->data > j->data)
            {
                pMin = j;
            }
        }
        swap(i->data, pMin->data);
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
                if(laSoNguyenTo(p->data))
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
    SelectionSort(L);
    ShowList(L);

    printf("\n\n5. Tach danh sach");
    List L1;
    List L2;
    TachDS(L, L1, L2);
    printf("\n- L1 (So nguyen to):");
    ShowList(L1);
    printf("\n- L2 (Con lai):");
    ShowList(L2);
    
    printf("\n");
    return 0;
}