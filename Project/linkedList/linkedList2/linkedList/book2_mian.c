/*
FILE: book2_main.c

Created: 24-03-27
Author: ������
*/

#include "BOOK2.h"

void main()
{
    book* head = NULL;
    int choice;
    do {
        printf("\n���� ��� �� ��ȸ ���α׷�\n");
        printf("1. ���� ���� + ���\n");
        printf("2. ���� �˻�- �뿩����\n");
        printf("3. ���� ����\n");
        printf("4. ���� ���- �뿩����\n");
        printf("0. ���α׷� ����\n");
        printf("����> ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            head = bookRegister(head);
            break;
        case 2:
            printf(" 1. �����˻� \n");
            printf(" 2. �����뿩 \n");
            printf(" 3. �����ݳ� \n");
            printf("���� > ");
            int choice1;
            scanf("%d", &choice1);
            switch (choice1) {
            case 1:
                searchBooks(head);
                break;
            case 2:
                rentBooks(head);
                break;
            case 3:
                returnBooks(head);
                break;
            default:
                printf("�߸��� �Է��Դϴ�.\n");
                break;
            }
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

