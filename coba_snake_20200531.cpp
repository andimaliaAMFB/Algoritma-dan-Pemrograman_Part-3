#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<windows.h>

int gameover;
enum direc{UP,DOWN,RIGHT,LEFT};
enum direc arah;
const int width=20;
const int hight=10;
int x,y,fx,fy,score=0;
int tailx[100],taily[100],ntail=0;
int Ltailx,Ltaily;

int setup()
{
	gameover=false;
	x=width/2;
	y=hight/2;
	fx=rand()%width;
	fy=rand()%hight;
	arah=DOWN;
	ntail=0;
}
int draw()
{
	_sleep(250);
	system("cls");
	//map//
	for(int i=0;i<width+2;i++)//up
	{
		if(y==0&&i==x+1)
			printf("O");
		else
			printf("#");
	}
	printf("\n");
	for(int i=0;i<hight;i++)//area
	{
		for(int j=0;j<width;j++)
		{
			if(j==0)//left
			{
				if(x==0&&i==y)
					printf("O");
				else
					printf("#");
			}
			if(i==y&&j==x)
			{
				if(x==0||x==width||y==0||y==hight)
					printf(" ");
				else
					printf("O");
			}
			else if(i==fy&&j==fx)
				printf("F");
			else
			{
				bool print=false;
				for(int k=1;k<=ntail;k++)
				{
					if(i==taily[k]&&j==tailx[k])
					{
						printf("o");
						print=true;
					}
				}
				if(!print)
					printf(" ");
			}
			
			if(j==width-1)//right
			{
				if(x==width&&i==y)
					printf("O");
				else
					printf("#");
			}
		}
		printf("\n");
	}
	for(int i=0;i<width+2;i++)//down
	{
		if(y==hight&&i==x+1)
			printf("O");
		else
			printf("#");
	}
	printf("\n");
	printf("CONTROL:  W\n");
	printf("        A    D\n");
	printf("          S\n");
	printf("SCORE: %d\n",score);	
	printf("%d,%d",x,y);
}
int direction()
{
	if(kbhit())
	{
		switch(getch())
		{
			case 'w':
				arah=UP;
				break;
			case 's':
				arah=DOWN;
				break;
			case 'a':
				arah=LEFT;
				break;
			case 'd':
				arah=RIGHT;
				break;
				/*w
				a	d
				  s*/
		}
	}
}
int logic()
{
	switch(arah)//snake keep move
	{
		case UP:
			y--;
			break;
		case DOWN:
			y++;
			break;
		case LEFT:
			x--;
			break;
		case RIGHT:
			x++;
			break;
	}
	if(x==fx&&y==fy)//snake eat fruit
	{
		ntail++;
		for(int i=0;i<ntail;i++)//scoring
		{
			if(ntail>10)
			{
				score+=2+(ntail/10);
			}
			else
				score++;
		}
		//new position fruit
		fx=rand()%width;
		fy=rand()%hight;
	}
	tailx[0]=x;
	taily[0]=y;
	Ltailx=tailx[0];
	Ltaily=taily[0];
	int tempx, tempy;
	for(int i=1;i<=ntail;i++)
	{
		tempx=tailx[i];
		tempy=taily[i];
		tailx[i]=Ltailx;
		taily[i]=Ltaily;
		Ltailx=tempx;
		Ltaily=tempy;
	}
	
	if(x>width||x<0||y>hight||y<0)
	{
		gameover=true;
	}
}

main()
{
	setup();
	while(!gameover)
	{
		draw();
		direction();
		logic();
	}
	return 0;
}
