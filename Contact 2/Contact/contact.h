#pragma once
#include<assert.h>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#define MAX 100
#define MAX_NAME 10
#define MAX_SEX 6
#define MAX_TELE 12
#define MAX_ADDR  15
#define FAULT_SZ 1
#define EXPAND_SZ 2
struct PeoInfo
{
	char name[MAX_NAME];
	char sex[MAX_SEX];
	int age;
	char tele[MAX_TELE];
	char adder[MAX_ADDR];
};
struct Contact
{
	int size;
	int capacity;
	struct PeoInfo *data;
	
};
void initContact(struct Contact* connect);
void addContact(struct Contact* connect);
void deleteContact(struct Contact* connect);
void searchContact(const struct Contact* connect);
void modifyContact(struct Contact* connect);
void emptyContact(struct Contact* connet);
void listContact(const struct Contact* connect);
void sortContact(struct Contact* connect);
