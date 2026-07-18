// Yêu cầu: Tổ chức quản lý dữ liệu bằng danh sách liên kết đơn. Cho cấu trúc của một node như
// sau, hãy viết chương trình sử dụng ngôn ngữ C thực hiện các yêu cầu:
// struct Node
// {
//  char data;
//  struct Node *next;
// };
// Câu 1: Xây dựng hàm để tạo danh sách gồm n Node bằng cách chèn vào sau phần tử đầu.
// Câu 2: Liệt kê các ký tự nguyên âm có trong danh sách. (Ký tự nguyên âm bao gồm: a, e, i, o,
// u thường và hoa)
// Câu 3: Xóa ký tự nguyên âm đầu tiên trong danh sách.
// Câu 4: Sắp xếp danh sách tăng dần.
// Câu 5: Tách danh sách thành 2 danh sách sao cho:
// - Danh sách thứ nhất chứa các ký tự nguyên âm.
// - Danh sách thứ hai chứa các phần tử còn lại
#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    char data;
    struct Node *next;
} Node;

Node* TaoNode(char x)
{
    Node *p = (Node*)malloc(sizeof(Node));
    p->data = x;
    p->next = NULL;
    return p;
}

void ChenSauDau(Node **head, char x)
{
    Node *p = TaoNode(x);
    if (*head == NULL)
    {
        *head = p;
        return;
    }
    p->next = (*head)->next;
    (*head)->next = p;
}

void TaoDanhSach(Node **head, int n)
{
    char x;
    for (int i = 0; i < n; i++)
    {
        scanf(" %c", &x);
        ChenSauDau(head, x);
    }
}

void Xuat(Node *head)
{
    while (head != NULL)
    {
        printf("%c ", head->data);
        head = head->next;
    }
    printf("\n");
}

int NguyenAm(char c)
{
    return c=='a'||c=='e'||c=='i'||c=='o'||c=='u'||
           c=='A'||c=='E'||c=='I'||c=='O'||c=='U';
}

void LietKeNguyenAm(Node *head)
{
    while (head != NULL)
    {
        if (NguyenAm(head->data))
            printf("%c ", head->data);
        head = head->next;
    }
    printf("\n");
}

void XoaNguyenAmDau(Node **head)
{
    Node *p = *head;
    Node *truoc = NULL;

    while (p != NULL)
    {
        if (NguyenAm(p->data))
        {
            if (truoc == NULL)
                *head = p->next;
            else
                truoc->next = p->next;
            free(p);
            return;
        }
        truoc = p;
        p = p->next;
    }
}

void SapXepTang(Node *head)
{
    Node *p, *q;
    char t;

    for (p = head; p != NULL; p = p->next)
        for (q = p->next; q != NULL; q = q->next)
            if (p->data > q->data)
            {
                t = p->data;
                p->data = q->data;
                q->data = t;
            }
}

void ThemCuoi(Node **head, Node **tail, char x)
{
    Node *p = TaoNode(x);

    if (*head == NULL)
    {
        *head = *tail = p;
    }
    else
    {
        (*tail)->next = p;
        *tail = p;
    }
}

void TachDanhSach(Node *head, Node **dsNguyenAm, Node **dsConLai)
{
    Node *tail1 = NULL;
    Node *tail2 = NULL;

    while (head != NULL)
    {
        if (NguyenAm(head->data))
            ThemCuoi(dsNguyenAm, &tail1, head->data);
        else
            ThemCuoi(dsConLai, &tail2, head->data);

        head = head->next;
    }
}

int main()
{
    Node *head = NULL;
    Node *dsNguyenAm = NULL;
    Node *dsConLai = NULL;

    int n;
    scanf("%d", &n);

    TaoDanhSach(&head, n);

    printf("Danh sach:\n");
    Xuat(head);

    printf("Nguyen am:\n");
    LietKeNguyenAm(head);

    XoaNguyenAmDau(&head);
    printf("Sau khi xoa nguyen am dau:\n");
    Xuat(head);

    SapXepTang(head);
    printf("Sau khi sap xep:\n");
    Xuat(head);

    TachDanhSach(head, &dsNguyenAm, &dsConLai);

    printf("Danh sach nguyen am:\n");
    Xuat(dsNguyenAm);

    printf("Danh sach con lai:\n");
    Xuat(dsConLai);

    return 0;
}
