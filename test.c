#include "game.h"

void menu() {
	printf("  1.play  0.exit   ");
}
void game() {
	char mine[ROWS][COLS] = { 0 };//放雷的
	char show[ROWS][COLS] = { 0 };//展示的
	//初始化数组
	//放雷为0
	intiarr(mine, ROWS, COLS, '0');
	intiarr(show, ROWS, COLS, '*');
	//设置雷
	setmine(mine, ROW, COL);
	//打印数组
	//displayarr(mine, ROW, COL);
	displayarr(show, ROW, COL);
	//排查雷
	findmine(mine, show, ROW, COL);
}

int main() {
	srand((unsigned int)time(NULL));
	int input = 0;

	do {
		menu();
		printf("\n请选择__\b\b");
		scanf_s("%d", &input);
		switch (input) {
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏");
			break;
		default:
			printf("输入错误，请重新输入");
			break;
		}
	} while (input);
	return 0;
}