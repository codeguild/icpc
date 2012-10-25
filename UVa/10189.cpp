#include <stdio.h>

int quantMina(char m[][100], int i, int j, int l, int c){
	int quant = 0;
	if(i+1 < l && j+1 < c && m[i+1][j+1] == '*') quant++;
	if(i-1 >= 0 && j-1 >= 0 && m[i-1][j-1] == '*') quant++;
	if(i+1 < l && j-1 >= 0 && m[i+1][j-1] == '*') quant++;
	if(i-1 >= 0 && j+1 < c && m[i-1][j+1] == '*') quant++;

	if(i+1 < l && m[i+1][j] == '*') quant++;
	if(i-1 >= 0 && m[i-1][j] == '*') quant++;
	if(j-1 >= 0 && m[i][j-1] == '*') quant++;
	if(j+1 < c && m[i][j+1] == '*') quant++;
	return quant;
}

int main()
{
	int l, c;
	char lixo;
	char m[100][100];
	int n = 1;
	while(true)
	{
		scanf("%d %d\n", &l, &c);
		if(l == 0)
			return 0;
		if(n != 1)
			printf("\n");

		for(int i = 0; i < l; i++){
			for(int j = 0; j < c; j++){
				scanf("%c", &m[i][j]);
			}
			scanf("%c", &lixo);
		}
		printf("Field #%d:\n", n);
		for(int i = 0; i < l; i++){
			for(int j = 0; j < c; j++){
				if(m[i][j] == '*')
					printf("*");
				else 
					printf("%d", quantMina(m, i, j, l, c));
			}
			printf("\n");
		}
		n++;
	}
	return 0;
}
