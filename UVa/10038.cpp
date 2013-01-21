#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int n;
	bool array[3001];
	while(scanf("%d", &n) != -1)
	{
		//printf("%d\n", n);
		bool jolly = true;
		memset(array, false, n);

		int ant;
		scanf("%d", &ant);
		for(int i = 1; i < n; i++)
		{
			int num;
			scanf("%d", &num);
			if(abs(num - ant) < 3001)
				array[abs(num - ant)] = true;
			ant = num;
		}

		for(int i = 1; i < n; i++)
			if(array[i] == false)
				jolly = false;

		if(jolly)
			printf("Jolly\n");
		else
			printf("Not jolly\n");
	}
	return 0;
}
