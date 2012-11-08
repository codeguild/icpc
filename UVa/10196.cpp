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
int testa(char matriz[8][8], int i, int j){
	switch(matriz[i][j]){
		case 'p':
			if (i <= 6){
				if(j > 0 && matriz[i+1][j-1] == 'K') return -1;
				if(j < 7 && matriz[i+1][j+1] == 'K') return -1; 
			} 
			break;
		case 'P':
			if (i > 0){
				if(j > 0 && matriz[i-1][j-1] == 'k') return 1;
				if(j < 7 && matriz[i-1][j+1] == 'k') return 1; 
			}
			break;
		case 'r':
		case 'R':
			for (int k = j+1; k < 8; k++){
				if(matriz[i][k] == ((matriz[i][j]=='r')?'K':'k')) return (matriz[i][j]=='r')?-1:1;
				if(matriz[i][k] != '.') break;
				
			}			

			for (int k = j-1; k >= 0; k--){
				if(matriz[i][k] == ((matriz[i][j]=='r')?'K':'k')) return (matriz[i][j]=='r')?-1:1;
				if(matriz[i][k] != '.') break;
				
			}
			for (int k = i+1; k < 8; k++){
				if(matriz[k][j] == ((matriz[i][j]=='r')?'K':'k')) return (matriz[i][j]=='r')?-1:1;
				if(matriz[k][j] != '.') break;
				
			}			

			for (int k = i-1; k >= 0; k--){
				if(matriz[k][j] == ((matriz[i][j]=='r')?'K':'k')) return (matriz[i][j]=='r')?-1:1;
				if(matriz[k][j] != '.') break;
				
			}
			break;
		case 'b':
		case 'B':
			for (int k = 1; max(i, j) + k < 8; k++){
				WATCH(matriz[i][j])
				if(matriz[i+k][j+k] == ((matriz[i][j]=='b')?'K':'k')) return ((matriz[i][j]=='b')?-1:1);
				PRINT("OK\n")
				if(matriz[i+k][j+k] != '.') break;
			}
			for (int k = 1; min(i, j) - k >= 0; k++){
				if(matriz[i-k][j-k] == ((matriz[i][j]=='b')?'K':'k')) return (matriz[i][j]=='b')?-1:1;
				if(matriz[i-k][j-k] != '.') break;
			}
			for (int k = 1; i + k < 8 && j - k >= 0; k++){
				if(matriz[i+k][j-k] == ((matriz[i][j]=='b')?'K':'k')) return (matriz[i][j]=='b')?-1:1;
				if(matriz[i+k][j-k] != '.') break;
			}
			for (int k = 1; j + k < 8 && i - k >= 0; k++){
				if(matriz[i-k][j+k] == ((matriz[i][j]=='b')?'K':'k')) return (matriz[i][j]=='b')?-1:1;
				if(matriz[i-k][j+k] != '.') break;
			}
			break;
		case 'q':
		case 'Q':
			for (int k = j+1; k < 8; k++){
				if(matriz[i][k] == ((matriz[i][j]=='q')?'K':'k')) return (matriz[i][j]=='q')?-1:1;
				if(matriz[i][k] != '.') break;
				
			}			

			for (int k = j-1; k >= 0; k--){
				if(matriz[i][k] == ((matriz[i][j]=='q')?'K':'k')) return (matriz[i][j]=='q')?-1:1;
				if(matriz[i][k] != '.') break;
				
			}
			for (int k = i+1; k < 8; k++){
				if(matriz[k][j] == ((matriz[i][j]=='q')?'K':'k')) return (matriz[i][j]=='q')?-1:1;
				if(matriz[k][j] != '.') break;
				
			}			

			for (int k = i-1; k >= 0; k--){
				if(matriz[k][j] == ((matriz[i][j]=='q')?'K':'k')) return (matriz[i][j]=='q')?-1:1;
				if(matriz[k][j] != '.') break;
				
			}
			//--
			for (int k = 1; max(i, j) + k < 8; k++){
				if(matriz[i+k][j+k] == ((matriz[i][j]=='b')?'K':'k')) return (matriz[i][j]=='b')?-1:1;
				if(matriz[i+k][j+k] != '.') break;
			}
			for (int k = 1; min(i, j) - k >= 0; k++){
				if(matriz[i-k][j-k] == ((matriz[i][j]=='b')?'K':'k')) return (matriz[i][j]=='b')?-1:1;
				if(matriz[i-k][j-k] != '.') break;
			}
			for (int k = 1; i + k < 8 && j - k >= 0; k++){
				if(matriz[i+k][j-k] == ((matriz[i][j]=='b')?'K':'k')) return (matriz[i][j]=='b')?-1:1;
				if(matriz[i+k][j-k] != '.') break;
			}
			for (int k = 1; j + k < 8 && i - k >= 0; k++){
				if(matriz[i-k][j+k] == ((matriz[i][j]=='b')?'K':'k')) return (matriz[i][j]=='b')?-1:1;
				if(matriz[i-k][j+k] != '.') break;
			}
			

			break; 
		case 'n':
		case 'N':
			if (i+2 < 8 && j+1 < 8)
			{
				if(matriz[i+2][j+1] == ((matriz[i][j]=='n')?'K':'k')) return (matriz[i][j]=='b')?-1:1;
				if(matriz[i+2][j+1] != '.') break;
			}
			if (i-2 < 8 && j+1 < 8)
			{
				if(matriz[i-2][j+1] == ((matriz[i][j]=='n')?'K':'k')) return (matriz[i][j]=='b')?-1:1;
				if(matriz[i-2][j+1] != '.') break;
			}
			if (i+2 < 8 && j-1 < 8)
			{
				if(matriz[i+2][j-1] == ((matriz[i][j]=='n')?'K':'k')) return (matriz[i][j]=='b')?-1:1;
				if(matriz[i+2][j-1] != '.') break;
			}
			if (i-2 < 8 && j-1 < 8)
			{
				if(matriz[i-2][j-1] == ((matriz[i][j]=='n')?'K':'k')) return (matriz[i][j]=='b')?-1:1;
				if(matriz[i-2][j-1] != '.') break;
			}

			if (i+1 < 8 && j+2 < 8)
			{
				if(matriz[i+1][j+2] == ((matriz[i][j]=='n')?'K':'k')) return (matriz[i][j]=='b')?-1:1;
				if(matriz[i+1][j+2] != '.') break;
			}
			if (i-1 < 8 && j+2 < 8)
			{
				if(matriz[i-1][j+2] == ((matriz[i][j]=='n')?'K':'k')) return (matriz[i][j]=='b')?-1:1;
				if(matriz[i-1][j+2] != '.') break;
			}
			if (i+1 < 8 && j-2 < 8)
			{
				if(matriz[i+1][j-2] == ((matriz[i][j]=='n')?'K':'k')) return (matriz[i][j]=='b')?-1:1;
				if(matriz[i+1][j-2] != '.') break;
			}
			if (i-1 < 8 && j-2 < 8)
			{
				if(matriz[i-1][j-2] == ((matriz[i][j]=='n')?'K':'k')) return (matriz[i][j]=='b')?-1:1;
				if(matriz[i-1][j-2] != '.') break;
			}
			break;
	}
	return 0;

}
int kingCheck(char matriz[8][8])
{
	for(int i = 0; i < 8; i++)
		for(int j = 0; j < 8; j++)
		{
			if(matriz[i][j] != '.'){
				int r = testa(matriz, i, j);
				if(r != 0)
				{
					WATCH(i)
					WATCH(j)
				}
				WATCH(r)
				if(r == 1) return 1;
				else if(r == -1) return -1;
			}
		}
	return 0;
}

void printmatriz(char matriz[8][8])
{
	for(int i = 0; i < 8; i++)
	{
		for(int j = 0; j < 8; j++)
			PRINT(matriz[i][j] << "\t")
		PRINT("\n");
	}

}

int main()
{
	char matriz[8][8];
	int tmp;
	int game = 1;
	while(true)
	{
		int totalDif = 0;
		for(int i = 0; i < 8; i++)
		{
			for(int j = 0; j < 8; j++)
			{
				tmp = getchar();
				matriz[i][j] = tmp;
				if(tmp != '.')
					totalDif++;
			}
			getchar();
		}
		if(totalDif == 0)
			return 0;
		printmatriz(matriz);
		int result = kingCheck(matriz);
		cout << "Game #" << game << ": ";
		if(result == 1)
			cout << "black king is in check.\n";
		else if(result == -1)
			cout << "white king is in check.\n";
		else
			cout << "no king is in check.\n";
		
		tmp = getchar();
		if (tmp == EOF)
			return 0;

		game++;
	}
	return 0;
}
