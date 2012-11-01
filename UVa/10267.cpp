#include<stdio.h>
#include<stlib.h>
#include<string>
#include<iostream>
#include<math.h>
#include<string.h>
#include<inttypes>
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


char mesa[260][260];

bool dentro(int X, int Y, int x, int y)
{
	return x <= X && x > 0 && y <= Y && y > 0;
}

void altera(int X, int Y, int x, int y, char C, char ant){
	mesa[x][y] = C;
	//if(x <= X && x > 0 && y <= Y && y > 0 && mesa[x][y] == ant){
	if (dentro(X, Y, x+1, y) && mesa[x+1][y] == ant) altera(X, Y, x+1, y, C, ant);
	if (dentro(X, Y, x-1, y) && mesa[x-1][y] == ant) altera(X, Y, x-1, y, C, ant);
	if (dentro(X, Y, x, y+1) && mesa[x][y+1] == ant) altera(X, Y, x, y+1, C, ant);
	if (dentro(X, Y, x, y-1) && mesa[x][y-1] == ant) altera(X, Y, x, y-1, C, ant);
	//}
}

void limpa(int X, int Y){
	for(int i = 0; i <= X; i++){
		for(int j = 0; j <= Y; j++){
			mesa[i][j] = 'O';
		}
	}
}

void swap(int * a, int * b)
{
	*a = *a^*b;
	*b = *b^*a;
	*a = *a^*b;
}

int main()
{
	while(true)
	{
		int Y;
		int X;

		int x;
		int y;
		char C;
		int x1;
		int x2;
		int y1;
		int y2;
		char ant;
		char letra;
		
		string nome;
		cin>>letra;
		WATCH(letra);
		switch(letra){
			case 'X': 
				return 0;
			case 'I': 
				cin>>X;
				cin>>Y;
				limpa(X, Y);
				break;
			case 'C':
				limpa(X, Y);
				break;
			case 'L':
				cin>>x;
				cin>>y;
				cin>>C;
				mesa[x][y] = C;
				break;
			case 'V': 		
				cin>>x;
				cin>>y1;
				cin>>y2;
				cin>>C;
				if(y1 > y2)
				{
					int tmp = y1;
					y1 = y2;
					y2 = tmp;
				}
				for(int i = y1; i<=y2; i++){
					mesa[x][i] = C;
				}
				break;	
			case 'H': 
				cin>>x1;
				cin>>x2;
				cin>>y;
				cin>>C;
				if(x1 > x2)
				{
					int tmp = x1;
					x1 = x2;
					x2 = tmp;
				}
				for(int i = x1; i<=x2; i++){
					mesa[i][y] = C;
				}
				break;
			case 'K':  
				cin>>x1;
				cin>>x2;
				cin>>y1;
				cin>>y2;
				cin>>C;
				if(x1 > x2)
				{
					int tmp = x1;
					x1 = x2;
					x2 = tmp;
				}
				if(y1 > y2)
				{
					int tmp = y1;
					y1 = y2;
					y2 = tmp;
				}
				for(int i = x1; i <= x2; i++){
					for(int j = y1; j <= y2; j++){
						mesa[i][j] = C;
					}
				}
				break;
			case 'F': 
				cin>>x;
				cin>>y;
				cin>>C;
				ant = mesa[x][y];
				altera(X, Y, x, y, C, ant);
				break;
			case 'S': 
				cin>>nome;
				cout<<nome;
				printf("\n");
				for(int i = 0; i < Y; i++)
				{
					for(int j = 0; j < X; j++) 
						printf("%c", mesa[j+1][i+1]);
					printf("\n");
				}
				break;
			default:
				break;
				//scanf("\n");
		}
	}
	return 0;
}












