#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <math.h>

#define X_CENTRE getmaxx()/2
#define Y_CENTRE getmaxy()/2

void draw_points(int xc, int yc, int x, int y, int color)
{
	int xcentre, ycentre;
	putpixel(X_CENTRE + x + xc , Y_CENTRE + y + yc, color);
	putpixel(X_CENTRE + y + xc, Y_CENTRE + x + yc, color);
	putpixel(X_CENTRE - y + xc, Y_CENTRE + x + yc, color);
	putpixel(X_CENTRE - x + xc, Y_CENTRE + y + yc, color);
	putpixel(X_CENTRE - x + xc, Y_CENTRE - y + yc, color);
	putpixel(X_CENTRE - y + xc, Y_CENTRE - x + yc, color);
	putpixel(X_CENTRE + y + xc, Y_CENTRE - x + yc, color);
	putpixel(X_CENTRE + x + xc, Y_CENTRE - y + yc, color);
}

void draw_circle(int xc, int yc, float radius)
{
	float x, y, p0, pk;
	x = 0;
	y = radius;
	
	if (fmod(radius, 1) == 0.0)
	{
		p0 = 1 - radius;
	}	
	else
	{
		p0 = (5/4) - radius;
	}
	pk = p0;
	while (x < y)
	{
		x++;
		if (pk < 0)
		{
			draw_points(xc, -yc, x, y, WHITE);
			pk = pk + (2 * x + 2) + 1;
		}
		
		else
		{
			y--;
			draw_points(xc, -yc, x, y, WHITE);	//this is a hack so that it works for computers
			pk = pk + (2 * x + 2) - (2 * y - 2);
		}
	}
	
	putpixel(X_CENTRE + xc, Y_CENTRE - yc, BLUE);
}

int main()
{
	int gd = DETECT, gm;
	int xc, yc;
	float radius;
	
	printf("Enter the centre of circle xc, yc: ");
	scanf("%d %d", &xc, &yc);
	
	printf("Enter the radius of circle: ");
	scanf("%f", &radius);
	
	initgraph(&gd, &gm, "C:\\TurboC3\\BGI");
	line(X_CENTRE, 100, X_CENTRE, getmaxy() - 100);
	line(100, Y_CENTRE, getmaxx() - 100, Y_CENTRE);
	draw_circle(xc, yc, radius);
	
	getch();
	closegraph();
	return 0;
}