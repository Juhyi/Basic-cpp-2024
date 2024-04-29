/*
FILE: linkedList

Created: 24-03-27
Author: ������
*/

#include "BOOK2.h"

book* bookRegister(book* head)
{
    char title[100];
    char writer[100];
    int year;
    char publisher[100];
    int price;
    int rented;

    printf("���� ���� �Է�> ");
    scanf("%s", title);
    printf("\n���� ���� �Է�> ");
    scanf("%s", writer);
    printf("\n���� ���ǳ⵵ �Է�> ");
    scanf("%d", &year);
    printf("\n���� ���ǻ� �Է�> ");
    scanf("%s", publisher);
    printf("\n���� ���� �Է�> ");
    scanf("%d", &price);

    book* newbook = (book*)malloc(sizeof(book));
    if (newbook == NULL)
    {
        printf("�޸��Ҵ� ����\n");
        return head;
    }

    strcpy(newbook->title, title);
    strcpy(newbook->writer, writer);
    newbook->year = year;
    strcpy(newbook->publisher, publisher);
    newbook->price = price;
    newbook->next = NULL;
    newbook->rented = 0;
    if (head == NULL) {
        head = newbook;
    }
    else
    {
        book* curr = head;
        while (curr->next != NULL) {
            curr = curr->next;
        }
        curr->next = newbook;
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
    printf("***[%s] ���� ���� �Ϸ�***\n", curr->title);
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
        printf("����: %s\n����: %s\n���ǳ⵵: %d\n���ǻ�: %s\n����: %d\n", curr->title, curr->writer, curr->year,
            curr->publisher, curr->price);
        if (curr->rented == 0) {
            printf("�뿩 ����\n");
        }
        else if (curr->rented == 1) {
            printf("�뿩��\n");
        }
        curr = head;
        prev = curr->next;
    }

}

void rentBooks(book* head) {
    if (head == NULL) {
        printf("Booklist is Empty.\n");
        return;
    }

    char rentTitle[100];
    printf("�뿩�� ������ �Է�> ");
    scanf(" %s", rentTitle);

    book* curr = head;
    while (curr != NULL) {
        if (strcmp(curr->title, rentTitle) == 0) {
            if (curr->rented == 0) {
                curr->rented = 1;
                printf("***[%s] ���� �뿩 �Ϸ�***\n", curr->title);
                return;
            }
            else {
                printf("***[%s] ������ �̹� �뿩 ���Դϴ�.***\n", curr->title);
                return;
            }
        }
        curr = curr->next;
    }

    printf("�Է��� ������ ã�� �� �����ϴ�.\n");
}

void returnBooks(book* head) {
    if (head == NULL) {
        printf("Booklist is Empty.\n");
        return;
    }

    char returnTitle[100];
    printf("�ݳ��� ������ �Է�> ");
    scanf(" %s", returnTitle);

    book* curr = head;
    while (curr != NULL) {
        if (strcmp(curr->title, returnTitle) == 0) {
            if (curr->rented == 1) {
                curr->rented = 0;
                printf("***[%s] ���� �ݳ� �Ϸ�***\n", curr->title);
                return;
            }
            else {
                printf("***[%s] ������ �̹� �ݳ��Ǿ����ϴ�.***\n", curr->title);
                return;
            }
        }
        curr = curr->next;
    }

    printf("�Է��� ������ ã�� �� �����ϴ�.\n");
}
void showBooks(book* head) {
    if (head == NULL) {
        printf("Booklist is Empty.\n");
        return;
    }

    printf("[���� ���]\n");
    int count = 1;
    book* curr = head;
    while (curr != NULL) {
        printf("[%d]\n����: %s\n����: %s\n���ǳ⵵: %d\n���ǻ�: %s\n����:%d\n",
            count, curr->title, curr->writer, curr->year, curr->publisher, curr->price);
        switch (curr->rented) {
        case 0:
            printf("�뿩 ����\n");
            break;
        case 1:
            printf("�뿩��\n");
            break;
        }
        curr = curr->next;
        count++;

        // curr�� NULL�� ��� ������ �����մϴ�.
        if (curr == NULL) {
            break;
        }
    }
}