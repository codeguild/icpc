#include<stdio.h>
#include<string>
#include<iostream>
using namespace std;


/*n2[0][0] = 0; n2[0][1] = 1; n2[0][2] = 0;
n2[1][0] = 0; n2[0][1] = 0; n2[1][2] = 1;
n2[2][0] = 0; n2[0][1] = 1; n2[2][2] = 0;
n2[3][0] = 1; n2[0][1] = 0; n2[3][2] = 0;
n2[4][0] = 0; n2[0][1] = 1; n2[4][2] = 0;*/
int main()
{
	int n1[5][3];
	int n2[5][3];
	int n3[5][3];
	int n4[5][3];
	int n5[5][3];
	int n6[5][3];
	int n7[5][3];
	int n8[5][3];
	int n9[5][3];
	int n0[5][3];

	n1[0][0] = 0; n1[0][1] = 0; n1[0][2] = 0;
	n1[1][0] = 0; n1[1][1] = 0; n1[1][2] = 1;
	n1[2][0] = 0; n1[2][1] = 0; n1[2][2] = 0;
	n1[3][0] = 0; n1[3][1] = 0; n1[3][2] = 1;
	n1[4][0] = 0; n1[4][1] = 0; n1[4][2] = 0;

	n2[0][0] = 0; n2[0][1] = 1; n2[0][2] = 0;
	n2[1][0] = 0; n2[1][1] = 0; n2[1][2] = 1;
	n2[2][0] = 0; n2[2][1] = 1; n2[2][2] = 0;
	n2[3][0] = 1; n2[3][1] = 0; n2[3][2] = 0;
	n2[4][0] = 0; n2[4][1] = 1; n2[4][2] = 0;


	int n;
	string cadeia;
	while(true)
	{
		cin>>n;
		cin>>cadeia;
		if(n == 0)
			return 0;
		for(int j = 0; j < 5; j++)
			for(int repete = 0; repete < (j == 1 || j == 3?n:1); repete++)
			{
				for(int i = 0; i < cadeia.size(); i++)
				{
					if(cadeia[i] == '1')
					{
						
						printf("%c", n1[j][0]==0?'0':'1');
						for(int repete2 = 0; repete2 < n; repete2++)
							printf("%c", n1[j][1]==0?'0':'1');
						printf("%c ", n1[j][2]==0?'0':'1');
					}
					else if(cadeia[i] == '2')
					{
						
						printf("%c", n2[j][0]==0?'0':'1');
						for(int repete2 = 0; repete2 < n; repete2++)
							printf("%c", n2[j][1]==0?'0':'1');
						printf("%c ", n2[j][2]==0?'0':'1');
					}
				}
				printf("\n");
			}
	}
	return 0;
}












