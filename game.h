#pragma once
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define ROW 9
#define COL 9

#define ROWS ROW+2
#define COLS COL+2

#define EASY_COUNT 10

//初始化数组
void intiarr(char arr[ROWS][COLS], int rows, int cols, char temp);
//展示数组
void displayarr(char arr[ROWS][COLS], int row, int col);
//设置雷
void setmine(char mine[ROWS][COLS], int row, int col);
//排查雷
void findmine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);