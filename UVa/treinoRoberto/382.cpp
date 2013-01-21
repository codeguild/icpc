#include<stdio.h>
#include<string>
#include<iostream>
#include<math.h>
#include<string.h>
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


//Sample Input

//15 28 6 56 60000 22 496 0

//Sample Output

//PERFECTION OUTPUT
//   15  DEFICIENT
//   28  PERFECT
//    6  PERFECT
//   56  ABUNDANT
//60000  ABUNDANT
//   22  DEFICIENT
//  496  PERFECT
//END OF OUTPUT

long int gera(long int ent){
	long int saida = 0;
	for (int i = 1; i <= ent/2; ++i)
	{
		if((ent%i == 0)){
			saida += i;
		}
	}
	return saida;
}
int main()
{
	printf("PERFECTION OUTPUT\n");
	long int ent;
	long int 
	saida;
	scanf("%ld", &ent);
	while(ent != 0){
		saida = gera(ent);

		

		if(saida == ent) printf("%5ld  PERFECT\n", ent);
		else if(saida < ent) printf("%5ld  DEFICIENT\n", ent);
		else printf("%5ld  ABUNDANT\n", ent);
		scanf("%ld", &ent);
	}
	printf("END OF OUTPUT");
	return 0;
}
