/*
FILE: book2.h
Created: 24-03-27
Author: ¿Ã¡÷»Ò
*/
#ifndef BOOK2_H
#define BOOK2_H
#define _CRT_SECURE_NO_WARRINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>



typedef struct BOOKINFO {
	char title[100];
	char writer[100];
	int year;
	char publisher[100];
	int price;
	int rented;
	struct BOOKINFO* next;
}book;

book* bookRegister(book*);
void showBooks(book*);
void deleteBooks(book*);
void searchBooks(book*);
void rentBooks(book*);
void returnBooks(book*);

#endif

