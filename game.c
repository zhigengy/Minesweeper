#include "game.h"

void intiarr(char arr[ROWS][COLS], int rows, int cols, char temp) {
	int i = 0;
	int j = 0;
	for (i = 0; i < rows; i++) {
		for (j = 0; j < cols; j++) {
			arr[i][j] = temp;
		}
	}
}

void displayarr(char arr[ROWS][COLS], int row, int col) {
	int i = 0;
	int j = 0;
	printf("------------------\n");
	for (j = 0; j <= col; j++) {
		printf("%d ",j);
	}
	printf("\n");
	for (i = 1; i <= row; i++) {
		printf("%d ", i);
		for (j = 1; j <= col; j++) {
			printf("%c ", arr[i][j]);
		}
		printf("\n");
	}
	printf("------------------\n");
}

void setmine(char mine[ROWS][COLS], int row, int col) {
	int count = EASY_COUNT;
	while (count) {
		int x = rand() % row + 1;
		int y = rand() % col + 1;
		if (mine[x][y] == '0') {
			mine[x][y] = '1';
			count--;
		}
	}
}

int get_mine_count(char mine[ROWS][COLS], int x, int y) {
	return (mine[x - 1][y] + mine[x - 1][y - 1] + mine[x][y - 1] + mine[x + 1][y - 1] + mine[x + 1][y] + mine[x + 1][y + 1] + mine[x][y + 1] + mine[x - 1][y + 1] - 8 * '0');
}

void findmine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col) {
	int x = 0;
	int y = 0;
	int win = 0;
	while (win<row*col-EASY_COUNT) {
		printf("请输入排雷坐标");
		scanf_s("%d %d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col) {
			if (mine[x][y] == '1') {
				printf("你被炸死了\n");
				displayarr(mine, ROW, COL);
				break;
			}
			else {
				win++;
				int count = get_mine_count(mine,x,y);
				show[x][y] = count + '0';
				displayarr(show, ROW, COL);
			}
		}
		else {
			printf("输入坐标超出范围，请重新输入");
		}
	}
	if (win == row * col - EASY_COUNT) {
		printf("排雷成功\n");
	}
	
}