#include<stdio.h>
#include<windows.h>

int n,a['n'],salin['n'];

void title()
{
	system("cls");
	printf("    SORTING QUICK SORT\n");
	printf("==============================\n\n");
}

void merge(int *salin,int lowptr,int highptr,int upperbound);
void devide(int *salin,int kiri,int kanan);
void view();
void sort();

main()
{
	title();
	int a['n'];
	printf("Masukan Banyak Data yang akan dimasukan: ");scanf("%d",&n);
	
	//input//
	for(int i=0;i<n;i++)
	{
		printf("Masukan data ke-%d: ",i+1);
		scanf("%d",&a[i]);
	}
	//output//
	title();
	printf("Data yang Anda Masukan              : ");
	view();
	printf("\n");
	sort();
	printf("Data setelah diurutkan              : ");
	view();
	return 0;
}

void merge(int *salin,int lowptr,int highptr,int upperbound)
{
	int x=0;
	int lowerbound=lowptr;
	int mid=highptr-1;
	int n=upperbound-lowerbound+1;
	while(lowptr<=mid && highptr<=upperbound)
	{
		if(a[lowptr]<a[highptr])
		{
			salin[x++]=a[lowptr++];
		}
 		else
		{
			salin[x++]=a[highptr++];
		}
 		while(lowptr<=mid)
		{
			salin[x++]=a[lowptr++];
		}
		while(highptr<=upperbound)
		{
			salin[x++]=a[highptr++];
		}
		for(int i=0;i<n;i++)
		{
			a[lowerbound+i]=salin[i];
		}
 
	}
}
 
void devide(int salin[],int kiri,int kanan)
{
	if(kiri<kanan)
	{
		int mid=(kiri+kanan)/2;
		devide(salin,kiri,mid);
		devide(salin,mid+1,kanan);
		merge(salin,kiri,mid+1,kanan);
	}
}

void view()
{
	for(int i=0;i<n;i++)
	{
		printf("%2d,",a[i]);
	}
}
 
void sort()
{
	devide(salin,0,n-1);
}
