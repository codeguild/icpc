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
#include<string>
#include<sstream>
#include<set>

using namespace std;

#ifdef MACRO 
	#define TRACE(x...) x
#else
	#define TRACE(x...)
#endif

#define PRINT(x...) TRACE(printf(x))
#define WATCH(x) TRACE(cout << #x" = " << x << "\n")
struct x
{
	int time;
	int score;
	int tempo;
};

int compare (const void * a, const void * b)
{
	if(((struct x *)b)->score == ((struct x *)a)->score)
	{
		if (((struct x *)b)->tempo == ((struct x *)a)->tempo)
			 return ((struct x *)a)->time - ((struct x *)b)->time;
		return ((struct x *)a)->tempo - ((struct x *)b)->tempo;
	}
	else
		return ((struct x *)b)->score - ((struct x *)a)->score;
}

int main()
{
	int n;
	scanf("%d\n\n", &n);
	int incor[100][10];
	struct x score[100];
	int time, problema, tempo;
	string letra;
	for(int i = 0; i < 100; i++)
	{
		for(int j = 0; j < 10; j++)
			incor[i][j] = 0;
		score[i].score = 0;
		score[i].tempo = 0;
		score[i].time = i;
	}

	set<int> vistos;
	while(n > 0)
	{
		char linha[256];
		while(true)
		{
			cin.getline(linha, 256);
			if(linha[0] == '\0')
			{
				qsort (score, 100, sizeof(struct x), compare);
				for(int i = 0; i < 100; i++)
				{
					if(vistos.find(score[i].time) != vistos.end())
						cout << score[i].time << " " << score[i].score << " " << score[i].tempo << endl;
				}
				for(int i = 0; i < 100; i++)
				{
					for(int j = 0; j < 10; j++)
						incor[i][j] = 0;
					score[i].score = 0;
					score[i].tempo = 0;
					score[i].time = i;
				}
				vistos.clear();

				n--;
				if(n > 0)
					cout << endl;
				break;
			}
			else
			{
				string slinha(linha);
				istringstream ss( slinha );
				ss >> time;
				ss >> problema;
				ss >> tempo;
				ss >> letra;
				vistos.insert(time);
				if(incor[time][problema] < 0)
				{}
				else if(letra[0] == 'I')
				{
					incor[time][problema]++;
				}
				else if(letra[0] == 'C')
				{
					score[time].tempo += tempo + incor[time][problema]*20;
					score[time].score++;
					incor[time][problema] = -1;
				}
			}
		}
	}
	return 0;
}

