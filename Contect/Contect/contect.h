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
struct PeoInfo
{
	char name[MAX_NAME];
	char sex[MAX_SEX];
	int age;
	char tele[MAX_TELE];
	char adder[MAX_ADDR];
};
struct Contect
{
	int size;
	struct PeoInfo date[100];
};
void initContect(struct Contect* connect);
void addContect(struct Contect* connect);
void deleteContect(struct Contect* connect);
void searchContect(const struct Contect* connect);
void modifyContect(struct Contect* connect);
void listContect(const struct Contect* connect);
void sortContect(struct Contect* connect);


