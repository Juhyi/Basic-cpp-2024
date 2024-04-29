#define CRP_SECURE_NO_WARNINGS                                                                                                                                                                                                                       book_ver1.c                                                                                                                                                                                                                            I
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct BOOKINFO {
    char title[100];
    char writer[100];
    int year;
    char publisher[100];
    int price;
    struct BOOKINFO* next;
}book;

//void showMenu();
book* bookRegister(book*);
void showBooks(book*);
void deleteBooks(book*);
void searchBooks(book*);
void main()
{
    book* head = NULL;
    int choice;
    do {
        printf("\n���� ��� �� ��ȸ ���α׷�\n");
        printf("1. ���� ���� + ���\n");
        printf("2. ���� �˻�\n");
        printf("3. ���� ����\n");
        printf("4. ���� ���\n");
        printf("0. ���α׷� ����\n");
        printf("����> ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            head = bookRegister(head);
            break;
        case 2:
            searchBooks(head);
            break;
        case 3:
            deleteBooks(head);
            if (head != NULL) {
                head = head->next;
            }
            break;
        case 4:
            showBooks(head);
            break;
        case 0:
            printf("���� ���α׷��� ����.\n");
            break;
        default:
            printf("�߸��� �����Դϴ�. �ٽ� �õ��ϼ���.\n");
            break;
        }
    } while (choice != 0);

    book* curr = head;
    while (curr != NULL) {
        book* temp = curr;
        curr = curr->next;
        free(temp);
    }
}

book* bookRegister(book* head)
{
    char title[100];
    char writer[100];
    int year;
    char publisher[100];
    int price;

    printf("���� ���� �Է�> ");
    scanf("%s", title);
    printf("\n���� ���� �Է�> ");
    scanf("%s", writer);
    printf("\n���� ���ǳ⵵ �Է�> ");
    scanf("%d", &year);

    book* newbook = (book*)malloc(sizeof(book));
    if (newbook == NULL)
    {
        printf("�޸��Ҵ� ����\n");
        return head;
    }

    strcpy(newbook->title, title);
    strcpy(newbook->writer, writer);
    strcpy(newbook->publisher, publisher);
    newbook->year = year;
    newbook->price = price;
    newbook->next = NULL;

    if (head == NULL) {
        head = newbook;
    }
    else
    {
        book* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newbook;
    }
    printf("���� �߰��Ϸ�\n");
    return head;
}

void deleteBooks(book* head) {
    if (head == NULL) {
        printf("Booklist is Empty\n");
        printf("**Delete Error\n");
    }

    book* curr = head;
    book* prev = NULL;

    char deletetitle[100];
    printf("������ ������ �Է�> ");
    scanf(" %s", deletetitle);
    printf("\n** ������ ������ Ȯ�� **\n");
    while (curr != NULL && strcmp(curr->title, deletetitle) != 0)
    {
        prev = curr;
        curr = curr->next;

    }

    if (curr == NULL)
    {
        printf("������ ������ �������� ����.\n");
        return;
    }

    if (prev == NULL) {
        head = head->next;

    }
    else {
        prev->next = curr->next;
        curr->next = NULL;
    }
    printf("***%s ���� ���� �Ϸ�***\n", curr->title);

    free(curr);
}
void searchBooks(book* head)
{
    if (head == NULL)
    {
        printf("Booklist is Empty.\n");
        return;
    }
    char searchTitle[100];
    printf("ã�� ������ �Է�> ");
    scanf(" %s", searchTitle);
    printf("\n**�˻���  ������ Ȯ��**\n");


    book* curr = head;
    book* prev = NULL;
    while (strcmp(curr->title, searchTitle) != 0)
    {
        prev = curr;
        curr = curr->next;
        return;
    }

    if (curr == NULL)
    {
        printf("�˻��� ������ �������� �ʽ��ϴ�.\n");
    }
    if (curr != NULL && strcmp(curr->title, searchTitle) == 0) {
        printf("[�˻��� ������ ����]\n");
        printf("����: %s, ����: %s, ���ǳ⵵: %d, ���ǻ�: %s, ����: %d\n", 
            curr->title, curr->writer, curr->year, curr->publisher, curr->price);
        curr = head;
        prev = curr->next;
    }

}
void showBooks(book* head) {
    if (head == NULL) {
        printf("Booklist is Empty.\n");
        return;
    }

    printf("���� ���:\n");
    int count = 1;
    book* curr = head;
    while (curr != NULL) {
        printf("����: %s, ����: %s, ���ǳ⵵: %d, ���ǻ�: %s, ����: %d\n",
            curr->title, curr->writer, curr->year, curr->publisher, curr->price);
        curr = curr->next;
        count++;
    }
}





