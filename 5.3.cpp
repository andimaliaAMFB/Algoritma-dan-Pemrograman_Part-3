#include<stdio.h>
#include<conio.h>
#include<windows.h>

void title()
{
	system("cls");
	printf("     Program Perkalian Dua Matriks\n");
	printf("=======================================\n\n");
}

int m,n,y;
void outmat(int n,int m,int y,int a[10][10],int b[10][10]);
int perkalian(int n,int m,int y,int a[10][10],int b[10][10]);

main()
{
	char jwb;
	do
	{
		title();
		int x,mat_1[10][10],mat_2[10][10];
		
		printf("Untuk Matriks 1\n");
		printf("Masukan Banyak Baris: ");scanf("%d",&n);
		printf("Masukan Banyak Kolom: ");scanf("%d",&m);
		printf("Untuk Matriks 2\n");
		printf("Masukan Banyak Baris: ");scanf("%d",&x);
		printf("Masukan Banyak Kolom: ");scanf("%d",&y);
		
		if(m!=x)
			printf("ERROR\nuntuk perkalian matriks, diperlukan banyak kolom 1=baris 2\n");
		else
		{
			printf("Untuk Matriks 1\n");
			for(int i=0;i<n;i++)
			{
				for(int j=0;j<m;j++)
				{
					printf("Masukan bilangan untuk [%d,%d]: ",i,j);
					scanf("%d",&mat_1[i][j]);
				}
			}
			printf("\n");
			printf("Untuk Matriks 2\n");
			for(int i=0;i<m;i++)
			{
				for(int j=0;j<y;j++)
				{
					printf("Masukan bilangan untuk [%d,%d]: ",i,j);
					scanf("%d",&mat_2[i][j]);
				}
			}
		}
		outmat(n,m,y,mat_1,mat_2);
		printf("Maka Hasil Perkalian Kedua Matriks tersebut adalah\n");
		perkalian(n,m,y,mat_1,mat_2);
		printf("\nUlangi program? [y/n] ");
		jwb=getche();
	}while(jwb=='y'||jwb=='Y');
}

void outmat(int n,int m,int y,int a[10][10],int b[10][10])
{
	title();
	printf("Untuk Matriks 1\n");
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			printf("%d ",a[i][j]);
		}
		printf("\n");
	}
	printf("\nUntuk Matriks 2\n");
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<y;j++)
		{
			printf("%d ",b[i][j]);
		}
		printf("\n");
	}
}

int perkalian(int n,int m,int y,int a[10][10],int b[10][10])
{
	int c['n']['y'];
	for(int i=0;i<n||i<m;i++)
	{
		for(int j=0;j<m||j<y;j++)
		{
			for(int k=0;k<m;k++)
			{
				c[i][j]+=a[i][k]*b[k][j];
			}
			if(i<n&&j<y)
				printf("%d ",c[i][j]);
		}
		printf("\n");
	}
}
