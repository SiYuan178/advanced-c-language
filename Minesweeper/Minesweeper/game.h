#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define ROW 9
#define COL 9
#define ROWS 9+2
#define COLS 9+2
#define BOMB 10
void menu();
void init(char arr[ROW][COL], int row, int col, char ch);
void print(char arr[ROW][COL], int row, int col);
void set_bomb(char arr[ROW][COL], int row, int col);
int cout_bomb(char arr1[ROW][COL], char arr2[ROW][COL], int row, int col);
void minesweeper(char mine[ROW][COL], char show[ROW][COL], int row, int col);