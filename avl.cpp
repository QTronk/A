#define LH 1
#define EH 0
#define RH -1

typedef struct AVLNode
{
    int key;
    char bF;
    AVLNode* pLeft;
    AVLNode* pRight;

} *AVLTree;


void RotateLL(AVLTree &T)
{
    AVLNode *T1 = T->pLeft;

    T->pLeft = T1->pRight;
    T1->pRight = T;

    switch(T1->bF)
    {
        case LH:
            T->bF = EH;
            T1->bF = EH;
            break;

        case EH:
            T->bF = LH;
            T1->bF = RH;
            break;
    }

    T = T1;
}


void RotateLR(AVLTree &T)
{
    AVLNode *T1 = T->pLeft;
    AVLNode *T2 = T1->pRight;

    T->pLeft = T2->pRight;
    T2->pRight = T;

    T1->pRight = T2->pLeft;
    T2->pLeft = T1;

    switch(T2->bF)
    {
        case LH:
            T->bF = RH;
            T1->bF = EH;
            break;

        case EH:
            T->bF = EH;
            T1->bF = EH;
            break;

        case RH:
            T->bF = EH;
            T1->bF = LH;
            break;
    }

    T2->bF = EH;
    T = T2;
}


void RotateRR(AVLTree &T)
{
    AVLNode *T1 = T->pRight;

    T->pRight = T1->pLeft;
    T1->pLeft = T;

    switch(T1->bF)
    {
        case RH:
            T->bF = EH;
            T1->bF = EH;
            break;

        case EH:
            T->bF = RH;
            T1->bF = LH;
            break;
    }

    T = T1;
}


void RotateRL(AVLTree &T)
{
    AVLNode *T1 = T->pRight;
    AVLNode *T2 = T1->pLeft;

    T->pRight = T2->pLeft;
    T2->pLeft = T;

    T1->pLeft = T2->pRight;
    T2->pRight = T1;

    switch(T2->bF)
    {
        case RH:
            T->bF = LH;
            T1->bF = EH;
            break;

        case EH:
            T->bF = EH;
            T1->bF = EH;
            break;

        case LH:
            T->bF = EH;
            T1->bF = RH;
            break;
    }

    T2->bF = EH;
    T = T2;
}

int BalanceLeft(AVLTree &T)
{
    switch(T->pLeft->bF)
    {
        case LH:
            RotateLL(T);
            return 2;

        case EH:
            RotateLL(T);
            return 1;

        case RH:
            RotateLR(T);
            return 2;
    }

    return 0;
}


int BalanceRight(AVLTree &T)
{
    switch(T->pRight->bF)
    {
        case LH:
            RotateRL(T);
            return 2;

        case EH:
            RotateRR(T);
            return 1;

        case RH:
            RotateRR(T);
            return 2;
    }

    return 0;
}
int InsertNodeAVL(AVLTree &T, int X)
{
    int kq;

    if(T != NULL)
    {
        if(T->key == X)
            return 0; // tồn tại x

        else if(T->key > X) // thêm về bên trái
        {
            kq = InsertNodeAVL(T->pLeft, X);

            if(kq < 2)
                return kq;

            switch(T->bF)
            {
                case RH:
                    T->bF = EH;
                    return 1;

                case EH:
                    T->bF = LH;
                    return 2;

                case LH:
                    BalanceLeft(T);
                    return 1;
            }
        }

        else // T->key < X, thêm về bên phải
        {
            kq = InsertNodeAVL(T->pRight, X);

            if(kq < 2)
                return kq;

            switch(T->bF)
            {
                case LH:
                    T->bF = EH;
                    return 1;

                case EH:
                    T->bF = RH;
                    return 2;

                case RH:
                    BalanceRight(T);
                    return 1;
            }
        }
    }


    // Tạo node mới
    T = new AVLNode;

    if(T == NULL)
        return -1; // thiếu bộ nhớ

    T->key = X;
    T->bF = EH;
    T->pLeft = T->pRight = NULL;

    return 2; // thêm thành công và chiều cao tăng
}
void TaoCayAVL(AVLTree &T, List L)
{
    T = NULL;

    Node *p = L.pHead;

    while(p != NULL)
    {
        InsertNodeAVL(T, p->data);
        p = p->pNext;
    }
}
void NLR_AVL(AVLTree T)
{
    if(T != NULL)
    {
        printf("%d ", T->key);
        NLR_AVL(T->pLeft);
        NLR_AVL(T->pRight);
    }
}
int main()
{
    List L;
    InitList(L);

    // nhập danh sách như cũ

    AVLTree avl = NULL;

    TaoCayAVL(avl, L);

    printf("Duyet AVL NLR: ");
    NLR_AVL(avl);

    return 0;
}