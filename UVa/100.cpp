#include <stdio.h>

int f3n1(long x)
{
	int ciclos = 1;
	while(x != 1)
	{
		ciclos++;
		if(x % 2 ==0)
			x /= 2;
		else
			x = (3*x)+1;
	}
	return ciclos;
}

int main()
{
	int i, j;
	while(scanf("%d %d", &i, &j) != -1)
	{
		int max = 0;
		printf("%d %d ", i, j);
		if(i > j){
			int temp = j;
			j = i;
			i = temp;
		}
		for(int k = i; k <= j; k++)
		{
			int tmp = f3n1(k);
			if(tmp > max)
				max = tmp;
		}
		printf("%d\n", max);
	}
	return 0;
}