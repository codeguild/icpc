#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<iostream>
#include<math.h>
#include<string.h>
#include<inttypes.h>
#include<ctype.h>
#include<algorithm>
#include<utility>

using namespace std;

#ifdef MACRO 
	#define TRACE(x...) x
#else
	#define TRACE(x...)
#endif

#define PRINT(x...) TRACE(printf(x))
#define WATCH(x) TRACE(cout << #x" = " << x << "\n")

#include <set>

int main()
{
	int testes;
	scanf("%d", &testes);
	for(int i = 0; i < testes; i++)
	{
		set<int> dias;
		int calendario;
		scanf("%d", &calendario);
		int h;
		scanf("%d", &h);
		for(int j = 0; j < h; j++)
		{
			int hi;
			scanf("%d", &hi);
			for(int k = hi; k <= calendario; k+=hi)
				if(k % 7 != 0 && k % 7 != 6)
					dias.insert(k);
		}
		printf("%d\n", dias.size());
	}
}
