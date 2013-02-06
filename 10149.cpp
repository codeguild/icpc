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
#include<numeric>
#include<functional>

using namespace std;

#ifdef MACRO 
	#define TRACE(x...) x
#else
	#define TRACE(x...)
#endif

#define PRINT(x...) TRACE(printf(x))
#define WATCH(x) TRACE(cout << #x" = " << x << "\n")
struct jogadas{
	int valor;
	int categoria;
	int linha;
}j [169];
bool cmp(jogadas a, jogadas b){
	if(a.valor > b.valor) return true;
	return false;
}
int calcula(){
	int res[12];
	memset(res, 0, 12);

	for (int i = 0; i < 169; ++i)
	{
		if(res[j[i].categoria] < j[i].valor)
			res[j[i].categoria] = j[i].valor;
	}

	return 0;
}
int main()
{
	int  n[5];
	int i = 0;
	while(scanf("%d %d %d %d %d",&n[0], &n[1], &n[2], &n[3], &n[4]) != -1){
		int k;
		for(k = 0; k < 13; k++)
			j[i*13+k].linha = i;
		for(k = 0; k < 6; k++){
			j[i*13+k].valor = (n[0]==k+1?k+1:0) +(n[1]==k+1?k+1:0) +(n[2]==k+1?k+1:0) +(n[3]==k+1?k+1:0) +(n[4]==k+1?k+1:0);
			j[i*13+k].categoria = k;
		}
		j[i*13+6].valor = accumulate(n, n+5, 0);
		j[i*13+6].categoria = 6;
		sort(n, n+5);
		if((n[0]==n[1] && n[1] == n[2]) || (n[1]==n[2] && n[2] == n[3]) || (n[2]==n[3] && n[3] == n[4])){
			j[i*13+7].valor = accumulate(n, n+5, 0);
		}else{
			j[i*13+7].valor = 0;
		}
		j[i*13+7].categoria = 7;

		if((n[0] == n[1] && n[1] == n[2] && n[2] == n[3]) || (n[1] == n[2] && n[2] == n[3] && n[3] == n[4])){
			j[i*13+8].valor = accumulate(n, n+5, 0);
		}else{
			j[i*13+8].valor = 0;
		}
		j[i*13+8].categoria = 8;

		if(n[0] == n[1] && n[1] == n[2] && n[2] == n[3] && n[3] == n[4]){
			j[i*13+9].valor = 50;
		}else{
			j[i*13+9].valor = 0;
		}
		j[i*13+9].categoria = 9;

		if((n[0] == n[1]+1 && n[1] == n[2]+1 && n[2] == n[3]+1) || (n[1] == n[2]+1 && n[2] == n[3]+1 && n[3] == n[4]+1)){
			j[i*13+10].valor = 25;
		}else{
			j[i*13+10].valor = 0;
		}
		j[i*13+10].categoria = 10;

		if(n[0] == n[1]+1 && n[1] == n[2]+1 && n[2] == n[3]+1 && n[3] == n[4]+1){
			j[i*13+11].valor = 35;
		}else{
			j[i*13+11].valor = 0;
		}
		j[i*13+11].categoria = 11;
		if((n[0] == n[1] && n[1] == n[2] && n[3] == n[4]) || (n[0] == n[1] && n[2] == n[3] && n[3] == n[4])){
			j[i*13+12].valor = 40;
		}else{
			j[i*13+12].valor = 0;
		}
		j[i*13+12].categoria = 12;

		if(i == 12){
		 i=0;
		 sort(j,j+169, cmp);
		 calcula();	
		}
		i++;
	}
	return 0;
}
