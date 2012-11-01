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

int programa[1000][3];
int registers[10];

int run()
{
	int cursor = 0;
	int linha = 0;
	while(true)
	{
		switch(programa[cursor][0])
		{
			case 1:
				return linha+1;
			case 2:
				registers[programa[cursor][1]] = programa[cursor][2];
				break;
			case 3:
				registers[programa[cursor][1]] += programa[cursor][2];
				break;
			case 4:
				registers[programa[cursor][1]] *= programa[cursor][2];
				break;
			case 5:
				registers[programa[cursor][2]] = registers[programa[cursor][1]];
				break;
			case 6:
				registers[programa[cursor][1]] += registers[programa[cursor][2]];
				break;
			case 7:
				registers[programa[cursor][1]] *= registers[programa[cursor][2]];
				break;
			case 8:
				registers[registers[programa[cursor][2]]] = registers[programa[cursor][1]];
				break;
			case 9:
				registers[programa[cursor][1]] = registers[registers[programa[cursor][2]]];
			case 0:
				if (registers[programa[cursor][2]] != 0)
					cursor = registers[programa[cursor][1]];
		}
		linha++;
	}
}

int main()
{
	char lixo;

	int n;
	scanf("%d", &n);
	scanf("%c", &lixo);
	char c1, c2, c3;
	for(int i = 0; i < n; i++)
	{
		WATCH(i);
		int len = 0;
		while(true)
		{
			scanf("%c", &c1);
			if (c1 == '\n')
				break;
			scanf("%c", &c2);
			scanf("%c", &c3);
			scanf("%c", &lixo);
			programa[len][0] = c1 - '0';
			programa[len][1] = c2 - '0';
			programa[len][2] = c3 - '0';
			len++;
		}
		memset(registers, 0, 10);
		int valor = run();
		printf("%d\n", valor);
	}
	return 0;
}
