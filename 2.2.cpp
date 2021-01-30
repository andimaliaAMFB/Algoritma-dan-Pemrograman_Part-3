//program 2.2//
#include<stdio.h>
main()
{
	int a;
	printf("Masukan sebuah bilangan bulat: ");
	scanf("%i",&a);
	if(a==0)
	{
		printf("Bilangan %d adalah NOL\n",a);
	}
	else
	{
		if(a>0)
		{
			printf("Bilangan %d adalah bilangan positif\n",a);
		}
		else
		{
			printf("Bilangan %d adalah bilangan negatif\n",a);
		}
	}
}
