/*
   File: id_pass.c

   Created: 2024-03-13
   Author: ������
*/
#define  CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define SIZE_ID  100
#define SIZE_PASS 100
#define SIZE_INFO 1024

int compare(char[], char[]);
void  main()
{
    char input_id[SIZE_ID];
    char input_pass[SIZE_PASS];
    char id[] = "juhyi12";
    char pass[] = "abc";
    char info[] = "�̸�: ������ �������: 991217 ��ȭ��ȣ: 01042352449";

    do {
        printf("ID  �Է�> ");
        scanf("%s", input_id);
        printf("PASSWORD �Է�> ");
        scanf("%s", input_pass);

        printf("\n**Login ���� Ȯ��**\n");

        int login = 0;
        int a = compare(id, input_id);
        int b = compare(pass, input_pass);
        if (a == 1 && b == 1)
        {
            FILE* fp;
            fp = fopen("my_info.txt", "w");
            if (fp == NULL)
            {
                fprintf(stderr, "ERROR");
                exit(1);
            }
            fprintf(fp, "*Login impormation\nID:%s\tPASSWORD:%s", input_id, input_pass);
            fprintf(fp, "\n\n*Human impormtion\n%s", info);
            fclose(fp);
            break;
        }
        else
        {
            printf("Login Fail\n");
            printf("Login Again\n");
        }
    } while (1);
    FILE* fp;
    fp = fopen("my_info.txt", "r");
    if (fp == NULL)
    {
        fprintf(stderr, "ERROR");
        exit(1);
    }
    printf("\nSuccess Login -> File Open\n");
    printf("\n***Login impormation***\nID:%s\tPASSWORD:%s", input_id, input_pass);
    printf("\n\n***Human impormtion***\n%s\n", info);
    fclose(fp);

}


int compare(char s1[], char s2[]) {
    int i = 0;
    while (s1[i] != '\0' || s2[i] != '\0') {
        if (s1[i] != s2[i]) {
            return 0;
        }
        i++;
    }
    return 1;
}