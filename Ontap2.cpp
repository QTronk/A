#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void XuatMang(int a[], int n)
{
    int i;
    for(i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void TaoMangNgauNhien(int a[], int n)
{
    int i;
    srand(time(NULL));

    for(i = 0; i < n; i++)
    {
        a[i] = rand() % 100;
    }
}

void SelectionSort(int a[], int n)
{
    int i, j;

    for(i = 0; i < n - 1; i++)
    {
        int min = i;

        for(j = i + 1; j < n; j++)
        {
            if(a[j] < a[min])
            {
                min = j;
            }
        }
        int temp = a[i];
        a[i] = a[min];
        a[min] = temp;
    }
}

int XoaTrung(int a[], int n)
{
    int i, j;
    int k = 0;

    for(i = 0; i < n; i++)
    {
        int trung = 0;
        for(j = 0; j < k; j++)
        {
            if(a[i] == a[j])
            {
                trung = 1;
                break;
            }
        }

        if(trung == 0)
        {
            a[k] = a[i];
            k++;
        }
    }

    return k;
}

typedef struct Node
{
    int data;
    struct Node* pNext;

}Node;

void InitList(Node **head)
{
    *head = NULL;
}

Node* TaoNode(int x)
{
    Node* p = (Node*)malloc(sizeof(Node));

    if(p == NULL)
    {
        printf("Khong du bo nho!");
        exit(1);
    }

    p->data = x;
    p->pNext = NULL;

    return p;
}

void AddTail(Node **head, int x)
{
    Node* p = TaoNode(x);

    if(*head == NULL)
    {
        *head = p;
    }
    else
    {
        Node* temp = *head;

        while(temp->pNext != NULL)
        {
            temp = temp->pNext;
        }

        temp->pNext = p;
    }
}

void TaoListTuMang(Node **head, int a[], int n)
{
    int i;
    for(i = 0; i < n; i++)
    {
        AddTail(head,a[i]);
    }
}

void XuatList(Node *head)
{
    Node* p = head;


    while(p != NULL)
    {
        printf("%d ",p->data);

        p = p->pNext;
    }


    printf("\n");
}

void Chen50(Node **head)
{
    Node* p = TaoNode(50);

    if(*head == NULL || (*head)->data >= 50)
    {
        p->pNext = *head;
        *head = p;

        return;
    }

    Node* current = *head;

    while(current->pNext != NULL &&
          current->pNext->data < 50)
    {
        current = current->pNext;
    }
    p->pNext = current->pNext;
    current->pNext = p;
}

void XoaNhoHon30(Node **head)
{
    Node* temp;

    while(*head != NULL && (*head)->data < 30)
    {
        temp = *head;
        *head = (*head)->pNext;
        free(temp);
    }

    if(*head == NULL)
        return;

    Node* p = *head;

    while(p->pNext != NULL)
    {
        if(p->pNext->data < 30)
        {
            temp = p->pNext;
            p->pNext = temp->pNext;
            free(temp);
        }
        else
            p = p->pNext;
    }
}

int DemNode(Node *head)
{
    int count = 0;

    while(head != NULL)
    {
        count++;
        head = head->pNext;
    }

    return count;
}

void ListSangMang(Node *head, int a[])
{
    int i = 0;
    while(head != NULL)
    {
        a[i] = head->data;
        i++;
        head = head->pNext;
    }
}

void MedianOrder(int a[], int b[], int left, int right, int *index)
{
    if(left > right)
        return;

    int mid = (left + right) / 2;

    b[*index] = a[mid];

    (*index)++;
    MedianOrder(a,b,left,mid-1,index);
    MedianOrder(a,b,mid+1,right,index);
}

typedef struct TreeNode
{
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
}TreeNode;

TreeNode* TaoTreeNode(int x)
{
    TreeNode* p = (TreeNode*)malloc(sizeof(TreeNode));

    if(p == NULL)
    {
        printf("Khong du bo nho!");
        exit(1);
    }

    p->data = x;
    p->left = NULL;
    p->right = NULL;

    return p;
}

void InitTree(TreeNode **root)
{
    *root = NULL;
}

void InsertBST(TreeNode **root, int x)
{
    if(*root == NULL)
    {
        *root = TaoTreeNode(x);
        return;
    }

    if(x < (*root)->data)
    {
        InsertBST(&((*root)->left),x);
    }
    else if(x > (*root)->data)
    {
        InsertBST(&((*root)->right),x);
    }
}

void TaoBSTTuMang(TreeNode **root, int a[], int n)
{
    int i;
    for(i = 0; i < n; i++)
        InsertBST(root,a[i]);
}

void NLR(TreeNode *root)
{
    if(root == NULL)
        return;

    printf("%d ",root->data);
    NLR(root->left);
    NLR(root->right);
}

void LNR(TreeNode *root)
{
    if(root == NULL)
        return;

    LNR(root->left);
    printf("%d ",root->data);
    LNR(root->right);
}

void LRN(TreeNode *root)
{
    if(root == NULL)
        return;

    LRN(root->left);
    LRN(root->right);
    printf("%d ",root->data);
}

int DemNodeLa(TreeNode *root)
{
    if(root == NULL)
        return 0;

    if(root->left == NULL && root->right == NULL)
        return 1;

    return DemNodeLa(root->left)
         + DemNodeLa(root->right);
}

int DemNodeHaiCon(TreeNode *root)
{
    if(root == NULL)
        return 0;

    int count = 0;

    if(root->left != NULL && root->right != NULL)
        count = 1;

    return count
         + DemNodeHaiCon(root->left)
         + DemNodeHaiCon(root->right);
}

int ChieuCao(TreeNode *root)
{
    if(root == NULL)
        return 0;

    int trai = ChieuCao(root->left);
    int phai = ChieuCao(root->right);

    if(trai > phai)
        return trai + 1;
    else
        return phai + 1;
}

int main()
{
    int a[100];
    int n;

    // 1
    printf("Nhap n: ");
    scanf("%d",&n);
    TaoMangNgauNhien(a,n);
    printf("\nMang ngau nhien: ");
    XuatMang(a,n);

    // 2
    SelectionSort(a,n);
    printf("Mang tang dan: ");
    XuatMang(a,n);

    // 3
    n = XoaTrung(a,n);
    printf("Mang sau khi xoa trung: ");
    XuatMang(a,n);

    // 4
    Node *head;
    InitList(&head);
    TaoListTuMang(&head,a,n);
    printf("\nLinked List: ");
    XuatList(head);

    // 5
    Chen50(&head);
    printf("Sau khi chen 50: ");
    XuatList(head);

    //6
    XoaNhoHon30(&head);
    printf("Sau khi xoa <30: ");
    XuatList(head);

    // 7
    int b[100];
    int size = DemNode(head);
    ListSangMang(head,b);
    printf("Array tu Linked List: ");
    XuatMang(b,size);

    // 8
    int c[100];
    int index = 0;
    MedianOrder(b,c,0,size-1,&index);
    printf("\nMedian Order: ");
    XuatMang(c,index);
    
    // 9
    TreeNode *root;
    InitTree(&root);
    TaoBSTTuMang(&root,c,index);
    printf("\nBST da tao thanh cong!");

    //10
    printf("\n\nNLR: ");
    NLR(root);
    printf("\nLNR: ");
    LNR(root);
    printf("\nLRN: ");
    LRN(root);

    // 11
    printf("\n\nSo node la: %d",
           DemNodeLa(root));
    printf("\nSo node co 2 con: %d",
           DemNodeHaiCon(root));

    //12
    printf("\nChieu cao cay: %d",
           ChieuCao(root));
           
    return 0;
}
