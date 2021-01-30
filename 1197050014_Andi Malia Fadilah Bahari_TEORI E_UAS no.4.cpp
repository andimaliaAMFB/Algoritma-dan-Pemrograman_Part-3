#include<stdio.h>
#include<conio.h>
#include<windows.h>

int n=0,bil['n'];

void title()
{
	system("cls");
	printf("    UAS Alogitma dan Pemrograman no.4\n");
	printf("=========================================\n\n");
}

int masuk_array(int n);
void cetak(int n,int *bil);
int pilih(int n,int *bil);
int tot(int n,int*bil);
float rat(int n,int*bil);
int urut_asce(int n,int *bil,int q);
int freku(int n,int *bil,int frek);
int cari(int n,int *bil,int cari);
int hapus(int n,int *bil,int hps);

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
		pilih(x,bil);
		
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
}

int pilih(int n,int *bil)
{
	int p,car,frek,hps,q;
	printf("Program Yang Anda Inginkan?\n");
	printf("1.Menghitung Jumlah Data         \t7.Mencari Data\n");
	printf("2.Menghitung Rata-rata Data      \t8.Menghitung Frekuensi Suatu Data\n");
	printf("3.Mencari Bilangan Terbesar      \t9.Menghapus Data\n");
	printf("4.Mencari Bilangan Terkecil      \t10.Keluar\n");
	printf("5.Mencari Bilangan Terbesar Kedua\n");
	printf("6.Mencari Bilangan Terkecil Kedua\n");
	printf("Pilihan Anda: ");scanf("%d",&p);
	printf("\n");
	switch(p)
	{
		case 1:
			printf("Jumlah Perhitungan dari %d bilangan yang dimasukan adalah %d\n",n,tot(n,bil));
			break;
		case 2:
			printf("Rata-rata dari %d bilangan yang dimasukan adalah %.2f\n",n,rat(n,bil));
			break;
		case 3:
			printf("Bilangan Terbesar: %d\n",urut_asce(n,bil,1));
			break;
		case 4:
			printf("Bilangan Terkecil: %d\n",urut_asce(n,bil,2));
			break;
		case 5:
			printf("Bilangan Terbesar Kedua: %d\n",urut_asce(n,bil,3));
			break;
		case 6:
			printf("Bilangan TerkecilKedua: %d\n",urut_asce(n,bil,4));
			break;
		case 7:
			printf("Bilangan Apa yang Anda Cari? ");
			scanf("%d",&car);
			cari(n,bil,car);
			break;
		case 8:
			printf("Frekuensi Bilangan apa yang anda cari? ");
			scanf("%d",&frek);
			printf("Frekuensi Kemunculan %2d adalah %d\n",frek,freku(n,bil,frek));
			break;
		case 9:
			printf("Bilangan Apa yang ingin Anda Hapus? ");
			scanf("%d",&hps);
			hapus(n,bil,hps);
			break;
	}
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

int cari(int n,int *bil,int cari)
{
	int c=0;
	for(int i=0;i<n;i++)
	{
		if(bil[i]==cari)
			c++;
	}
	if(c>0)
		printf("%d ADA dalam deret\n",cari);
	else
		printf("%d TIDAK ADA dalam deret\n",cari);
}

int hapus(int n,int *bil,int hps)
{
	int z=0;
	printf("Deret setelah %d dihapus: ",hps);
	for(int i=0;i<n;i++)
	{
		if(bil[i]==hps)
			z++;
		else
			printf("%d, ",bil[i]);
	}
}

int urut_asce(int n,int *bil,int q)
{
	int tmp,ma,mi,ma2,mi2;
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
	ma=bil[n-1];
	mi=bil[0];
	ma2=bil[n-2];
	mi2=bil[1];
	for(int i=2;i<n;i++)
	{
		if(ma2==ma)
			ma2=bil[n-(i+1)];
		if(mi2==mi)
			mi2=bil[i];
	}
	switch(q)
	{
		case 1:
			return ma;
			break;
		case 2:
			return mi;
			break;
		case 3:
			return ma2;
			break;
		case 4:
			return mi2;
			break;
	}
}
