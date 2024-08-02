#include "graphics.h"
#include <time.h>
#include <stdlib.h>
#include <stdio.h>


void player(int x, int y) {
	readimagefile("ptank.gif", x * 50, y * 50, x * 50 + 50, y * 50 + 50);
}

void shoot(int zx, int zy) {
	readimagefile("fire.gif", zx, zy, zx + 50, zy - 50);
}


void main() {
	initwindow(1010, 510);
	//setbkcolor(GREEN);
	clearviewport();
	setcolor(BLACK);
	srand((unsigned)time(NULL));
	//setbkcolor(GREEN);

	int map[10][20] = {
{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
{1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
	};
	int lifes = 3;
	int key = 0;
	int px = 1, py = 1;
	int frame = 0;
	int cnt = 0;
	int zx = -1, zy = -1;
	

	// space = 32 
	while (lifes > 0) {
		if (kbhit()) {
			key = getch();
			//printf("%d\n", key);
			switch (key) {
			case 77: player(px++, py);  break;
			case 72: player(px, py--); break;
			case 80: player(px, py++);  break;
			case 75: player(px--, py);  break;
			case 32: zx = px; zy = py; shoot(zy++, zy++); break;
			}
		}
		else { key = 0; }
		


		if (frame == 50000) {
			setactivepage(cnt % 2);
			clearviewport();
			readimagefile("map.gif", 0, 0, 1000, 500);
			for (int i = 0; i < 10; i++) {
				for (int j = 0; j < 20; j++) {
					switch (map[i][j]) {
					case 2:
					player(px, py); break;
					
					}
			
				}	
			}
		
			
			setvisualpage(cnt % 2);
			cnt++;
			

			
			frame = 0;
		}
		frame++;
	}



	delay(1000000000);
}
	
/*
		if (buttn == 72 up arrow) { map[y][x]++; y++; delay(500);}
		if (buttn == 80 don arrow) {  }
		if (buttn == 77 right arrow) {  }
		if (buttn == 75)
*/