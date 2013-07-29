#include <graphics.h>
#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <string.h>

#define MAX 10

struct bar_data
{
	char desc[100];
	int freq;
	int color;
};


void bla_line(int x1, int y1, int x2, int y2, int color)
{
	int dx, dy, p0, pk, i, x, y;
	float slope;
	
	dx = x2 - x1;
	dy = y2 - y1;
	x = x1; y = y1;
	slope = dy/(float)dx;
	
	if (abs(dx == 0))
	{
		setcolor(color);
		line(x1, y1, x2, y2);
	}

	if (abs(slope) < 1)
	{
		putpixel(x, y, color);
		p0 = (2 * dy - dx);
		pk = p0;
		for (i = 0; i < abs(dx); i++)
		{	
			(x1 < x2)?x++:x--;		
			if (pk < 0)
			{				
				putpixel(x, y, color);
				pk += (2 * dy);
			}
			else
			{				
				(y1 < y2)?y++:y--;
				putpixel(x, y, color);
				pk += ((2 * dy) - (2 * dx));
			}
		}
	}
	else
	{
		putpixel(x, y, color);
		p0 = (2 * dx - dy);
		pk = p0;
		for (i = 0; i < abs(dy); i++)
		{	
			(y1 < y2)?y++:y--;		
			if (pk < 0)
			{				
				putpixel(x, y, color);
				pk += (2 * dx);
			}
			else
			{				
				(x1 < x2)?x++:x--;
				putpixel(x, y, color);
				pk += (2 * dx) - (2 * dy);
			}
		}
	}
}

void my_rectangle(int x1, int y1, int x2, int y2, int color)
{
	bla_line(x1, y1, x1, y2, color);
	bla_line(x1, y1, x2, y1, color);
	bla_line(x1, y2, x2, y2, color);
	bla_line(x2, y1, x2, y2, color);
}

int main()
{
	int gd = DETECT, gm;
	struct bar_data bars[MAX];
	int n, i, j, xspacing = 10;
	int left, bottom, right, top, xtotal, xsize;
	int xstart, ystart, xend, yend;
	
	int total_freq = 0;

	printf("Enter the number of items: ");
	scanf("%d", &n);
	
	for (i = 0, j = 1; i < n;i++)
	{
		printf("Enter the item title: ");
		scanf("%s", bars[i].desc);
		printf("Enter the item frequency: ");
		scanf("%d", &bars[i].freq);
		bars[i].color = j;
		if (j++ >= 13) j = 1;
		total_freq += bars[i].freq;
	}
	
	initgraph(&gd, &gm, "C:\\TurboC3\\BGI");
	setbkcolor(BLACK);
	left = 50;top = 50;
	bottom = getmaxy() - 50;
	right = getmaxx() - 50;	
	
	xtotal = right -left;
	xsize = (xtotal - (xspacing * (n + 1)))/n;
	if (xsize > 100) xsize = 100;
	bla_line(left, top, left, bottom, WHITE);
	bla_line(left, bottom, right, bottom, WHITE);

	ystart = bottom;
	xstart = left;
	xend = xstart + xspacing;

	for (i = 0; i < n; i++)
	{
		char title[100];
		float ratio;
		ratio = bars[i].freq/(float)total_freq;
		ratio *= 100;
		xstart = xend + xspacing;
		xend = xstart + xsize;
		yend = ystart - (ratio * 2);
		
		my_rectangle(xstart, ystart, xend, yend, bars[i].color);
		sprintf(title, "%s: %d", bars[i].desc, bars[i].freq);
		outtextxy(xstart + 5, ystart + 10, title);
	}


	getch();
	closegraph();
	return 0;
}
