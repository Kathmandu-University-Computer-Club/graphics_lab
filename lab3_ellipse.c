#include <stdio.h>
#include <graphics.h>
#include <math.h>

#define X_CEN getmaxx()/2
#define Y_CEN getmaxy()/2

void draw_axis()
{
	line(50, Y_CEN, getmaxx() - 50, Y_CEN);
	line(X_CEN, 50, X_CEN, getmaxy() - 50);
}

void draw_symmetry(int xc, int yc, int x, int y)
{
	putpixel(X_CEN + xc + x, Y_CEN - yc + y, BLUE);
	putpixel(X_CEN + xc - x, Y_CEN - yc + y, BLUE);
	putpixel(X_CEN + xc + x, Y_CEN - yc - y, BLUE);
	putpixel(X_CEN + xc - x, Y_CEN - yc - y, BLUE);
}

int main()
{
	int gd = DETECT, gm;
	float rx, ry, xc, yc, x = 0, y, pk1, pk2, i1, i2, k = 10;
	char str[100];	
	
	printf("Enter the centre xc, yc of ellipse: ");
	scanf("%f %f", &xc, &yc);
	printf("Enter two radii rx, ry: ");
	scanf("%f %f", &rx, &ry);
	
	initgraph(&gd, &gm, "C:/TC/BGI/");
	pk1 = pow(ry, 2) - (pow(rx, 2) * ry) + (pow(rx, 2)/4);
	
	x = 0; y = ry;
	i1 = 2 * pow(ry, 2) * x;
	i2 = 2 * pow(rx, 2) * y;
	draw_axis();
	do
	{
		char str[300];
		x++;
		draw_symmetry(xc, yc, x, y);
		if (pk1 < 0)
		{
			pk1 += (((2 * pow(ry, 2) * x) + pow(ry, 2)));			
		}
		else
		{
			y--;
			pk1 += (((2 * pow(ry, 2) * x) - (2 * pow(rx, 2) * y) + pow(ry, 2)));			
		}
		i1 = 2 * pow(ry, 2) * x;
		i2 = 2 * pow(rx, 2) * y;
	} while (i1 < i2);
	
	pk2 = (pow(ry, 2) * pow(x + 0.5, 2)) + (pow(rx, 2) * pow(y - 1, 2)) - (pow(rx, 2) * pow(ry, 2));
	
	while (y > 0)
	{
		char str[200];
		y--;
		draw_symmetry(xc, yc, x, y);
		if (pk2 > 0)
		{
			pk2 = pk2 - ((2 * pow(rx, 2) * y) + pow(rx, 2));
		}
		else
		{
			x++;
			pk2 += (((2 * pow(ry, 2) * x) - (2 * pow(rx, 2) * y) + pow(rx, 2)));
		}				
	}
	getch();
	closegraph();
	return 0;
}
