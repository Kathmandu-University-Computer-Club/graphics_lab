#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <math.h>

int main()
{
	int gd = DETECT, gm;
	int x1, y1, x2, y2, dx, dy, stepsize;
	float xinc, yinc, x, y;
	int i;
	initgraph(&gd, &gm, "C:\\TurboC3\\BGI");
	printf("Enter x1, y1: ");
	scanf("%d %d", &x1, &y1);
	printf("Enter x2, y2: ");
	scanf("%d %d", &x2, &y2);
	clrscr();
	dx = x2 - x1;
	dy = y2 - y1;
	stepsize = (abs(dx) > abs(dy))?abs(dx):abs(dy);
	xinc = dx/(float)stepsize;
	yinc = dy/(float)stepsize;
	x = x1;
	y = y1;
	
	for (i = 0; i < stepsize; i++)
	{
		putpixel(x, y, BLACK);
		x += xinc;
		y += yinc;		
		delay(50);
	}	
	
	
	getch();
	closegraph();
	return 0;
}
