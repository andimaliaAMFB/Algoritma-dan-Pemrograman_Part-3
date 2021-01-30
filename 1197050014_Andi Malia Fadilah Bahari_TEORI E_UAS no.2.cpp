#include<stdio.h>
#include<conio.h>
#include<windows.h>

int n=0,bil['n'];

void title()
{
	system("cls");
	printf("    UAS Alogitma dan Pemrograman no.2\n");
	printf("=========================================\n\n");
}

int masuk_array(int n);
void cetak(int n,int *bil);
int tot(int n,int*bil);
float rat(int n,int*bil);
int urut_asce(int n,int *bil);
int freku(int n,int *bil,int frek);

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
	int frek;
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
	printf("Frekuensi Bilangan apa yang anda cari? ");
	scanf("%d",&frek);
	printf("\n\n");
	printf("Jumlah Perhitungan dari %d bilangan yang dimasukan adalah %d\n",n,tot(n,bil));
	printf("Rata-rata dari %d bilangan yang dimasukan adalah %.2f\n",n,rat(n,bil));
	urut_asce(n,bil);
	printf("Frekuensi Kemunculan %2d adalah %d\n",frek,freku(n,bil,frek));
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

int urut_asce(int n,int *bil)
{
	int tmp;
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(bil[i]>bil[j])
			{
				tmp=bil[i];
				bil[i]=bil[j];
				bil[j]=tmp;
			}
		}
	}
	printf("Bilangan Terbesar      : %d\n",bil[n-1]);
	printf("Bilangan Terbesar Kedua: %d\n",bil[n-2]);
	printf("Bilangan Terkecil      : %d\n",bil[0]);
	printf("Bilangan Terkecil Kedua: %d\n",bil[1]);
}

int freku(int n,int *bil,int frek)
{
	int f=0;
	for(int i=0;i<n;i++)
	{
		if(bil[i]==frek)
			f++;
	}
	return f;
}
