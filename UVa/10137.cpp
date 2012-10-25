#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int main()
{
	int n = 0;
	double array[1000];
	while(true)
	{
		scanf("%d", &n);
		if(n == 0)
			return 0;

		float soma = 0;
		for(int i = 0; i < n; i++)
		{
			scanf("%lf", &array[i]);
			soma += array[i];
		}
		float media = soma/n;
		//media = (int)(media*100);
		//media = round(media*100);
		//media = media/100;

		float difPositivo = 0;
		float difNegativo = 0;
		for(int i = 0; i < n; i++)
		{
			double x = (double) (long) ((array[i] - media) * 100.0) / 100.0;
			if(x >=	 0){
				difPositivo += x;
			}
			else
				difNegativo += x;
		}
		double dif = (-difNegativo > difPositivo) ? -difNegativo : difPositivo;
		printf("%.2f\n", dif);
	}
}

