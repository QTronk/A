#include <stdlib.h>
#include <time.h>

void NhapRandom(List &L, int n)
{
    srand(time(NULL));
    
    printf("Tu dong sinh ngau nhien cac node:\n");
    for(int i = 0; i < n; i++){
        int x = rand() % 99 + 1;
        printf("> %d\n", x);
        CreateNode(L, x);
    }
}

void BubbleSort(List L)
{
    if (L.pHead == NULL || L.pHead->pNext == NULL) return;
    Node *pTailSorted = NULL;
    bool swapped;
    do
    {
        swapped = false;
        Node *p = L.pHead;
        while (p->pNext != pTailSorted)
        {
            if (p->data > p->pNext->data)
            {
                swap(p->data, p->pNext->data);
                swapped = true;
            }
            p = p->pNext;
        }
        pTailSorted = p;
        
    } while (swapped);
}

void InsertionSort(List L)
{
    if (L.pHead == NULL || L.pHead->pNext == NULL) return;
    for (Node *i = L.pHead->pNext; i != NULL; i = i->pNext)
    {
        int key = i->data;
        Node *j = L.pHead;
        
        while (j != i)
        {
            if (j->data > key)
                swap(j->data, key);
            j = j->pNext;
        }
        i->data = key;
    }
}

void NhapMang(int a[], int n)
{
    printf("Nhap %d phan tu cho mang:\n", n);
    for(int i = 0; i < n; i++)
    {
        printf("a[%d] = ", i);
        if(scanf("%d", &a[i]) <= 0) return;
    }
}

void MangToDS(List &L, int a[], int n)
{
    InitList(L);
    
    for(int i = 0; i < n; i++)
    {
        CreateNode(L, a[i]);
    }
}

void DSToMang(List L, int a[], int &n)
{
    n = 0;
    for (Node *p = L.pHead; p != NULL; p = p->pNext)
    {
        a[n] = p->data;
        n++;
    }
}

void ShowMang(int a[], int n)
{
    printf("\nDu lieu trong mang: ");
    if (n == 0)
    {
        printf("(Mang rong)");
        return;
    }
    
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
}

void XoaTheoGiaTri(List &L, int x)
{
    Node *p = L.pHead;
    Node *pPre = NULL;

    while (p != NULL && p->data != x)
    {
        pPre = p;
        p = p->pNext;
    }

    if (p == NULL)
    {
        printf("\nKhong tim thay phan tu %d trong danh sach!", x);
        return;
    }

    if (p == L.pHead)
    {
        L.pHead = L.pHead->pNext;
        if (L.pHead == NULL)
            L.pTail = NULL;
    }
    else if (p == L.pTail)
    {
        L.pTail = pPre;
        pPre->pNext = NULL;
    }
    else
    {
        pPre->pNext = p->pNext;
    }

    delete p;
    printf("\nDa xoa phan tu %d thanh cong.", x);
}

void ChenVaoDSHopLe(List &L, int x)
{
    Node *pNew = new Node;
    if (pNew == NULL) return;
    pNew->data = x;
    pNew->pNext = NULL;
    if (L.pHead == NULL || x <= L.pHead->data)
    {
        pNew->pNext = L.pHead;
        L.pHead = pNew;
        if (L.pTail == NULL) L.pTail = pNew;
        printf("\nDa chen %d vao dau danh sach.", x);
        return;
    }
    Node *p = L.pHead;
    while (p->pNext != NULL && p->pNext->data < x)
    {
        p = p->pNext;
    }

    pNew->pNext = p->pNext;
    p->pNext = pNew;
    if (pNew->pNext == NULL)
    {
        L.pTail = pNew;
        printf("\nDa chen %d vao cuoi danh sach.", x);
    }
    else
        printf("\nDa chen %d vao giua danh sach.", x);
}

void XoaTrungDanhSachDaXep(List &L)
{
    if (L.pHead == NULL || L.pHead->pNext == NULL) return;
    Node *p = L.pHead;
    while (p->pNext != NULL)
    {
        if (p->data == p->pNext->data)
        {
            Node *pTrung = p->pNext;
            p->pNext = pTrung->pNext;
            if (pTrung == L.pTail)
                L.pTail = p;
            delete pTrung;
        }
        else
            p = p->pNext;
    }
    printf("\nDa loai bo cac phan tu trung lap khoi danh sach da sap xep.");
}

void XoaNhoHonN(List &L, int n)
{
    while (L.pHead != NULL && L.pHead->data < n)
    {
        Node *pTemp = L.pHead;
        L.pHead = L.pHead->pNext;
        delete pTemp;
    }
    if (L.pHead == NULL)
    {
        L.pTail = NULL;
        return;
    }
    Node *p = L.pHead;
    while (p->pNext != NULL)
    {
        if (p->pNext->data < n)
        {
            Node *pXoa = p->pNext;
            p->pNext = pXoa->pNext;
            if (pXoa == L.pTail) L.pTail = p;
            delete pXoa;
        }
        else
            p = p->pNext;
    }
}

