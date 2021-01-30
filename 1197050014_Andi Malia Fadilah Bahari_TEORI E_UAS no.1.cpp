#include<stdio.h>
#include<conio.h>
#include<windows.h>

int n=0,bil['n'];

void title()
{
	system("cls");
	printf("    UAS Alogitma dan Pemrograman no.1\n");
	printf("=========================================\n\n");
}

int masuk_array(int n);
void cetak(int n,int *bil);
int tot(int n,int*bil);
float rat(int n,int*bil);
int max(int n,int*bil);
int min(int n,int*bil);

main()
{
	char jwb;
	do
	{
		title();
		int x;
		printf("Masukan Banyak Bilangan Yang Akan Dimasukan: ");scanf("%d",&x);
		
		masuk_array(x);
		
		cetak(x,bil);
		
		printf("\n\n");
		printf("Ulangi Program? [y/n] ");
		jwb=getche();
	}while(jwb=='y'||jwb=='Y');
	return 0;
}

int masuk_array(int n)
{
	for(int i=0;i<n;i++)
	{
		if(i==0)
			printf("Masukan Bilangan pertama: ");
		else
			printf("Masukan Bilangan ke-%d   : ",(i+1));
		scanf("%d",&bil[i]);
	}
}
void cetak(int n,int *bil)
{
	title();
	printf("Deret Bilangannya: ");
	for(int i=0;i<n;i++)
	{
		printf("%d",bil[i]);
		if(i<(n-1))
			printf(", ");
		else
			printf("\n");
	}
	
	printf("Jumlah Perhitungan dari %d bilangan yang dimasukan adalah %d\n",n,tot(n,bil));
	printf("Rata-rata dari %d bilangan yang dimasukan adalah %.2f\n",n,rat(n,bil));
	printf("Bilangan Terbesar      : %d\n",max(n,bil));
	printf("Bilangan Terkecil      : %d\n",min(n,bil));
}

int tot(int n,int*bil)
{
	int jum=0;
	for(int i=0;i<n;i++)
	{
		jum=jum+bil[i];
	}
	return jum;
}

float rat(int n,int*bil)
{
	float jum=0,rata=0;
	for(int i=0;i<n;i++)
	{
		jum=jum+bil[i];
	}
	rata=jum/n;
	return rata;
}

int max(int n,int*bil)
{
	int max=bil[0];
	for(int i=1;i<n;i++)
	{
		if(max<bil[i])
		{
			max=bil[i];
		}
	}
	return max;
}

int min(int n,int*bil)
{
	int min=bil[0];
	for(int i=1;i<n;i++)
	{
		if(min>bil[i])
		{
			min=bil[i];
		}
	}
	return min;
}
