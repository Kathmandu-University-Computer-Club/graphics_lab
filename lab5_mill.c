#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>

#define X_CEN getmaxx()/2
#define Y_CEN getmaxy()/2

int main()
{
	int gd = DETECT, gm, start_angle = 0;
	initgraph(&gd, &gm, "C:/TC/BGI");	
	
	while (!kbhit())
	{
		clrscr();
		line(X_CEN - 30, Y_CEN + 60, X_CEN + 30, Y_CEN + 60);
		line(X_CEN - 30, Y_CEN +60, X_CEN, Y_CEN - 60);
		line(X_CEN + 30, Y_CEN + 60, X_CEN, Y_CEN - 60);
		pieslice(X_CEN , Y_CEN - 60, start_angle, start_angle + 10, 40);
		pieslice(X_CEN , Y_CEN - 60, start_angle + 90, start_angle + 100, 40);
		pieslice(X_CEN , Y_CEN - 60, start_angle + 180, start_angle + 190, 40);
		pieslice(X_CEN , Y_CEN - 60, start_angle + 280, start_angle + 290, 40);
		delay(50);
		start_angle += 10;
		if (start_angle >= 350)
			start_angle = 0;
	}
	
	getch();
	closegraph();
	return 0;
}
