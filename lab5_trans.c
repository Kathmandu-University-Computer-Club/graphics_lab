#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <math.h>

#define X_CEN getmaxx()/2
#define Y_CEN getmaxy()/2
#define PI 3.14

struct point
{
	float x, y;
};

void draw_axis()
{
	line(X_CEN, 100, X_CEN, getmaxy() - 100);
	line(100, Y_CEN, getmaxx() - 100, Y_CEN);
}

void draw_triangle(int x1, int y1, int x2, int y2, int x3, int y3)
{
	x1 += X_CEN;
	y1 = Y_CEN - y1;
	x2 += X_CEN;
	y2 = Y_CEN - y2;
	x3 += X_CEN;
	y3 = Y_CEN - y3;
	line(x1, y1, x2, y2);
	line(x2, y2, x3, y3);
	line(x3, y3, x1, y1);
}

int main()
{
	int gd = DETECT, gm;
	struct point t[3];
	struct point image[3];
	char ch;
	int i, flag = 1;
	float tx, ty, sx, sy, angle, shx, shy;
	
	
	initgraph(&gd, &gm, "C:/TurboC3/BGI");
	
	while (1)
	{		
		clrscr();
		setbkcolor(BLACK);
		printf("-------------------------------------------------\n");
		printf("|\t2D Transformation for fun & profit\t|\n");
		printf("|\t1. Input triangle sides\t\t\t|\n");
		printf("|\t2. Translation  \t\t\t|\n");
		printf("|\t3. Scaling  \t\t\t\t|\n");
		printf("|\t4. Rotation  \t\t\t\t|\n");
		printf("|\t5. Shearing \t\t\t\t|\n");
		printf("|\t6. Reflection \t\t\t\t|\n");
		printf("|\t0. Exit  \t\t\t\t|\n");
		printf("-------------------------------------------------\n\n");
		
		printf("Enter your choice: ");
		fflush(stdin);
		scanf("%c", &ch);
		//fflush(stdin);		
		flag = 1;
		
		switch (ch)
		{
			case '1':
					for (i = 0; i < 3; i++)
					{
						printf("Enter %dth point: ", i+1);
						scanf("%f %f", &t[i].x, &t[i].y);
					}
					fflush(stdin);
					flag = 0;
					break;
			case '2':
					printf("Enter translation vectors tx & ty: ");
					scanf("%f %f", &tx, &ty);
					for (i = 0; i < 3; i++)
					{
						image[i].x = t[i].x + tx;
						image[i].y = t[i].y + ty;
					}
					break;
					
			case '3':
					printf("Enter scaling factors Sx & Sy: ");
					scanf("%f %f", &sx, &sy);
					for (i = 0; i < 3; i++)
					{
						image[i].x = t[i].x * sx;
						image[i].y = t[i].y * sy;
					}
					break;
					
			case '4':					
					printf("Enter the rotation angle (-ve value for clockwise rotation): ");
					scanf("%d", &angle);	
					angle = 90;				
					for (i = 0; i < 3; i++)
					{						
						image[i].x = (t[i].x * cos(angle * PI/180)) - (t[i].y * sin(angle * PI/180));
						image[i].y = (t[i].y * sin(angle * PI/180)) + (t[i].y * cos(angle * PI/180));
					}					
					break;
					
			case '5':
					printf("Choose direction on which to shear(x for X-dirn & y for Y-dirn shear: ");
					fflush(stdin);
					scanf("%c", &ch);
					
					if (tolower(ch) == 'x')
					{
						printf("Enter value of SHx: ");
						scanf("%f", &shx);
						for (i = 0; i < 3; i++)
						{
							image[i].x = t[i].x + (shx * t[i].y);
							image[i].y = t[i].y;
						}
					}
					else
					{
						printf("Enter value of SHx: ");
						scanf("%f", &shy);
						for (i = 0; i < 3; i++)
						{	
							image[i].x = t[i].x;
							image[i].y = t[i].y + (shy * t[i].x);
						}
					}
					break;
					
			case '6':
					printf("\n1. About x-axis");
					printf("\n2. About y-axis");
					printf("\n3. About xy-axis");
					fflush(stdin);
					printf("Enter choice: ");
					scanf("%c", &ch);
					if (ch == '1')
					{
						for (i = 0; i < 3; i++)
						{
							image[i].x = t[i].x;
							image[i].y = -t[i].y;
						}
					}
					else if (ch == '2')
					{
						for (i = 0; i < 3; i++)
						{
							image[i].x = -t[i].x;
							image[i].y = t[i].y;
						}
					}
					else
					{
						for (i = 0; i < 3; i++)
						{
							image[i].x = -t[i].x;
							image[i].y = -t[i].y;
						}
					}
					break;
			case '0':
					closegraph();
					exit(0);
					break;
			default:
					printf("Wrong Choice\n");
					getch();
		}
		if (flag == 1)
		{
			clrscr();
			draw_axis();
			draw_triangle(t[0].x, t[0].y, t[1].x, t[1].y, t[2].x, t[2].y);
			draw_triangle(image[0].x, image[0].y, image[1].x, image[1].y, image[2].x, image[2].y);
			getch();
		}
	}
	//getch();
	closegraph();
	return 0;
}
