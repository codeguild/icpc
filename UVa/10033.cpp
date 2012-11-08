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
	#define TRACE(x...) {\
		x;\
		cout.flush();\
	}
#else
	#define TRACE(x...)
#endif

#define PRINT(x...) TRACE(cout << x << "\n")
#define WATCH(x) TRACE(cout << #x" = '" << x << "'\n")

int programa[1001][3];
int registers[10];
int ram[1001];

void printregisters()
{
	for(int i = 0; i < 10; i++)
		printf("%d ", registers[i]);
	printf("\n");
}

int run()
{
	int cursor = 0;
	int linha = 0;
	int valor;
	while(true)
	{
		WATCH(programa[cursor][0])
		switch(programa[cursor][0])
		{
			case 1:
				return linha+1;
			case 2:
				registers[programa[cursor][1]] = programa[cursor][2];
				break;
			case 3:
				registers[programa[cursor][1]] += programa[cursor][2];
				registers[programa[cursor][1]] %= 1000;
				break;
			case 4:
				registers[programa[cursor][1]] *= programa[cursor][2];
				registers[programa[cursor][1]] %= 1000;
				break;
			case 5:
				registers[programa[cursor][1]] = registers[programa[cursor][2]];
				break;
			case 6:
				registers[programa[cursor][1]] += registers[programa[cursor][2]];
				registers[programa[cursor][1]] %= 1000;
				break;
			case 7:
				registers[programa[cursor][1]] *= registers[programa[cursor][2]];
				registers[programa[cursor][1]] %= 1000;
				break;
			case 8:
				valor = registers[programa[cursor][2]];
				registers[programa[cursor][1]]  =  programa[valor][0];
				registers[programa[cursor][1]] += (programa[valor][1]*10);
				registers[programa[cursor][1]] += (programa[valor][2]*100);
				break;
			case 9:
				valor = registers[programa[cursor][2]];
				programa[valor][0]  = registers[programa[cursor][1]]%10;
				programa[valor][1] = (registers[programa[cursor][1]]/10)%10;;
				programa[valor][2] = (registers[programa[cursor][1]]/100)%10;;
				//registers[programa[cursor][1]] = registers[registers[programa[cursor][2]]];
				break;
			case 0:
				if (registers[programa[cursor][2]] != 0)
					cursor = registers[programa[cursor][1]]-1;
				break;
		}
		cursor++;
		linha++;
		if(linha > 20)
			return 0;
	}
}

int main()
{
	char lixo;

	int n;
	scanf("%d\n", &n);
	int c1;
	char c2, c3;
	for(int i = 0; i < n; i++)
	{
		WATCH(i);
		int len = 0;
		bzero(registers, sizeof(int)*10);
		bzero(programa, sizeof(int)*1000);
		while(true)
		{
			c1 = getchar();
			WATCH(c1);
			if (c1 == '\n' || c1 == EOF)
			{
				PRINT("OK")
				break;
			}
			else
				PRINT("FAIL")
			c2 = getchar();
			WATCH(c2);
			c3 = getchar();
			WATCH(c3);
			getchar();
			programa[len][0] = c1 - '0';
			programa[len][1] = c2 - '0';
			programa[len][2] = c3 - '0';
			len++;
		}
		int valor = run();
		printf("%d\n", valor);
	}
	return 0;
}

