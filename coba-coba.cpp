#include<stdio.h>
#include<conio.h>
#include<windows.h>

void run();
void map();
void sistem();
void position();
void move();
void hitkey();

const int Pl = 10;
const int  Ll = 10;
const int l = Pl*Ll;

int x;
int y;

int dx;
int dy;
int d['x']['y'];

int direct = 0;
int food = 1;

int main()
{
	run();
}

void run()
{
	map();
	sistem();
}

void map()
{
	for(int x=1;x<=Ll;x++)
	{
		for(int y=1;y<=Pl;y++)
		{
			if(x==1||x==Ll)
			{
				printf("X");
			}
			else if(y==1||y==Pl)
			{
				printf("X");
			}
			else
			{
				move();
			}
		}
		printf("\n");
	}
}

void sistem()
{
	hitkey();
	switch(direct)
	{
		case 0:
			move,(0,1);
			break;
		case 1:
			move,(1,0);
			break;
		case 2:
			move,(0,-1);
			break;
		case 3:
			move,(-1,0);
			break;
	}
	
}

void hitkey()
{
	getche();
	switch(getche())
	{
		/*	W		0
		  A	  D = 3	  1
		  	S		2*/
		case 'w':
			direct=0;
			break;
		case 'd':
			direct=1;
			break;
		case 's':
			direct=2;
			break;
		case 'a':
			direct=3;
			break;
	}
}

void move(int x,int y)
{
	dx+=x;
	dy+=y;
	for(x=1;x<=Pl;x++)
	{
		for(y=1;y<=Ll;y++)
		{
			printf("%d",d[dx][dy]);
		}
	}
}
