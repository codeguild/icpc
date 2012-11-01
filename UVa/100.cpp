#include <stdio.h>
#include <iostream>

using namespace std;

#ifdef MACRO 
	#define TRACE(x...) x
#else
	#define TRACE(x...)
#endif

#define PRINT(x...) TRACE(printf(x))
#define WATCH(x) TRACE(cout << "\n# " << #x" = " << x << " #\n")

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
		WATCH(i);
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
