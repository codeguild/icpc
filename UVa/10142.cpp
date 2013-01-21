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

#define PRINT(x...) TRACE(cout << x)
#define WATCH(x) TRACE(cout << #x" = '" << x << "'\n")

int 

int main()
{
	int cases;
	cin >> cases;

	int n;
	cin >> n;
	n++;
	char* cadidatos[21];
	int votos[1000][21];
	int temp[20];
	while(true)
	{
		for(int i = 1; i < n; i++){
			cin.getline(candidados[i], 80);
		}
		int cont = 0;
		int numElem = 0;
		while(true){
			cont = 0;
			while (getchar() != '\n'){
				cin >> temp[cont];
				cont++;
			}
			if(cont == n) {
				for(int i = 0; i < n; i++){
					votos[numElem][i] = temp[i];
				}
				numElem++;
			}
			else if(cont == 1)
			{
				roda(candidados, votos, n);
				n = cont;
				break;
			}
			else
			{
				roda(candidados, votos, n);
				return 0;
			}
		}
	}

	return 0;
}
