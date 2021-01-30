#include<stdio.h>
#include<windows.h>

int fibbo(int last,int now);
void title()
{
	system("cls");
	printf("Program Bilangan Fibonacci\n");
	printf("==========================\n\n");
}
main()
{
	int n;
	title();
	printf("Masukan Banyak Bilangan: ");
	scanf("%d",&n);
	
	int a[n];
	a[0]=0;
	a[1]=1;
	for(int i=0;i<n;i++)
	{
		if(i>1)
			a[i]=fibbo(a[i-2],a[i-1]);
		printf("%d",a[i]);
		if(i!=n-1)
			printf(" ");
	}
}

int fibbo(int last,int now)
{
	int lanjut=last+now;
	return lanjut;
}
