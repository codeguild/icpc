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

int main()
{
	int * cards = new int[53];
	int * cardsTmp = new int[53];
	int shuffle [101][53];
	int seq[101];

	int caso;
	scanf("%d", &caso);
	for(int i = 0; i < caso; i++)
	{
		int n;
		scanf("%d", &n);
		for(int j = 1; j <= n; j++)
			for(int k = 1; k <= 52; k++)
				scanf("%d", &shuffle[j][k]);
		for(int j = 1; j <= n; j++)
			scanf("%d", &seq[j]);
		for(int k = 1; k <= 52; k++)
			cards[k] = k;

		for(int j = 1; j <= n; j++)
		{
			PRINT("OK\n");
			cardsTmp = new int[53];
			for(int k = 1; k <= 52; k++)
			{
				cardsTmp[k] = cards[shuffle[seq[j]][k]];
				PRINT("%d  ", cardsTmp[k]);
			}
			PRINT("\n");
			cards = cardsTmp;
		}

		for(int j = 1; j <= 52; j++)
		{
			int c = cards[j];
			if (c % 13 == 0)
				printf("Ace of ");
			else if(c % 13 < 10)
				printf("%d of ", (c%13)+1);
			else if (c % 13 == 10)
				printf("Jack of ");
			else if (c % 13 == 11)
				printf("Queen of ");
			else if (c % 13 == 12)
				printf("King of ");

			if(c < 14)
				printf("Clubs\n");
			else if(c < 27)
				printf("Diamonds\n");
			else if (c < 40)
				printf("Hearts\n");
			else
				printf("Spades\n");
		}
		if(i < (caso -1))
		{
			printf("\n");
		}
	}
	return 0;
}
