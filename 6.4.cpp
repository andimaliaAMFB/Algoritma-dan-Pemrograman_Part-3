#include<stdio.h>
#include<windows.h>

int n,tmp,pivot,swapind;

void title()
{
	system("cls");
	printf("    SORTING QUICK SORT\n");
	printf("==============================\n\n");
}

void acse (int n,int *a);
void decse(int n,int *a);

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
	for(int i=0;i<n;i++)
	{
		printf("%2d,",a[i]);
	}
	printf("\n");
	acse(n,a);
	printf("\n");
	decse(n,a);
	return 0;
}

void acse(int n,int *a)
{
	for(int i=0;i<n;i++)
	{
		pivot=a[i];
		for(int j=i+1;j<n;j++)
		{
			swapind=i+1;
			if(a[j]<a[swapind])
			{
				tmp=a[j];
				a[j]=a[swapind];
				a[swapind]=tmp;
			}
		}
		if(a[swapind]<a[i])
		{
			tmp=a[swapind];
			a[swapind]=a[i];
			a[i]=tmp;
		}
	}
	//output//
	printf("Data sesudah diurutkan dari terkecil: ");
	for(int i=0;i<n;i++)
	{
		printf("%2d,",a[i]);
	}
}
void decse(int n,int *a)
{
	for(int i=0;i<n;i++)
	{
		pivot=a[i];
		for(int j=i+1;j<n;j++)
		{
			swapind=i+1;
			if(a[j]>a[swapind])
			{
				tmp=a[j];
				a[j]=a[swapind];
				a[swapind]=tmp;
			}
		}
		if(a[swapind]>a[i])
		{
			tmp=a[swapind];
			a[swapind]=a[i];
			a[i]=tmp;
		}
	}
	//output//
	printf("Data sesudah diurutkan dari terbesar: ");
	for(int i=0;i<n;i++)
	{
		printf("%2d,",a[i]);
	}
}