int DemNode(List L)
{
    int count = 0;
    Node *p = L.pHead;
    while (p != NULL)
    {
        count++;
        p = p->pNext;
    }
    return count;
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
void TachDS(List L, List &L1, List &L2)
{
    //Khong mat L goc
    InitList(L1); 
    InitList(L2);

    Node *p = L.pHead;

    while (p != NULL)
    {
        Node *q = new Node;

        q->data = p->data;
        q->pNext = NULL;

        if(p->data % 2 == 0)
            AddTail(L1, q);
        else
            AddTail(L2, q);

        p = p->pNext;
    }
}
void LNR(TREE t)
{
    if(t != NULL)
    {
        LNR(t->pLeft);
        printf("%d ", t->data);
        LNR(t->pRight);
    }
}
void LRN(TREE t)
{
    if(t != NULL)
    {
        LRN(t->pLeft);
        LRN(t->pRight);
        printf("%d ", t->data);
    }
}

int Dem(TREE t)
{
    if(t == NULL)
        return 0;

    int dem = 0;

    // Node lá (0 con)
    if(t->pLeft == NULL && t->pRight == NULL)
        dem = 1;

    // Node có đúng 1 con trái
    // if(t->pLeft != NULL && t->pRight == NULL)
    //     dem = 1;

    // Node có đúng 1 con phải
    // if(t->pLeft == NULL && t->pRight != NULL)
    //     dem = 1;

    // Node có đúng 1 con (trái hoặc phải)
    // if((t->pLeft != NULL && t->pRight == NULL) ||
    //    (t->pLeft == NULL && t->pRight != NULL))
    //     dem = 1;

    // Node có đủ 2 con
    // if(t->pLeft != NULL && t->pRight != NULL)
    //     dem = 1;

    return dem + Dem(t->pLeft) + Dem(t->pRight);
}

int main()
{
    List L;
    InitList(L);
    
    List L1, L2;
    int n;
    int chon;

    while (true)
    {
        printf("\n\n=============== MENU CHUONG TRINH ===============");
        printf("\n1. Tao danh sach gom n node");
        printf("\n2. Hien thi danh sach chan / le");
        printf("\n3. Xoa phan tu nho nhat");
        printf("\n4. Sap xep tang dan (Selection Sort)");
        printf("\n5. Tach danh sach (SNT va Con lai)");
        printf("\n0. Thoat chuong trinh");
        printf("\n=================================================");
        printf("\nBan chon chuc nang (0-5): ");
        
        if (scanf("%d", &chon) <= 0) break;

        switch (chon)
        {
            case 0:
                printf("\nThoat chuong trinh. Tam biet!\n");
                return 0;

            case 1:
                InitList(L);
                printf("\n1. Tao danh sach gom n node: ");
                if (scanf("%d", &n) <= 0) break;
                NhapThuCong(L, n);
                ShowList(L);
                break;

            case 2:
                printf("\n2. Hien thi danh sach chan / le");
                ShowEven(L);
                ShowOdd(L);
                break;

            case 3:
                printf("\n3. Xoa phan tu nho nhat");
                XoaMin(L);
                ShowList(L);
                break;

            case 4:
                printf("\n4. Sap xep tang dan");
                SelectionSort(L);
                ShowList(L);
                break;

            case 5:
                printf("\n5. Tach danh sach");
                TachDS(L, L1, L2);
                printf("\n- L1 (So nguyen to):");
                ShowList(L1);
                printf("\n- L2 (Con lai):");
                ShowList(L2);
                
                // InitList(L1);
                // InitList(L2);
                // printf("\n[Thong bao]: Danh sach goc da duoc tach va lam rong. Hay chon Case 1 de nhap lai!");
                break;

            case 6:
                {
                    InitList(L);
                    printf("\n1. Tao danh sach tu mang");
                    printf("\nNhap so luong phan tu n: ");
                    if (scanf("%d", &n) <= 0) break;
                    
                    int a[100]; 
                    NhapMang(a, n);
                    MangToDS(L, a, n);
                    ShowList(L);
                }
                break;

            case 7:
                {
                    printf("\n6. Chuyen Danh sach sang Mang va Hien thi");
                    
                    int a[100];
                    int nMang;
                    
                    DSToMang(L, a, nMang);
                    ShowMang(a, nMang);
                }
                break;

            case 8:
                {
                    printf("\n7. Xoa node theo gia tri nhap vao");
                    if (L.pHead == NULL)
                    {
                        printf("\nDanh sach hien tai dang rong!");
                        break;
                    }
                    int x;
                    printf("\nNhap gia tri can xoa: ");
                    if (scanf("%d", &x) <= 0) break;
                    XoaTheoGiaTri(L, x);
                    ShowList(L);
                }
                break;

            case 9:
                {
                    printf("\n9. Chen phan tu vao danh sach da sap xep");
                    if (L.pHead != NULL)
                    {
                        printf("\n[He thong]: Dang tu dong sap xep lai danh sach truoc khi chen...");
                        InterchangeSort(L);
                        ShowList(L);
                    }
                    
                    int x;
                    printf("\nNhap gia tri can chen: ");
                    if (scanf("%d", &x) <= 0) break;
                    ChenVaoDSHopLe(L, x);
                    ShowList(L);
                }
                break;

            case 10:
                {
                    printf("\n10. Loai bo phan tu trung (Danh sach da sap xep)");
                    if (L.pHead == NULL || L.pHead->pNext == NULL)
                    {
                        printf("\nDanh sach khong du phan tu de co kha nang trung lap!");
                        break;
                    }
                    XoaTrungDanhSachDaXep(L);
                    ShowList(L);
                }
                break;

            case 11:
                {
                    printf("\n11. Xoa tat ca cac node co gia tri nho hon N");
                    if (L.pHead == NULL)
                    {
                        printf("\nDanh sach dang rong, khong co gi de xoa!");
                        break;
                    }
                    int nVal;
                    printf("\nNhap gia tri N: ");
                    if (scanf("%d", &nVal) <= 0) break;
                    XoaNhoHonN(L, nVal);
                    ShowList(L);
                }
                break;

            default:
                printf("\nChuc nang khong hop le! Vui long chon lai tu 0 den 5.");
                break;
        }
    }
    return 0;
}